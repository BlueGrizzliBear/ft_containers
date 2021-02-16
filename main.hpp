#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include <sstream>
#include <fstream>

#include <list>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>

#include "./List.hpp"
#include "./Vector.hpp"
#include "./Map.hpp"
#include "./Stack.hpp"
#include "./Queue.hpp"

# define COUT	std::cout
# define ENDL	std::endl
# define RENDL	RESET_ALL << std::endl

# define RESET_ALL	"\033[0m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"

template <class T>
class Predicate
{
	private:
		T const	_val;
	public:
		Predicate(T const & val) : _val(val) {}
		~Predicate(void) {}
		bool	operator()(T const & val)
		{
			if (val == T(_val))
				return (true);
			return (false);
		}
};

template <class T>
class BinaryPredicate
{
	private:
		T const	_val;
	public:
		BinaryPredicate(T const & val) : _val(val) {}
		~BinaryPredicate(void) {}
		bool	operator()(T const & val1, T const & val2)
		{
			if (val1 != _val && _val != val2 )
				return (true);
			return (false);
		}
};

template <class T>
class Compare
{
	public:
		Compare(void) {}
		~Compare(void) {}
		bool	operator()(T const & val1, T const & val2)
		{
			return (val1 < val2);
		}
};

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

template <class containerT>
std::stringstream *	print_cont(containerT & cont, std::string const & test_name)
{

	std::stringstream * ss = new std::stringstream();

	typename containerT::iterator begin = cont.begin();
	typename containerT::iterator end = cont.end();

	*ss << test_name << ENDL;

	*ss << "Elements = [ ";
	
	while (begin != end)
	{
		*ss << *begin << " ";
		++begin;
	}
	*ss << "]" << ENDL;
	*ss << "Size = " << cont.size() << ENDL;
	*ss << ENDL;
	return (ss);
}

template <class containerT>
std::stringstream *	print_map(containerT & cont, std::string const & test_name)
{

	std::stringstream * ss = new std::stringstream();

	typename containerT::iterator begin = cont.begin();
	typename containerT::iterator end = cont.end();

	*ss << test_name << ENDL;

	*ss << "Elements = [ ";
	
	while (begin != end)
	{
		*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
		++begin;
	}
	*ss << "]" << ENDL;
	*ss << "Size = " << cont.size() << ENDL;
	*ss << ENDL;
	return (ss);
}

#include "test_list.hpp"
#include "test_vector.hpp"
#include "test_map.hpp"
#include "test_stack.hpp"
#include "test_queue.hpp"

#endif