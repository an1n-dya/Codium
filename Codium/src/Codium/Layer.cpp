#include "cepch.h"
#include "Layer.h"

namespace Codium {
	Layer::Layer(const std::string& debugName)
		: m_DebugName(debugName) { }

	Layer::~Layer() { }
}
