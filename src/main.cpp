#include "spdlog/common.h"
#include "suit.h"
#include "tile.h"
#include "json/json.hpp"
#include <fstream>
#include <iostream>
#include <list>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

using nlohmann::json;

void inititalize_logger() {
}

int main()
{
    Suit::init();
    inititalize_logger();
    int a = 1;
    return 0;
}