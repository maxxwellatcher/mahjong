#include "suit.h"
#include "tile.h"
#include "json/json.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using nlohmann::json;

void Suit::init()
{
    Suit::get_static_suit();
}

Suit::Suit()
{
}

const std::vector<Tile>& Suit::get_static_suit()
{
    static const auto suit = Suit::load_static_suit();
    return suit;
}

std::vector<Tile> Suit::load_static_suit()
{
    std::vector<Tile> tiles;
    try {
        std::ifstream ifs("tiles.json");
        json j;
        ifs >> j;
        tiles.reserve(j.size());
        for (const auto& tile_json : j) {
            tiles.emplace_back(Tile {
                static_cast<std::string>(tile_json.at("suit")),
                static_cast<std::string>(tile_json.at("val")),
                static_cast<int>(tile_json.at("id")),
            });
        }
    } catch (const nlohmann::json::exception& e) {
    }
    return tiles;
}
