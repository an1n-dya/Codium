#pragma once

#include "Codium/Layer.h"

#include "Codium/Events/ApplicationEvent.h"
#include "Codium/Events/KeyEvent.h"
#include "Codium/Events/MouseEvent.h"

#include "imgui.h"

namespace Codium {
	class CODIUM_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);
		
		ImGuiKey GlfwKeyToImGuiKey(int key);
	private:
		float m_Time = 0.0f;
	};
}
