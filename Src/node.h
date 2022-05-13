#ifndef NODE_H
#define NODE_H

#include <utility>

//That's the data structure for storing a single search node.
//You MUST store all the intermediate computations occuring during the search
//incapsulated to Nodes (so NO separate arrays of g-values etc.)

struct Node
{
    int     i, j, step; //grid cell coordinates
    double  F, g, H; //f-, g- and h-values of the search node
    Node    *parent; //backpointer to the predecessor node (e.g. the node which g-value was used to set the g-velue of the current node)

};

struct Cordinates {
    int x, y, step;

    bool operator==(const Cordinates &p) const {
        return x == p.x && y == p.y && step == p.step;
    }
};

struct pair_hash {
    std::size_t operator()(const std::pair<int, int> &x) const {
        return std::hash<int>()(x.first) ^ std::hash<int>()(x.second);
    }
};

struct cord_hash {
    std::size_t operator()(const Cordinates &cord) const {
        return std::hash<int>()(cord.x) ^ std::hash<int>()(cord.y) ^ std::hash<int>()(cord.step);
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

#endif
