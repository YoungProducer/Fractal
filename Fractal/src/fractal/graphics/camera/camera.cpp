#include "camera.h"

namespace frc { namespace graphics {

	Camera::Camera(glm::mat4& perspective)
		:	m_Perspective(perspective),
			m_ModelView	 (glm::mat4(1.0f)),
			m_CameraPos	 (glm::vec3(0.0f)),
			m_CameraDir	 (glm::vec3(0.0f)),
			m_CameraUp	 (glm::vec3(0.0f)),
			m_Rotation	 (glm::vec3(0.0f))
	{

	}

} }