#pragma once

#include "../glm/glm.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/gtc/matrix_transform.hpp"

#include <deque>

#include "renderer2D.h"
#include "renderable2d.h"
#include "staticSprite.h"
#include "shaders/shaderManager.h"


namespace frc {	namespace graphics {

		class SimpleRenderer2d : public Renderer2d
		{
		private:
			std::deque<const StaticSprite*> m_RendererQueue;

		public:
			void submit(const Renderable2d* rendereable) override;
			void flush() override;
		};

} }