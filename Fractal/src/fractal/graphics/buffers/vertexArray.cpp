#include "vertexArray.h"

namespace frc { namespace graphics {

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_ArrayId);
	}

	VertexArray::~VertexArray()
	{
		for (unsigned int i = 0; i < m_Buffers.size(); i++)
			m_Buffers.pop_back();

		glDeleteVertexArrays(1, &m_ArrayId);
	}

	void VertexArray::addBuffer(Buffer* buffer, int index)
	{
		m_Buffers.push_back(buffer);

		enable();
		buffer->enable();

		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, (const void*)0);

		buffer->disable();
		disable();
	}

	void VertexArray::enable() const 
	{
		glBindVertexArray(m_ArrayId);
	}

	void VertexArray::disable() const
	{
		glBindVertexArray(0);
	}

} }