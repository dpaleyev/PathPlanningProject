#ifndef PALEYEV_DANIEL_ASEARCH_HIGHLEVELSEARCH_H
#define PALEYEV_DANIEL_ASEARCH_HIGHLEVELSEARCH_H

#include "MDD.h"
#include "TreeNode.h"

struct HighLevelResults {
  std::vector<std::list<Node>> paths;
  float totalCost;
};

class HighLevelSearch {
  std::list<TreeNode> OPEN;
  std::unordered_map<int, std::unordered_map<int, MDD>> diagram;
  bool findCardinalConflict(TreeNode &node, std::vector<Constraint> &res,
                            const Map &Map, const EnvironmentOptions &options);
  bool isCardinal(int id, int cost, int depth, const Map &Map,
                  const EnvironmentOptions &options);
  bool findBypass(TreeNode &node, std::vector<Constraint> &conflict,
                  ILogger *Logger, const Map &Map,
                  const EnvironmentOptions &options);

public:
  HighLevelResults solve(ILogger *Logger, const Map &Map,
                         const EnvironmentOptions &options);
  std::list<TreeNode>::iterator findBestNode();
};

#endif // PALEYEV_DANIEL_ASEARCH_HIGHLEVELSEARCH_H
