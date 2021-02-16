#include "./Stack.hpp"

/* Constructor */
/* default	(1)	*/
template <typename Type, class Container>
ft::stack<Type, Container>::stack(const container_type & ctnr) : _cont(ctnr)	{}

/* Capacity */
template <typename Type, class Container>
bool	ft::stack<Type, Container>::empty(void) const
{ return (_cont.empty()); }

template <typename Type, class Container>
typename ft::stack<Type, Container>::size_type	ft::stack<Type, Container>::size(void) const
{ return (_cont.size()); }

/* Element access */
template <typename Type, class Container>
typename ft::stack<Type, Container>::value_type &	ft::stack<Type, Container>::top(void)
{
	return (_cont.back());
}

template <typename Type, class Container>
typename ft::stack<Type, Container>::value_type const &	ft::stack<Type, Container>::top(void) const
{
	return (_cont.back());
}

/* Modifiers */
template <typename Type, class Container>
void	ft::stack<Type, Container>::push(const value_type& val)
{
	_cont.push_back(val);
}

template <typename Type, class Container>
void	ft::stack<Type, Container>::pop(void)
{
	_cont.pop_back();
}

/* --- Non-member function overloads --- */
/*	(1)	*/
template <typename Type, class Container>
bool	ft::operator==(const stack<Type, Container> & lhs, const stack<Type, Container> & rhs)
{
	return (operator==(lhs._cont, rhs._cont));
}

/*	(2)	*/
template <typename Type, class Container>
bool	ft::operator!=(const stack<Type, Container> & lhs, const stack<Type, Container> & rhs)
{
	return (!(operator==(lhs, rhs)));
}

/*	(3)	*/
template <typename Type, class Container>
bool	ft::operator<(const stack<Type, Container> & lhs, const stack<Type, Container> & rhs)
{
	return (operator<(lhs._cont, rhs._cont));
}

/*	(4)	*/
template <typename Type, class Container>
bool	ft::operator<=(const stack<Type, Container> & lhs, const stack<Type, Container> & rhs)
{
	return ((!operator<(rhs, lhs)));
}

/*	(5)	*/
template <typename Type, class Container>
bool	ft::operator>(const stack<Type, Container> & lhs, const stack<Type, Container> & rhs)
{
	return (operator<(rhs, lhs));
}

/*	(6)	*/
template <typename Type, class Container>
bool	ft::operator>=(const stack<Type, Container> & lhs, const stack<Type, Container> & rhs)
{
	return (!(operator<(lhs, rhs)));
}
