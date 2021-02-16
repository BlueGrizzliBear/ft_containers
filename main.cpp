#include "main.hpp"

int main(void)
{
	std::cout << MAGENTA << "*--------------- WELCOME TO FT_CONTAINERS TESTING ! ---------------*" << RESET_ALL << ENDL;
	std::cout << ENDL;

	std::cout << CYAN << "*--- TESTING Container : List . . . ---*" << RESET_ALL << ENDL;
	list_test();
	std::cout << ENDL;

	std::cout << CYAN << "*--- TESTING Container : Vector . . . ---*" << RESET_ALL << ENDL;
	vector_test();
	std::cout << ENDL;

	std::cout << CYAN << "*--- TESTING Container : Map . . . ---*" << RESET_ALL << ENDL;
	map_test();
	std::cout << ENDL;

	std::cout << CYAN << "*--- TESTING Container : Stack . . . ---*" << RESET_ALL << ENDL;
	stack_test();
	std::cout << ENDL;

	std::cout << CYAN << "*--- TESTING Container : Queue . . . ---*" << RESET_ALL << ENDL;
	queue_test();
	std::cout << ENDL;

	return (0);
}