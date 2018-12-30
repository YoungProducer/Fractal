#include "cube.h"

Cube::Cube()
{
	update();
}

void Cube::update()
{
	m_RendererLayers.clear();
	m_RendererLayers.push_back(m_Top);
	m_RendererLayers.push_back(m_Middle);
	m_RendererLayers.push_back(m_Bottom);
}

void Cube::render(frc::graphics::BatchRenderer2D& renderer)
{
	for (int i = 0; i < m_RendererLayers.size(); i++)
		m_RendererLayers[i].addToRenderer(renderer);

	update();
}

void Cube::rotateTop(float angle)
{
	m_Top.rotateY(angle);
}

void Cube::rotateMiddleE(float angle)
{
	m_Middle.rotateY(angle);
}

void Cube::rotateBottom(float angle)
{
	m_Bottom.rotateY(angle);
}

void Cube::rotateRight(float angle)
{
	Layer right;

	std::vector<std::vector<Part>> parts(3);
	parts[0] = m_Top.getRight();
	parts[1] = m_Middle.getRight();
	parts[2] = m_Bottom.getRight();

	right.setParts(parts);
	right.rotateX(angle);
	
	m_Top.setRight(right.getLeft());

	m_RendererLayers.push_back(right);
}

void Cube::rotateLeft(float angle)
{
	Layer left;

	std::vector<std::vector<Part>> parts(3);
	parts[0] = m_Top.getLeft();
	parts[1] = m_Middle.getLeft();
	parts[2] = m_Bottom.getLeft();

	left.setParts(parts);
	left.rotateX(angle);

	m_Top.setRight(left.getRight());

	m_RendererLayers.push_back(left);
}

void Cube::rotateFront(float angle)
{
	Layer front;

	std::vector<std::vector<Part>> parts(3);
	parts[0] = m_Top.getFront();
	parts[1] = m_Middle.getFront();
	parts[2] = m_Bottom.getFront();

	front.setParts(parts);
	front.rotateX(angle);

	m_Top.setRight(front.getBack());

	m_RendererLayers.push_back(front);
}

void Cube::rotateBack(float angle)
{
	Layer back;

	std::vector<std::vector<Part>> parts(3);
	parts[0] = m_Top.getBack();
	parts[1] = m_Middle.getBack();
	parts[2] = m_Bottom.getBack();

	back.setParts(parts);
	back.rotateX(angle);

	m_Top.setRight(back.getFront());

	m_RendererLayers.push_back(back);
}