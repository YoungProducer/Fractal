#pragma once

#include "../../Fractal/src/fractal/frc.h"

#include <math.h>

#define TOP		0
#define FRONT	1
#define RIGHT	2
#define BOTTOM	3
#define BACK	4
#define LEFT	5

using namespace frc;
using namespace frc::graphics;

class Plane : public Sprite3d
{
public:

	Plane() { };
	Plane(int index, glm::vec4 color);

	void translateX(float value);
	void translateY(float value);
	void translateZ(float value);

	glm::vec3 rotateX(glm::vec3 rotPoint, float angle);
	void rotX(float angle);
	glm::vec3 rotateY(glm::vec3 rotPoint, float angle);
	void rotY(float angle);
	glm::vec3 rotateZ(glm::vec3 rotPoint, float angle);
	void rotZ(float angle);


private:
	void top();
	void front();
	void right();
	void bottom();
	void back();
	void left();
};
