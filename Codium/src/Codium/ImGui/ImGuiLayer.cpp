#include "cepch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include "GLFW/glfw3.h"

#include "Codium/Application.h"

namespace Codium {
	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer") { }

	ImGuiLayer::~ImGuiLayer() { }

	void ImGuiLayer::OnAttach() {
		// TODO : OnAttach()
	}

	void ImGuiLayer::OnDetach() { }

	void ImGuiLayer::OnUpdate() {
		// TODO : OnUpdate()
	}

	void ImGuiLayer::OnEvent(Event& event) { }
}
