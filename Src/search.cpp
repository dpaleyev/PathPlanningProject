#include "search.h"


Search::Search()
{
//set defaults here
}

Search::~Search() {}


SearchResult Search::startSearch(ILogger *Logger, const Map &map, const EnvironmentOptions &options)
{
    auto start_time = std::chrono::system_clock::now();
    sresult.pathfound = false;
    auto [start_i, start_j] = map.getStart();
    Node* start = new Node {start_i, start_j, 0, 0, 0, nullptr};
    OPEN_order.insert(start);
    OPEN_find.insert({{start->i, start->j}, start});

    Node* head = nullptr;
    while (!OPEN_order.empty()) {
        Node* s = *OPEN_order.begin();
        OPEN_order.erase(OPEN_order.begin());
        OPEN_find.erase({s->i, s->j});
        CLOSED.insert({{s->i, s->j}, s});
        if (std::make_pair(s->i, s->j) == map.getGoal()) {
            sresult.pathfound = true;
            head = s;
            break;
        }
        for (int d_i = -1; d_i <= 1; d_i++) {
            for (int d_j = -1; d_j <= 1; d_j++) {
                if (d_i == 0 && d_j == 0) {
                    continue;
                }
                double d_dist = abs(d_i) == abs(d_j) ? CN_SQRT_TWO * map.getCellSize() : map.getCellSize();
                if (OPEN_find.find({s->i + d_i, s->j + d_j}) == OPEN_find.end() &&
                    CLOSED.find({s->i + d_i, s->j + d_j}) == CLOSED.end()) {
                    Node *s_new = new Node{s->i + d_i, s->j + d_j, 0, s->g + d_dist, 0, s};
                    OPEN_order.insert(s_new);
                    OPEN_find.insert({{s_new->i, s_new->j}, start});
                } else {
                    if (OPEN_find.find({s->i + d_i, s->j + d_j}) != OPEN_find.end()) {
                        Node *s_new = OPEN_find[{s->i + d_i, s->j + d_j}];
                        if (s->g + d_dist > s_new->g) {
                            s_new->g = s->g + d_dist;
                            s_new->parent = s;
                        }
                    }
                }
            }
        }
    }
    //makePrimaryPath(*head);
    sresult.nodescreated = OPEN_find.size() + CLOSED.size();
    sresult.numberofsteps = CLOSED.size();
    sresult.time = (std::chrono::system_clock::now() - start_time).count();
    sresult.hppath = &hppath; //Here is a constant pointer
    sresult.lppath = &lppath;
    return sresult;
}



void Search::makePrimaryPath(Node curNode)
{
    hppath.push_back(curNode);
    while (curNode.parent) {
        curNode = *curNode.parent;
        hppath.push_back(curNode);
    }
}

/*void Search::makeSecondaryPath()
{
    //need to implement
}*/
