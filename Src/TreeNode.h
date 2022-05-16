//
// Created by Даниил Палеев on 22.04.2022.
//

#ifndef PALEYEV_DANIEL_ASEARCH_TREENODE_H
#define PALEYEV_DANIEL_ASEARCH_TREENODE_H
#include "environmentoptions.h"
#include "ilogger.h"
#include "map.h"
#include "node.h"
#include "search.h"
#include <list>
#include <memory>
#include <utility>
#include <vector>

struct Constraint {
  int id;
  int time;
  std::pair<int, int> cell;
};

class TreeNode {
public:
  float totalCost = 0;
  std::unordered_map<
      int, std::unordered_map<
               int, std::unordered_set<std::pair<int, int>, pair_hash>>>
      constraints;
  std::vector<std::shared_ptr<std::list<Node>>> paths;
  std::vector<float> costs;

  TreeNode() = default;

  TreeNode(TreeNode &node, std::vector<Constraint> constraint)
      : totalCost(node.totalCost), constraints(node.constraints),
        paths(node.paths), costs(node.costs) {
    for (auto &c : constraint) {
      constraints[c.id][c.time].insert(c.cell);
    }
  }

  void findPaths(ILogger *Logger, const Map &Map,
                 const EnvironmentOptions &options);
  void updatePath(ILogger *Logger, const Map &Map,
                  const EnvironmentOptions &options, int agent_id);
  bool hasConflict(std::vector<Constraint> &res);
  int countConflicts();
  std::vector<std::list<Node>> getPaths();
};

#endif // PALEYEV_DANIEL_ASEARCH_TREENODE_H
