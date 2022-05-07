//
// Created by Даниил Палеев on 22.04.2022.
//

#include "TreeNode.h"

void TreeNode::findPaths(ILogger *Logger, const Map &Map, const EnvironmentOptions &options) {
    paths = {};
    costs = {};
    totalCost = 0;
    for (int agent_id = 0; agent_id < Map.getAgentsNumber(); ++agent_id) {
        Search search;
        SearchResult sr = search.startSearch(Logger, Map, options, agent_id, {});
        paths.push_back(std::make_shared<std::list<Node>>(*sr.hppath));
        costs.push_back(sr.pathlength);
        totalCost += sr.pathlength;
    }
}

void TreeNode::updatePath(ILogger *Logger, const Map &Map, const EnvironmentOptions &options, int agent_id) {
    Search search;
    SearchResult sr = search.startSearch(Logger, Map, options, agent_id, constraints[agent_id]);
    paths[agent_id] = std::make_shared<std::list<Node>>(*sr.hppath);
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

bool TreeNode::hasConflict(std::vector<Constraint>& res) {
    for (int i = 0; i < paths.size(); i++) {
        for (int j = i + 1; j < paths.size(); j++) {
            auto min_index = std::min(paths[i]->size(), paths[j]->size());
            auto it1 = paths[i]->begin();
            auto it2 = paths[j]->begin();
            for (int k = 0; k < std::max(paths[i]->size(), paths[j]->size()); k++) {
                if (it1->i == it2->i && it1->j == it2->j) {
                    if (k < paths[i]->size()) {
                        res.push_back({i, k, {it1->i, it1->j}});
                    }
                    if (k < paths[j]->size()) {
                        res.push_back({j, k, {it1->i, it1->j}});
                    }
                    return true;
                }
                if (k != 0) {
                    auto pr1 = it1;
                    if (k < paths[i]->size()) {
                        pr1 = prev(it1);
                    }
                    auto pr2 = it2;
                    if (k < paths[j]->size()) {
                        pr2 = prev(it2);
                    }
                    if (it1->i == pr2->i && it1->j == pr2->j && pr1->i == it2->i && pr1->j == it2->j) {
                        res.push_back({i, k, {it1->i, it1->j}});
                        res.push_back({j, k, {it2->i, it2->j}});
                        return true;
                    }
                }
                if (k < paths[i]->size()) {
                    ++it1;
                }
                if (k < paths[j]->size()) {
                    ++it2;
                }
            }
        }
    }
    return false;
}

int TreeNode::countConflicts() {
    int count = 0;
    for (int i = 0; i < paths.size(); i++) {
        for (int j = i + 1; j < paths.size(); j++) {
            auto min_index = std::min(paths[i]->size(), paths[j]->size());
            auto it1 = paths[i]->begin();
            auto it2 = paths[j]->begin();
            for (int k = 0; k < std::max(paths[i]->size(), paths[j]->size()); k++) {
                if (it1->i == it2->i && it1->j == it2->j) {
                    count++;
                }
                if (k != 0) {
                    auto pr1 = it1;
                    if (k < paths[i]->size()) {
                        pr1 = prev(it1);
                    }
                    auto pr2 = it2;
                    if (k < paths[j]->size()) {
                        pr2 = prev(it2);
                    }
                    if (it1->i == pr2->i && it1->j == pr2->j && pr1->i == it2->i && pr1->j == it2->j) {
                        count++;
                    }
                }
                if (k < paths[i]->size()) {
                    ++it1;
                }
                if (k < paths[j]->size()) {
                    ++it2;
                }
            }
        }
    }
    return count;
}