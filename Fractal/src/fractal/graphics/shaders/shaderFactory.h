#pragma once

#include "glew.h"

#include <iostream>
#include <string>

namespace frc { namespace graphics {

	class ShaderFactory
	{
	private:


	public:
		static GLuint compileShader(std::string code, GLuint type);
		static GLuint createShader(std::string vertexCode, std::string fragmentCode);
	};

} }