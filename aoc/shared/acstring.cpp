#include "acstring.h"

namespace acstring
{
	std::vector<std::string> Split(const std::string& str, const std::string& delim)
	{
		std::vector<std::string> tokens;
		size_t last = 0;
		size_t next = 0;
		while ((next = str.find(delim, last)) != std::string::npos)
		{
			tokens.push_back(str.substr(last, next - last));
			last = next + delim.size();
		}
		if (last < str.size())
			tokens.push_back(str.substr(last));
		return tokens;
	}
}