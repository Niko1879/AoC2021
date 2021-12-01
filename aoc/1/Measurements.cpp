#include <numeric>
#include "Measurements.h"


int ComputeTotalIncreases(const std::vector<int>& readings, int windowSize)
{
	if (windowSize >= readings.size())
		return 0;

	int previousReadingSum = INT_MAX;
	int numIncreases = 0;
	for (int i = 0; i <= readings.size() - windowSize; ++i)
	{
		int reading = std::accumulate(readings.begin() + i, readings.begin() + i + windowSize, 0);

		if (reading > previousReadingSum)
		{
			++numIncreases;
		}

		previousReadingSum = reading;
	}

	return numIncreases;
}