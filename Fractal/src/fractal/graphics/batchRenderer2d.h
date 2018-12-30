#pragma once

#include "../glm/glm.hpp"
#include "../glm/gtc/type_precision.hpp"

#include "glew.h"
#include "glfw3.h"

#include "renderable2d.h"
#include "renderer2d.h"
#include "sprite.h"
#include "sprite3d.h"
#include "buffers\indexBuffer.h"

#define RENDERER_MAX_SPRITES_2D		80000
#define RENDERER_VERTEX_SIZE_2D		sizeof(VertexData)
#define RENDERER_SPRITE_SIZE_2D		RENDERER_VERTEX_SIZE_2D * 3
#define RENDERER_BUFFER_SIZE_2D		RENDERER_SPRITE_SIZE_2D * RENDERER_MAX_SPRITES_2D
#define RENDERER_INDICES_SIZE_2D	RENDERER_MAX_SPRITES_2D * 6

#define SHADER_VERTEX_INDEX 0
#define SHADER_COLOR_INDEX  1

namespace frc { namespace graphics {

		struct VertexData
		{
			glm::vec3 vertex;
			glm::vec4 color;
		};

		class BatchRenderer2D : public Renderer2d
		{
		private:
			GLuint m_VAO;
			GLuint m_VBO;
			GLsizei m_IndexCount;
			IndexBuffer* m_IBO;
			VertexData* m_Buffer;

			bool m_DefaultRenderer;

		private:

		public:
			BatchRenderer2D();
			BatchRenderer2D(GLuint* indices, GLuint iCount);
			~BatchRenderer2D();

			void begin();
			void end();
			void submit(const Sprite3d* sprite);
			void submit(const Renderable2d* renderable) override;
			void submit(float* positions, GLuint pCount, GLuint componentCount, glm::vec4 color);
			void flush() override;
		private:
			void init();
			void init(GLuint* indices, GLuint iCount);
		};


} }


