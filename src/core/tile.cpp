#include "tile.h"
#include "type_info.h"
#include <iostream>

Tile::Tile(SuitType type, std::string val)
{
    this->m_type = type;
    if (check_val(val))
        this->m_val = val;
    else
        throw "Invalid tile value, type:" + this->type_str.at(type);
}

bool Tile::check_val(const std::string& val)
{
    auto ret = type_str.find(this->m_type);
    if (ret == type_str.end())
        return false;

    switch (ret->first) {
        case SuitType::Dot:
        case SuitType::Sou:
        case SuitType::Character: {
            auto n = std::stoi(val);
            return 0 < n && n < 10;
        }
        case SuitType::Wind: {
            return val == "east" || val == "south" || val == "west" || val == "north";
        }
        case SuitType::Dragon: {
            return val == "red" || val == "green" || val == "white";
        }
        case SuitType::Flower: {
            return val == "plum" || val == "orchid" || val == "bamboo" || val == "chrysanthemum"
                || val == "spring" || val == "summer" || val == "autumn" || val == "winter";
        }
        default: {
            return false;
        }
    }
    return true;
}

const std::map<SuitType, std::string> Tile::type_str = {
    { SuitType::Sou, "Sou" },
    { SuitType::Character, "Character" },
    { SuitType::Dot, "Dot" },
    { SuitType::Dragon, "Dragon" },
    { SuitType::Flower, "Flower" },
    { SuitType::None, "None" },
    { SuitType::Wind, "Wind" }
};