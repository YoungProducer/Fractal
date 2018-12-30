#include "cubeParts.h"

Part::Part()
{
	m_Faces.resize(6);
}

Part::~Part()
{
	
}

Middle::Middle(glm::vec4 color)
	: Part()
{
	m_Faces[0] = Plane(TOP, color);
	m_Faces[1] = Plane(FRONT, color);
	m_Faces[2] = Plane(RIGHT, color);
	m_Faces[3] = Plane(BOTTOM, color);
	m_Faces[4] = Plane(BACK, color);
	m_Faces[5] = Plane(LEFT, color);
}

Edge::Edge(glm::vec4 tColor, glm::vec4 fColor, glm::vec4 rColor)
	: Part()
{
	m_Faces[0] = Plane(TOP,		tColor);
	m_Faces[1] = Plane(FRONT,	fColor);
	m_Faces[2] = Plane(RIGHT,	rColor);
	m_Faces[3] = Plane(BOTTOM,	tColor);
	m_Faces[4] = Plane(BACK,	fColor);
	m_Faces[5] = Plane(LEFT,	rColor);
}

Corner::Corner(glm::vec4 tColor, glm::vec4 fColor, glm::vec4 rColor)
	: Part()
{
	m_Faces[0] = Plane(TOP,		tColor);
	m_Faces[1] = Plane(FRONT,	fColor);
	m_Faces[2] = Plane(RIGHT,	rColor);
	m_Faces[3] = Plane(BOTTOM,	tColor);
	m_Faces[4] = Plane(BACK,	fColor);
	m_Faces[5] = Plane(LEFT,	rColor);
}

void Part::addToRenderer(frc::graphics::BatchRenderer2D& renderer)
{
	for (int i = 0; i < 6; i++)
		renderer.submit(&m_Faces[i]);
}

void Part::rotateX(float angle)
{
	for (int i = 0; i < 6; i++)
	{
		m_Faces[i].rotX(angle);
	}
}

void Part::rotateY(float angle)
{
	for (int i = 0; i < 6; i++)
	{
		m_Faces[i].rotY(angle);
	}
}

void Part::rotateZ(float angle)
{
	for (int i = 0; i < 6; i++)
	{
		m_Faces[i].rotZ(angle);
	}
}
