#pragma once

#include "glew.h"

#include "shaderFactory.h"
#include "../../utils/file.h"

#include <string>

namespace frc {	namespace graphics {

	class Shader
	{
	private:

		std::string m_VertexSrc;
		std::string m_FragmentSrc;
		std::string m_VertexCode;
		std::string m_FragmentCode;

		GLuint m_ShaderId;

	public:

		Shader(std::string vertexPath, std::string fragmentPath);
		~Shader();

		void enable() const;
		void disable() const;

		inline const void setVertexSrc(std::string path) { m_VertexSrc = path; update(); };
		inline const std::string& getVertexSrc() const { return m_VertexSrc; };

		inline const void setFragmentSrc(std::string path) { m_FragmentSrc = path; update(); };
		inline const std::string& getFragmentSrc() const { return m_FragmentSrc; };

		inline const void setShaderId(GLuint shaderId) { m_ShaderId = shaderId; };
		inline const GLuint& getShaderId() const { return m_ShaderId; };

	private:
		void update();
	};

} }