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
