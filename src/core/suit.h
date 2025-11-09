#pragma once
#include "tile.h"
#include <list>
#include <vector>

class Suit {
public:
    Suit();

    Suit(const Suit&) = delete;
    Suit& operator=(const Suit&) = delete;

    static void init();

    static const std::vector<Tile>& get_static_suit();

private:
    static std::vector<Tile> load_static_suit();

private:
    std::vector<int> tiles;
};