//
// Created by Даниил Палеев on 05.05.2022.
//

#include "MDD.h"
#include <set>
#include <unordered_set>

MDD::MDD(const Map &map, const EnvironmentOptions &options, int id, int c) {
  cost = c;
  agent_id = id;
  layers.resize(cost + 1, 0);
  auto depth1 = bfs(map, options, map.getStart(agent_id));
  auto depth2 = bfs(map, options, map.getGoal(agent_id));
  for (auto elem : depth1) {
    auto ind = elem.first;
    int depth = elem.second;
    if (depth2.find(ind) != depth2.end()) {
      if (depth + depth2[ind] <= cost) {
        for (int i = depth; i <= cost - depth2[ind]; ++i) {
          layers[i] += 1;
        }
      }
    }
  }
}

std::unordered_map<std::pair<int, int>, int, pair_hash>
MDD::bfs(const Map &map, const EnvironmentOptions &options,
         std::pair<int, int> start) {
  std::unordered_map<std::pair<int, int>, int, pair_hash> result;
  std::set<Node *, Comparator> order;
  std::unordered_set<std::pair<int, int>, pair_hash> used;
  Node *start_node = new Node{start.first, start.second, 0, 0, 0, 0, nullptr};
  order.insert(start_node);
  used.insert(std::make_pair(start_node->i, start_node->j));

  while (!order.empty()) {
    Node *s = *order.begin();
    order.erase(order.begin());
    result[{s->i, s->j}] = s->step;

    for (int d_i = -1; d_i <= 1; d_i++) {
      for (int d_j = -1; d_j <= 1; d_j++) {
        if (d_i == 0 && d_j == 0) {
          continue;
        }
        if (!map.CellOnGrid(s->i + d_i, s->j + d_j)) {
          continue;
        }
        if (map.CellIsObstacle(s->i + d_i, s->j + d_j)) {
          continue;
        }

        if (abs(d_i) == 1 && abs(d_j) == 1) {
          if (!options.allowdiagonal) {
            continue;
          }
          if (!options.allowdiagonal && map.CellIsObstacle(s->i + d_i, s->j) &&
              map.CellIsObstacle(s->i, s->j + d_j)) {
            continue;
          }
          if (!options.cutcorners && (map.CellIsObstacle(s->i + d_i, s->j) ||
                                      map.CellIsObstacle(s->i, s->j + d_j))) {
            continue;
          }
        }

        if (used.find({s->i + d_i, s->j + d_j}) == used.end()) {
          if (s->step + 1 <= cost) {
            Node *s_new = new Node{s->i + d_i,
                                   s->j + d_j,
                                   s->step + 1,
                                   static_cast<double>(s->step + 1),
                                   0,
                                   0,
                                   s};
            order.insert(s_new);
            used.insert(std::make_pair(s_new->i, s_new->j));
          }
        }
      }
    }
  }
  return result;
}

bool MDD::isCardinal(int step) { return layers[step] < 2; }
