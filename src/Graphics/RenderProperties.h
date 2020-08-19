#pragma once

namespace ThunderEngine {
	namespace Graphics {
		enum class RenderPrimitives
		{
			Triangles,
			Traingles_Strip,
			Quads
		};

		enum class BufferUsage
		{
			Static_Draw,
			Dynamic_Draw
		};

		enum class ShaderType {
			Int,
			Unsigned_int,
			Float,
			Byte,
			Unsigned_Byte,
			Short,
			Unsigned_Short
		};
	}
}