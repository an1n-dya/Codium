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
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

        ImGui::StyleColorsDark();

        Application& app = Application::Get();
        GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
        io.BackendPlatformName = "imgui_impl_glfw";
        
        m_Time = 0.0f;

        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::OnDetach() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::OnUpdate() {
        ImGui_ImplOpenGL3_NewFrame();
        
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::Get();
        
        io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());
        
        float time = (float)glfwGetTime();
        io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
        m_Time = time;
        
        ImGui::NewFrame();
        
        static bool show_demo_window = true;
        ImGui::ShowDemoWindow(&show_demo_window);
        
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::OnEvent(Event& event) { }
}
