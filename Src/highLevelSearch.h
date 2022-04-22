#ifndef PALEYEV_DANIEL_ASEARCH_HIGHLEVELSEARCH_H
#define PALEYEV_DANIEL_ASEARCH_HIGHLEVELSEARCH_H

#include "TreeNode.h"

struct HighLevelResults {
    std::vector<std::list<Node>> paths;
    float totalCost;
};

class HighLevelSearch {
    std::list<TreeNode> OPEN;
public:
    HighLevelResults solve(ILogger *Logger, const Map &Map, const EnvironmentOptions &options);
    std::list<TreeNode>::iterator findBestNode();
};

#endif //PALEYEV_DANIEL_ASEARCH_HIGHLEVELSEARCH_H
