#pragma once
#include "type_info.h"
#include <map>
#include <string>

class Tile {
public:
    Tile(SuitType type, std::string val);
    Tile(std::string type, std::string val);

    const static std::map<SuitType, std::string> type_str;

private:
    bool check_val();

    SuitType m_type;
    std::string m_val;
    int m_id;
};