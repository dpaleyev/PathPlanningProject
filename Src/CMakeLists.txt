
set(HEADERS         config.h
                    environmentoptions.h
                    gl_const.h
                    ilogger.h
                    map.h
                    mission.h
                    node.h
                    search.h
                    searchresult.h
                    tinyxml2.h
                    xmllogger.h highLevelSearch.cpp highLevelSearch.h)

set(SOURCES         config.cpp
                    environmentoptions.cpp
                    map.cpp
                    mission.cpp
                    search.cpp
                    tinyxml2.cpp
                    xmllogger.cpp highLevelSearch.cpp highLevelSearch.h)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} main.cpp highLevelSearch.cpp highLevelSearch.h TreeNode.cpp TreeNode.h)

add_library(PPLIB ${HEADERS} ${SOURCES} highLevelSearch.cpp highLevelSearch.h)

install(TARGETS ${PROJECT_NAME} 
        CONFIGURATIONS Debug
        DESTINATION Bin/Debug)

install(TARGETS ${PROJECT_NAME}
        CONFIGURATIONS Release
        DESTINATION Bin/Release)
