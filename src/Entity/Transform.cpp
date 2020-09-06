#include "tepch.h"
#include "Transform.h"

namespace ThunderEngine {
	namespace Entity {
		Transform::Transform() : m_Position(0.f), m_Rotation(0.f), m_Scale(1.f, 1.f, 1.f)
		{
		}

		Transform::~Transform()
		{

		}

		void Transform::SetPosition(const glm::vec3& pos)
		{
			m_Position = pos;
		}

		void Transform::Translate(const glm::vec3& pos)
		{
			m_Position += pos;
		}

		void Transform::SetRotation(const glm::vec3& rot)
		{
			m_Rotation = rot;
		}

		void Transform::Rotate(const glm::vec3& rot)
		{
			m_Rotation += rot;
		}

		void Transform::SetScale(const glm::vec3& scale)
		{
			m_Scale = scale;
		}

		void Transform::Scale(const glm::vec3& scale)
		{
			m_Scale += scale;
		}
	}
}