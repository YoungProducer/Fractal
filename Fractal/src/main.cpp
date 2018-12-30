//#include "fractal/frc.h"
//
//using namespace frc;
//using namespace frc::graphics;
//using namespace frc::app;
//
//int main()
//{
//	WindowProperties wProp;
//	wProp.width = 1280;
//	wProp.height = 720;
//
//	Window window(wProp, "Fractal");
//	window.setEventCallBacks();
//
//	float positions[] =
//	{
//		 -5.0, -5.0, 0.0,
//		 10.0, -5.0, 0.0,
//		 10.0, 10.0, 0.0,
//		 -5.0, 10.0, 0.0		
//	};
//
//	float cube[] =
//	{
//		1.0, -1.0, -1.0,
//		1.0, -1.0, 1.0,
//		-1.0, -1.0, 1.0,
//		-1.0, -1.0, -1.0,
//		1.0, 1.0, -1.0,
//		1.0, 1.0, 1.0,
//		-1.0, 1.0, 1.0,
//		-1.0, 1.0, -1.0,
//	};
//
//	GLuint cubeind[]
//	{
//		1, 3, 0,
//		7, 5, 4,
//		4, 1, 0,
//		5, 2, 1,
//		2, 7, 3,
//		0, 7, 4,
//		1, 2, 3,
//		7, 6, 5,
//		4, 5, 1,
//		5, 6, 2,
//		2, 6, 7,
//		0, 3, 7
//	};
//
//	float pososp[] =
//	{
//		1.0, 1.0,
//		3.0, 1.0,
//		3.0, 3.0,
//		1.0, 1.0
//	};
//
//	GLuint indices[]
//	{
//		0, 1, 2,
//		2, 3, 0
//	};
//
//	Shader basic("res/shaders/Basic.vert", "res/shaders/Basic.frag");
//	basic.enable();
//
//	glm::mat4 perspective = glm::perspective(45.f, 1280.f / 720.f, 0.1f, 1000.f);
//	glm::mat4 ortho = glm::ortho(0.0f, 16.f, 0.0f, 9.0f, -1.0f, 1.0f);
//
//	FPScamera camera(perspective);
//
//	BatchRenderer2D renderer(cubeind, 36);
//	Sprite spr(-5, -5, 10, 10, glm::vec4(1.0, 0.0, 1.0, 1.0));
//
//	//ShaderManager::setUniform4f(&basic, "u_Color", 1.0f, 1.0f, 1.0f, 1.0f);
//	ShaderManager::setUniform4f(&basic, "u_LightPos", 0.0f, 0.0f, 1.5f, 1.0f);
//
//	Buffer buffer(pososp, 4 * 2, 2);
//	IndexBuffer* indexBuffer = new IndexBuffer(indices, 6);
//	VertexArray* vertexArray = new VertexArray;
//	vertexArray->addBuffer(&buffer, 0);
//
//
//	while (!window.closed())
//	{
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		ShaderManager::setUniformMatrix4f(&basic, "pr_matrix", perspective);
//		ShaderManager::setUniformMatrix4f(&basic, "ml_matrix", camera.getModelViewMatrix());
//
//		if (Input::isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
//		{
//			std::cout << "Right button is clicked!" << std::endl;
//		}
//
//		renderer.begin();
//		//renderer.submit(positions, 12, 3);
//		renderer.submit(cube, 24, 3, glm::vec4(1.0, 0.0, 1.0, 1.0));
//		renderer.end();
//		renderer.flush();
//
//		camera.update(window.getWindow());
//		window.update();
//	}
//
//	return 1;
//}