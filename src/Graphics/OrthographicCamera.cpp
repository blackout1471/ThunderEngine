#include "tepch.h"
#include "OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace ThunderEngine {
	namespace Graphics {

		OrthographicCamera::OrthographicCamera()
		{
			this->Recalculate();
		}

		void OrthographicCamera::SetProjection(float width, float height)
		{
			m_Width = width;
			m_Height = height;

			this->Recalculate();
		}

		void OrthographicCamera::Recalculate()
		{
			m_Projection = glm::ortho<float>(0.f, m_Width, 0, m_Height, m_Near, m_Far);
		}
	}
}