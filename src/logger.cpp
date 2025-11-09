#include "logger.h"
#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/basic_file_sink.h"

Logger* Logger::Instance() {
    static Logger instance;
    return &instance;
}

Logger::Logger() {
    spdlog::init_thread_pool(8192, 1);
    auto file_logger = spdlog::basic_logger_mt<spdlog::async_factory>("file_looger", "log/log.txt");
    file_logger->debug("hello, world!");
}