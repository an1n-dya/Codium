#pragma once

#ifdef CE_PLATFORM_WINDOWS

extern Codium::Application* Codium::CreateApplication();

int main(int argc, char** argv) {
	Codium::Log::Init();
	CE_CORE_WARN("Initialized Log!");
	int a = 5;
	CE_INFO("Hello! Var={0}", a);

	auto app = Codium::CreateApplication();
	app->Run();
	delete app;
}

#endif
