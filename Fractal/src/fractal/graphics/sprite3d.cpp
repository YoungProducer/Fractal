#include "sprite3d.h"

namespace frc { namespace graphics {

	Sprite3d::Sprite3d(float* positions, GLuint count, GLuint componentCount, glm::vec4 color)
		: m_Count(count), m_ComponentCount(componentCount), m_Color(color)
	{
		m_Positions = new float[count];
		m_Positions = positions;
	}

} }