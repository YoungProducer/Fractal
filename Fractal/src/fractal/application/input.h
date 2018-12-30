#pragma once

#include "../glm/glm.hpp"
#include "../glm/gtc/type_ptr.hpp"

#include "glew.h"
#include "glfw3.h"

namespace frc { namespace app {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

	class InputManager
	{
	private:
		bool m_KeyState[MAX_KEYS];
		bool m_LastKeyState[MAX_KEYS];

		bool m_MouseClicked[MAX_BUTTONS];
		bool m_MousePressed[MAX_BUTTONS];
		bool m_MouseReleased[MAX_BUTTONS];
		bool m_MousePreviousStatePress[MAX_BUTTONS];
		bool m_MousePreviousStateRelease[MAX_BUTTONS];
		bool m_MouseGrabbed;

		glm::vec2 m_MousePosition;
		glm::vec2 m_PreviousPosition;
	public:
		InputManager();

		void update();

		void setCallback(GLFWwindow* window);

		void clearKeys();
		void clearMouseButtons();

		bool isKeyPressed(int keycode) const;

		bool isMouseButtonClicked(int button) const;
		bool isMouseButtonPressed(int button) const;
		bool isMouseButtonReleased(int button) const;

		inline void setMousePosition(GLFWwindow* window, const glm::vec2& position) { m_MousePosition = position; glfwSetCursorPos(window, (double)position.x, (double)position.y); };
		inline const glm::vec2& getMousePosition() const { return m_MousePosition; };
		inline const glm::vec2& getPreviousMousePosition() const { return m_PreviousPosition; };

		inline void setMouseGrabbed(const bool& isGrabbed) { m_MouseGrabbed = isGrabbed; };
		inline const bool& isMouseGrabbed() const { return m_MouseGrabbed; };

		glm::vec2 const getWindowSize(GLFWwindow* window) const;
		glm::vec2 const getWindowPosition(GLFWwindow* window) const;
	private:
		friend static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		friend static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
	};


	class Input
	{
	private:
		friend class InputManager;

	public:

		inline static bool isKeyPressed(int keycode) { return s_InputManager->isKeyPressed(keycode); };
		inline static bool isMouseButtonClicked(int button) { return s_InputManager->isMouseButtonClicked(button); };
		inline static bool isMouseButtonPressed(int button) { return s_InputManager->isMouseButtonPressed(button); };
		inline static bool isMouseButtonReleased(int button) { return s_InputManager->isMouseButtonReleased(button); };

		inline static InputManager* getInputManager() { return s_InputManager; };

		inline static const glm::vec2& getMousePosition() { return s_InputManager->getMousePosition(); };
		inline static const glm::vec2& getPreviousMousePosition() { return s_InputManager->getPreviousMousePosition(); };
		inline static const glm::vec2  getWindowSize(GLFWwindow* window) { return s_InputManager->getWindowSize(window); };
		inline static const glm::vec2& getWindowPosition(GLFWwindow* window) { return s_InputManager->getWindowPosition(window); };
	private:
		static InputManager* s_InputManager;
	};

#define FRC_MOUSE_LEFT	  GLFW_MOUSE_BUTTON_LEFT
#define FRC_MOUSE_MIDDLE	  GLFW_MOUSE_BUTTON_MIDDLE
#define FRC_MOUSE_RIGHT    GLFW_MOUSE_BUTTON_RIGHT

#define FRC_NO_CURSOR	  NULL

#define FRC_MODIFIER_LEFT_CONTROL	GLFW_KEY_LEFT_CONTROL
#define FRC_MODIFIER_LEFT_ALT		GLFW_KEY_LEFT_ALT
#define FRC_MODIFIER_LEFT_SHIFT		GLFW_KEY_LEFT_SHIFT
#define FRC_MODIFIER_RIGHT_CONTROL	GLFW_KEY_RIGHT_CONTROL
#define FRC_MODIFIER_RIGHT_ALT		GLFW_KEY_RIGHT_ALT
#define FRC_MODIFIER_RIGHT_SHIFT		GLFW_KEY_RIGHT_SHIFT

#define FRC_KEY_TAB			  GLFW_KEY_TAB
#define FRC_KEY_SPACE		  GLFW_KEY_SPACE

#define FRC_KEY_0			  GLFW_KEY_0
#define FRC_KEY_1			  GLFW_KEY_1
#define FRC_KEY_2			  GLFW_KEY_2
#define FRC_KEY_3			  GLFW_KEY_3
#define FRC_KEY_4			  GLFW_KEY_4
#define FRC_KEY_5			  GLFW_KEY_5
#define FRC_KEY_6			  GLFW_KEY_6
#define FRC_KEY_7			  GLFW_KEY_7
#define FRC_KEY_8			  GLFW_KEY_8
#define FRC_KEY_9			  GLFW_KEY_9

#define FRC_KEY_A			  GLFW_KEY_A
#define FRC_KEY_B			  GLFW_KEY_B
#define FRC_KEY_C			  GLFW_KEY_C
#define FRC_KEY_D			  GLFW_KEY_D
#define FRC_KEY_E			  GLFW_KEY_E
#define FRC_KEY_F			  GLFW_KEY_F
#define FRC_KEY_G			  GLFW_KEY_G
#define FRC_KEY_H			  GLFW_KEY_H
#define FRC_KEY_I			  GLFW_KEY_I
#define FRC_KEY_J			  GLFW_KEY_J
#define FRC_KEY_K			  GLFW_KEY_K
#define FRC_KEY_L			  GLFW_KEY_L
#define FRC_KEY_M			  GLFW_KEY_M
#define FRC_KEY_N			  GLFW_KEY_N
#define FRC_KEY_O			  GLFW_KEY_O
#define FRC_KEY_P			  GLFW_KEY_P
#define FRC_KEY_Q			  GLFW_KEY_Q
#define FRC_KEY_R			  GLFW_KEY_R
#define FRC_KEY_S			  GLFW_KEY_S
#define FRC_KEY_T			  GLFW_KEY_T
#define FRC_KEY_U			  GLFW_KEY_U
#define FRC_KEY_V			  GLFW_KEY_V
#define FRC_KEY_W			  GLFW_KEY_W
#define FRC_KEY_X			  GLFW_KEY_X
#define FRC_KEY_Y			  GLFW_KEY_Y
#define FRC_KEY_Z			  GLFW_KEY_Z

#define FRC_KEY_ESCAPE         GLFW_KEY_ESCAPE
#define FRC_KEY_MENU           GLFW_KEY_MENU
#define FRC_KEY_ALT	          FRC_KEY_MENU
#define FRC_KEY_PAUSE          GLFW_KEY_PAUSE

#define FRC_KEY_FRCACE          0x20
#define FRC_KEY_PRIOR          0x21
#define FRC_KEY_NEXT           0x22
#define FRC_KEY_END            0x23
#define FRC_KEY_HOME           0x24
#define FRC_KEY_LEFT           0x25
#define FRC_KEY_UP             0x26
#define FRC_KEY_RIGHT          0x27
#define FRC_KEY_DOWN           0x28
#define FRC_KEY_SELECT         0x29
#define FRC_KEY_PRINT          0x2A
#define FRC_KEY_EXECUTE        0x2B
#define FRC_KEY_SNAPSHOT       0x2C
#define FRC_KEY_INSERT         0x2D
#define FRC_KEY_DELETE         0x2E
#define FRC_KEY_HELP           0x2F

#define FRC_KEY_NUMPAD0        0x60
#define FRC_KEY_NUMPAD1        0x61
#define FRC_KEY_NUMPAD2        0x62
#define FRC_KEY_NUMPAD3        0x63
#define FRC_KEY_NUMPAD4        0x64
#define FRC_KEY_NUMPAD5        0x65
#define FRC_KEY_NUMPAD6        0x66
#define FRC_KEY_NUMPAD7        0x67
#define FRC_KEY_NUMPAD8        0x68
#define FRC_KEY_NUMPAD9        0x69
#define FRC_KEY_MULTIPLY       0x6A
#define FRC_KEY_ADD            0x6B
#define FRC_KEY_SEPARATOR      0x6C
#define FRC_KEY_SUBTRACT       0x6D
#define FRC_KEY_DECIMAL        0x6E
#define FRC_KEY_DIVIDE         0x6F
#define FRC_KEY_F1             0x70
#define FRC_KEY_F2             0x71
#define FRC_KEY_F3             0x72
#define FRC_KEY_F4             0x73
#define FRC_KEY_F5             0x74
#define FRC_KEY_F6             0x75
#define FRC_KEY_F7             0x76
#define FRC_KEY_F8             0x77
#define FRC_KEY_F9             0x78
#define FRC_KEY_F10            0x79
#define FRC_KEY_F11            0x7A
#define FRC_KEY_F12            0x7B
#define FRC_KEY_F13            0x7C
#define FRC_KEY_F14            0x7D
#define FRC_KEY_F15            0x7E
#define FRC_KEY_F16            0x7F
#define FRC_KEY_F17            0x80
#define FRC_KEY_F18            0x81
#define FRC_KEY_F19            0x82
#define FRC_KEY_F20            0x83
#define FRC_KEY_F21            0x84
#define FRC_KEY_F22            0x85
#define FRC_KEY_F23            0x86
#define FRC_KEY_F24            0x87

#define FRC_KEY_NUMLOCK        0x90 
#define FRC_KEY_SCROLL         0x91

#define FRC_KEY_LSHIFT         GLFW_KEY_LEFT_SHIFT
#define FRC_KEY_RSHIFT         GLFW_KEY_RIGHT_SHIFT
#define FRC_KEY_FRCONTROL       GLFW_KEY_LEFT_CONTROL
#define FRC_KEY_RCONTROL       GLFW_KEY_RIGHT_CONTROL
#define FRC_KEY_LMENU          GLFW_KEY_LEFT_ALT
#define FRC_KEY_RMENU          GLFW_KEY_LEFT_ALT


} }