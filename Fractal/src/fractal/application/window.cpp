#include "window.h"

namespace frc { namespace app {

	Window::Window(const WindowProperties& properties, const std::string& title)
		: m_X(0), m_Y(0), m_Propetries(properties), m_Title(title), m_Closed(false)
	{
		glfwInit();
		m_Window = glfwCreateWindow(m_Propetries.width, m_Propetries.height, title.c_str(), NULL, NULL);
		m_InputManager = new InputManager;
		init();
	}

	Window::~Window()
	{
		delete m_InputManager;
	}

	void Window::init()
	{
		glfwMakeContextCurrent(m_Window);
		glewInit();
		glfwSwapInterval(1);
		glEnable(GL_DEPTH_TEST);
	}

	void Window::update()
	{
		m_Closed = glfwWindowShouldClose(m_Window);
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void Window::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

} }