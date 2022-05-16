#include "map.h"


Map::Map()
{
    height = -1;
    width = -1;
    agents_n = -1;
    start_i = {};
    start_j = {};
    goal_i = {};
    goal_j = {};
    Grid = nullptr;
    cellSize = 1;
}

Map::~Map()
{
    if (Grid) {
        for (int i = 0; i < height; ++i)
            delete[] Grid[i];
        delete[] Grid;
    }
}

bool Map::CellIsTraversable(int i, int j) const
{
    return (Grid[i][j] == CN_GC_NOOBS);
}

bool Map::CellIsObstacle(int i, int j) const
{
    return (Grid[i][j] != CN_GC_NOOBS);
}

bool Map::CellOnGrid(int i, int j) const
{
    return (i < height && i >= 0 && j < width && j >= 0);
}

bool Map::getMap(const char *FileName)
{
    int rowiter = 0, grid_i = 0, grid_j = 0, start_i_it = 0, start_j_it = 0, goal_i_it = 0, goal_j_it = 0;

    tinyxml2::XMLElement *root = 0, *map = 0, *element = 0, *mapnode;

    std::string value;
    std::stringstream stream;

    bool hasGridMem = false, hasGrid = false, hasHeight = false, hasWidth = false, hasSTX = false, hasSTY = false, hasFINX = false, hasFINY = false, hasCellSize = false, hasAgentsNumber = false;

    tinyxml2::XMLDocument doc;

    // Load XML File
    if (doc.LoadFile(FileName) != tinyxml2::XMLError::XML_SUCCESS) {
        std::cout << "Error opening XML file!" << std::endl;
        return false;
    }
    // Get ROOT element
    root = doc.FirstChildElement(CNS_TAG_ROOT);
    if (!root) {
        std::cout << "Error! No '" << CNS_TAG_ROOT << "' tag found in XML file!" << std::endl;
        return false;
    }

    // Get MAP element
    map = root->FirstChildElement(CNS_TAG_MAP);
    if (!map) {
        std::cout << "Error! No '" << CNS_TAG_MAP << "' tag found in XML file!" << std::endl;
        return false;
    }

    for (mapnode = map->FirstChildElement(); mapnode; mapnode = mapnode->NextSiblingElement()) {
        element = mapnode->ToElement();
        value = mapnode->Value();
        std::transform(value.begin(), value.end(), value.begin(), ::tolower);

        stream.str("");
        stream.clear();

        if(value != CNS_TAG_GRID && value != CNS_TAG_STX && value != CNS_TAG_STY && value != CNS_TAG_FINX && value != CNS_TAG_FINY)
        {
           stream << element->GetText();
        }


        if (!hasGridMem && hasHeight && hasWidth) {
            Grid = new int *[height];
            for (int i = 0; i < height; ++i)
                Grid[i] = new int[width];
            hasGridMem = true;
        }

        if (value == CNS_TAG_AGENTSN) {
            if (hasAgentsNumber) {
                std::cout << "Warning! Duplicate '" << CNS_TAG_AGENTSN << "' encountered." << std::endl;
                std::cout << "Only first value of '" << CNS_TAG_AGENTSN << "' =" << agents_n << "will be used."
                          << std::endl;
            }
            else {
                if (!((stream >> agents_n) && (agents_n > 0))) {
                    std::cout << "Warning! Invalid value of '" << CNS_TAG_AGENTSN
                              << "' tag encountered (or could not convert to integer)." << std::endl;
                    std::cout << "Value of '" << CNS_TAG_AGENTSN << "' tag should be an integer >0" << std::endl;
                    std::cout << "Continue reading XML and hope correct value of '" << CNS_TAG_AGENTSN
                              << "' tag will be encountered later..." << std::endl;
                }
                else {
                    hasAgentsNumber = true;
                    start_i.resize(agents_n);
                    start_j.resize(agents_n);
                    goal_i.resize(agents_n);
                    goal_j.resize(agents_n);
                }
            }
        }
        else if (value == CNS_TAG_HEIGHT) {
            if (hasHeight) {
                std::cout << "Warning! Duplicate '" << CNS_TAG_HEIGHT << "' encountered." << std::endl;
                std::cout << "Only first value of '" << CNS_TAG_HEIGHT << "' =" << height << "will be used."
                          << std::endl;
            }
            else {
                if (!((stream >> height) && (height > 0))) {
                    std::cout << "Warning! Invalid value of '" << CNS_TAG_HEIGHT
                              << "' tag encountered (or could not convert to integer)." << std::endl;
                    std::cout << "Value of '" << CNS_TAG_HEIGHT << "' tag should be an integer >=0" << std::endl;
                    std::cout << "Continue reading XML and hope correct value of '" << CNS_TAG_HEIGHT
                              << "' tag will be encountered later..." << std::endl;
                }
                else
                    hasHeight = true;
            }
        }
        else if (value == CNS_TAG_WIDTH) {
            if (hasWidth) {
                std::cout << "Warning! Duplicate '" << CNS_TAG_WIDTH << "' encountered." << std::endl;
                std::cout << "Only first value of '" << CNS_TAG_WIDTH << "' =" << width << "will be used." << std::endl;
            }
            else {
                if (!((stream >> width) && (width > 0))) {
                    std::cout << "Warning! Invalid value of '" << CNS_TAG_WIDTH
                              << "' tag encountered (or could not convert to integer)." << std::endl;
                    std::cout << "Value of '" << CNS_TAG_WIDTH << "' tag should be an integer AND >0" << std::endl;
                    std::cout << "Continue reading XML and hope correct value of '" << CNS_TAG_WIDTH
                              << "' tag will be encountered later..." << std::endl;

                }
                else
                    hasWidth = true;
            }
        }
        else if (value == CNS_TAG_CELLSIZE) {
            if (hasCellSize) {
                std::cout << "Warning! Duplicate '" << CNS_TAG_CELLSIZE << "' encountered." << std::endl;
                std::cout << "Only first value of '" << CNS_TAG_CELLSIZE << "' =" << cellSize << "will be used."
                          << std::endl;
            }
            else {
                if (!((stream >> cellSize) && (cellSize > 0))) {
                    std::cout << "Warning! Invalid value of '" << CNS_TAG_CELLSIZE
                              << "' tag encountered (or could not convert to double)." << std::endl;
                    std::cout << "Value of '" << CNS_TAG_CELLSIZE
                              << "' tag should be double AND >0. By default it is defined to '1'" << std::endl;
                    std::cout << "Continue reading XML and hope correct value of '" << CNS_TAG_CELLSIZE
                              << "' tag will be encountered later..." << std::endl;
                }
                else
                    hasCellSize = true;
            }
        }
        else if (value == CNS_TAG_STX) {
            if (!hasWidth) {
                std::cout << "Error! '" << CNS_TAG_STX << "' tag encountered before '" << CNS_TAG_WIDTH << "' tag."
                          << std::endl;
                return false;
            }

            if (!hasAgentsNumber) {
                std::cout << "Error! '" << CNS_TAG_AGENTSN << "' tag encountered before '" << CNS_TAG_AGENTSN << "' tag."
                          << std::endl;
                return false;
            }

            if (hasSTX) {
                std::cout << "Warning! Duplicate '" << CNS_TAG_STX << "' encountered." << std::endl;
            }
            else {
                element = mapnode->FirstChildElement();
                while (start_j_it < agents_n) {
                    if (!element) {
                        std::cout << "Error! Not enough '" << CNS_TAG_AGENT << "' tags inside '" << CNS_TAG_STX
                                  << "' tag."
                                  << std::endl;
                        std::cout << "Number of '" << CNS_TAG_AGENT
                                  << "' tags should be equal the value of '" << CNS_TAG_AGENTSN
                                  << "' tag which is " << agents_n << std::endl;
                        return false;
                    }
                    std::string str = element->GetText();
                    std::stringstream ss(str);

                    if (!(ss >> start_j[start_j_it] && start_j[start_j_it] >= 0 && start_j[start_j_it] < width)) {
                        std::cout << "Warning! Invalid value of '" << CNS_TAG_STX
                                  << "' tag encountered (or could not convert to integer)" << std::endl;
                        std::cout << "Value of '" << CNS_TAG_STX << "' tag should be an integer AND >=0 AND < '"
                                  << CNS_TAG_WIDTH << "' value, which is " << width << std::endl;
                        std::cout << "Continue reading XML and hope correct value of '" << CNS_TAG_STX
                                  << "' tag will be encountered later..." << std::endl;
                    }

                    ++start_j_it;

                    element = element->NextSiblingElement();
                }
                hasSTX = true;
            }
        }else if (value == CNS_TAG_STY) {
            if (!hasHeight) {
                std::cout << "Error! '" << CNS_TAG_STY << "' tag encountered before '" << CNS_TAG_HEIGHT << "' tag."
                          << std::endl;
                return false;
            }

            if (!hasAgentsNumber) {
                std::cout << "Error! '" << CNS_TAG_AGENTSN << "' tag encountered before '" << CNS_TAG_AGENTSN << "' tag."
                          << std::endl;
                return false;
            }

            if (hasSTY) {
                std::cout << "Warning! Duplicate '" << CNS_TAG_STY << "' encountered." << std::endl;
            }
            else {
                element = mapnode->FirstChildElement();
                while (start_i_it < agents_n) {
                    if (!element) {
                        std::cout << "Error! Not enough '" << CNS_TAG_AGENT << "' tags inside '" << CNS_TAG_STY
                                  << "' tag."
                                  << std::endl;
                        std::cout << "Number of '" << CNS_TAG_AGENT
                                  << "' tags should be equal the value of '" << CNS_TAG_AGENTSN
                                  << "' tag which is " << agents_n << std::endl;
                        return false;
                    }
                    std::string str = element->GetText();
                    std::stringstream ss(str);

                    if (!(ss >> start_i[start_i_it] && start_i[start_i_it] >= 0 && start_i[start_i_it] < height)) {
                        std::cout << "Warning! Invalid value of '" << CNS_TAG_STY
                                  << "' tag encountered (or could not convert to integer)" << std::endl;
                        std::cout << "Value of '" << CNS_TAG_STY << "' tag should be an integer AND >=0 AND < '"
                                  << CNS_TAG_HEIGHT << "' value, which is " << height << std::endl;
                        std::cout << "Continue reading XML and hope correct value of '" << CNS_TAG_STY
                                  << "' tag will be encountered later..." << std::endl;
                    }

                    ++start_i_it;

                    element = element->NextSiblingElement();
                }
                hasSTY = true;
            }
        }
        else if (value == CNS_TAG_FINX) {
            if (!hasWidth) {
                std::cout << "Error! '" << CNS_TAG_FINX << "' tag encountered before '" << CNS_TAG_WIDTH << "' tag."
                          << std::endl;
                return false;
            }

            if (!hasAgentsNumber) {
                std::cout << "Error! '" << CNS_TAG_AGENTSN << "' tag encountered before '" << CNS_TAG_AGENTSN << "' tag."
                          << std::endl;
                return false;
            }

            if (hasFINX) {
                std::cout << "Warning! Duplicate '" << CNS_TAG_FINX << "' encountered." << std::endl;
            }
            else {
                element = mapnode->FirstChildElement();
                while (goal_j_it < agents_n) {
                    if (!element) {
                        std::cout << "Error! Not enough '" << CNS_TAG_AGENT << "' tags inside '" << CNS_TAG_FINX
                                  << "' tag."
                                  << std::endl;
                        std::cout << "Number of '" << CNS_TAG_AGENT
                                  << "' tags should be equal the value of '" << CNS_TAG_AGENTSN
                                  << "' tag which is " << agents_n << std::endl;
                        return false;
                    }
                    std::string str = element->GetText();
                    std::stringstream ss(str);

                    if (!(ss >> goal_j[goal_j_it] && goal_j[goal_j_it] >= 0 && goal_j[goal_j_it] < width)) {
                        std::cout << "Warning! Invalid value of '" << CNS_TAG_FINX
                                  << "' tag encountered (or could not convert to integer)" << std::endl;
                        std::cout << "Value of '" << CNS_TAG_FINX << "' tag should be an integer AND >=0 AND < '"
                                  << CNS_TAG_WIDTH << "' value, which is " << width << std::endl;
                        std::cout << "Continue reading XML and hope correct value of '" << CNS_TAG_FINX
                                  << "' tag will be encountered later..." << std::endl;
                    }

                    ++goal_j_it;

                    element = element->NextSiblingElement();
                }
                hasFINX = true;
            }
        }
        else if (value == CNS_TAG_FINY) {
            if (!hasHeight) {
                std::cout << "Error! '" << CNS_TAG_FINY << "' tag encountered before '" << CNS_TAG_HEIGHT << "' tag."
                          << std::endl;
                return false;
            }

            if (!hasAgentsNumber) {
                std::cout << "Error! '" << CNS_TAG_AGENTSN << "' tag encountered before '" << CNS_TAG_AGENTSN << "' tag."
                          << std::endl;
                return false;
            }

            if (hasFINY) {
                std::cout << "Warning! Duplicate '" << CNS_TAG_FINY << "' encountered." << std::endl;
            }
            else {
                element = mapnode->FirstChildElement();
                while (goal_i_it < agents_n) {
                    if (!element) {
                        std::cout << "Error! Not enough '" << CNS_TAG_AGENT << "' tags inside '" << CNS_TAG_FINY
                                  << "' tag."
                                  << std::endl;
                        std::cout << "Number of '" << CNS_TAG_AGENT
                                  << "' tags should be equal the value of '" << CNS_TAG_AGENTSN
                                  << "' tag which is " << agents_n << std::endl;
                        return false;
                    }
                    std::string str = element->GetText();
                    std::stringstream ss(str);

                    if (!(ss >> goal_i[goal_i_it] && goal_i[goal_i_it] >= 0 && goal_i[goal_i_it] < height)) {
                        std::cout << "Warning! Invalid value of '" << CNS_TAG_FINY
                                  << "' tag encountered (or could not convert to integer)" << std::endl;
                        std::cout << "Value of '" << CNS_TAG_FINY << "' tag should be an integer AND >=0 AND < '"
                                  << CNS_TAG_HEIGHT << "' value, which is " << height << std::endl;
                        std::cout << "Continue reading XML and hope correct value of '" << CNS_TAG_FINY
                                  << "' tag will be encountered later..." << std::endl;
                    }

                    ++goal_i_it;

                    element = element->NextSiblingElement();
                }
                hasFINY = true;
            }
        }
        else if (value == CNS_TAG_GRID) {
            hasGrid = true;
            if (!(hasHeight && hasWidth)) {
                std::cout << "Error! No '" << CNS_TAG_WIDTH << "' tag or '" << CNS_TAG_HEIGHT << "' tag before '"
                          << CNS_TAG_GRID << "'tag encountered!" << std::endl;
                return false;
            }
            element = mapnode->FirstChildElement();
            while (grid_i < height) {
                if (!element) {
                    std::cout << "Error! Not enough '" << CNS_TAG_ROW << "' tags inside '" << CNS_TAG_GRID << "' tag."
                              << std::endl;
                    std::cout << "Number of '" << CNS_TAG_ROW
                              << "' tags should be equal (or greater) than the value of '" << CNS_TAG_HEIGHT
                              << "' tag which is " << height << std::endl;
                    return false;
                }
                std::string str = element->GetText();
                std::vector<std::string> elems;
                std::stringstream ss(str);
                std::string item;
                while (std::getline(ss, item, ' '))
                    elems.push_back(item);
                rowiter = grid_j = 0;
                int val;
                if (elems.size() > 0)
                    for (grid_j = 0; grid_j < width; ++grid_j) {
                        if (grid_j == elems.size())
                            break;
                        stream.str("");
                        stream.clear();
                        stream << elems[grid_j];
                        stream >> val;
                        Grid[grid_i][grid_j] = val;
                    }

                if (grid_j != width) {
                    std::cout << "Invalid value on " << CNS_TAG_GRID << " in the " << grid_i + 1 << " " << CNS_TAG_ROW
                              << std::endl;
                    return false;
                }
                ++grid_i;

                element = element->NextSiblingElement();
            }
        }
    }
    //some additional checks
    if (!hasGrid) {
        std::cout << "Error! There is no tag 'grid' in xml-file!\n";
        return false;
    }
    if (!(hasFINX && hasFINY && hasSTX && hasSTY))
        return false;

    for (int i = 0; i < agents_n; ++i) {
        if (Grid[start_i[i]][start_j[i]] != CN_GC_NOOBS) {
            std::cout << "Error! Start cell" << start_j[i] << ' ' << start_i[i] << "is not traversable (cell's value is" << Grid[start_i[i]][start_j[i]] << ")!"
                      << std::endl;
            return false;
        }

        if (Grid[goal_i[i]][goal_j[i]] != CN_GC_NOOBS) {
            std::cout << "Error! Goal cell" << goal_j[i] << ' ' << goal_i[i] << "is not traversable (cell's value is" << Grid[start_i[i]][start_j[i]] << ")!"
                      << std::endl;
            return false;
        }
    }

    return true;
}



int Map::getValue(int i, int j) const
{
    if (i < 0 || i >= height)
        return -1;

    if (j < 0 || j >= width)
        return -1;

    return Grid[i][j];
}

int Map::getMapHeight() const
{
      return height;
}

int Map::getMapWidth() const
{
      return width;
}

double Map::getCellSize() const
{
      return cellSize;
}

int Map::getAgentsNumber() const {
    return agents_n;
}

std::pair<int, int> Map::getStart(int agent_id) const {
    return {start_i[agent_id], start_j[agent_id]};
}

std::pair<int, int> Map::getGoal(int agent_id) const {
    return {goal_i[agent_id], goal_j[agent_id]};
}

bool Map::CellIsIntoCorridor(int i, int j) const {
    if (CellIsObstacle(i, j)) {
        return false;
    }
    std::vector<int> d_i = {1, 0, -1, 0}, d_j = {0, 1, 0, -1};
    int count = 0;
    for (int it = 0; it < 4; ++it) {
        if (CellIsTraversable(i + d_i[it], j + d_j[it])) {
            count++;
        }
    }
    return count == 2;
}
