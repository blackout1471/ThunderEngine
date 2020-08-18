#pragma once
#include "ShaderType.h"

namespace ThunderEngine {
	class VertexArray {
	public:
		virtual void InsertAttributePointer(unsigned int index, unsigned int size, ShaderType type, bool normalised, unsigned int stride, void* ptr) = 0;
		virtual void EnablePointer(unsigned int location) = 0;
		virtual void BindBuffer() = 0;
	};
}