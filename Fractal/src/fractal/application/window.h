#pragma once

#include "../glm/glm.hpp"
#include "../glm/gtc/type_ptr.hpp"

#include "glew.h"
#include "glfw3.h"

#include "input.h"

#include <string>

namespace frc { namespace app {

	struct WindowProperties
	{
		short width;
		short height;
	};

	class Window
	{
	private:

		short m_X;
		short m_Y;
		std::string m_Title;
		WindowProperties m_Propetries;
		bool m_Closed;
		GLFWwindow* m_Window;
		InputManager* m_InputManager;
		
	public:

		Window(const WindowProperties& properties, const std::string& title);
		~Window();

		void update();
		void clear();
		inline const bool& closed() const { return m_Closed; };

		void setEventCallBacks() { m_InputManager->setCallback(m_Window); };

		inline void setWindowPosition(const glm::vec2& pos) const { glfwSetWindowPos(m_Window, pos.x, pos.y); };
		inline void setWindowPosition(const short& x, const short& y) const { glfwSetWindowPos(m_Window, x, y); };

		inline GLFWwindow* getWindow() const { return m_Window; };
	private:
		void init();

	};

} }
