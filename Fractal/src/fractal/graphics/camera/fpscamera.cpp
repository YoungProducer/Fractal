#include "fpscamera.h"

namespace frc { namespace graphics {

	FPScamera::FPScamera(glm::mat4 perspective)
		: Camera(perspective), m_Speed(0.1f), m_Sensitivity(0.05f)
	{
		m_PreviousMousePosition = app::Input::getMousePosition();

		setCameraPos(0.0, 0.0, 2.0);
		setCameraDir(0.0, 0.0, 0.0);
		setCameraUp(0.0, 1.0, 0.0);
		setCameraRot(0.0, 0.0, 0.0);
	}

	void FPScamera::update(GLFWwindow* window)
	{
		glm::vec2 windowSize = app::Input::getWindowSize(window);
		glm::vec2 windowCenter = glm::vec2(windowSize / 2.0f);
		m_MousePosition = app::Input::getMousePosition();
		m_PreviousMousePosition = app::Input::getPreviousMousePosition();
		m_Perspective = glm::perspective(45.0f, windowSize.x / windowSize.y, 0.1f, 1000.0f);

		if (app::Input::isKeyPressed(FRC_KEY_W))
		{
			m_CameraPos += m_Speed * m_CameraDir;
		}

		if (app::Input::isKeyPressed(FRC_KEY_S))
		{
			m_CameraPos -= m_Speed * m_CameraDir;
		}

		if (app::Input::isKeyPressed(FRC_KEY_A))
		{
			m_CameraPos -= glm::normalize(glm::cross(m_CameraDir, m_CameraUp)) * m_Speed;
		}

		if (app::Input::isKeyPressed(FRC_KEY_D))
		{
			m_CameraPos += glm::normalize(glm::cross(m_CameraDir, m_CameraUp)) * m_Speed;
		}

		if (app::Input::isKeyPressed(FRC_KEY_SPACE))
		{
			m_CameraPos.y += m_Speed * 0.5f;
		}

		if (app::Input::isKeyPressed(FRC_KEY_LSHIFT))
		{
			m_CameraPos.y -= m_Speed * 0.5f;
		}

		if (app::Input::isMouseButtonPressed(FRC_MOUSE_RIGHT))
		{
			m_OffsetX = (m_MousePosition.x - m_PreviousMousePosition.x) * m_Sensitivity;
			m_OffsetY = (m_MousePosition.y - m_PreviousMousePosition.y) * m_Sensitivity;
			app::Input::getInputManager()->setMousePosition(window, windowCenter);

			m_Rotation.x += m_OffsetX;
			m_Rotation.y += m_OffsetY;
			m_Rotation.z += m_OffsetX;

			m_CameraDir.x = cos(glm::radians(m_Rotation.x + m_OffsetX)) * cos(glm::radians(m_Rotation.y + m_OffsetY));
			m_CameraDir.y = -tan(glm::radians(m_Rotation.y + m_OffsetY));
			m_CameraDir.z = sin(glm::radians(m_Rotation.z + m_OffsetX)) * cos(glm::radians(m_Rotation.y + m_OffsetY));
		}

		m_ModelView = glm::lookAt(m_CameraPos, m_CameraPos + m_CameraDir, m_CameraUp);
		app::Input::getInputManager()->update();
	}

} }