#include "shader.h"

namespace frc {	namespace graphics {

	Shader::Shader(std::string vertexPath, std::string fragmentPath)
		: m_VertexSrc(vertexPath), m_FragmentSrc(fragmentPath)
	{
		m_VertexCode   = File::readFileSh(vertexPath);
		m_FragmentCode = File::readFileSh(fragmentPath);

		m_ShaderId = ShaderFactory::createShader(m_VertexCode, m_FragmentCode);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_ShaderId);
	}

	void Shader::enable() const 
	{
		glUseProgram(m_ShaderId);
	}

	void Shader::disable() const
	{
		glUseProgram(0);
	}

	void Shader::update()
	{
		m_VertexCode   = File::readFileSh(m_VertexSrc);
		m_FragmentCode = File::readFileSh(m_FragmentSrc);

		m_ShaderId = ShaderFactory::createShader(m_VertexCode, m_FragmentCode);
	}

} }