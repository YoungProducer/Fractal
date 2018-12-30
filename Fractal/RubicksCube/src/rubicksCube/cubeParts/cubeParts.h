#pragma once

#include "../../Fractal/src/fractal/frc.h"

#include "plane.h"

using namespace frc;
using namespace frc::graphics;

class Part
{
protected:
	std::vector<Plane> m_Faces;

public:
	Part();
	~Part();

	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);

	void addToRenderer(frc::graphics::BatchRenderer2D& renderer);

	inline std::vector<Plane>& getPlanes() { return m_Faces; };
	inline void setPlanes(std::vector<Plane> planes) { m_Faces = planes; };

	Part& operator = (const Part& part)
	{
		m_Faces = part.m_Faces;
		return *this;
	}

};

class Middle : public Part
{
public:
	Middle(glm::vec4 color);
};

class Edge : public Part
{
public:
	Edge(glm::vec4 tColor, glm::vec4 fColor, glm::vec4 rColor);
};

class Corner : public Part
{
public:
	Corner(glm::vec4 tColor, glm::vec4 fColor, glm::vec4 rColor);
};
