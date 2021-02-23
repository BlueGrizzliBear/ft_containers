#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <memory>
#include <limits>
// #include <map>

#include "./Node.hpp"
#include "./Iterator.hpp"

namespace ft
{
	/* map Container declaration */
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
	{
		/* --- Member types --- */
		public:
			typedef Key 	key_type;
			typedef T 		mapped_type;
			typedef std::pair<const key_type, mapped_type> 		value_type;
			typedef	Compare	key_compare;
			class value_compare
			{
				friend class map;
				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type & x, const value_type & y) const	{ return comp(x.first, y.first); }
			};
			typedef Alloc	allocator_type;
			typedef typename Alloc::reference &			reference;
			typedef typename Alloc::const_reference &	const_reference;
			typedef typename Alloc::pointer &			pointer;
			typedef typename Alloc::const_pointer &		const_pointer;

			typedef typename ft::Bidirectional<value_type, Alloc, PNode<Key, T, Compare, Alloc> >		iterator;
			typedef typename ft::Bidirectional<const value_type, Alloc, PNode<Key, T, Compare, Alloc> >	const_iterator;
			typedef typename ft::Reverse_Iterator<iterator>												reverse_iterator;
			typedef typename ft::Reverse_Iterator<const_iterator>										const_reverse_iterator;

			typedef std::ptrdiff_t	difference_type;
			typedef std::size_t		size_type;

		private:
			typedef typename allocator_type::template rebind<PNode<Key, T, Compare, Alloc> >::other	node_allocator;
			typedef	PNode<Key, T, Compare, Alloc>	node;

		/* --- Member attributes --- */
		private:
			key_compare		_compare;
			allocator_type	_alloc;
			node_allocator	_node_alloc;
			size_type		_size;
			node *			_root;
		
		/* --- Member functions --- */
		public:
		/* Constructor */
			/* empty	(1)	*/	explicit map(const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type());
			/* range	(2)	*/	template <class InputIterator>
								map(InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type());
			/* copy		(3)	*/	map(const map & x);

		/* Destructor */
			~map();

		/* Operators */
			/* assignation	(1)	*/	map &	operator=(map const & rhs);

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
			mapped_type &	operator[] (const key_type & k);

		/* Modifiers */
			/* single element	(1)	*/	std::pair<iterator, bool>	insert(const value_type & val);
			/* with hint		(2)	*/	iterator	insert(iterator position, const value_type & val);
			/* range			(3)	*/	template <class InputIterator>
										void	insert(InputIterator first, InputIterator last);

			/* (1)	*/	void		erase(iterator position);
			/* (2)	*/	size_type	erase(const key_type & k);
			/* (3)	*/	void		erase(iterator first, iterator last);

			void	swap(map & x);

			void	clear(void);

		/* Observers */
			key_compare		key_comp(void) const;

			value_compare	value_comp(void) const;
			
		/* Operations */
			/* (1)	*/	iterator		find (const key_type & k);
			/* (2)	*/	const_iterator	find (const key_type & k) const;

			size_type	count(const key_type & k) const;

			/* (1)	*/	iterator		lower_bound(const key_type & k);
			/* (2)	*/	const_iterator	lower_bound(const key_type & k) const;

 			/* (1)	*/	iterator 		upper_bound(const key_type & k);
			/* (2)	*/	const_iterator	upper_bound(const key_type & k) const;

			/* (1)	*/	std::pair<const_iterator, const_iterator>	equal_range (const key_type & k) const;
			/* (2)	*/	std::pair<iterator, iterator>				equal_range (const key_type & k);

		/* --- Private functions --- */
		private:
			value_type *	_try_add_node(value_type pair);
			node *			_create_node(value_type pair, bool is_end, node * parent = NULL, node * left = NULL, node * right = NULL);
			node *			_find_node(const value_type & pair) const;
			void			_reinsert_branch(PNode<Key, T, Compare, Alloc> * node);
			void			_destroy_branch(PNode<Key, T, Compare, Alloc> * node);
	};
}

# include "./Map.tpp"

#endif