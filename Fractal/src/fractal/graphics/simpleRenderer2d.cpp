#include "simpleRenderer2d.h"

namespace frc {	namespace graphics {

		void SimpleRenderer2d::submit(const Renderable2d* renderable2d)
		{
			m_RendererQueue.push_back((StaticSprite*)renderable2d);
		}

		void SimpleRenderer2d::flush()
		{
			while (!m_RendererQueue.empty())
			{
				const StaticSprite* sprite = m_RendererQueue.front();
				sprite->getVertexArray()->enable();
				sprite->getIndexBuffer()->enable();

				ShaderManager::setUniformMatrix4f(&sprite->getShader(), "ml_matrix", glm::translate(glm::mat4(1.0f), sprite->getPosition()));
				glDrawElements(GL_TRIANGLES, sprite->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);

				sprite->getIndexBuffer()->disable();
				sprite->getVertexArray()->disable();

				m_RendererQueue.pop_front();

			}
		}

	}
}