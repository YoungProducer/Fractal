#pragma once

#include "shader.h"

#include <../glm/glm.hpp>
#include <../glm/gtc/type_ptr.hpp>

namespace frc {	namespace graphics {

		class ShaderManager
		{
		public:
			static int setUniform1f(Shader* shader, std::string uniformName, float	   data);
			static int setUniform2f(Shader* shader, std::string uniformName, glm::vec2 data);
			static int setUniform3f(Shader* shader, std::string uniformName, glm::vec3 data);
			static int setUniform4f(Shader* shader, std::string uniformName, glm::vec4 data);

			static int setUniform2f(Shader* shader, std::string uniformName, float x, float y);
			static int setUniform3f(Shader* shader, std::string uniformName, float x, float y, float z);
			static int setUniform4f(Shader* shader, std::string uniformName, float x, float y, float z, float w);

			static int setUniformMatrix3f(Shader* shader, std::string uniformName, glm::mat3 data);
			static int setUniformMatrix4f(Shader* shader, std::string uniformName, glm::mat4 data);

		private:

			static inline const unsigned int& getUniformLocation(Shader* shader, std::string uniformName) { return glGetUniformLocation(shader->getShaderId(), uniformName.c_str()); };
		};

	}
}
