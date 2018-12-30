#pragma once

#include "glew.h"
#include "glfw3.h"

namespace frc { namespace graphics {

		class IndexBuffer
		{
		private:

			unsigned int m_Count;
			GLuint m_BufferId;

		public:

			IndexBuffer() { };
			IndexBuffer(GLuint* data, unsigned int count);
			~IndexBuffer();

			void setIndexBufferData(GLuint* data, unsigned int count);

			void enable() const;
			void disable() const;

			const unsigned int getCount() const { return m_Count; };
		};

} }
