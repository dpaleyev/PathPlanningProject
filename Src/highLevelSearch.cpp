//
// Created by Даниил Палеев on 22.04.2022.
//

#include "highLevelSearch.h"

HighLevelResults HighLevelSearch::solve(ILogger *Logger, const Map &Map, const EnvironmentOptions &options) {
    auto root = TreeNode();
    root.findPaths(Logger, Map, options);
    OPEN.push_back(root);

    while(!OPEN.empty()) {
        auto bestIt = findBestNode();
        TreeNode P = *bestIt;
        OPEN.erase(bestIt);

        std::vector<Constraint> conflict;
        if (!P.hasConflict(conflict)) {
            HighLevelResults hsr;
            hsr.paths = P.getPaths();
            hsr.totalCost = P.totalCost;
            return hsr;
        }

        if (true) { //TODO:Parse input options PC + BP
            if (!findCardinalConflict(P, conflict, Map, options)) {
                if (findBypass(P, conflict, Logger, Map, options)) {
                    continue;
                }
            }
        }

        for (int i = 0; i < 2; ++i) {
            TreeNode A(P, conflict[i]);
            A.updatePath(Logger, Map, options, conflict[i].id);
            OPEN.push_back(A);
        }
    }
    return {};
}

std::list<TreeNode>::iterator HighLevelSearch::findBestNode() {
    auto bestNode = OPEN.begin();
    for (auto it = OPEN.begin(); it != OPEN.end(); ++it) {
        if (it->totalCost < bestNode->totalCost) {
            bestNode = it;
        }
    }
    return bestNode;
}

bool HighLevelSearch::findCardinalConflict(TreeNode &node, std::vector<Constraint>& res, const Map &Map, const EnvironmentOptions &options) {
    for (int i = 0; i < (int)node.paths.size(); i++) {
        for (int j = i + 1; j < (int)node.paths.size(); j++) {
            auto it1 = node.paths[i]->begin();
            auto it2 = node.paths[j]->begin();
            for (size_t k = 0; k < std::max(node.paths[i]->size(), node.paths[j]->size()); k++) {
                if (it1->i == it2->i && it1->j == it2->j) {
                    if (isCardinal(i, node.costs[i], k, Map, options) || isCardinal(j, node.costs[j], k, Map, options)) {
                        res = {};
                        if (k < node.paths[i]->size()) {
                            res.push_back({i, (int)k, {it1->i, it1->j}});
                        }
                        if (k < node.paths[j]->size()) {
                            res.push_back({j, (int)k, {it1->i, it1->j}});
                        }
                        return true;
                    }
                }
                if (k != 0) {
                    auto pr1 = it1;
                    if (k < node.paths[i]->size()) {
                        pr1 = prev(it1);
                    }
                    auto pr2 = it2;
                    if (k < node.paths[j]->size()) {
                        pr2 = prev(it2);
                    }
                    if (it1->i == pr2->i && it1->j == pr2->j && pr1->i == it2->i && pr1->j == it2->j) {
                        if (isCardinal(i, node.costs[i], k, Map, options) || isCardinal(j, node.costs[j], k, Map, options)) {
                            res = {};
                            res.push_back({i, (int)k, {it1->i, it1->j}});
                            res.push_back({j, (int)k, {it2->i, it2->j}});
                            return true;
                        }
                    }
                }
                if (k < node.paths[i]->size()) {
                    ++it1;
                }
                if (k < node.paths[j]->size()) {
                    ++it2;
                }
            }
        }
    }
    return false;
}

bool HighLevelSearch::isCardinal(int id, int cost, int depth, const Map &Map, const EnvironmentOptions &options) {
    if (depth > cost) {
        return false;
    }

    if (diagram.find(id) == diagram.end()) {
        diagram[id][cost] = MDD(Map, options, id, cost);
    }
    if (diagram[id].find(cost) == diagram[id].end()) {
        diagram[id][cost] = MDD(Map, options, id, cost);
    }

    MDD &d = diagram[id][cost];
    return d.isCardinal(depth);
}

bool HighLevelSearch::findBypass(TreeNode &node, std::vector<Constraint> &conflict, ILogger *Logger, const Map &Map, const EnvironmentOptions &options) {
    for (int i = 0; i < 2; ++i) {
        TreeNode A(node, conflict[i]);
        A.updatePath(Logger, Map, options, conflict[i].id);
        if (A.totalCost == node.totalCost && A.countConflicts() < node.countConflicts()) {
            node.paths = A.paths;
            OPEN.push_back(node);
            return true;
        }
    }
    return false;
}
