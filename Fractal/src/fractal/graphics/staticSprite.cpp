#include "staticSprite.h"

namespace frc { namespace graphics {

		StaticSprite::StaticSprite(float x, float y, float width, float height, glm::vec4 color, Shader& shader)
			: Renderable2d(glm::vec3(x, y, 0), glm::vec2(width, height), color), m_Shader(shader)
		{
			m_VertexArray = new VertexArray();
			m_IndexBuffer = new IndexBuffer();

			float vertices[] =
			{
				0, 0, 0.5f,
				0, width, 0.5f,
				height, height, 0.5f,
				width, 0, 0.5f
			};

			GLuint indicies[] =
			{
				0, 1, 2,
				2, 3, 0
			};

			float colors[] =
			{
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w
			};

			m_VertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
			m_VertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

			m_IndexBuffer->setIndexBufferData(indicies, 6);

		}

		StaticSprite::~StaticSprite()
		{
			delete m_VertexArray;
			delete m_IndexBuffer;
		}

	}
}