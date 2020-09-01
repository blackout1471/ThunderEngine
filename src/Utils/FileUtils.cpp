#include "tepch.h"
#include "FileUtils.h"
#include <sstream>
#include <iterator>
#include <Core/Core.h>

namespace ThunderEngine {
	namespace Utils {
		std::string FileUtils::ReadFileContent(const std::string path) {

			std::string content;

			try {

				std::ifstream ifs(path.c_str());
				TE_ASSERT(ifs.is_open(), "Could not open path: {}", { path });

				ifs >> std::noskipws;

				std::string line;

				while (std::getline(ifs, line)) {
					content.append(line);
					content.append("\n");
				}

				ifs.close();
			}
			catch (std::exception const& e) {
				TE_LOG_ERROR("{}", {e.what()});
			}

			return content;
		}

		unsigned char* FileUtils::ReadImageData(const std::string path, unsigned int* width, unsigned int* height, unsigned int* channels)
		{
			unsigned char* _dataPtr = stbi_load(path.c_str(), (int*)width, (int*)height, (int*)channels, 0);

			TE_ASSERT(_dataPtr, "Couldn't load image: {}", { path });

			//stbi_image_free(_dataPtr);

			return _dataPtr;
		}

		void FileUtils::FlipImages(const bool flip)
		{
			stbi_set_flip_vertically_on_load(flip);
		}

		std::vector<std::string> FileUtils::Split(const std::string& text, char delimiter)
		{
			std::vector<std::string> tokens;

			if (delimiter == ' ' || delimiter == 0x20)
			{
				std::istringstream buf(text);
				std::istream_iterator<std::string> beg(buf), end;

				tokens = std::vector<std::string>(beg, end);
			}
			else
			{
				std::string token;
				std::istringstream tokenStream(text);

				while (std::getline(tokenStream, token, delimiter))
				{
					tokens.push_back(token);
				}
			}

			return tokens;
		}
	}
}