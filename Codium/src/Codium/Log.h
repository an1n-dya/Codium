#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Codium {
	class CODIUM_API Log {
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define CE_CORE_TRACE(...)    ::Codium::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CE_CORE_INFO(...)     ::Codium::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CE_CORE_WARN(...)     ::Codium::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CE_CORE_ERROR(...)    ::Codium::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CE_CORE_FATAL(...)    ::Codium::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CE_TRACE(...)         ::Codium::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CE_INFO(...)          ::Codium::Log::GetClientLogger()->info(__VA_ARGS__)
#define CE_WARN(...)          ::Codium::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CE_ERROR(...)         ::Codium::Log::GetClientLogger()->error(__VA_ARGS__)
#define CE_FATAL(...)         ::Codium::Log::GetClientLogger()->fatal(__VA_ARGS__)
