#pragma once

namespace ThunderEngine {
	namespace Systems {
		class System {
		public:
			virtual void OnStart() = 0;
			virtual void OnUpdate() = 0;
			virtual void OnDraw() = 0;
		};
	}
}