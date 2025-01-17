#ifndef ILOGGER_H
#define ILOGGER_H
#include "map.h"
#include "node.h"
#include <list>
#include <unordered_map>

class ILogger {
public:
  ILogger(std::string loglevel) { this->loglevel = loglevel; }
  virtual bool getLog(const char *FileName, const std::string *LogParams) = 0;
  virtual void saveLog() = 0;
  // virtual void writeToLogMap(const Map& map, const std::list<Node>& path) =
  // 0; virtual void writeToLogOpenClose(const typename &open, const typename
  // &close) = 0;
  virtual void writeToLogPath(const std::vector<std::list<Node>> &path) = 0;
  virtual void writeToLogHPpath(const std::vector<std::list<Node>> &path) = 0;
  virtual void writeToLogNotFound() = 0;
  virtual void writeToLogSummary(float length, double time,
                                 double cellSize) = 0;
  virtual ~ILogger(){};

protected:
  std::string loglevel;
};

#endif
