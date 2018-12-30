#include "plane.h"

Plane::Plane(int index, glm::vec4 color)
{
	m_Count = 12;
	m_ComponentCount = 3;
	m_Color = color;

	switch (index)
	{
	case TOP:
		top();
		break;
	case FRONT:
		front();
		break;
	case RIGHT:
		right();
		break;
	case BOTTOM:
		bottom();
		break;
	case BACK:
		back();
		break;
	case LEFT:
		left();
		break;
	default:
		top();
		break;
	}
}

void Plane::translateX(float value)
{
	m_Positions[0] += value;
	m_Positions[3] += value;
	m_Positions[6] += value;
	m_Positions[9] += value;
}

void Plane::translateY(float value)
{
	m_Positions[1] += value;
	m_Positions[4] += value;
	m_Positions[7] += value;
	m_Positions[10] += value;
}

void Plane::translateZ(float value)
{
	m_Positions[2] += value;
	m_Positions[5] += value;
	m_Positions[8] += value;
	m_Positions[11] += value;
}

void Plane::top()
{
	m_Positions = new float[12]
	{
		-0.5f, 0.5f,  0.5f,
		 0.5f, 0.5f,  0.5f,
		 0.5f, 0.5f, -0.5f,
		-0.5f, 0.5f, -0.5f
	};
}

void Plane::front()
{
	m_Positions = new float[12]
	{
		-0.5f, -0.5f, 0.5f,
		 0.5f, -0.5f, 0.5f,
		 0.5f,  0.5f, 0.5f,
		-0.5f,  0.5f, 0.5f
	};
}

void Plane::right()
{
	m_Positions = new float[12]
	{
		0.5f, -0.5f,  0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f,  0.5f, -0.5f,
		0.5f,  0.5f,  0.5f
	};
}

void Plane::bottom()
{
	top();
	m_Positions[1] *= -1;
	m_Positions[4] *= -1;
	m_Positions[7] *= -1;
	m_Positions[10] *= -1;
}

void Plane::back()
{
	m_Positions = new float[12]
	{
		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f
	};
}

void Plane::left()
{
	right();
	m_Positions[0] *= -1;
	m_Positions[3] *= -1;
	m_Positions[6] *= -1;
	m_Positions[9] *= -1;
}

glm::vec3 Plane::rotateX(glm::vec3 rotPoint, float angle)
{
	glm::mat3 rotMat;
	rotMat[0] = glm::vec3(1, 0, 0);
	rotMat[1] = glm::vec3(0, cos(glm::radians(angle)), sin(glm::radians(angle)));
	rotMat[2] = glm::vec3(0, -sin(glm::radians(angle)), cos(glm::radians(angle)));

	return rotPoint * rotMat;
}

void Plane::rotX(float angle)
{
	glm::vec3 pos;
	
	for (int i = 0; i < 12; i += 3)
	{
		pos = rotateX(glm::vec3(m_Positions[i], m_Positions[i + 1], m_Positions[i + 2]), angle);

		m_Positions[  i  ] = pos.x;
		m_Positions[i + 1] = pos.y;
		m_Positions[i + 2] = pos.z;
	}
}

glm::vec3 Plane::rotateY(glm::vec3 rotPoint, float angle)
{
	glm::mat3 rotMat;
	rotMat[0] = glm::vec3(cos(glm::radians(angle)), 0, -sin(glm::radians(angle)));
	rotMat[1] = glm::vec3(0, 1, 0);
	rotMat[2] = glm::vec3(sin(glm::radians(angle)), 0, cos(glm::radians(angle)));

	return rotPoint * rotMat;
}

void Plane::rotY(float angle)
{
	glm::vec3 pos;

	for (int i = 0; i < 12; i += 3)
	{
		pos = rotateY(glm::vec3(m_Positions[i], m_Positions[i + 1], m_Positions[i + 2]), angle);

		m_Positions[i] = pos.x;
		m_Positions[i + 1] = pos.y;
		m_Positions[i + 2] = pos.z;
	}
}

glm::vec3 Plane::rotateZ(glm::vec3 rotPoint, float angle)
{
	glm::mat3 rotMat;
	rotMat[0] = glm::vec3(cos(glm::radians(angle)), sin(glm::radians(angle)), 0);
	rotMat[1] = glm::vec3(-sin(glm::radians(angle)), cos(glm::radians(angle)), 0);
	rotMat[2] = glm::vec3(0, 0, 1);

	return rotPoint * rotMat;
}

void Plane::rotZ(float angle)
{
	glm::vec3 pos;

	for (int i = 0; i < 12; i += 3)
	{
		pos = rotateZ(glm::vec3(m_Positions[i], m_Positions[i + 1], m_Positions[i + 2]), angle);

		m_Positions[i] = pos.x;
		m_Positions[i + 1] = pos.y;
		m_Positions[i + 2] = pos.z;
	}
}