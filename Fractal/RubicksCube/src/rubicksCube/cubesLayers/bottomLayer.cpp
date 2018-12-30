#include "bottomLayer.h"

BottomLayer::BottomLayer()
	: Layer(LBOT)
{
	for (int i = 0; i < 6; i++)
	{
		m_Parts[0][0].getPlanes()[i].translateZ(-1.0f - m_LayersMargin);
		m_Parts[0][0].getPlanes()[i].translateX(-1.0f - m_LayersMargin);
		m_Parts[0][0].getPlanes()[i].translateY(-1.0f - m_LayersMargin);
				  
		m_Parts[0][1].getPlanes()[i].translateZ(-1.0f - m_LayersMargin);
		m_Parts[0][1].getPlanes()[i].translateY(-1.0f - m_LayersMargin);
				  
		m_Parts[0][2].getPlanes()[i].translateX( 1.0f + m_LayersMargin);
		m_Parts[0][2].getPlanes()[i].translateZ(-1.0f - m_LayersMargin);
		m_Parts[0][2].getPlanes()[i].translateY(-1.0f - m_LayersMargin);
				  
		m_Parts[1][0].getPlanes()[i].translateX(-1.0f - m_LayersMargin);
		m_Parts[1][0].getPlanes()[i].translateY(-1.0f - m_LayersMargin);
				  
		m_Parts[1][1].getPlanes()[i].translateY(-1.0f - m_LayersMargin);
				  
		m_Parts[1][2].getPlanes()[i].translateX( 1.0f + m_LayersMargin);
		m_Parts[1][2].getPlanes()[i].translateY(-1.0f - m_LayersMargin);
				  
		m_Parts[2][0].getPlanes()[i].translateX(-1.0f - m_LayersMargin);
		m_Parts[2][0].getPlanes()[i].translateZ( 1.0f + m_LayersMargin);
		m_Parts[2][0].getPlanes()[i].translateY(-1.0f - m_LayersMargin);
				  
		m_Parts[2][1].getPlanes()[i].translateZ( 1.0f + m_LayersMargin);
		m_Parts[2][1].getPlanes()[i].translateY(-1.0f - m_LayersMargin);
				  
		m_Parts[2][2].getPlanes()[i].translateX( 1.0f + m_LayersMargin);
		m_Parts[2][2].getPlanes()[i].translateZ( 1.0f + m_LayersMargin);
		m_Parts[2][2].getPlanes()[i].translateY(-1.0f - m_LayersMargin);
	}
}

BottomLayer::~BottomLayer()
{

}
