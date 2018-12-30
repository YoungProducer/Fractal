#pragma once

#include <fstream>
#include <string>
#include <sstream>

namespace frc {

	class File
	{
	private:


	public:
		static std::string readFileSh(std::string filepath);
		static std::string readFile(std::string filepath);
	};

}
