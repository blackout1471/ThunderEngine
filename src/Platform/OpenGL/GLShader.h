#pragma once
#include <Graphics/Shader.h>

namespace ThunderEngine {
	namespace OpenGl {
		class GLShader : public Graphics::Shader
		{
		private:
			unsigned int m_Id;
			const char* m_VSource;
			const char* m_FSource;
		public:

			/// <summary>
			/// Creates a shader from data in the memory
			/// </summary>
			/// <param name="vertexSource">The vertex source data</param>
			/// <param name="fragmentSource">The fragment source data</param>
			GLShader(const char* vertexSource, const char* fragmentSource);
			virtual ~GLShader() { delete m_VSource, delete m_FSource; }
		public:

			/// <summary>
			/// Bind the shader as the current
			/// </summary>
			virtual void Bind() override;

			/// <summary>
			/// Deletes the current shader
			/// </summary>
			virtual void Delete() override;
		protected:
			/// <summary>
			/// Gets the location of a variable in the shader
			/// </summary>
			/// <param name="name"></param>
			/// <returns></returns>
			virtual const int GetUniformLocation(const char* name) override;

		private:

			/// <summary>
			/// Compiles the shader 
			/// </summary>
			/// <returns></returns>
			unsigned int Compile();

		public:
			/// <summary>
			/// Sets a int for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetInt(const std::string& name, int value) override;

			/// <summary>
			/// Sets 2 int's for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetInt2(const std::string& name, int value, int value2) override;

			/// <summary>
			/// Sets 3 int's for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetInt3(const std::string& name, int value, int value2, int value3) override;

			/// <summary>
			/// Sets 3 int's for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetInt4(const std::string& name, int value, int value2, int value3, int value4) override;

			/// <summary>
			/// Sets a float for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetFloat(const std::string& name, float value) override;

			/// <summary>
			/// Sets 2 floats's for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetFloat2(const std::string& name, float value, float value2) override;

			/// <summary>
			/// Sets 3 floats's for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetFloat3(const std::string& name, float value, float value2, float value3) override;

			/// <summary>
			/// Sets 4 floats's for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetFloat4(const std::string& name, float value, float value2, float value3, float value4) override;

			/// <summary>
			/// Sets vec2 for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetVec2(const std::string& name, glm::vec2& vector) override;

			/// <summary>
			/// Sets vec3 for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetVec3(const std::string& name, glm::vec3& vector) override;

			/// <summary>
			/// Sets vec4 for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetVec4(const std::string& name, glm::vec4& vector) override;

			/// <summary>
			/// Sets matrix3x3 for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetMat3(const std::string& name, const glm::mat3& matrix) override;

			/// <summary>
			/// Sets matrix4x4 for a location in the shader
			/// </summary>
			/// <param name="name">The name of the variable</param>
			/// <param name="value">The value to send to the shader</param>
			virtual void SetMat4(const std::string& name, const glm::mat4& matrix) override;
		};
	}
}