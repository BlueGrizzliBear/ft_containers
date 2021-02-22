#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iostream>
#include <memory>
#include <iterator>
#include <cstddef>
#include <cstdlib>

namespace ft
{
	/* ========= Basic Iterators : Class declarations ========= */

	/* iterator categories declaration */
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	/* iterator_traits declaration */
	template<class Iterator>
	struct iterator_traits_from_it
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits
	{
		typedef ptrdiff_t	difference_type;
		typedef T			value_type;
		typedef T *			pointer;
		typedef T &			reference;
	};
	
	template <class T>
	struct iterator_traits<const T>
	{
		typedef ptrdiff_t	difference_type;
		typedef T			value_type;
		typedef const T *	pointer;
		typedef const T &	reference;
	};
	

	/* BaseIterator Class declaration */
	template <class Type, class Alloc, class Node>
	class BaseIterator
	{
		protected:
		/* --- Member attributes --- */
			Node *	_current;

		public:
		/* --- Member types --- */
			typedef typename ft::iterator_traits<Type>::difference_type	difference_type;
			typedef typename ft::iterator_traits<Type>::value_type		value_type;
			typedef typename ft::iterator_traits<Type>::pointer			pointer;
			typedef typename ft::iterator_traits<Type>::reference		reference;

		/* --- Member functions --- */
		/* Constructor */
			/* default	(1)	*/	BaseIterator(Node * node = NULL);
			/* copy		(2)	*/	BaseIterator(BaseIterator<value_type, Alloc, Node> const & cpy);

		/* Destructor */
			~BaseIterator();

		/* Element access */
			Node *	getCurrent(void) const;

		/* Operators */
			/* assignation	(1)	*/	BaseIterator &	operator=(BaseIterator const & rhs);
			/* equality		(2)	*/	bool			operator==(BaseIterator const & rhs) const;
			/* inequality	(3)	*/	bool			operator!=(BaseIterator const & rhs) const;
	};
	/* --- Non-member function overloads --- */
	/* relationnal Operators (BaseIterator) */
		/*	(1)	*/	template <class Type, class Alloc, class Node>
					bool	operator==(const BaseIterator<Type, Alloc, Node>& lhs, const BaseIterator<Type, Alloc, Node>& rhs);
		/*	(2)	*/	template <class Type, class Alloc, class Node>
					bool	operator!=(const BaseIterator<Type, Alloc, Node>& lhs, const BaseIterator<Type, Alloc, Node>& rhs);
		/*	(3)	*/	template <class Type, class Alloc, class Node>
					bool	operator<(const BaseIterator<Type, Alloc, Node>& lhs, const BaseIterator<Type, Alloc, Node>& rhs);
		/*	(4)	*/	template <class Type, class Alloc, class Node>
					bool	operator<=(const BaseIterator<Type, Alloc, Node>& lhs, const BaseIterator<Type, Alloc, Node>& rhs);
		/*	(5)	*/	template <class Type, class Alloc, class Node>
					bool	operator>(const BaseIterator<Type, Alloc, Node>& lhs, const BaseIterator<Type, Alloc, Node>& rhs);
		/*	(6)	*/	template <class Type, class Alloc, class Node>
					bool	operator>=(const BaseIterator<Type, Alloc, Node>& lhs, const BaseIterator<Type, Alloc, Node>& rhs);


	/* Bidirectionnal Class declaration */
	template <class Type, class Alloc, class Node>
	class Bidirectional : public BaseIterator<typename ft::iterator_traits<Type>::value_type, Alloc, Node>
	{
		public:
		/* --- Member types --- */
			typedef Alloc	alloc_type;
			typedef Node	node_type;
			typedef typename ft::iterator_traits<Type>::difference_type	difference_type;
			typedef typename ft::iterator_traits<Type>::value_type		value_type;
			typedef typename ft::iterator_traits<Type>::pointer			pointer;
			typedef typename ft::iterator_traits<Type>::reference		reference;
			typedef bidirectional_iterator_tag	iterator_category;

		/* --- Member functions --- */
		/* Constructor */
			/* default	(1)	*/	Bidirectional(Node * node = NULL);
			/* copy		(2)	*/	Bidirectional(Bidirectional<value_type, Alloc, Node> const & cpy);
			// /* base		(3)	*/	Bidirectional(BaseIterator<Type, Alloc, Node> const & cpy);

		/* Destructor */
			virtual ~Bidirectional();

		/* Conversions before operations  */
			reference	_deref_val(value_type * type) const;
			template <class OtherClass>
			reference	_deref_val(OtherClass * other_class) const;
			
			pointer	_ref_val(value_type *) const;
			template <class OtherClass>
			pointer	_ref_val(OtherClass *) const;
			
			void	_pre_incr(value_type *);
			template <class OtherClass>
			void	_pre_incr(OtherClass *);
			
			void	_pre_decr(value_type *);
			template <class OtherClass>
			void	_pre_decr(OtherClass *);

		/* Operators */
			/* dereference	(4)	*/	reference	operator*(void) const;
			/* reference	(5)	*/	pointer		operator->(void) const;

			/* pre-increment	(6)	*/	Bidirectional &	operator++(void);
			/* post-increment	(7)	*/	Bidirectional	operator++(int);

			/* pre-decrement	(8)	*/	Bidirectional &	operator--(void);
			/* post-decrement	(9)	*/	Bidirectional	operator--(int);
	};

	/* RandomAccess Class declaration */
	template <class Type, class Alloc, class Node>
	class RandomAccess : public Bidirectional<typename ft::iterator_traits<Type>::value_type, Alloc, Node>
	{
		public:
		/* --- Member types --- */
			typedef Alloc	alloc_type;
			typedef Node	node_type;
			typedef typename ft::iterator_traits<Type>::value_type		value_type;
			typedef typename ft::iterator_traits<Type>::pointer			pointer;
			typedef typename ft::iterator_traits<Type>::reference		reference;
			typedef typename ft::iterator_traits<Type>::difference_type	difference_type;
			typedef random_access_iterator_tag	iterator_category;

		/* --- Member functions --- */
		/* Constructor */
			/* default	(1)	*/	RandomAccess(Node * node = NULL);
			/* copy		(2)	*/	RandomAccess(RandomAccess<value_type, Alloc, Node> const & cpy);
			/* copy		(3)	*/	RandomAccess(Bidirectional<value_type, Alloc, Node> const & cpy);
			// /* base		(3)	*/	RandomAccess(BaseIterator<Type, Alloc, Node> const & cpy);

		/* Destructor */
			virtual ~RandomAccess();

		/* Operators */
			/* unary plus				(10)	*/			RandomAccess	operator+(difference_type n) const;
			/* addition					(11)	*/	friend	RandomAccess	operator+(difference_type n, RandomAccess const & a)	{ return (RandomAccess(a.getCurrent() + n)); }
			/* unary minus				(12)	*/			RandomAccess	operator-(difference_type n) const;
			/* subtraction				(13)	*/			difference_type	operator-(RandomAccess const & b) const;
			/* less than				(14)	*/			bool			operator<(RandomAccess const & b) const;
			/* greater than 			(15)	*/			bool			operator>(RandomAccess const & b) const;
			/* less than or equal to	(16)	*/			bool			operator<=(RandomAccess const & b) const;
			/* greater than or equal to	(17)	*/			bool			operator>=(RandomAccess const & b) const;
			/* addition-assignement		(18)	*/			RandomAccess &	operator+=(difference_type n);
			/* subtraction-assignement	(19)	*/			RandomAccess &	operator-=(difference_type n);
			/* subscript				(20)	*/			reference		operator[](difference_type n) const;
	};

	/* Reverse_Iterator Class declaration */
	template <class Iter>
	class Reverse_Iterator
	{
		public:
		/* --- Member types --- */
			typedef Iter	iterator_type;
			typedef typename ft::iterator_traits_from_it<Iter>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits_from_it<Iter>::value_type			value_type;
			typedef typename ft::iterator_traits_from_it<Iter>::difference_type		difference_type;
			typedef typename ft::iterator_traits_from_it<Iter>::pointer				pointer;
			typedef typename ft::iterator_traits_from_it<Iter>::reference			reference;

		/* --- Member functions --- */
		/* Constructor */
			/* default			(1)	*/	Reverse_Iterator(void);
			/* initialization	(2)	*/	explicit Reverse_Iterator(iterator_type const & init);
			/* copy				(3)	*/	template <class It>
										Reverse_Iterator(const Reverse_Iterator<It> & cpy);

		/* Destructor */
			~Reverse_Iterator();

		/* Element access */
			iterator_type	base(void) const;

		/* Operators */
			/* assignation				(0)		*/	Reverse_Iterator &	operator=(Reverse_Iterator const & rhs);
			/* dereference				(1) 	*/	reference			operator*(void) const;
			/* unary plus				(2)		*/	Reverse_Iterator	operator+(difference_type n) const;
			/* pre-increment			(3)		*/	Reverse_Iterator &	operator++(void);
			/* post-increment			(4)		*/	Reverse_Iterator	operator++(int);
			/* addition-assignement		(5)		*/	Reverse_Iterator &	operator+=(difference_type n);
			/* unary minus				(6)		*/	Reverse_Iterator	operator-(difference_type n) const;
			/* pre-decrement			(7)		*/	Reverse_Iterator &	operator--(void);
			/* post-decrement			(8)		*/	Reverse_Iterator	operator--(int);
			/* subtraction-assignement	(9)		*/	Reverse_Iterator &	operator-=(difference_type n);
			/* reference				(10)	*/	pointer				operator->(void) const;
			/* subscript				(11)	*/	reference			operator[](difference_type n) const;

		protected:
		/* --- Member attributes --- */
			iterator_type	_base;
	};
	/* --- Non-member function overloads --- */
	/* relationnal Operators (Reverse_Iterator) */
		/*	(1)	*/	template <class Iter>
					bool	operator==(const Reverse_Iterator<Iter>& lhs, const Reverse_Iterator<Iter>& rhs);
		/*	(2)	*/	template <class Iter>
					bool	operator!=(const Reverse_Iterator<Iter>& lhs, const Reverse_Iterator<Iter>& rhs);
		/*	(3)	*/	template <class Iter>
					bool	operator<(const Reverse_Iterator<Iter>& lhs, const Reverse_Iterator<Iter>& rhs);
		/*	(4)	*/	template <class Iter>
					bool	operator<=(const Reverse_Iterator<Iter>& lhs, const Reverse_Iterator<Iter>& rhs);
		/*	(5)	*/	template <class Iter>
					bool	operator>(const Reverse_Iterator<Iter>& lhs, const Reverse_Iterator<Iter>& rhs);
		/*	(6)	*/	template <class Iter>
					bool	operator>=(const Reverse_Iterator<Iter>& lhs, const Reverse_Iterator<Iter>& rhs);
	/* operator+ (Reverse_Iterator) */
		/* addition		*/	template <class Iter>
							ft::Reverse_Iterator<Iter> operator+(typename ft::Reverse_Iterator<Iter>::difference_type n, const ft::Reverse_Iterator<Iter>& rev_it) { return (rev_it + n); }

	/* operator- (Reverse_Iterator) */
		/* subtraction	*/	template <class Iter>
							typename ft::Reverse_Iterator<Iter>::difference_type operator-(const ft::Reverse_Iterator<Iter>& lhs, const ft::Reverse_Iterator<Iter>& rhs) { return (rhs.base() - lhs.base()); }



	/* ========= Tools for containers : types ========= */

	/* Definition of which class is of integer type, for List Range-Constructor (explicit keyword creating havoc) */
	/* Inspired from how the range List Constructor checks the types in the STL */

	/*
	template <bool, class _Tp = void> struct _LIBCPP_TEMPLATE_VIS enable_if {};
	template <class _Tp> struct _LIBCPP_TEMPLATE_VIS enable_if<true, _Tp> {typedef _Tp type;};

	list(_InpIter __f, _InpIter __l, const allocator_type& __a,
			typename enable_if<__is_input_iterator<_InpIter>::value>::type* = 0);

	template<class _InputIterator,
	         class _Alloc = typename std::allocator<typename iterator_traits<_InputIterator>::value_type>,
	         class = typename enable_if<__is_allocator<_Alloc>::value, void>::type
	         >
	list(_InputIterator, _InputIterator)
	*/

	/* Definition of default template of is_integral */
	template <class T>	struct is_integral						{ typedef void *	type; };

	/* Definition of specialized template of is_integral */
	template <>         struct is_integral<bool>				{ typedef int		type; };
	template <>         struct is_integral<char>				{ typedef int		type; };
	template <>         struct is_integral<signed char>			{ typedef int		type; };
	template <>         struct is_integral<unsigned char>		{ typedef int		type; };
	template <>         struct is_integral<wchar_t>				{ typedef int		type; };
	// template <>         struct is_integral<char16_t>			{ typedef int		type; };
	// template <>         struct is_integral<char32_t>			{ typedef int		type; };
	template <>         struct is_integral<short>				{ typedef int		type; };
	template <>         struct is_integral<unsigned short>		{ typedef int		type; };
	template <>         struct is_integral<int>					{ typedef int		type; };
	template <>         struct is_integral<unsigned int>		{ typedef int		type; };
	template <>         struct is_integral<long>				{ typedef int		type; };
	template <>         struct is_integral<unsigned long>		{ typedef int		type; };
	template <>         struct is_integral<long long>			{ typedef int		type; };
	template <>         struct is_integral<unsigned long long>	{ typedef int		type; };
	// template <>         struct is_integral<__int128_t>			{ typedef int		type; };
	// template <>         struct is_integral<__uint128_t>			{ typedef int		type; };
}

#include "./Iterator.tpp"
#endif