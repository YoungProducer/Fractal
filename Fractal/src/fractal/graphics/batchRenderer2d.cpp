#include "batchRenderer2d.h"

namespace frc {
	namespace graphics {

		BatchRenderer2D::BatchRenderer2D()
			: m_DefaultRenderer(true)
		{
			init();
		}

		BatchRenderer2D::BatchRenderer2D(GLuint* indices, GLuint iCount)
			: m_IndexCount(iCount), m_DefaultRenderer(false)
		{
			init(indices, iCount);
		}

		BatchRenderer2D::~BatchRenderer2D()
		{
			delete m_IBO;
			glDeleteBuffers(1, &m_VBO);
		}

		void BatchRenderer2D::init()
		{
			glGenVertexArrays(1, &m_VAO);
			glGenBuffers(1, &m_VBO);

			glBindVertexArray(m_VAO);
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
			glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE_2D, NULL, GL_DYNAMIC_DRAW);
			glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
			glEnableVertexAttribArray(SHADER_COLOR_INDEX);
			glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE_2D, (const GLvoid*)0);
			glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE_2D, (const GLvoid*)sizeof(VertexData::vertex));
			glBindBuffer(GL_ARRAY_BUFFER, 0);

			GLuint* indices = new GLuint[RENDERER_INDICES_SIZE_2D];
			int offset = 0;

			for (int i = 0; i < RENDERER_INDICES_SIZE_2D; i += 6)
			{
				indices[i] = offset + 0;
				indices[i + 1] = offset + 1;

				indices[i + 2] = offset + 2;
				indices[i + 3] = offset + 2;
				indices[i + 4] = offset + 3;
				indices[i + 5] = offset + 0;

				offset += 4;
			}

			m_IBO = new IndexBuffer(indices, RENDERER_INDICES_SIZE_2D);

			glBindVertexArray(0);
		}

		void BatchRenderer2D::init(GLuint* indices, GLuint iCount)
		{
			glGenVertexArrays(1, &m_VAO);
			glGenBuffers(1, &m_VBO);

			glBindVertexArray(m_VAO);
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
			glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE_2D, NULL, GL_DYNAMIC_DRAW);
			glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
			glEnableVertexAttribArray(SHADER_COLOR_INDEX);
			glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE_2D, (const GLvoid*)0);
			glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE_2D, (const GLvoid*)sizeof(VertexData::vertex));
			glBindBuffer(GL_ARRAY_BUFFER, 0);

			m_IBO = new IndexBuffer(indices, iCount);

			glBindVertexArray(0);
		}

		void BatchRenderer2D::begin()
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
			m_Buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		}

		void BatchRenderer2D::end()
		{
			glUnmapBuffer(GL_ARRAY_BUFFER);
		}

		void BatchRenderer2D::submit(const Renderable2d* renderable)
		{
			const glm::vec3 position = renderable->getPosition();
			const glm::vec2 size = renderable->getSize();
			const glm::vec4 color = renderable->getColor();

			m_Buffer->vertex = position;
			m_Buffer->color = color;
			m_Buffer++;

			m_Buffer->vertex = glm::vec3(position.x, position.y + size.y, position.z);
			m_Buffer->color = color;
			m_Buffer++;

			m_Buffer->vertex = glm::vec3(position.x + size.x, position.y + size.y, position.z);
			m_Buffer->color = color;
			m_Buffer++;

			m_Buffer->vertex = glm::vec3(position.x + size.x, position.y, position.z);
			m_Buffer->color = color;
			m_Buffer++;

			m_IndexCount += 6;
		}

		void BatchRenderer2D::submit(const Sprite3d* sprite)
		{
			const float* positions = sprite->getPositions();
			const glm::vec4 color = sprite->getColor();

			for (int i = 0; i < sprite->getCount(); i += sprite->getComponentCount())
			{
				m_Buffer->vertex = glm::vec3(positions[i], positions[i + 1], positions[i + 2]);
				m_Buffer->color = color;
				m_Buffer++;
			}

			m_IndexCount += 6;
		}

		void BatchRenderer2D::submit(float* positions, GLuint pCount, GLuint componentCount, glm::vec4 color)
		{
			for (int i = 0; i < pCount; i += componentCount)
			{
				m_Buffer->vertex = glm::vec3(positions[i], positions[i + 1], positions[i + 2]);
				m_Buffer->color = color;
				m_Buffer++;
			}

			//m_IndexCount += 9;
		}

		void BatchRenderer2D::flush()
		{
			glBindVertexArray(m_VAO);
			m_IBO->enable();

			glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, NULL);

			m_IBO->disable();
			glBindVertexArray(0);

			if (m_DefaultRenderer)
				m_IndexCount = 0;
		}

	}
}