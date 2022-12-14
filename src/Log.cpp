#include "Log.h"

namespace Zoro {
    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;

    void Log::Init()
    {
        //spdlog::set_pattern("%^[%T] %n: %v\n%@%$");
        spdlog::set_pattern("%^[%n]%$ >> %v");
        s_CoreLogger = spdlog::stdout_color_mt("ZORO");
        s_CoreLogger->set_level(spdlog::level::trace);

    }
}
