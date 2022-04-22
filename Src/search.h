#ifndef SEARCH_H
#define SEARCH_H
#include "ilogger.h"
#include "searchresult.h"
#include "environmentoptions.h"
#include <list>
#include <vector>
#include <math.h>
#include <limits>
#include <chrono>
#include <set>
#include <unordered_map>
#include <utility>
#include <unordered_set>

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*1000000+v.second;
    }
};

struct Comparator {
    bool operator() (const Node* a, const Node* b) const {
        if (a->F == b->F) {
            if (a->i == b->i) {
                return a->j < b->j;
            }
            return a->i < b->i;
        }
        return a->F < b->F;
    }
};

struct PairHash {
    std::size_t operator()(const std::pair<int, int> &x) const {
        return std::hash<int>()(x.first) ^ std::hash<int>()(x.second);
    }
};

class Search
{
    public:
        Search();
        ~Search(void);
        SearchResult startSearch(ILogger *Logger, const Map &map, const EnvironmentOptions &options, int agent_id, const std::unordered_map<int, std::unordered_set<std::pair<int, int>, pair_hash>>& constraints);

    protected:
        //CODE HERE

        //Hint 1. You definetely need class variables for OPEN and CLOSE

        //Hint 2. It's a good idea to define a heuristic calculation function, that will simply return 0
        //for non-heuristic search methods like Dijkstra

        //Hint 3. It's a good idea to define function that given a node (and other stuff needed)
        //will return it's sucessors, e.g. unordered list of nodes

        //Hint 4. working with OPEN and CLOSE is the core
        //so think of the data structures that needed to be used, about the wrap-up classes (if needed)
        //Start with very simple (and ineffective) structures like list or vector and make it work first
        //and only then begin enhancement!

        std::set<Node*, Comparator> OPEN_order;
        std::unordered_map<std::pair<int, int>, Node*, PairHash> CLOSED, OPEN_find;
        SearchResult                    sresult; //This will store the search result
        std::list<Node>                 lppath, hppath; //

        //CODE HERE to define other members of the class
        void makePrimaryPath(Node curNode);
        void makeSecondaryPath();
        static double getHeuristic(int i_cur, int j_cur, const EnvironmentOptions &options, const Map& map, int agent_id);
};
#endif
