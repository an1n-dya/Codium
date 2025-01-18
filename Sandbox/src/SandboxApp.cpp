#include <Codium.h>

class Sandbox : public Codium::Application
{
public:
	Sandbox() { }

	~Sandbox() { }
};

Codium::Application* Codium::CreateApplication()
{
	return new Sandbox();
}
