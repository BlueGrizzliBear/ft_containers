#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string.h>
// #include <vector>

#include "./Node.hpp"
#include "./Iterator.hpp"

namespace ft
{
	/* Vector Container declaration */
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		/* --- Member types --- */
		public:
			typedef T 		value_type;
			typedef Alloc	allocator_type;
			typedef typename Alloc::reference &			reference;
			typedef typename Alloc::const_reference &	const_reference;
			typedef typename Alloc::pointer &			pointer;
			typedef typename Alloc::const_pointer &		const_pointer;

			typedef typename ft::RandomAccess<T, Alloc, T>			iterator;
			typedef typename ft::RandomAccess<const T, Alloc, T>	const_iterator;
			typedef typename ft::Reverse_Iterator<iterator>			reverse_iterator;
			typedef typename ft::Reverse_Iterator<const_iterator>	const_reverse_iterator;

			typedef std::ptrdiff_t	difference_type;
			typedef std::size_t		size_type;

		/* --- Member attributes --- */
		private:
			allocator_type			_alloc;
			size_type				_size;
			T *						_head;
			T *						_tail;
			T *						_end;
		
		/* --- Member functions --- */
		public:
		/* Constructor */
			/* default	(1)	*/	explicit vector(const allocator_type & alloc = allocator_type());
			/* fill		(2)	*/	explicit vector(size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type());
			/* range	(3)	*/	template <class InputIterator>
								vector(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type());
			/* copy		(4)	*/	vector(const vector& x);

		/* Destructor */
			~vector();

		/* Operators */
			/* assignation	(1)	*/	vector &	operator=(vector const & rhs);

		/* Iterators */
			iterator				begin(void);
			const_iterator			begin(void) const;
			iterator				end(void);
			const_iterator			end(void) const;
			reverse_iterator		rbegin(void);
			const_reverse_iterator	rbegin(void) const;
			reverse_iterator		rend(void);
			const_reverse_iterator	rend(void) const;

		/* Capacity */
			size_type	size(void) const;
			size_type	max_size(void) const;
			void		resize(size_type n, value_type val = value_type());
			size_type	capacity(void) const;
			bool		empty(void) const;
			void		reserve(size_type n);

		/* Element access */
			reference		operator[](size_type n);
			const_reference	operator[](size_type n) const;

			reference		at(size_type n);
			const_reference	at(size_type n) const;

			reference		front(void);
			const_reference	front(void) const;

			reference		back(void);
			const_reference	back(void) const;

		/* Modifiers */
			/* range	(1)	*/	template <class InputIterator>
								void	assign(InputIterator first, InputIterator last);
			/* fill		(2)	*/	void	assign(size_type n, const value_type & val);

			void	push_back(const value_type & val);

			void	pop_back(void);

			/* single element	(1)	*/	iterator	insert(iterator position, const value_type & val);
			/* fill				(2)	*/	void		insert(iterator position, size_type n, const value_type & val);
			/* range			(3)	*/	template <class InputIterator>
										void		insert(iterator position, InputIterator first, InputIterator last);

			/* single element	(1)	*/	iterator	erase(iterator position);
			/* range			(2)	*/	iterator	erase(iterator first, iterator last);

			void		swap(vector & x);

			void		clear(void);

		/* Observers -- not implemented -- */
			// allocator_type	get_allocator(void) const;
		
		/* --- Private functions --- */
		private:
			void	_reallocate(size_type n, bool twice);

			void	_check_max_size(size_type n) const throw(std::length_error);
			void	_check_out_of_bound(size_type n) const throw(std::out_of_range);

			void	_add_n_values_from_int(size_type n, const value_type & val);
			
			template <class InputIterator>
			void	_add_values_from_iterators(InputIterator & first, InputIterator & last, void *);
			template <class InputIterator>
			void	_add_values_from_iterators(InputIterator & first, InputIterator & last, int);
			
			template <class InputIterator>
			void	_insert_values_from_iterators(iterator position, InputIterator & first, InputIterator & last, void *);
			template <class InputIterator>
			void	_insert_values_from_iterators(iterator position, InputIterator & first, InputIterator & last, int);			

	};

	/* --- Non-member function overloads --- */
		/*	(1)	*/	template <class T, class Alloc>
					bool	operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		/*	(2)	*/	template <class T, class Alloc>
					bool	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		/*	(3)	*/	template <class T, class Alloc>
					bool	operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		/*	(4)	*/	template <class T, class Alloc>
					bool	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		/*	(5)	*/	template <class T, class Alloc>
					bool	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		/*	(6)	*/	template <class T, class Alloc>
					bool	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		template <class T, class Alloc>
		void	swap(vector<T,Alloc>& x, vector<T,Alloc>& y);

}

# include "./Vector.tpp"

#endif