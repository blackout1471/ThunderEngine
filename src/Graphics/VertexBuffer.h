#pragma once

namespace ThunderEngine {
	class VertexBuffer {
	public:
		virtual void SetData(void* data, unsigned int size) = 0;
		virtual void BindBuffer() = 0;
	};
}