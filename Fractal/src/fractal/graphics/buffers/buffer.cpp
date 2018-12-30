#include "buffer.h"

namespace frc {
	namespace graphics {

		Buffer::Buffer(float* data, unsigned int count, unsigned int componentCount)
			: m_ComponentCount(componentCount)
		{
			glGenBuffers(1, &m_BufferId);
			glBindBuffer(GL_ARRAY_BUFFER, m_BufferId);
			glBufferData(GL_ARRAY_BUFFER, sizeof(float) * count, data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		Buffer::~Buffer()
		{
			glDeleteBuffers(1, &m_BufferId);
		}

		void Buffer::enable() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_BufferId);
		}

		void Buffer::disable() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

	}
}