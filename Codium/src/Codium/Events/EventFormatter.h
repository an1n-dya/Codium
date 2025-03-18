#pragma once

#include "Event.h"
#include <spdlog/fmt/fmt.h>

template<>
struct fmt::formatter<Codium::Event> : fmt::formatter<std::string> {
    auto format(const Codium::Event& e, format_context& ctx) const {
        return formatter<std::string>::format(e.ToString(), ctx);
    }
};
