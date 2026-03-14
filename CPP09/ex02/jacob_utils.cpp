#include "eader.h"

/**
 * @brief creates a jacobsthal numbers series according to the requested range
 * 
 * @param range number of characters, meaning the number that has to be included in the jacobsthal series
 * @return std::vector<int> a vector containing the series
 */
std::vector<int>	jacob_series(int range)
{
	std::vector<int> series;

	if (range == 0 || range <= 4)
		return(jacob_series_limits(range));
	
	series.push_back(0);
	series.push_back(1);
	series.push_back(3);
	std::vector<int>::iterator it = series.end() - 1;
	int	actual = 0;
	int	previous = *it;
	int	before_previous = *(it - 1);
	while (actual < range)
	{
		actual = previous + (before_previous * 2);
		series.push_back(actual);
		it = series.end() - 1;
		previous = *it;
		before_previous = *(it - 1);
	}
	return(series);
}
// Serie di numeri di jacobsthal
// Primo numero = 0
// Secondo numero = 1
// Ogni numero dopo = il numero precedente + 2 volte quello ancora prima

/**
 * @brief Fills the gaps between jacobsthal 
 * 
 * @return std::vector<int> vector containing the order to be followed when inserting the smaller numbers in the bigger numbers stl
 */
std::vector<int>	jacob_blocks(int range)
{
	std::vector<int>	series = jacob_series(range);
	size_t				size = series.size();

	if (size == 0 || size <= 4)
		return (series);
	
	std::vector<int> blocks = first_jacob_part();

	series.erase(series.begin(), series.begin() + 4);
	int start = 5;
	while (series.empty() == false)
	{
		int max = series[0];
		for (int i = start + 1; i < max && i <= range; i++)
			blocks.push_back(i);
		if (*blocks.end() == range)
			break;
		start = series[0];
		series.erase(series.begin());
	}
	return(decrease(blocks));
}

std::vector<int>	jacob_series_limits(int range)
{
	std::vector<int> series;

	if (range == 0)
		return(series);
	else if (range == 1)
	{
		series.push_back(0);
		return (series);
	}
	else if (range == 2)
	{
		series.push_back(0);
		series.push_back(1);
		return (series);
	}
	else if (range == 3)
	{
		series.push_back(0);
		series.push_back(2);
		series.push_back(1);
		return (series);
	}
	return (series);
}

std::vector<int>	first_jacob_part()
{
	std::vector<int> blocks;

	blocks.push_back(1);
	blocks.push_back(3);
	blocks.push_back(2);
	blocks.push_back(5);
	blocks.push_back(4);

	return (blocks);
}

// blocks: 1 3 2 5 4
// series: 1 3 5 11
// 0 1 3 5 11
// 0 
// 1
// 3 2
// 5 4
// 11 10 9 8 7
// 22 21 20 19 18 17 16 15 14 13 12