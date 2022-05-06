//
// Created by Даниил Палеев on 05.05.2022.
//

#ifndef PALEYEV_DANIEL_ASEARCH_MDD_H
#define PALEYEV_DANIEL_ASEARCH_MDD_H

#include "node.h"
#include "map.h"
#include "environmentoptions.h"
#include <unordered_map>


class MDD {

    std::vector<int> layers;
    int cost, agent_id;

    std::unordered_map<std::pair<int, int>, int, pair_hash>
    bfs(const Map &map, const EnvironmentOptions &options, std::pair<int, int> start);

public:

    MDD(const Map &map, const EnvironmentOptions &options, int id, int c);
    bool isCardinal(int step);
};

#endif //PALEYEV_DANIEL_ASEARCH_MDD_H
