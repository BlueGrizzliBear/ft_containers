#ifndef QUEUE_HPP
# define QUEUE_HPP

#include <iostream>
#include <memory>
#include <deque>
// #include <queue>

#include "./Node.hpp"
#include "./Iterator.hpp"

namespace ft
{
	/* List Container declaration */
	template <class T, class Container = std::deque<T> >
	class queue
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
			explicit queue(const container_type & ctnr = container_type());

		/* Capacity */
			bool		empty(void) const;
			size_type	size(void) const;

		/* Element access */
			value_type &		front(void);
			const value_type &	front(void) const;

			value_type &		back(void);
			const value_type &	back(void) const;

		/* Modifiers */
			void	push(const value_type & val);
			void	pop(void);

		/* Friend usage on the non-member operator overloads --- mandatory since no operator overload is defined in queue on cplusplus.com --- */
		template <class Type, class Cont>
		friend	bool	operator==(const queue<Type, Cont> & lhs, const queue<Type, Cont> & rhs);
		template <class Type, class Cont>
		friend	bool	operator<(const queue<Type, Cont> & lhs, const queue<Type, Cont> & rhs);
	};

	/* --- Non-member function overloads --- */
		/*	(1)	*/	template <class T, class Container>
					bool	operator==(const queue<T, Container> & lhs, const queue<T, Container> & rhs);
		/*	(2)	*/	template <class T, class Container>
					bool	operator!=(const queue<T, Container> & lhs, const queue<T, Container> & rhs);
		/*	(3)	*/	template <class T, class Container>
					bool	operator<(const queue<T, Container> & lhs, const queue<T, Container> & rhs);
		/*	(4)	*/	template <class T, class Container>
					bool	operator<=(const queue<T, Container> & lhs, const queue<T, Container> & rhs);
		/*	(5)	*/	template <class T, class Container>
					bool	operator>(const queue<T, Container> & lhs, const queue<T, Container> & rhs);
		/*	(6)	*/	template <class T, class Container>
					bool	operator>=(const queue<T, Container> & lhs, const queue<T, Container> & rhs);
}

# include "./Queue.tpp"

#endif