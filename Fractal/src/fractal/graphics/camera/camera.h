#pragma once

#include "glew.h"
#include "glfw3.h"

#include "../../application/input.h"

#include "../glm/glm.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/gtc/matrix_transform.hpp"

namespace frc { namespace graphics {

	class Camera
	{
	protected:

		glm::vec3 m_CameraPos;
		glm::vec3 m_CameraDir;
		glm::vec3 m_CameraUp;
		glm::vec3 m_Rotation;

		glm::mat4 m_Perspective;
		glm::mat4 m_ModelView;

	public:

		Camera() { };
		Camera(glm::mat4& perspective);

		inline const glm::vec3& getCameraPos() const { return m_CameraPos; };
		inline const void setCameraPos(const glm::vec3 position) { m_CameraPos = position; };
		inline const void setCameraPos(const float x, const float y, const float z) { m_CameraPos = glm::vec3(x, y, z); };

		inline const glm::vec3& getCameraDir() const { return m_CameraDir; };
		inline const void setCameraDir(const glm::vec3 direction) { m_CameraDir = direction; };
		inline const void setCameraDir(const float x, const float y, const float z) { m_CameraDir = glm::vec3(x, y, z); };

		inline const glm::vec3& getCameraUp() const { return m_CameraUp; };
		inline const void setCameraUp(const glm::vec3 upvector) { m_CameraUp = upvector; };
		inline const void setCameraUp(const float x, const float y, const float z) { m_CameraUp = glm::vec3(x, y, z); };

		inline const glm::vec3& getCameraRot() const { return m_Rotation; };
		inline const void setCameraRot(const glm::vec3& rotation) { m_Rotation = rotation; };
		inline const void setCameraRot(const float x, const float y, const float z) { m_Rotation = glm::vec3(x, y, z); };

		inline const glm::mat4& getPerspectiveMatrix() const { return m_Perspective; };
		inline const void setPerspectiveMatrix(const glm::mat4& matrix) { m_Perspective = matrix; };

		inline const glm::mat4& getModelViewMatrix() const { return m_ModelView; };
		inline const void setModelViewMatrix(const glm::mat4& matrix) { m_ModelView = matrix; };
	};

} }