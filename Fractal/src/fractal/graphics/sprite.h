#pragma once

#include "glew.h"

#include "renderable2d.h"

namespace frc { namespace graphics {

	class Sprite : public Renderable2d
	{
	private:


	public:
		Sprite(float x, float y, float width, float height, glm::vec4 color);


	};

} }
