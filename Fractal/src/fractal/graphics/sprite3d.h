#pragma once

#include "../glm/glm.hpp"
#include "../glm/gtc/type_ptr.hpp"

#include "glew.h"

namespace frc { namespace graphics {

	class Sprite3d
	{
	protected:
		float*	m_Positions;
		GLuint	m_Count;
		GLuint	m_ComponentCount;

		glm::vec4 m_Color;

	public:
		Sprite3d() { };
		Sprite3d(float* positions, GLuint count, GLuint componentCount, glm::vec4 color);

		inline const float*		getPositions() const { return m_Positions; };
		inline const GLuint&	getCount() const { return m_Count; };
		inline const GLuint&	getComponentCount() const { return m_ComponentCount; };
		inline const glm::vec4& getColor() const { return m_Color; };
	};

} }
