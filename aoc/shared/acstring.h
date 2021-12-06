#pragma once
#include <vector>
#include <string>

namespace AcString
{
	std::vector<std::string> Split(const std::string& str, const std::string& delim);

	std::vector<std::vector<std::string>> Split(const std::vector<std::string> lines, const std::string& delim);
}