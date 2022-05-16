#ifndef SEARCH_H
#define SEARCH_H
#include "environmentoptions.h"
#include "ilogger.h"
#include "searchresult.h"
#include <chrono>
#include <limits>
#include <list>
#include <math.h>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

class Search {
public:
  Search();
  ~Search(void);
  SearchResult
  startSearch(ILogger *Logger, const Map &map,
              const EnvironmentOptions &options, int agent_id,
              const std::unordered_map<
                  int, std::unordered_set<std::pair<int, int>, pair_hash>>
                  &constraints);

protected:
  // CODE HERE

  // Hint 1. You definetely need class variables for OPEN and CLOSE

  // Hint 2. It's a good idea to define a heuristic calculation function, that
  // will simply return 0 for non-heuristic search methods like Dijkstra

  // Hint 3. It's a good idea to define function that given a node (and other
  // stuff needed) will return it's sucessors, e.g. unordered list of nodes

  // Hint 4. working with OPEN and CLOSE is the core
  // so think of the data structures that needed to be used, about the wrap-up
  // classes (if needed) Start with very simple (and ineffective) structures like
  // list or vector and make it work first and only then begin enhancement!

  std::set<Node *, Comparator> OPEN_order;
  std::unordered_map<Cordinates, Node *, cord_hash> CLOSED, OPEN_find;
  SearchResult sresult;           // This will store the search result
  std::list<Node> lppath, hppath; //

  // CODE HERE to define other members of the class
  void makePrimaryPath(Node curNode);
  void makeSecondaryPath();
  static double getHeuristic(int i_cur, int j_cur,
                             const EnvironmentOptions &options, const Map &map,
                             int agent_id);
};
#endif
