#include "indexBuffer.h"

namespace frc {
	namespace graphics {

		IndexBuffer::IndexBuffer(GLuint* data, unsigned int count)
			: m_Count(count)
		{
			glGenBuffers(1, &m_BufferId);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferId);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * count, data, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		IndexBuffer::~IndexBuffer()
		{
			glDeleteBuffers(1, &m_BufferId);
		}

		void IndexBuffer::setIndexBufferData(GLuint* data, unsigned int count)
		{
			m_Count = count;

			glGenBuffers(1, &m_BufferId);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferId);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * count, data, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		void IndexBuffer::enable() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferId);
		}

		void IndexBuffer::disable() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

	}
}