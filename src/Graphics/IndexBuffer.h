#pragma once

namespace ThunderEngine {
	namespace Graphics {
		class IndexBuffer
		{
		public:
			/// <summary>
			/// Binds the index buffer
			/// </summary>
			virtual void Bind() = 0;

			/// <summary>
			/// Deletes the current index buffer from gpu
			/// </summary>
			virtual void Delete() = 0;
		};
	}
}