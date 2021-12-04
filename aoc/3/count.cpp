#include "count.h"
#include <algorithm>
#include <sstream>


std::vector<std::string> Transpose(const std::vector<std::string>& strs)
{
	std::vector<std::stringstream> bufs;
	int i = 0;

	for (const std::string& str : strs)
	{
		for (char c : str)
		{
			if (i >= bufs.size())
			{
				bufs.push_back(std::stringstream());
			}

			bufs[i++] << c;
		}

		i = 0;
	}

	std::vector<std::string> ret;
	for (std::stringstream& buf : bufs)
	{
		ret.push_back(buf.str());
	}

	return ret;
}


char MostCommonBit(const std::string& binaryValue)
{
	int numberOfOnes = std::count_if(binaryValue.begin(), binaryValue.end(), [](char x) { return x == '1'; });
	if ((double)numberOfOnes / binaryValue.size() >= 0.5)
	{
		return '1';
	}
	return '0';
}


std::string Reduce(const std::vector<std::string>& values, bool lowest)
{
	std::vector<std::string> ret(values);
	int i = 0;
	while (ret.size() != 1)
	{
		std::vector<std::string> transposes = Transpose(ret);
		std::vector<std::string> tmp;
		char mostCommon = MostCommonBit(transposes[i]);
		for (const std::string& s : ret)
		{
			if ((lowest) ? s[i] != mostCommon : s[i] == mostCommon)
			{
				tmp.push_back(s);
			}
		}

		++i;
		ret = tmp;
	}

	return ret.back();

}