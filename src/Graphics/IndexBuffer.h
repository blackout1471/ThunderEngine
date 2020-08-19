#pragma once

namespace ThunderEngine {
	namespace Graphics {
		class IndexBuffer
		{
		public:
			virtual void Bind() = 0;
			virtual void Delete() = 0;
		};
	}
}