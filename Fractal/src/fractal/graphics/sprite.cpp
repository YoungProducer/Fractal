#include "sprite.h"

namespace frc { namespace graphics {

	Sprite::Sprite(float x, float y, float width, float height, glm::vec4 color)
		: Renderable2d(glm::vec3(x, y, 0), glm::vec2(width, height), color)
	{

	}

} }