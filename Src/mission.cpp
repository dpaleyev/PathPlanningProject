#include "mission.h"
#include <iostream>

Mission::Mission()
{
    logger = nullptr;
    fileName = nullptr;
}

Mission::Mission(const char *FileName)
{
    fileName = FileName;
    logger = nullptr;
}

Mission::~Mission()
{
    if (logger)
        delete logger;
}

bool Mission::getMap()
{
    return map.getMap(fileName);
}

bool Mission::getConfig()
{
    return config.getConfig(fileName);
}

bool Mission::createLog()
{
    if (logger != nullptr) delete logger;
    logger = new XmlLogger(config.LogParams[CN_LP_LEVEL]);
    return logger->getLog(fileName, config.LogParams);
}

void Mission::createEnvironmentOptions()
{
    options.cutcorners = config.SearchParams[CN_SP_CC];
    options.allowsqueeze = config.SearchParams[CN_SP_AS];
    options.allowdiagonal = config.SearchParams[CN_SP_AD];
    options.metrictype = config.SearchParams[CN_SP_MT];
    options.prioratizeconflicts = config.HighSearchParams[CN_SP_PC];
    options.bypass = config.HighSearchParams[CN_SP_BP];
    options.corridorsymmetry = config.HighSearchParams[CN_SP_CR];
    options.targetsymmetry = config.HighSearchParams[CN_SP_TR];

}

void Mission::createSearch()
{
//might be helpful in case numerous algorithms are added
}

void Mission::startSearch()
{
    auto start_time = std::chrono::system_clock::now();
    hsr = search.solve(logger, map, options);
    time = (std::chrono::system_clock::now() - start_time).count();
}

void Mission::printSearchResultsToConsole()
{
    std::cout << "Path ";
    if (hsr.totalCost == -1)
        std::cout << "NOT ";
    std::cout << "found!" << std::endl;
    if (hsr.totalCost != -1) {
        std::cout << "pathlength=" << hsr.totalCost << std::endl;
        std::cout << "pathlength_scaled=" << hsr.totalCost * map.getCellSize() << std::endl;
    }
    std::cout << "time=" << time << std::endl;
}

void Mission::saveSearchResultsToLog()
{
    logger->writeToLogSummary( hsr.totalCost, time, map.getCellSize());
    if (hsr.totalCost != -1) {
        //logger->writeToLogPath(hsr.paths);
        logger->writeToLogHPpath(hsr.paths);
        //logger->writeToLogMap(map, *sr.lppath);
    } else
        logger->writeToLogNotFound();
    logger->saveLog();
}

