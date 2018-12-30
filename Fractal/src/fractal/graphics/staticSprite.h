#pragma once

#include "renderable2d.h"

namespace frc {	namespace graphics {

		class StaticSprite : public Renderable2d
		{
		private:
			Shader&		 m_Shader;
			IndexBuffer* m_IndexBuffer;
			VertexArray* m_VertexArray;

		public:

			StaticSprite(float x, float y, float width, float height, glm::vec4 color, Shader& shader);
			~StaticSprite();

			inline const VertexArray* getVertexArray() const { return m_VertexArray; };
			inline const IndexBuffer* getIndexBuffer() const { return m_IndexBuffer; };
			inline Shader& getShader() const { return m_Shader; };
		};

} }
