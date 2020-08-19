#pragma once
#include <string>
#include <stb_image.h>

namespace ThunderEngine {
	namespace Utils {
		class FileUtils {
		public:
			static std::string ReadFileContent(const std::string path);
			static unsigned char* ReadImageData(const std::string path, unsigned int* width, unsigned int* height);
			static void FlipImages(const bool flip);
			static std::vector<std::string> Split(const std::string& text, char delimiter);
		};
	}
}