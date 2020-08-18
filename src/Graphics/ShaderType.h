#pragma once

namespace ThunderEngine {
	enum class ShaderType {
		Int,
		Unsigned_int,
		Float,
		Byte,
		Unsigned_Byte,
		Short,
		Unsigned_Short
	};

	class ShaderTypeConverter {
	public:
		inline static unsigned int ConvertToOpenglType(ShaderType type)
		{
			return 0x1406;

			/*unsigned int v = GL_FLOAT;

			switch (type)
			{
			case ThunderEngine::ShaderType::Int:
				v = GL_INT;
				break;
			case ThunderEngine::ShaderType::Unsigned_int:
				v = GL_UNSIGNED_INT;
				break;
			case ThunderEngine::ShaderType::Float:
				v = GL_FLOAT;
				break;
			case ThunderEngine::ShaderType::Byte:
				v = GL_BYTE;
				break;
			case ThunderEngine::ShaderType::Unsigned_Byte:
				v = GL_UNSIGNED_BYTE;
				break;
			case ThunderEngine::ShaderType::Short:
				v = GL_SHORT;
				break;
			case ThunderEngine::ShaderType::Unsigned_Short:
				v = GL_UNSIGNED_SHORT;
				break;
			}*/

			/*return v;*/
		}
	};
}