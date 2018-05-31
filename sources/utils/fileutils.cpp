//
// Created by Marc on 01/06/2018.
//

#include <fstream>
#include <sstream>
#include "utils/fileutils.hpp"

namespace lazy
{
	namespace utils
	{
		std::string		LoadFile(const std::string &path)
		{
			std::stringstream result;
			std::ifstream in(path);

			if (in.is_open() && !in.bad())
			{
				result << in.rdbuf();
				in.close();
			}
			return result.str();
		}
	}
}