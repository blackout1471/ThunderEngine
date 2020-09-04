#pragma once

namespace ThunderEngine {
	namespace System {
		class System {
		public:
			virtual void OnStart() = 0;
			virtual void OnUpdate() = 0;
			virtual void OnDraw() = 0;
		};
	}
}