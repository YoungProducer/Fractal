#pragma once

#include "renderable2d.h"

namespace frc {	namespace graphics {

	class Renderer2d
	{
	public:
		virtual void submit(const Renderable2d* rendereable) = 0;
		virtual void flush() = 0;
	};

} }
