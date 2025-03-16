#pragma once

#if defined(CE_PLATFORM_WINDOWS) || defined(CE_PLATFORM_LINUX)

extern Codium::Application* Codium::CreateApplication();

int main(int argc, char** argv) {
	Codium::Log::Init();
	CE_CORE_WARN("Logging Initialized");

	auto app = Codium::CreateApplication();
	app->Run();
	delete app;
}

#endif
