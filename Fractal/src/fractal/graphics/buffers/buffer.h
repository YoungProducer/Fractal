#pragma once

#include "glew.h"
#include "glfw3.h"

namespace frc {
	namespace graphics
	{
		class Buffer
		{
		private:

			int m_ComponentCount;
			GLuint m_BufferId;
		public:
			Buffer() { };
			Buffer(float* data, unsigned int count, unsigned int componentCount);
			~Buffer();

			void enable() const;
			void disable() const;

			const int& getComponentCount() const { return m_ComponentCount; };
		};

	}
}
