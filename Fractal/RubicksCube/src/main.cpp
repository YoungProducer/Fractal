#include "../../src/fractal/frc.h"
#include "rubicksCube/cube.h"
#include "rubicksCube/cubeParts/cubeParts.h"
#include "rubicksCube/cubesLayers/topLayer.h"
#include "rubicksCube/cubesLayers/middleLayer.h"
#include "rubicksCube/cubesLayers/bottomLayer.h"
#include "rubicksCube/cubesLayers/cubesLayer.h"


using namespace frc;
using namespace frc::app;
using namespace frc::graphics;

float positions[] =
{
	0.0, 0.0, 0.0,
	1.0, 0.0, 0.0,
	1.0, 1.0, 0.0,
	0.0, 1.0, 0.0
};

GLuint indices[] =
{
	0, 1, 2,
	2, 3, 0
};

int main()
{
	WindowProperties wProp;
	wProp.width = 1280;
	wProp.height = 720;

	std::string wTitle = "Rubic's Cube";

	Window window(wProp, wTitle);
	window.setEventCallBacks();

	Cube cube;
	
	BottomLayer bottom;
	MiddleLayer middle;
	TopLayer top;
	Layer right;

	glm::mat4 ortho = glm::ortho(0.0, 16.0, 0.0, 9.0, -1.0, 1.0);
	glm::mat4 perspective = glm::perspective(45.f, 1280.f / 720.f, 0.1f, 100.0f);

	Shader basic("C:/Users/PC/Documents/Visual Studio 2017/Projects/Fractal/Fractal/res/shaders/Basic.vert", "C:/Users/PC/Documents/Visual Studio 2017/Projects/Fractal/Fractal/res/shaders/Basic.frag");
	basic.enable();

	FPScamera camera(perspective);

	BatchRenderer2D renderer;

	ShaderManager::setUniform4f(&basic, "u_LightPos", 0.0f, 0.0f, 1.5f, 1.0f);

	//////////////////////////////////////////////////////
	std::vector<std::vector<Part>> newParts;
	newParts.resize(3);
	for (int i = 0; i < 3; i++)
		newParts[i].resize(3);

	std::vector<Part> parts;

	int rotcount = 0;

	while (!window.closed())
	{
		window.clear();

		ShaderManager::setUniformMatrix4f(&basic, "pr_matrix", perspective);
		ShaderManager::setUniformMatrix4f(&basic, "ml_matrix", camera.getModelViewMatrix());

		if (Input::isKeyPressed(FRC_KEY_1))
		{
			if (Input::isKeyPressed(FRC_KEY_RSHIFT))
				cube.rotateTop(90);
			else
				cube.rotateTop(-90);
		}

		if (Input::isKeyPressed(FRC_KEY_2))
		{
			if (Input::isKeyPressed(FRC_KEY_RSHIFT))
				cube.rotateMiddleE(90);
			else
				cube.rotateMiddleE(-90);
		}

		if (Input::isKeyPressed(FRC_KEY_3))
		{
			if (Input::isKeyPressed(FRC_KEY_RSHIFT))
				cube.rotateBottom(90);
			else
				cube.rotateBottom(-90);
		}

		if (Input::isKeyPressed(FRC_KEY_4))
		{
			if (Input::isKeyPressed(FRC_KEY_RSHIFT))
				cube.rotateLeft(90);
			else
				cube.rotateLeft(-90);
		}

		if (Input::isKeyPressed(FRC_KEY_6))
		{
			if (Input::isKeyPressed(FRC_KEY_RSHIFT))
				cube.rotateRight(90);
			else
				cube.rotateRight(-90);
		}

		if (Input::isKeyPressed(FRC_KEY_7))
		{
			if (Input::isKeyPressed(FRC_KEY_RSHIFT))
				cube.rotateFront(90);
			else
				cube.rotateFront(-90);
		}

		if (Input::isKeyPressed(FRC_KEY_9))
		{
			if (Input::isKeyPressed(FRC_KEY_RSHIFT))
				cube.rotateBack(90);
			else
				cube.rotateBack(-90);
		}

		renderer.begin();

		cube.render(renderer);

		renderer.end();
		renderer.flush();

		camera.update(window.getWindow());
		window.update();
	}

	return 1;
}