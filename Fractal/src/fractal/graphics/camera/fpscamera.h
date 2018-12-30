#pragma once

#include "camera.h"

namespace frc { namespace graphics { 

	class FPScamera : public Camera
	{
	private:
		float m_OffsetX;
		float m_OffsetY;
		float m_Speed;
		float m_Sensitivity;

		glm::vec2 m_MousePosition;
		glm::vec2 m_PreviousMousePosition;

	public:

		FPScamera(glm::mat4 perspective);

		void update(GLFWwindow* window);
		inline const void setMouseSensitivity(const float sensitivity) { m_Sensitivity = sensitivity; };
		inline const void setMouseSensitivity(const float& sensitivity) { m_Sensitivity = sensitivity; };
	};

} }