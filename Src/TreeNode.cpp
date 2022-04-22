//
// Created by Даниил Палеев on 22.04.2022.
//

#include "TreeNode.h"
#include "search.h"

void TreeNode::findPaths(ILogger *Logger, const Map &Map, const EnvironmentOptions &options) {
    paths = {};
    costs = {};
    totalCost = 0;
    for (int agent_id = 0; agent_id < Map.getAgentsNumber(); ++agent_id) {
        Search search;
        SearchResult sr = search.startSearch(Logger, Map, options, agent_id, {});
        paths.push_back(std::make_shared<std::list<Node>>(*sr.lppath));
        costs.push_back(sr.pathlength);
        totalCost += sr.pathlength;
    }
}

void TreeNode::updatePath(ILogger *Logger, const Map &Map, const EnvironmentOptions &options, int agent_id) {
    Search search;
    SearchResult sr = search.startSearch(Logger, Map, options, agent_id, constraints[agent_id]);
    paths[agent_id] = std::make_shared<std::list<Node>>(*sr.lppath);
    totalCost -= costs[agent_id];
    costs[agent_id] = sr.pathlength;
    totalCost += sr.pathlength;
}

std::vector<std::list<Node>> TreeNode::getPaths() {
    std::vector<std::list<Node>> result;
    for (auto & path : paths) {
        result.push_back(*path);
    }
    return result;
}

bool TreeNode::hasConflict(std::vector<int>& res) {
    for (int i = 0; i < paths.size(); i++) {
        for (int j = i + 1; j < paths.size(); j++) {
            auto min_index = std::min(paths[i]->size(), paths[j]->size());
            auto it1 = paths[i]->begin();
            auto it2 = paths[j]->begin();
            for (int k = 0; k < min_index; k++) {
                if (it1->i == it2->i && it1->j == it2->j) {
                    res = {i, j, it1->i, it1->j, k};
                    return true;
                }
            }
        }
    }
    return false;
}
