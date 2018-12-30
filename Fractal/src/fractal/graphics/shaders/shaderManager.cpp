#include "shaderManager.h"

namespace frc { namespace graphics { 

	int ShaderManager::setUniform1f(Shader* shader, std::string uniformName, float	   data)
	{	
		unsigned int location = ShaderManager::getUniformLocation(shader, uniformName);
		if (location == -1)
			return 0;
		glUniform1f(location, data);
		return 1;
	}

	int ShaderManager::setUniform2f(Shader* shader, std::string uniformName, glm::vec2 data)
	{
		unsigned int location = ShaderManager::getUniformLocation(shader, uniformName);
		if (location == -1)
			return 0;
		glUniform2f(location, data.x, data.y);
		return 1;
	}

	int ShaderManager::setUniform3f(Shader* shader, std::string uniformName, glm::vec3 data)
	{
		unsigned int location = ShaderManager::getUniformLocation(shader, uniformName);
		if (location == -1)
			return 0;
		glUniform3f(location, data.x, data.y, data.z);
		return 1;
	}
	int ShaderManager::setUniform4f(Shader* shader, std::string uniformName, glm::vec4 data)
	{
		unsigned int location = ShaderManager::getUniformLocation(shader, uniformName);
		if (location == -1)
			return 0;
		glUniform4f(location, data.x, data.y, data.z, data.w);
		return 1;
	}
	int ShaderManager::setUniform2f(Shader* shader, std::string uniformName, float x, float y)
	{
		unsigned int location = ShaderManager::getUniformLocation(shader, uniformName);
		if (location == -1)
			return 0;
		glUniform2f(location, x, y);
		return 1;
	}

	int ShaderManager::setUniform3f(Shader* shader, std::string uniformName, float x, float y, float z)
	{
		unsigned int location = ShaderManager::getUniformLocation(shader, uniformName);
		if (location == -1)
			return 0;
		glUniform3f(location, x, y, z);
		return 1;
	}

	int ShaderManager::setUniform4f(Shader* shader, std::string uniformName, float x, float y, float z, float w)
	{
		unsigned int location = ShaderManager::getUniformLocation(shader, uniformName);
		if (location == -1)
			return 0;
		glUniform4f(location, x, y, z, w);
		return 1;
	}

	int ShaderManager::setUniformMatrix3f(Shader* shader, std::string uniformName, glm::mat3 data)
	{
		unsigned int location = ShaderManager::getUniformLocation(shader, uniformName);
		if (location == -1)
			return 0;
		glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(data));
		return 1;
	}

	int ShaderManager::setUniformMatrix4f(Shader* shader, std::string uniformName, glm::mat4 data)
	{
		unsigned int location = getUniformLocation(shader, uniformName);
		if (location == -1)
		{
			return 0;
		}
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(data));
	}


} }