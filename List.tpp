#include "./List.hpp"

/* Constructor */
/* default	(1)	*/
template <typename Type, class Alloc>
ft::list<Type, Alloc>::list(const allocator_type & alloc) : _alloc(alloc), _size(0), _end(_node_alloc.allocate(1))
{
	_end->next = NULL;
	_end->prev = NULL;
	_update();
}

/* fill		(2)	*/
template <typename Type, class Alloc>
ft::list<Type, Alloc>::list(size_type n, const value_type & val, const allocator_type & alloc)
: _alloc(alloc), _size(0), _end(_add_node(value_type(), NULL, NULL))
{
	_add_n_values_from_int(n, val);
	_update();
}

/* range	(3)	*/
template <typename Type, class Alloc>
template <class InputIterator>
ft::list<Type, Alloc>::list(InputIterator first, InputIterator last, const allocator_type & alloc) : _alloc(alloc), _size(0), _end(_node_alloc.allocate(1))
{
	_add_values_from_iterators(first, last, typename ft::is_integral<InputIterator>::type());
	_update();
}

/* copy		(4)	*/
template <typename Type, class Alloc>
ft::list<Type, Alloc>::list(const list & cpy) : _size(0), _end(_node_alloc.allocate(1))
{ *this = cpy; }


/* Destructor */
template <typename Type, class Alloc>
ft::list<Type, Alloc>::~list(void)
{
	clear();
	_node_alloc.destroy(_end);
	_node_alloc.deallocate(_end, 1);
}


/* Operators */
/* assignation	(1)	*/
template <typename Type, class Alloc>
ft::list<Type, Alloc> &	ft::list<Type, Alloc>::operator=(list const & rhs)
{
	if (this != &rhs)
	{
		clear();
		_alloc = rhs._alloc;
		_node_alloc = rhs._node_alloc;
		DLNode<Type, Alloc> * tmp = rhs._head;
		while (tmp != rhs._end)
		{
			push_back(tmp->val);
			tmp = tmp->next;
		}
	}
	return (*this);
}


/* Iterators */
template <typename Type, class Alloc>
typename ft::list<Type, Alloc>::iterator				ft::list<Type, Alloc>::begin(void)
{ return (iterator(_head)); }

template <typename Type, class Alloc>
typename ft::list<Type, Alloc>::const_iterator		ft::list<Type, Alloc>::begin(void) const
{ return (const_iterator(_head)); }

template <typename Type, class Alloc>
typename ft::list<Type, Alloc>::iterator				ft::list<Type, Alloc>::end(void)
{ return (iterator(_end)); }

template <typename Type, class Alloc>
typename ft::list<Type, Alloc>::const_iterator				ft::list<Type, Alloc>::end(void) const
{ return (const_iterator(_end)); }

template <typename Type, class Alloc>
typename ft::list<Type, Alloc>::reverse_iterator				ft::list<Type, Alloc>::rbegin(void)
{ return (reverse_iterator(_tail)); }

template <typename Type, class Alloc>
typename ft::list<Type, Alloc>::const_reverse_iterator		ft::list<Type, Alloc>::rbegin(void) const
{ return (const_reverse_iterator(_tail)); }

template <typename Type, class Alloc>
typename ft::list<Type, Alloc>::reverse_iterator				ft::list<Type, Alloc>::rend(void)
{ return (reverse_iterator(_end)); }

template <typename Type, class Alloc>
typename ft::list<Type, Alloc>::const_reverse_iterator				ft::list<Type, Alloc>::rend(void) const
{ return (const_reverse_iterator(_end)); }


/* Capacity */
template <typename Type, class Alloc>
bool	ft::list<Type, Alloc>::empty(void) const
{ return (_size == 0); }

template <typename Type, class Alloc>
typename ft::list<Type, Alloc>::size_type	ft::list<Type, Alloc>::size(void) const
{ return (_size); }

template <typename Type, class Alloc>
typename ft::list<Type, Alloc>::size_type	ft::list<Type, Alloc>::max_size(void) const
{ return (_node_alloc.max_size()); }


/* Element access */
template <typename Type, class Alloc>
typename ft::list<Type, Alloc>::reference	ft::list<Type, Alloc>::front(void)
{
	return (_head->val);
}

template <typename Type, class Alloc>
typename ft::list<Type, Alloc>::const_reference	ft::list<Type, Alloc>::front(void) const
{
	return (_head->val);	
}

template <typename Type, class Alloc>
typename ft::list<Type, Alloc>::reference	ft::list<Type, Alloc>::back(void)
{
	return (_tail->val);
}

template <typename Type, class Alloc>
typename ft::list<Type, Alloc>::const_reference	ft::list<Type, Alloc>::back(void) const
{
	return (_tail->val);
}


/* Modifiers */
/* range	(1)	*/
template <typename Type, class Alloc>
template <class InputIterator>
void	ft::list<Type, Alloc>::assign(InputIterator first, InputIterator last)
{
	clear();
	_add_values_from_iterators(first, last, typename ft::is_integral<InputIterator>::type());
	_update();
}
	
/* fill		(2)	*/
template <typename Type, class Alloc>
void	ft::list<Type, Alloc>::assign(size_type n, const value_type & val)
{
	clear();
	_add_n_values_from_int(n, val);
	_update();
}

template <typename Type, class Alloc>
void	ft::list<Type, Alloc>::push_front(const value_type & val)
{
	if (empty())
		_head = _tail = _add_node(val, NULL, NULL);
	else
	{
		DLNode<Type, Alloc> * n = _add_node(val, _end, _head);
		_head->prev = n;
		_head = n;
	}
	++_size;
	_update();
}

template <typename Type, class Alloc>
void	ft::list<Type, Alloc>::pop_front(void)
{
	if (!empty())
	{
		DLNode<Type, Alloc> * old_head = _head;
		_head = _head->next;
		_node_alloc.destroy(old_head);
		_node_alloc.deallocate(old_head, 1);
		--_size;
		_update();
	}
}

template <typename Type, class Alloc>
void	ft::list<Type, Alloc>::push_back(const value_type & val)
{
	if (empty())
		_head = _tail = _add_node(val, NULL, NULL);
	else
	{
		DLNode<Type, Alloc> * n = _add_node(val, _tail, _end);
		_tail->next = n;
		_tail = n;
	}
	++_size;
	_update();
}

template <typename Type, class Alloc>
void	ft::list<Type, Alloc>::pop_back(void)
{
	if (!empty())
	{
		DLNode<Type, Alloc> * old_tail = _tail;
		_tail = _tail->prev;
		_node_alloc.destroy(old_tail);
		_node_alloc.deallocate(old_tail, 1);
		--_size;
		_update();
	}
}

/* single element	(1)	*/
template <typename Type, class Alloc>
typename ft::list<Type, Alloc>::iterator	ft::list<Type, Alloc>::insert(iterator position, const value_type & val)
{
	DLNode<Type, Alloc> * n = _add_node(val, position.getCurrent()->prev, position.getCurrent());
	position.getCurrent()->prev->next = n;
	position.getCurrent()->prev = n;
	_head = _end->next;
	_tail = _end->prev;
	++_size;
	_update();
	return (iterator(n));
}

/* fill				(2)	*/
template <typename Type, class Alloc>
void		ft::list<Type, Alloc>::insert(iterator position, size_type n, const value_type & val)
{
	for (size_type i = 0; i < n; i++)
		insert(position, val);
}

/* range			(3)	*/
template <typename Type, class Alloc>
template <class InputIterator>
void		ft::list<Type, Alloc>::insert(iterator position, InputIterator first, InputIterator last)
{
	_insert_values_from_iterators(position, first, last, typename ft::is_integral<InputIterator>::type());
}

/* single element	(1)	*/
template <typename Type, class Alloc>
typename ft::list<Type, Alloc>::iterator	ft::list<Type, Alloc>::erase(iterator position)
{
	if (position.getCurrent() == _end)
		return (position.getCurrent()->next);
	iterator	tmp(position.getCurrent()->next);
	position.getCurrent()->prev->next = position.getCurrent()->next;
	position.getCurrent()->next->prev = position.getCurrent()->prev;
	_head = _end->next;
	_tail = _end->prev;
	_node_alloc.destroy(position.getCurrent());
	_node_alloc.deallocate(position.getCurrent(), 1);
	--_size;
	return (tmp);
}

/* range			(2)	*/
template <typename Type, class Alloc>
typename ft::list<Type, Alloc>::iterator	ft::list<Type, Alloc>::erase(iterator first, iterator last)
{
	while (first != last)
	{
		iterator tmp(first.getCurrent()->next);
		erase(first);
		first = tmp;
	}
	return (last);
}

template <typename Type, class Alloc>
void	ft::list<Type, Alloc>::swap(list & x)
{
	list tmp(x);
	x = *this;
	*this = tmp;
}

template <typename Type, class Alloc>
void	ft::list<Type, Alloc>::resize(size_type n, value_type val)
{
	if (n > _size)
	{
		for (size_t i = _size; i < n; i++)
			push_back(val);
	}
	else if (n < _size)
	{
		size_type tmp(_size);
		for (size_type i = n; i < tmp; i++)
			pop_back();
	}
	_update();
}

template <typename Type, class Alloc>
void	ft::list<Type, Alloc>::clear(void)
{
	while (!empty())
		pop_front();
	_update();
}

/* Operations */
/* entire list		(1)	*/
template <typename Type, class Alloc>
void	ft::list<Type, Alloc>::splice(iterator position, list& x)
{
	if (!x.empty())
	{
		x._head->prev = position.getCurrent()->prev;
		x._tail->next = position.getCurrent();
		
		if (!empty())
		{
			position.getCurrent()->prev->next = x._head;
			position.getCurrent()->prev = x._tail;
		}
		else
		{
			position.getCurrent()->prev = x._tail;
			position.getCurrent()->next = x._head;
		}

		_size += x._size;
		_head = _end->next;
		_tail = _end->prev;

		x._size = 0;
		x._head = x._tail = x._end;
	}
}

/* single element	(2)	*/
template <typename Type, class Alloc>
void	ft::list<Type, Alloc>::splice(iterator position, list& x, iterator i)
{
	if (!x.empty())
	{
		i.getCurrent()->prev->next = i.getCurrent()->next;
		i.getCurrent()->next->prev = i.getCurrent()->prev;

		x._size--;
		if (x.empty())
			x._head = x._tail = x._end;
		else
		{	x._head = x._end->next;
			x._tail = x._end->prev;
		}

		if (empty())
		{
			i.getCurrent()->prev = position.getCurrent();
			i.getCurrent()->next = position.getCurrent();
		}
		else
		{
			i.getCurrent()->prev = position.getCurrent()->prev;
			i.getCurrent()->next = position.getCurrent();
		}

		if (empty())
		{
			position.getCurrent()->prev = i.getCurrent();
			position.getCurrent()->next = i.getCurrent();
			_head = _tail = i.getCurrent();
		}
		else
		{
			position.getCurrent()->prev->next = i.getCurrent();
			position.getCurrent()->prev = i.getCurrent();
			_head = _end->next;
			_tail = _end->prev;
		}
		_size++;
	}
}

/* element range	(3)	*/
template <typename Type, class Alloc>
void	ft::list<Type, Alloc>::splice(iterator position, list& x, iterator first, iterator last)
{
	size_t tmp = 0;
	iterator	tmp_first(first);

	while (tmp_first != last)
	{
		tmp_first++;
		tmp++;
	}
	while (tmp != 0)
	{
		tmp--;
		iterator tmp(first.getCurrent()->next);
		splice(position, x, first);
		first = tmp;
	}
}


template <typename Type, class Alloc>
void	ft::list<Type, Alloc>::remove(const value_type & val)
{
	iterator	begin = this->begin();
	iterator	end = this->end();
	iterator	tmp;
	while (begin != end)
	{
		tmp = begin;
		begin++;
		if (tmp.getCurrent()->val == val)
			erase(tmp);
	}
}

template <typename Type, class Alloc>
template <class Predicate>
void	ft::list<Type, Alloc>::remove_if(Predicate pred)
{
	iterator	begin = this->begin();
	iterator	end = this->end();
	iterator	tmp;

	while (begin != end)
	{
		tmp = begin;
		begin++;
		if (pred(tmp.getCurrent()->val))
			erase(tmp);
	}
}

/*	(1)	*/
template <typename Type, class Alloc>
void	ft::list<Type, Alloc>::unique(void)
{
	iterator	begin = this->begin();
	iterator	end = this->end();
	iterator	tmp;
	iterator	begin_next = this->begin();

	while (_size > 1 && begin != end && begin.getCurrent()->next != end.getCurrent())
	{
		tmp = begin;
		begin++;
		if ((*tmp) == tmp.getCurrent()->next->val)
			erase(tmp);
	}
}

/*	(2)	*/
template <typename Type, class Alloc>
template <class BinaryPredicate>
void	ft::list<Type, Alloc>::unique(BinaryPredicate binary_pred)
{
	iterator	begin = this->begin();
	iterator	end = this->end();
	iterator	tmp;

	while (_size > 1 && begin != end && begin.getCurrent()->next != end.getCurrent())
	{
		tmp = begin.getCurrent()->next;
		if (binary_pred(tmp.getCurrent()->val, begin.getCurrent()->val))
			erase(tmp);
		else
			begin++;
	}
}

/*	(1)	*/
template <typename Type, class Alloc>
void	ft::list<Type, Alloc>::merge(list& x)
{
	if (&x != this)
	{
		iterator	xbegin = x.begin(), xend = x.end();
		iterator	begin, end;
		iterator	tmp1, tmp2;

		while (xbegin != xend)
		{
			tmp1 = xbegin;
			xbegin++;
			begin = this->begin();	
			end = this->end();
			while (begin != end && (*tmp1) >= (*begin))
				begin++;
			tmp2 = begin;
			splice(tmp2, x, tmp1);
			_update();
		}
	}
}

/*	(2)	*/
template <typename Type, class Alloc>
template <class Compare>
void	ft::list<Type, Alloc>::merge(list& x, Compare comp)
{
	if (&x != this)
	{
		iterator	xbegin = x.begin(), xend = x.end();
		iterator	begin, end;
		iterator	tmp1, tmp2;

		while (xbegin != xend)
		{
			tmp1 = xbegin;
			xbegin++;
			begin = this->begin();	
			end = this->end();
			while (begin != end && !comp(*tmp1, *begin))
				begin++;
			tmp2 = begin;
			splice(tmp2, x, tmp1);
		}
	}
}

/*	(1)	*/
template <typename Type, class Alloc>
void	ft::list<Type, Alloc>::sort(void)
{
	sort(std::less<Type>());
}

/*	(2)	*/
template <typename Type, class Alloc>
template <class Compare>
void	ft::list<Type, Alloc>::sort(Compare comp)
{
	ft::list<Type, Alloc> result;

	ft::list<Type, Alloc> tmp;
	iterator	tmp_end(tmp.end());
	
	iterator	end(this->end());
	iterator	it;

	if (size() > 1)
	{
		--end;
		while (!empty())
		{
			it = end;
			--end;
			tmp.splice(tmp_end, *this, it);
			result.merge(tmp, comp);
		}
		splice(this->end(), result);
	}
}

template <typename Type, class Alloc>
void	ft::list<Type, Alloc>::reverse(void)
{
	ft::list<Type, Alloc> result;

	iterator	begin(this->end());	begin--;
	iterator	end(this->end());
	iterator	tmp;

	if (size() > 1)
	{
		while (begin != end)
		{
			iterator tmp(begin.getCurrent());
			begin--;
			result.splice(result.end(), *this, tmp);
		}
		splice(this->end(), result, result.begin(), result.end());
	}
}

/* Observers -- not implemented -- */
// allocator_type	get_allocator(void) const;

/* --- Private functions --- */
template <typename Type, class Alloc>
void	ft::list<Type, Alloc>::_update(void)
{
	_end->next = _head;
	_end->prev = _tail;
	if (!empty())
	{
		_head->prev = _end;
		_tail->next = _end;
	}
	else
		_head = _tail = _end;
}

template <typename Type, class Alloc>
void	ft::list<Type, Alloc>::_add_n_values_from_int(size_t n, const value_type & val)
{
	for (size_t i = 0; i < n; i++)
		push_front(val);
}

template <typename Type, class Alloc>
template <class InputIterator>
void	ft::list<Type, Alloc>::_add_values_from_iterators(InputIterator & first, InputIterator & last, void *)
{
	while (first != last)
	{
		push_back(*first);
		first++;
	}
}

template <typename Type, class Alloc>
template <class InputIterator>
void	ft::list<Type, Alloc>::_add_values_from_iterators(InputIterator & first, InputIterator & last, int)
{
	*this = list(static_cast<size_type>(first), static_cast<value_type>(last));
}

template <typename Type, class Alloc>
ft::DLNode<Type, Alloc> *	ft::list<Type, Alloc>::_add_node(const value_type & val, DLNode<Type, Alloc> *prev, DLNode<Type, Alloc> *next)
{

	DLNode<Type, Alloc> * _n = _node_alloc.allocate(1);
	try
	{
		_node_alloc.construct(_n, DLNode<Type, Alloc>(val, prev, next));
	}
	catch(std::exception & e)
	{
		_node_alloc.deallocate(_n, 1);
		throw;
	}
	return (_n);
}

template <typename Type, class Alloc>
template <class InputIterator>
void	ft::list<Type, Alloc>::_insert_values_from_iterators(iterator position, InputIterator & first, InputIterator & last, void *)
{
	while (first != last)
	{
		insert(position, *first);
		first++;
	}
}

template <typename Type, class Alloc>
template <class InputIterator>
void	ft::list<Type, Alloc>::_insert_values_from_iterators(iterator position, InputIterator & first, InputIterator & last, int)
{
	insert(position, static_cast<size_type>(first), static_cast<value_type>(last));
}


/* --- Non-member function overloads --- */
/*	(1)	*/
template <class T, class Alloc>
bool	ft::operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	
	typename ft::list<T, Alloc>::const_iterator lhs_begin = lhs.begin();
	typename ft::list<T, Alloc>::const_iterator lhs_end = lhs.end();
	typename ft::list<T, Alloc>::const_iterator rhs_begin = rhs.begin();
	while (lhs_begin != lhs_end)
	{
		if (!(*lhs_begin == *rhs_begin))
			return (false);
		++lhs_begin;
		++rhs_begin;
	}
	return (true);
}

/*	(2)	*/
template <class T, class Alloc>
bool	ft::operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{ return (!(lhs == rhs)); }

/*	(3)	*/
template <class T, class Alloc>
bool	ft::operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	typename ft::list<T, Alloc>::const_iterator lhs_begin = lhs.begin();
	typename ft::list<T, Alloc>::const_iterator lhs_end = lhs.end();
	typename ft::list<T, Alloc>::const_iterator rhs_begin = rhs.begin();
	typename ft::list<T, Alloc>::const_iterator rhs_end = rhs.end();

	/* Lexicographical_compare */
	while (lhs_begin != lhs_end)
	{
		if (rhs_begin == rhs_end || *rhs_begin < *lhs_begin)
			return (false);
		else if (*lhs_begin < *rhs_begin)
			return (true);
		++lhs_begin;
		++rhs_begin;
	}
	return (rhs_begin != rhs_end);
}

/*	(4)	*/
template <class T, class Alloc>
bool	ft::operator<=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{ return (!(rhs < lhs)); }

/*	(5)	*/
template <class T, class Alloc>
bool	ft::operator>(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{ return (rhs < lhs); }

/*	(6)	*/
template <class T, class Alloc>
bool	ft::operator>=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{ return (!(lhs < rhs)); }

template <class T, class Alloc>
void	ft::swap(list<T,Alloc>& x, list<T,Alloc>& y)
{
	x.swap(y);
}