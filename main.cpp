#include "main.hpp"

void	print_result(std::stringstream * std_ss, std::stringstream * my_ss, int & cat_nb, std::string cat_str)
{
	static int 		a = 0;

	if (!(std_ss->str().compare(my_ss->str())))
		COUT << GREEN << "[OK] " << RESET_ALL;
	else
	{
		std::ofstream	file;
		if (!a++)
			file.open("./errors.txt", std::ofstream::trunc);
		else
			file.open("./errors.txt", std::ofstream::app);
		COUT << RED << "[KO] " << RESET_ALL;
		if (cat_nb == 1)
			file << cat_str << ENDL;
		file << "*------------ test #" << cat_nb << " ------------*" << ENDL;
		file << "std::" << std_ss->str() << "ft::" << my_ss->str();
		file.close();
	}
	delete std_ss;
	delete my_ss;
}

int main(void)
{
	std::cout << MAGENTA << "*--------------- WELCOME TO FT_CONTAINERS TESTING ! ---------------*" << RESET_ALL << ENDL;
	std::cout << ENDL;

	std::cout << CYAN << "*--- TESTING Container : List . . . ---*" << RESET_ALL << ENDL;
	list_tester<ft::list, std::list, int>("list", "<int>");
	std::cout << ENDL;

	std::cout << CYAN << "*--- TESTING Container : Vector . . . ---*" << RESET_ALL << ENDL;
	vector_tester<ft::vector, std::vector, int>("vector", "<int>");
	std::cout << ENDL;

	std::cout << CYAN << "*--- TESTING Container : Map . . . ---*" << RESET_ALL << ENDL;
	map_tester<ft::map, std::map, int, std::string>("map", "<int, std::string>");
	std::cout << ENDL;

	std::cout << CYAN << "*--- TESTING Container : Stack . . . ---*" << RESET_ALL << ENDL;
	stack_tester<ft::stack, std::stack, int>("stack", "<int>");
	std::cout << ENDL;

	std::cout << CYAN << "*--- TESTING Container : Queue . . . ---*" << RESET_ALL << ENDL;
	queue_tester<ft::queue, std::queue, int>("queue", "<int>");
	std::cout << ENDL;

	return (0);
}