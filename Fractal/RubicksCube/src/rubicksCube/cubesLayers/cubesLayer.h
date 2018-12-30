#pragma once

#include <iostream>
#include <vector>

#include "../../Fractal/src/fractal/frc.h"
#include "../../utils/colors.h"
#include "../cubeParts/cubeParts.h"

#define LTOP 0
#define LMID 1
#define LBOT 2

class Layer
{
protected:
	float m_LayersMargin;
	std::vector<Part> m_PartsWrapper;
	std::vector<std::vector<Part>> m_Parts;
public:
	Layer() : m_LayersMargin(0.01f) { };
	Layer(int index);
	Layer(std::vector<std::vector<Part>> parts);

	void rotateWrapper(bool clockwise, short rotateCount);

	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);

	void addToRenderer(frc::graphics::BatchRenderer2D& renderer);

	inline const float& getLayersMargin() const { return m_LayersMargin; };
	inline const void setLayerMargin(const float margin) { m_LayersMargin = margin; };

	inline const std::vector<Part> getWrapper() const { return m_PartsWrapper; };
	inline const void setWrapper(const std::vector<Part>& wrapper) { m_PartsWrapper = wrapper; updateLayer(); };

	inline const std::vector<std::vector<Part>> getParts() const { return m_Parts; };
	inline const void setParts(const std::vector<std::vector<Part>>& parts) { m_Parts = parts; updateWrapper(); };
	
	inline const std::vector<Part> getFront()	const { return std::vector<Part> { m_Parts[2][0], m_Parts[2][1], m_Parts[2][2] }; };
	inline const std::vector<Part> getBack()	const { return std::vector<Part> { m_Parts[0][0], m_Parts[0][1], m_Parts[0][2] }; };
	inline const std::vector<Part> getRight()	const { return std::vector<Part> { m_Parts[0][2], m_Parts[1][2], m_Parts[2][2] }; };
	inline const std::vector<Part> getLeft()	const { return std::vector<Part> { m_Parts[0][0], m_Parts[1][0], m_Parts[2][0] }; };
	inline const std::vector<Part> getMiddleX()	const { return std::vector<Part> { m_Parts[0][1], m_Parts[1][1], m_Parts[2][1] }; };
	inline const std::vector<Part> getMiddleY() const { return std::vector<Part> { m_Parts[1][0], m_Parts[1][1], m_Parts[1][2] }; };
	
	inline const void setFront	(const std::vector<Part>& front) { m_Parts[2][0] = front[0]; m_Parts[2][1] = front[1]; m_Parts[2][2] = front[2]; updateWrapper(); updateLayer(); };
	inline const void setBack	(const std::vector<Part>& right) { m_Parts[0][0] = right[0]; m_Parts[0][1] = right[1]; m_Parts[0][2] = right[2]; updateWrapper(); updateLayer(); };
	inline const void setRight	(const std::vector<Part>& right) { m_Parts[0][2] = right[0]; m_Parts[1][2] = right[1]; m_Parts[2][2] = right[2]; updateWrapper(); updateLayer(); };
	inline const void setLeft	(const std::vector<Part>& right) { m_Parts[0][0] = right[0]; m_Parts[1][0] = right[1]; m_Parts[2][0] = right[2]; updateWrapper(); updateLayer(); };
	inline const void setMiddleX(const std::vector<Part>& right) { m_Parts[0][1] = right[0]; m_Parts[1][1] = right[1]; m_Parts[2][1] = right[2]; updateWrapper(); updateLayer(); };
	inline const void setMiddleY(const std::vector<Part>& right) { m_Parts[1][0] = right[0]; m_Parts[1][1] = right[1]; m_Parts[1][2] = right[2]; updateWrapper(); updateLayer(); };


	inline const std::string toString();

private:
	void updateWrapper();
	void updateLayer();
};