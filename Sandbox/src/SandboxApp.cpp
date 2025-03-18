#include <Codium.h>

#include "Codium/Events/EventFormatter.h"

class ExampleLayer : public Codium::Layer {
public:
	ExampleLayer()
		: Layer("Example") { }

	void OnUpdate() override {
		CE_INFO("ExampleLayer::Update");
	}

	void OnEvent(Codium::Event& event) override {
		CE_TRACE("{0}", event);
	}
};

class Sandbox : public Codium::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() { }
};

Codium::Application* Codium::CreateApplication() {
	return new Sandbox();
}
