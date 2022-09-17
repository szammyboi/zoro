#pragma once

// Credit to TheCherno/Hazel

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <memory>

#define ZORO_OFFSET "                 "

namespace Zoro {
    class Log
    {
    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger> GetCoreLogger() {return s_CoreLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
    };
}

#ifdef DEBUG
    //Log::SetLevel(spdlog::level::debug);
    //spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    //spdlog::debug("This message should be displayed..");  
#endif

#define ZORO_TRACE(...) Zoro::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ZORO_INFO(...) Zoro::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ZORO_WARN(...) Zoro::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ZORO_ERROR(...) Zoro::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ZORO_FATAL(...) Zoro::Log::GetCoreLogger()->critical(__VA_ARGS__)

#ifdef DEBUG
    #define ZORO_DEBUG(...) Zoro::Log::GetCoreLogger()->debug(__VA_ARGS__)
#else
    #define ZORO_DEBUG(...)
#endif
