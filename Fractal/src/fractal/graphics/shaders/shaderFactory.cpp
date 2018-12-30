#include "shaderFactory.h"

namespace frc { namespace graphics {

	GLuint ShaderFactory::compileShader(std::string code, GLuint type)
	{
		unsigned int id = glCreateShader(type);
		const char* src;

		src = code.c_str();

		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);

		if (result == GL_FALSE)
		{
			int lenght;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);
			char* message = (char*)alloca(lenght * sizeof(char));
			glGetShaderInfoLog(id, lenght, &lenght, message);
			std::cout << "Failed to compile " <<
				(type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
			std::cout << message << std::endl;
			glDeleteShader(id);
			return 0;
		}

		return id;
	}

	GLuint ShaderFactory::createShader(std::string vertexCode, std::string fragmentCode)
	{
		GLuint program = glCreateProgram();
		GLuint vertexShader   = compileShader(vertexCode, GL_VERTEX_SHADER);
		GLuint fragmentShader = compileShader(fragmentCode, GL_FRAGMENT_SHADER);

		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return program;
	}

} }