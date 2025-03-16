#include "Application.h"

#include "Codium/Events/ApplicationEvent.h"
#include "Codium/Log.h"

namespace Codium {
	Application::Application() { }

	Application::~Application() { }

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			CE_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput)) {
			CE_TRACE(e);
		}

		while (true);
	}
}
