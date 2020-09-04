#pragma once
#include "Camera.h"

namespace ThunderEngine {
	namespace Graphics {
		class OrthographicCamera : public Camera {
		public:
			OrthographicCamera();
			virtual ~OrthographicCamera() = default;

			void SetProjection(float width, float height);

		private:
			void Recalculate();
		private:
			float m_Width = 1280;
			float m_Height = 720;
			float m_Near = -1.f;
			float m_Far = 1.f;
		};
	}
}