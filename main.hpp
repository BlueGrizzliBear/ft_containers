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

void	print_result(std::stringstream * std_ss, std::stringstream * my_ss, int & cat_nb, std::string cat_str);

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

template <class containerT>
std::stringstream *	print_stack(containerT & cont, std::string const & test_name)
{

	std::stringstream * ss = new std::stringstream();

	*ss << test_name << ENDL;
	*ss << "From the top to the end of the Stack = [ ";

	while (!cont.empty())
	{
		*ss << "(" << cont.top() << ") ";
		cont.pop();
	}
	*ss << "]" << ENDL;
	*ss << "Size = " << cont.size() << ENDL << ENDL;
	return (ss);
}

template <class containerT>
std::stringstream *	print_queue(containerT & cont, std::string const & test_name)
{

	std::stringstream * ss = new std::stringstream();

	*ss << test_name << ENDL;
	*ss << "From the front to the back of the queue = [ ";

	while (!cont.empty())
	{
		*ss << "(" << cont.front() << ") ";
		cont.pop();
	}
	*ss << "]" << ENDL;
	*ss << "Size = " << cont.size() << ENDL << ENDL;
	return (ss);
}

#include "test_list.hpp"
#include "test_vector.hpp"
#include "test_map.hpp"
#include "test_stack.hpp"
#include "test_queue.hpp"

#endif