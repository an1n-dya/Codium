#pragma once

#ifdef CE_PLATFORM_WINDOWS

extern Codium::Application* Codium::CreateApplication();

int main(int argc, char** argv) {
	auto app = Codium::CreateApplication();
	app->Run();
	delete app;
}

#endif
