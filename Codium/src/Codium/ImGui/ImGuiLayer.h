#pragma once

#include "Codium/Layer.h"

#include "imgui.h"

struct GLFWcursor;

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
        float m_Time = 0.0f;
        GLFWcursor* m_MouseCursors[ImGuiMouseCursor_COUNT] = {};
    };
}
