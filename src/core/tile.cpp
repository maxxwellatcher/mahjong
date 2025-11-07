#include "tile.h"
#include "type_info.h"
#include <iostream>

Tile::Tile(SuitType type, std::string val)
{
    this->m_type = type;
    if (check_val())
        this->m_val = val;
    else
        throw "Invalid tile value, type:" + this->type_str.at(type);
}

bool Tile::check_val()
{
    auto ret = type_str.find(this->m_type);
    if (ret == type_str.end())
        return false;

    switch (ret->first) {
        case SuitType::Dots:
        case SuitType::Bamboo:
        case SuitType::Characters: {
            auto n = std::stoi(this->m_val);
            return 0 < n && n < 10;
        }
        case SuitType::Wind: {
            return this->m_val == "East" || this->m_val == "South" || this->m_val == "West" || this->m_val == "North";
        }
        case SuitType::Dragon: {
            return this->m_val == "Red" || this->m_val == "Green" || this->m_val == "White";
        }
        case SuitType::Flower: {
            return this->m_val == "Plum" || this->m_val == "Orchid" || this->m_val == "Bamboo" || this->m_val == "Chrysanthemum";
        }
        default: {
            return false;
        }
    }
    return true;
}

const std::map<SuitType, std::string> Tile::type_str = {
    { SuitType::Bamboo, "Bamboo" }, { SuitType::Characters, "Characters" },
    { SuitType::Dots, "Dots" }, { SuitType::Dragon, "Dragon" },
    { SuitType::Flower, "Flower" }, { SuitType::None, "None" },
    { SuitType::Wind, "Wind" }
};