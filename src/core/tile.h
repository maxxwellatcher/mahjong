#pragma once
#include "type_info.h"
#include <map>
#include <string>

class Tile {
public:
    explicit Tile(SuitType type, std::string val, int id);
    Tile(std::string type, std::string val, int id);

    const static std::map<SuitType, std::string> type_str;

private:
    bool check_val(const std::string& val);
    bool check_type(const std::string& str);

    SuitType m_type;
    std::string m_val;
    int m_id;
};