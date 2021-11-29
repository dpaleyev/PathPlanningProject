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
    OPEN.insert(new Node {start_i, start_j, 0, 0, 0, nullptr});

    while (!OPEN.empty()) {
        Node* v = *OPEN.begin();
        OPEN.erase(OPEN.begin());
        CLOSED.insert(v);
        for (Node* i: OPEN) {
            if (i->g < v->g) {
                v = i;
            }
        }
        if (std::make_pair(v->i, v->j) == map.getGoal()) {
            sresult.pathfound = true;
        }
        for (auto& sucessor : getSucessors(map, v->i, v->j)) {
            Node* target = nullptr;
            for (Node* i: CLOSED) {
                if (i->i == sucessor.first && i->j == sucessor.second) {
                    target = i;
                }
            }
            if (!target) {
                for (Node* i: OPEN) {
                    if (i->i == sucessor.first && i->j == sucessor.second) {
                        target = i;
                    }
                }
                if (target) {
                    if (target->g > v->g + map.getCellSize()) {
                        target->g = v->g + map.getCellSize();
                        target->parent = v;
                    }
                    continue;
                } else {
                    OPEN.insert(new Node {sucessor.first, sucessor.second, 0, v->g + map.getCellSize(), 0, v});
                }
            }
        }
    }

    sresult.nodescreated = OPEN.size() + CLOSED.size();
    sresult.numberofsteps = CLOSED.size();
    sresult.time = (std::chrono::system_clock::now() - start_time).count();
    sresult.hppath = &hppath; //Here is a constant pointer
    sresult.lppath = &lppath;
    return sresult;
}

std::vector<std::pair<int, int>> Search::getSucessors(const Map &map, int i, int j) {
    std::vector<std::pair<int, int>> res;
    std::vector<int> delta_i = {-1, 0, 1, 0};
    std::vector<int> delta_j = {0, -1, 0, 1};
    for (int p = 0; p < 4; ++p) {
        if (map.CellOnGrid(i + delta_i[p], j + delta_j[p]) && map.CellIsTraversable(i + delta_i[p], j + delta_j[p])) {
            res.emplace_back(i + delta_i[p], j + delta_j[p]);
        }
    }
    return res;
}

/*void Search::makePrimaryPath(Node curNode)
{
    //need to implement
}*/

/*void Search::makeSecondaryPath()
{
    //need to implement
}*/
