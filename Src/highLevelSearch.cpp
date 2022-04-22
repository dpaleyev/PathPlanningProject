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

        std::vector<int> conflict;
        if (!P.hasConflict(conflict)) {
            HighLevelResults hsr;
            hsr.paths = P.getPaths();
            hsr.totalCost = P.totalCost;
            return hsr;
        }
        for (int i = 0; i < 2; ++i) {
            Constraint constraint;
            constraint.id = conflict[i];
            constraint.time = conflict[4];
            constraint.cell = {conflict[2], conflict[3]};
            TreeNode A(P, constraint);
            A.updatePath(Logger, Map, options, conflict[i]);
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
