#pragma once

#include "glew.h"
#include "glfw3.h"

#include "buffer.h"

#include <vector>

namespace frc {
	namespace graphics {

		class VertexArray
		{
		private:

			GLuint m_ArrayId;
			std::vector<Buffer*> m_Buffers;

		public:

			VertexArray();
			~VertexArray();

			void addBuffer(Buffer* buffer, int index);
			void enable() const;
			void disable() const;

		};

	}
}