#include "cubesLayer.h"

Layer::Layer(int index)
	: m_LayersMargin(0.01f)
{
	m_Parts.resize(3);
	for (int i = 0; i < 3; i++)
		m_Parts[i].resize(3);

	switch (index)
	{
	case 0:
		m_Parts[0][0] = Corner(YELLOW, ORANGE, BLUE);
		m_Parts[0][1] = Edge(YELLOW, ORANGE, BLUE);
		m_Parts[0][2] = Corner(YELLOW, ORANGE, GREEN);
		m_Parts[1][0] = Edge(YELLOW, ORANGE, BLUE);
		m_Parts[1][1] = Middle(YELLOW);
		m_Parts[1][2] = Edge(YELLOW, RED, GREEN);
		m_Parts[2][0] = Corner(YELLOW, RED, BLUE);
		m_Parts[2][1] = Edge(YELLOW, RED, BLUE);
		m_Parts[2][2] = Corner(YELLOW, RED, GREEN);
		break;
	case 1:
		m_Parts[0][0] = Edge(YELLOW, ORANGE, BLUE);
		m_Parts[0][1] = Middle(ORANGE);
		m_Parts[0][2] = Edge(YELLOW, ORANGE, GREEN);
		m_Parts[1][0] = Middle(BLUE);
		m_Parts[1][1] = Middle(BLACK);
		m_Parts[1][2] = Middle(GREEN);
		m_Parts[2][0] = Edge(YELLOW, RED, BLUE);
		m_Parts[2][1] = Middle(RED);
		m_Parts[2][2] = Edge(YELLOW, RED, GREEN);
		break;
	case 2:
		m_Parts[0][0] = Corner(WHITE, ORANGE, BLUE);
		m_Parts[0][1] = Edge(WHITE, ORANGE, BLUE);
		m_Parts[0][2] = Corner(WHITE, ORANGE, GREEN);
		m_Parts[1][0] = Edge(WHITE, ORANGE, BLUE);
		m_Parts[1][1] = Middle(WHITE);
		m_Parts[1][2] = Edge(WHITE, RED, GREEN);
		m_Parts[2][0] = Corner(WHITE, RED, BLUE);
		m_Parts[2][1] = Edge(WHITE, RED, BLUE);
		m_Parts[2][2] = Corner(WHITE, RED, GREEN);
		break;
	default:
		break;
	}

	updateWrapper();
}

Layer::Layer(std::vector<std::vector<Part>> parts)
	: m_Parts(parts)
{
	updateWrapper();
}

void Layer::addToRenderer(frc::graphics::BatchRenderer2D& renderer)
{
	std::vector<Plane> planes;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			m_Parts[i][j].addToRenderer(renderer);
		}
}

void Layer::rotateWrapper(bool clockwise, short rotateCount)
{
	std::vector<Part> wrapper;

	if (clockwise)
	{
		for (int i = m_PartsWrapper.size() - rotateCount * 2; i < m_PartsWrapper.size(); i++)
		{
			wrapper.push_back(m_PartsWrapper[i]);
		}

		for (int i = 0; i < m_PartsWrapper.size() - rotateCount * 2; i++)
		{
			wrapper.push_back(m_PartsWrapper[i]);
		}
	}
	else
	{
		for (int i = rotateCount * 2; i < m_PartsWrapper.size(); i++)
		{
			wrapper.push_back(m_PartsWrapper[i]);
		}

		for (int i = 0; i < rotateCount * 2; i++)
		{
			wrapper.push_back(m_PartsWrapper[i]);
		}
	}

	setWrapper(wrapper);
}

void Layer::updateWrapper()
{
	m_PartsWrapper.clear();
	int index = 0;
	int j;
	int size = 3;
	int turn = size / 2;
	for (int k = 1; k <= turn; k++)/*Цикл по номеру витка*/
	{
		if (index > m_PartsWrapper.size() - 1)
			break;

		for (j = k - 1; j < size - k + 1; j++)
		{
			m_PartsWrapper.push_back(m_Parts[k - 1][j]);
			index++;
		}
		for (j = k; j < size - k + 1; j++)
		{
			m_PartsWrapper.push_back(m_Parts[j][size - k]);
			index++;
		}
		for (j = size - k - 1; j >= k - 1; --j)
		{
			m_PartsWrapper.push_back(m_Parts[size - k][j]);
			index++;
		}
		for (j = size - k - 1; j >= k; j--)
		{
			m_PartsWrapper.push_back(m_Parts[j][k - 1]);
			index++;
		}
	}
}

void Layer::updateLayer()
{
	int index = 0;
	int pIndex = 0;
	int j;
	int size = 3;
	int turn = size / 2;

	for (int k = 1; k <= turn; k++)/*Цикл по номеру витка*/
	{
		for (j = k - 1; j < size - k + 1; j++)
		{
			if (index > m_PartsWrapper.size() - 1)
				break;
			m_Parts[k - 1][j] = m_PartsWrapper[index++];
		}
		for (j = k; j < size - k + 1; j++)
		{
			if (index > m_PartsWrapper.size() - 1)
				break;
			m_Parts[j][size - k] = m_PartsWrapper[index++];
		}
		for (j = size - k - 1; j >= k - 1; --j)
		{
			if (index > m_PartsWrapper.size() - 1)
				break;
			m_Parts[size - k][j] = m_PartsWrapper[index++];
		}
		for (j = size - k - 1; j >= k; j--)
		{
			if (index > m_PartsWrapper.size() - 1)
				break;
			m_Parts[j][k - 1] = m_PartsWrapper[index++];
		}
	}
}

void Layer::rotateX(float angle)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m_Parts[i][j].rotateX(angle);

	if (angle > 0)
		rotateWrapper(true, 1);
	else
		rotateWrapper(false, 1);
}

void Layer::rotateY(float angle)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m_Parts[i][j].rotateY(angle);

	if (angle > 0)
		rotateWrapper(true, 1);
	else
		rotateWrapper(false, 1);
}

void Layer::rotateZ(float angle)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m_Parts[i][j].rotateZ(angle);

	if (angle > 0)
		rotateWrapper(true, 1);
	else
		rotateWrapper(false, 1);
}