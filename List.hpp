#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>
#include <memory>
// #include <list>

#include "./Node.hpp"
#include "./Iterator.hpp"

namespace ft
{
	/* List Container declaration */
	template <class T, class Alloc = std::allocator<T> >
	class list
	{
		/* --- Member types --- */
		public:
			typedef T 		value_type;
			typedef Alloc	allocator_type;
			typedef typename Alloc::reference &			reference;
			typedef typename Alloc::const_reference &	const_reference;
			typedef typename Alloc::pointer &			pointer;
			typedef typename Alloc::const_pointer &		const_pointer;

			typedef typename ft::Bidirectional<T, Alloc, DLNode<T, Alloc> >			iterator;
			typedef typename ft::Bidirectional<const T, Alloc, DLNode<T, Alloc> >	const_iterator;
			typedef typename ft::Reverse_Iterator<iterator>							reverse_iterator;
			typedef typename ft::Reverse_Iterator<const_iterator>					const_reverse_iterator;

			typedef std::ptrdiff_t	difference_type;
			typedef std::size_t		size_type;

		private:
			typedef typename allocator_type::template rebind<DLNode<T, Alloc> >::other	node_allocator;

		/* --- Member attributes --- */
		private:
			allocator_type		_alloc;
			node_allocator		_node_alloc;
			size_type			_size;
			DLNode<T, Alloc> *	_head;
			DLNode<T, Alloc> *	_tail;
			DLNode<T, Alloc> *	_end;
		
		/* --- Member functions --- */
		public:
		/* Constructor */
			/* default	(1)	*/	explicit list(const allocator_type & alloc = allocator_type());
			/* fill		(2)	*/	explicit list(size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type());
			/* range	(3)	*/	template <class InputIterator>
								list(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type());
			/* copy		(4)	*/	list(const list & cpy);

		/* Destructor */
			~list();

		/* Operators */
			/* assignation	(1)	*/	list &	operator=(list const & rhs);

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
			bool		empty(void) const;
			size_type	size(void) const;
			size_type	max_size(void) const;

		/* Element access */
			reference		front(void);
			const_reference	front(void) const;

			reference		back(void);
			const_reference	back(void) const;

		/* Modifiers */
			/* range	(1)	*/	template <class InputIterator>
								void	assign(InputIterator first, InputIterator last);
			/* fill		(2)	*/	void	assign(size_type n, const value_type & val);

			void	push_front(const value_type & val);

			void	pop_front(void);

			void	push_back(const value_type & val);

			void	pop_back(void);

			/* single element	(1)	*/	iterator	insert(iterator position, const value_type & val);
			/* fill				(2)	*/	void		insert(iterator position, size_type n, const value_type & val);
			/* range			(3)	*/	template <class InputIterator>
										void		insert(iterator position, InputIterator first, InputIterator last);

			/* single element	(1)	*/	iterator	erase(iterator position);
			/* range			(2)	*/	iterator	erase(iterator first, iterator last);

			void		swap(list & x);

			void		resize(size_type n, value_type val = value_type());

			void		clear(void);

		/* Operations */
			/* entire list		(1)	*/	void	splice(iterator position, list& x);
			/* single element	(2)	*/	void	splice(iterator position, list& x, iterator i);
			/* element range	(3)	*/	void	splice(iterator position, list& x, iterator first, iterator last);

			void	remove(const value_type & val);

			template <class Predicate>
			void	remove_if(Predicate pred);

			/*	(1)	*/	void	unique(void);
			/*	(2)	*/	template <class BinaryPredicate>
						void	unique(BinaryPredicate binary_pred);

			/*	(1)	*/	void	merge(list& x);
			/*	(2)	*/	template <class Compare>
						void	merge(list & x, Compare comp);

			/*	(1)	*/	void	sort(void);
			/*	(2)	*/	template <class Compare>
						void	sort(Compare comp);

			void	reverse(void);

		/* Observers -- not implemented -- */
			// allocator_type	get_allocator(void) const;
		
		/* --- Private functions --- */
		private:
			void	_update(void);

			void	_add_n_values_from_int(size_t n, const value_type & val);
			
			template <class InputIterator>
			void	_add_values_from_iterators(InputIterator & first, InputIterator & last, void *);
			template <class InputIterator>
			void	_add_values_from_iterators(InputIterator & first, InputIterator & last, int);
			
			DLNode<T, Alloc> *	_add_node(const value_type & val, DLNode<T,Alloc> *prev, DLNode<T,Alloc> *next);

			template <class InputIterator>
			void	_insert_values_from_iterators(iterator position, InputIterator & first, InputIterator & last, void *);
			template <class InputIterator>
			void	_insert_values_from_iterators(iterator position, InputIterator & first, InputIterator & last, int);			

	};

	/* --- Non-member function overloads --- */
		/*	(1)	*/	template <class T, class Alloc>
					bool	operator==(const list<T, Alloc> & lhs, const list<T, Alloc> & rhs);
		/*	(2)	*/	template <class T, class Alloc>
					bool	operator!=(const list<T, Alloc> & lhs, const list<T, Alloc> & rhs);
		/*	(3)	*/	template <class T, class Alloc>
					bool	operator<(const list<T, Alloc> & lhs, const list<T, Alloc> & rhs);
		/*	(4)	*/	template <class T, class Alloc>
					bool	operator<=(const list<T, Alloc> & lhs, const list<T, Alloc> & rhs);
		/*	(5)	*/	template <class T, class Alloc>
					bool	operator>(const list<T, Alloc> & lhs, const list<T, Alloc> & rhs);
		/*	(6)	*/	template <class T, class Alloc>
					bool	operator>=(const list<T, Alloc> & lhs, const list<T, Alloc> & rhs);

		template <class T, class Alloc>
		void	swap(list<T, Alloc> & x, list<T, Alloc> & y);

}

# include "./List.tpp"

#endif