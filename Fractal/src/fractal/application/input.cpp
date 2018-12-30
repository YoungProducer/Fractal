#include "input.h"

namespace frc { namespace app {

	InputManager* Input::s_InputManager = nullptr;

	void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		InputManager* inputManager = (InputManager*)glfwGetWindowUserPointer(window);
		inputManager->m_KeyState[key] = action != GLFW_RELEASE;
	}

	void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		InputManager* inputManager = (InputManager*)glfwGetWindowUserPointer(window);
		inputManager->m_MousePressed[button] = action != GLFW_RELEASE;
		if (action == GLFW_RELEASE) inputManager->m_MouseReleased[button] = true;
	}

	void CursorPositionCallback(GLFWwindow *window, double xpos, double ypos)
	{
		InputManager* inputManager = (InputManager*)glfwGetWindowUserPointer(window);
		inputManager->m_MousePosition = glm::vec2(xpos, ypos);
	}

	InputManager::InputManager()
	{
		clearKeys();
		clearMouseButtons();

		Input::s_InputManager = this;

		m_MouseGrabbed = true;

		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			m_MousePreviousStatePress[i] = false;
			m_MousePreviousStateRelease[i] = false;
		}
	}

	void InputManager::update()
	{
		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			m_MouseClicked[i] = m_MousePressed[i] && !m_MouseReleased[i];
			m_MouseReleased[i] = false;
		}
		m_MousePreviousStatePress[MAX_BUTTONS] = m_MousePressed[MAX_BUTTONS];
		m_MousePreviousStateRelease[MAX_BUTTONS] = m_MouseReleased[MAX_BUTTONS];
		m_PreviousPosition = m_MousePosition;
	}

	void InputManager::setCallback(GLFWwindow* window)
	{
		glfwSetWindowUserPointer(window, this);
		glfwSetKeyCallback(window, KeyCallback);
		glfwSetMouseButtonCallback(window, MouseButtonCallback);
		glfwSetCursorPosCallback(window, CursorPositionCallback);
	}

	void InputManager::clearKeys()
	{
		for (size_t i = 0; i < MAX_KEYS; i++)
		{
			m_KeyState[i] = false;
			m_LastKeyState[i] = false;
		}
	}

	void InputManager::clearMouseButtons()
	{
		for (size_t i = 0; i < MAX_BUTTONS; i++)
		{
			m_MouseClicked[i] = false;
			m_MousePressed[i] = false;
			m_MouseReleased[i] = false;
		}
	}

	bool InputManager::isKeyPressed(int keycode) const
	{
		if (keycode >= MAX_KEYS)
			return false;

		return m_KeyState[keycode];
	}

	bool InputManager::isMouseButtonPressed(int button) const
	{
		if (button >= MAX_BUTTONS)
			return false;

		return m_MousePressed[button];
	}

	bool InputManager::isMouseButtonReleased(int button) const
	{
		if (button >= MAX_BUTTONS)
			return false;

		return m_MouseReleased[button];
	}

	glm::vec2 const InputManager::getWindowSize(GLFWwindow* window) const
	{
		int w, h;
		glfwGetWindowSize(window, &w, &h);

		return glm::vec2(w, h);
	}

	glm::vec2 const InputManager::getWindowPosition(GLFWwindow * window) const
	{
		int x, y;
		glfwGetWindowPos(window, &x, &y);

		return glm::vec2(x, y);
	}

	bool InputManager::isMouseButtonClicked(int button) const
	{
		if (button >= MAX_BUTTONS)
			return false;

		return m_MouseClicked[button];
	}

} }