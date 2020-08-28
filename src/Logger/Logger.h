#pragma once
#include <variant>

namespace ThunderEngine {
	namespace Logger {
		class Logger
		{
		protected:

			/// <summary>
			/// Method for basic writing to the object focused on
			/// </summary>
			/// <param name="message"></param>
			virtual void Write(std::string message) = 0;
		public:

			/// <summary>
			/// Open the target for writing to
			/// </summary>
			virtual void Open() = 0;

			/// <summary>
			/// method for writing info
			/// </summary>
			/// <param name="message"></param>
			/// <param name="vec"></param>
			virtual void WriteInfo(const std::string message, std::vector<std::variant<std::string, int, float, unsigned int>> vec) = 0;
			
			/// <summary>
			/// Method for writing warning to target
			/// </summary>
			/// <param name="message"></param>
			/// <param name="vec"></param>
			virtual void WriteWarning(const std::string message, std::vector<std::variant<std::string, int, float, unsigned int>> vec) = 0;
			
			/// <summary>
			/// Method for writing Error to target
			/// </summary>
			/// <param name="message"></param>
			/// <param name="vec"></param>
			virtual void WriteError(const std::string message, std::vector<std::variant<std::string, int, float, unsigned int>> vec) = 0;
			
			/// <summary>
			/// Close the target
			/// </summary>
			virtual void Close() = 0;
		};
	}
}

