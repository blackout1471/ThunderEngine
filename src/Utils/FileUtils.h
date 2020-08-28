#pragma once
#include <string>
#include <stb_image.h>

namespace ThunderEngine {
	namespace Utils {
		class FileUtils {
		public:
			/// <summary>
			/// Read content from a file
			/// </summary>
			/// <param name="path"></param>
			/// <returns></returns>
			static std::string ReadFileContent(const std::string path);

			/// <summary>
			/// Read image data
			/// </summary>
			/// <param name="path">the files destination</param>
			/// <param name="width">returns the width of the image</param>
			/// <param name="height">returns the height of the image</param>
			/// <param name="channels">returns the channels of the image</param>
			/// <returns></returns>
			static unsigned char* ReadImageData(const std::string path, unsigned int* width, unsigned int* height, unsigned int* channels);
			
			/// <summary>
			/// stb funtion to flip the image data
			/// it usually comes in where its flipped
			/// </summary>
			/// <param name="flip"></param>
			static void FlipImages(const bool flip);

			/// <summary>
			/// Split text from a delimiter
			/// </summary>
			/// <param name="text"></param>
			/// <param name="delimiter"></param>
			/// <returns></returns>
			static std::vector<std::string> Split(const std::string& text, char delimiter);
		};
	}
}