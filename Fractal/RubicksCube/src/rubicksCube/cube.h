#pragma once

#include "cubesLayers/cubesLayer.h"
#include "cubesLayers/topLayer.h"
#include "cubesLayers/middleLayer.h"
#include "cubesLayers/bottomLayer.h"

class Cube
{
private:

	TopLayer m_Top;
	MiddleLayer m_Middle;
	BottomLayer m_Bottom;

	std::vector<Layer> m_RendererLayers;

public:

	Cube();

	void update();
	void render(frc::graphics::BatchRenderer2D& renderer);

	void rotateBottom(float angle);
	void rotateTop(float angle);
	void rotateRight(float angle);
	void rotateLeft(float angle);
	void rotateFront(float angle);
	void rotateBack(float angle);
	void rotateMiddleM(float angle);
	void rotateMiddleS(float angle);
	void rotateMiddleE(float angle);
};
