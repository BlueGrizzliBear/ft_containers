#ifndef STACK_HPP
# define STACK_HPP

#include <iostream>
#include <memory>
#include <deque>
// #include <stack>

#include "./Node.hpp"
#include "./Iterator.hpp"

namespace ft
{
	/* List Container declaration */
	template <class T, class Container = std::deque<T> >
	class stack
	{
		/* --- Member types --- */
		public:
			typedef T 			value_type;
			typedef Container	container_type;
			typedef std::size_t	size_type;

		/* --- Member attributes --- */
		protected:
			container_type	_cont;

		/* --- Member functions --- */
		public:
		/* Constructor */
			explicit stack(const container_type & ctnr = container_type());

		/* Capacity */
			bool		empty(void) const;
			size_type	size(void) const;

		/* Element access */
			value_type &		top(void);
			const value_type &	top(void) const;

		/* Modifiers */
			void	push(const value_type & val);
			void	pop(void);

		/* Friend usage on non-member operator overloards --- mandatory since no operator overload is defined in stack on cplusplus.com --- */
		template <class Type, class Cont>
		friend	bool	operator==(const stack<Type, Cont> & lhs, const stack<Type, Cont> & rhs);
		template <class Type, class Cont>
		friend	bool	operator<(const stack<Type, Cont> & lhs, const stack<Type, Cont> & rhs);
	};

	/* --- Non-member function overloads --- */
		/*	(1)	*/	template <class T, class Container>
					bool	operator==(const stack<T, Container> & lhs, const stack<T, Container> & rhs);
		/*	(2)	*/	template <class T, class Container>
					bool	operator!=(const stack<T, Container> & lhs, const stack<T, Container> & rhs);
		/*	(3)	*/	template <class T, class Container>
					bool	operator<(const stack<T, Container> & lhs, const stack<T, Container> & rhs);
		/*	(4)	*/	template <class T, class Container>
					bool	operator<=(const stack<T, Container> & lhs, const stack<T, Container> & rhs);
		/*	(5)	*/	template <class T, class Container>
					bool	operator>(const stack<T, Container> & lhs, const stack<T, Container> & rhs);
		/*	(6)	*/	template <class T, class Container>
					bool	operator>=(const stack<T, Container> & lhs, const stack<T, Container> & rhs);
}

# include "./Stack.tpp"

#endif