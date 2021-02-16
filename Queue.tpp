#include "./Queue.hpp"

/* Constructor */
/* default	(1)	*/
template <typename Type, class Container>
ft::queue<Type, Container>::queue(const container_type & ctnr) : _cont(ctnr)	{}

/* Capacity */
template <typename Type, class Container>
bool	ft::queue<Type, Container>::empty(void) const
{ return (_cont.empty()); }

template <typename Type, class Container>
typename ft::queue<Type, Container>::size_type	ft::queue<Type, Container>::size(void) const
{ return (_cont.size()); }

/* Element access */
template <typename Type, class Container>
typename ft::queue<Type, Container>::value_type &	ft::queue<Type, Container>::front(void)
{
	return (_cont.front());
}

template <typename Type, class Container>
typename ft::queue<Type, Container>::value_type const &	ft::queue<Type, Container>::front(void) const
{
	return (_cont.front());
}

template <typename Type, class Container>
typename ft::queue<Type, Container>::value_type &	ft::queue<Type, Container>::back(void)
{
	return (_cont.back());
}

template <typename Type, class Container>
typename ft::queue<Type, Container>::value_type const &	ft::queue<Type, Container>::back(void) const
{
	return (_cont.back());
}

/* Modifiers */
template <typename Type, class Container>
void	ft::queue<Type, Container>::push(const value_type& val)
{
	_cont.push_back(val);
}

template <typename Type, class Container>
void	ft::queue<Type, Container>::pop(void)
{
	_cont.pop_front();
}

/* --- Non-member function overloads --- */
/*	(1)	*/
template <typename Type, class Container>
bool	ft::operator==(const queue<Type, Container> & lhs, const queue<Type, Container> & rhs)
{
	return (operator==(lhs._cont, rhs._cont));
}

/*	(2)	*/
template <typename Type, class Container>
bool	ft::operator!=(const queue<Type, Container> & lhs, const queue<Type, Container> & rhs)
{
	return (!(operator==(lhs, rhs)));
}

/*	(3)	*/
template <typename Type, class Container>
bool	ft::operator<(const queue<Type, Container> & lhs, const queue<Type, Container> & rhs)
{
	return (operator<(lhs._cont, rhs._cont));
}

/*	(4)	*/
template <typename Type, class Container>
bool	ft::operator<=(const queue<Type, Container> & lhs, const queue<Type, Container> & rhs)
{
	return ((!operator<(rhs, lhs)));
}

/*	(5)	*/
template <typename Type, class Container>
bool	ft::operator>(const queue<Type, Container> & lhs, const queue<Type, Container> & rhs)
{
	return (operator<(rhs, lhs));
}

/*	(6)	*/
template <typename Type, class Container>
bool	ft::operator>=(const queue<Type, Container> & lhs, const queue<Type, Container> & rhs)
{
	return (!(operator<(lhs, rhs)));
}
