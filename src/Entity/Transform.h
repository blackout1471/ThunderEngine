#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

namespace ThunderEngine {
	namespace Entity {
		class Transform
		{
		private:
			glm::vec3 m_Position;
			glm::vec3 m_Rotation;
			glm::vec3 m_Scale;

		public:
			Transform();
			~Transform();

			void SetPosition(const glm::vec3& pos);
			void Translate(const glm::vec3& pos);

			void SetRotation(const glm::vec3& rot);
			void Rotate(const glm::vec3& rot);

			void SetScale(const glm::vec3& scale);
			void Scale(const glm::vec3& scale);

		public:
			glm::mat4& GetModel()
			{
				glm::quat rotatedQuat = glm::quat(m_Rotation);
				glm::mat4 mat = glm::translate(glm::mat4{ 1.0f }, m_Position) * glm::toMat4(rotatedQuat) * glm::scale(glm::mat4{ 1.0f }, m_Scale);

				return mat;
			}

			const glm::mat4& GetModel() const
			{
				glm::quat rotatedQuat = glm::quat(m_Rotation);
				glm::mat4 mat = glm::translate(glm::mat4{ 1.0f }, m_Position) * glm::toMat4(rotatedQuat) * glm::scale(glm::mat4{ 1.0f }, m_Scale);

				return mat;
			}
		};
	}
}


