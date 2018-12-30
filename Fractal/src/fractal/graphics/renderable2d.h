#pragma once

#include "buffers/buffer.h"
#include "buffers/indexBuffer.h"
#include "buffers/vertexArray.h"
#include "shaders/shader.h"
#include "shaders/shaderManager.h"

namespace frc {	namespace graphics {

		/*struct VertexData
		{
			glm::vec3 vertex;
			glm::vec4 color;
		};*/

		class Renderable2d
		{
		private:
			glm::vec3 m_Pos;
			glm::vec2 m_Size;
			glm::vec4 m_Color;

		public:
			Renderable2d(glm::vec3 position, glm::vec2 size, glm::vec4 color)
				: m_Pos(position), m_Size(size), m_Color(color)
			{ };

			virtual ~Renderable2d() { };

		public:
			inline const glm::vec3& getPosition()	const { return m_Pos; };
			inline const glm::vec2& getSize()		const { return m_Size; };
			inline const glm::vec4& getColor()		const { return m_Color; };
		};

} }
