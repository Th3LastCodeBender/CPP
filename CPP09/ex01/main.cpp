#include "eader.h"
#include "RPN.hpp"

bool	checkParameters(int argc, char	*argv[])
{
	if (argc != 2)
	{
		std::cerr << "Incorrect Parameters: less than one parameter passed!" << std::endl;
		return (false);
	}
	else if (argv[1] == NULL)
	{
		std::cerr << "Incorrect Parameters: string input is NULL!" << std::endl;
		return (false);
	}
	else if (argv[1][0] == '\0')
	{
		std::cerr << "Incorrect Parameters: string input is empty!" << std::endl;
		return (false);
	}
	return (true);
	
}

int main(int argc, char	*argv[])
{
	RPN	operation;
	// std::string data[] = {
    // "3 5 +",
    // "10 2 / 3 +",
    // "4 2 5 * + 1 3 2 * + /",
    // "7 3 - 2 *",
    // "5 1 2 + 4 * + 3 -"
    // "2 3 + 5 * 6 -",
    // "9 3 / 2 4 * +",
    // "8 2 5 * + 1 3 2 * + /",
    // "7 2 3 * - 4 5 + *",
    // "4 6 + 2 3 + * 5 -",
    // "9 1 - 2 3 + * 4 /",
    // "6 2 / 3 4 + * 5 1 - +",
    // "8 3 2 * + 4 2 / -",
    // "7 5 + 6 2 * - 3 +",
    // "9 4 2 * + 6 3 / -"
	// };
	if (checkParameters(argc, argv) == false)
		return (0);

	// size_t size = sizeof(data) / sizeof(data[0]);
	// for (size_t i = 0; i < size; i++)
	// 	operation.inputProcess(data[i].c_str());
	
	if (operation.inputProcess(argv[1]) == true)
		std::cout << operation.getResult() << std::endl;
}
