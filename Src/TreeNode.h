#ifndef PALEYEV_DANIEL_ASEARCH_TREENODE_H
#define PALEYEV_DANIEL_ASEARCH_TREENODE_H
#include <utility>
#include <vector>
#include <list>
#include <memory>
#include "node.h"
#include "map.h"
#include "environmentoptions.h"
#include "ilogger.h"


struct Constraint {
    int id;
    int time;
    std::pair<int, int> cell;
};

class TreeNode {
public:
    float totalCost = 0;
    std::unordered_map<int, std::unordered_map<int, std::vector<std::pair<int, int>>>> constraints;
    std::vector<std::shared_ptr<std::list<Node>>> paths;
    std::vector<float> costs;

    TreeNode() = default;

    TreeNode(TreeNode& node, Constraint& constraint) : totalCost(node.totalCost), constraints(node.constraints), paths(node.paths), costs(node.costs) {
        constraints[constraint.id][constraint.time].push_back(constraint.cell);
    }

    void findPaths(ILogger *Logger, const Map &Map, const EnvironmentOptions &options);
    void updatePath(ILogger *Logger, const Map &Map, const EnvironmentOptions &options, int agent_id);
    bool hasConflict(std::vector<int>& res);
    std::vector<std::list<Node>> getPaths();

};

#endif //PALEYEV_DANIEL_ASEARCH_HIGHLEVELSEARCH_H