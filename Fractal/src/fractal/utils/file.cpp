#include "file.h"

namespace frc {

	std::string File::readFile(std::string filepath)
	{
		std::ifstream stream(filepath);
		std::string line;
		std::stringstream ss;

		while (!stream.eof())
		{
			std::getline(stream, line);
			ss << line;
		}

		return ss.str();
	}

	std::string File::readFileSh(std::string filepath)
	{
		std::ifstream stream(filepath);
		std::string line;
		std::stringstream ss;

		while (!stream.eof())
		{
			std::getline(stream, line);
			ss << line << "\n";
		}

		return ss.str();
	}
	   
}