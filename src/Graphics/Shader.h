#pragma once
#include <string>

#include <glm/glm.hpp>

namespace ThunderEngine {
	namespace Graphics {
		class Shader
		{
		public:
			/// <summary>
			/// Creates a shader based on the source given
			/// </summary>
			/// <param name="vertexSource"></param>
			/// <param name="fragmentSource"></param>
			inline Shader(const char* vertexSource, const char* fragmentSource) {};
			inline virtual ~Shader() {};
		public:
			/// <summary>
			/// Bind the shader as the current
			/// </summary>
			virtual void Bind() = 0;

			/// <summary>
			/// Deletes the current shader from gpu
			/// </summary>
			virtual void Delete() = 0;

		public:
			/// <summary>
			/// Sets a int for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetInt(const std::string& name, int value) = 0;

			/// <summary>
			/// Sets 2 int's for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetInt2(const std::string& name, int value, int value2) = 0;

			/// <summary>
			/// Sets 3 int's for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetInt3(const std::string& name, int value, int value2, int value3) = 0;

			/// <summary>
			/// Sets 3 int's for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetInt4(const std::string& name, int value, int value2, int value3, int value4) = 0;

			/// <summary>
			/// Sets a float for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetFloat(const std::string& name, float value) = 0;

			/// <summary>
			/// Sets 2 floats's for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetFloat2(const std::string& name, float value, float value2) = 0;

			/// <summary>
			/// Sets 3 floats's for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetFloat3(const std::string& name, float value, float value2, float value3) = 0;

			/// <summary>
			/// Sets 4 floats's for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetFloat4(const std::string& name, float value, float value2, float value3, float value4) = 0;

			/// <summary>
			/// Sets vec2 for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetVec2(const std::string& name, glm::vec2& vector) = 0;

			/// <summary>
			/// Sets vec3 for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetVec3(const std::string& name, glm::vec3& vector) = 0;

			/// <summary>
			/// Sets vec4 for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetVec4(const std::string& name, glm::vec4& vector) = 0;

			/// <summary>
			/// Sets matrix3x3 for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetMat3(const std::string& name, const glm::mat3& matrix) = 0;

			/// <summary>
			/// Sets matrix4x4 for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetMat4(const std::string& name, const glm::mat4& matrix) = 0;
		protected:
			/// <summary>
			/// Gets the location of a variable in the shader
			/// </summary>
			/// <param name="name"></param>
			/// <returns></returns>
			virtual const int GetUniformLocation(const char* name) = 0;
		};
	}
}