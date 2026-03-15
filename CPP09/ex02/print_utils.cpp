#include "eader.h"

void	print_vec_couples(std::vector<std::pair<int, int> > couples)
{
	size_t couples_size = couples.size();
	
	std::cout << "------------------------\n";
	std::cout << "couples:\n";
	for (size_t i = 0; i < couples_size; i++)
	{
		std::cout << "|" << couples[i].first;
		std::cout << " , " << couples[i].second << '|' << std::endl;
	}
	std::cout << "------------------------\n";
}
void	print_stl(std::vector<int> vect){print_stl(vect, "");}

void	print_stl(std::deque<int> deque){print_stl(deque, "");}

void	print_stl(std::vector<int> vect, std::string msg)
{
	std::cout << msg;
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

void	print_stl(std::deque<int> deque, std::string msg)
{
	std::cout << msg;
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

std::vector<int>	decrease(std::vector<int> vect)
{
	size_t size = vect.size();
	for (size_t i = 0; i < size; i++)
		vect[i]--;
	return(vect);
}

void	print_time(clock_t &start, clock_t &end, std::string stl, int elements)
{
	double duration_us = double(end - start) / CLOCKS_PER_SEC * 1e6;

	std::cout	<< "Time to process a range of " 
				<< elements
				<< " elements with "
				<< stl << " : "
				<< duration_us 
				<< " us\n"; 
}