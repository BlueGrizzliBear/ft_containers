#include "./Map.hpp"

/* Constructor */
/* empty	(1)	*/
template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map(const key_compare & comp, const allocator_type & alloc)
: _compare(comp), _alloc(alloc), _size(0), _root(_create_node(std::pair<Key, T>(), 1))
{}

/* range	(2)	*/
template <class Key, class T, class Compare, class Alloc>
template <class InputIterator>
ft::map<Key, T, Compare, Alloc>::map(InputIterator first, InputIterator last, const key_compare & comp, const allocator_type & alloc)
: _compare(comp), _alloc(alloc), _size(0), _root(_create_node(std::pair<Key, T>(), 1))
{
	InputIterator tmp;
	while (first != last)
	{
		tmp = first;
		first++;
		_try_add_node(*tmp);
	}
}

/* copy		(3)	*/
template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map(const map & x) : _compare(x._compare), _alloc(x._alloc), _size(0), _root(_create_node(std::pair<Key, T>(), 1))
{
	*this = x;
}

/* Destructor */
template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::~map(void)
{
	clear();
	_node_alloc.destroy(_root);
	_node_alloc.deallocate(_root, 1);		
	_root = NULL;
}


/* Operators */
/* assignation	(1)	*/
template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc> &	ft::map<Key, T, Compare, Alloc>::operator=(map const & rhs)
{
	if (this != &rhs)
	{
		clear();
		_compare = rhs._compare;

		const_iterator begin = rhs.begin();
		const_iterator end = rhs.end();
		for (; begin != end; begin++)
		{
			_try_add_node(begin.getCurrent()->pair);
		}
	}
	return (*this);
}


/* Iterators */
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator	ft::map<Key, T, Compare, Alloc>::begin(void)
{
	PNode<Key, T, Compare, Alloc> * tmp = _root;
	while (tmp->left && !tmp->left->is_end)
		tmp = tmp->left;
	return (iterator(tmp));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator	ft::map<Key, T, Compare, Alloc>::begin(void) const
{
	PNode<Key, T, Compare, Alloc> * tmp = _root;
	while (tmp->left && !tmp->left->is_end)
		tmp = tmp->left;
	return (const_iterator(tmp));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator	ft::map<Key, T, Compare, Alloc>::end(void)
{
	PNode<Key, T, Compare, Alloc> * tmp = _root;
	if (tmp->right)
	{
		while (tmp->right && !tmp->right->is_end)
			tmp = tmp->right;
		return (iterator(tmp->right));
	}
	return (iterator(tmp));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator	ft::map<Key, T, Compare, Alloc>::end(void) const
{
	PNode<Key, T, Compare, Alloc> * tmp = _root;
	if (tmp->right)
	{
		while (tmp->right && !tmp->right->is_end)
			tmp = tmp->right;
		return (const_iterator(tmp->right));
	}
	return (const_iterator(tmp));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::reverse_iterator	ft::map<Key, T, Compare, Alloc>::rbegin(void)
{
	PNode<Key, T, Compare, Alloc> * tmp = _root;
	while (tmp->right && !tmp->right->is_end)
		tmp = tmp->right;
	return (reverse_iterator(tmp));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator	ft::map<Key, T, Compare, Alloc>::rbegin(void) const
{
	PNode<Key, T, Compare, Alloc> * tmp = _root;
	while (tmp->right && !tmp->right->is_end)
		tmp = tmp->right;
	return (const_reverse_iterator(tmp));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::reverse_iterator	ft::map<Key, T, Compare, Alloc>::rend(void)
{
	PNode<Key, T, Compare, Alloc> * tmp = _root;
	if (tmp->left)
	{
		while (tmp->left && !tmp->left->is_end)
			tmp = tmp->left;
		return (reverse_iterator(tmp->left));
	}
	return (reverse_iterator(tmp));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator	ft::map<Key, T, Compare, Alloc>::rend(void) const
{
	PNode<Key, T, Compare, Alloc> * tmp = _root;
	if (tmp->left)
	{
		while (tmp->left && !tmp->left->is_end)
			tmp = tmp->left;
		return (const_reverse_iterator(tmp->left));
	}
	return (const_reverse_iterator(tmp));
}

/* Capacity */
template <class Key, class T, class Compare, class Alloc>
bool	ft::map<Key, T, Compare, Alloc>::empty(void) const
{ return (_size == 0); }

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type	ft::map<Key, T, Compare, Alloc>::size(void) const
{ return (_size); }

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type	ft::map<Key, T, Compare, Alloc>::max_size(void) const
{ return (_node_alloc.max_size()); }

/* Element access */
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::mapped_type &	ft::map<Key, T, Compare, Alloc>::operator[] (const key_type & k)
{
	return(_try_add_node(std::pair<Key, T>(k, mapped_type()))->second);
}

/* Modifiers */
/* single element	(1)	*/
template <class Key, class T, class Compare, class Alloc>
std::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool>	ft::map<Key, T, Compare, Alloc>::insert(const value_type & val)
{
	size_t size = _size;
	PNode<Key, T, Compare, Alloc> * ptr = _find_node(*_try_add_node(val));
	bool was_added = (_size == size ? 0 : 1);
	return (std::pair<iterator, bool>(iterator(ptr), was_added));
}

/* with hint		(2)	*/
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator	ft::map<Key, T, Compare, Alloc>::insert(iterator position, const value_type & val)
{
	PNode<Key, T, Compare, Alloc> * tmp_root = position.getCurrent();
	PNode<Key, T, Compare, Alloc> ** next = NULL;
	PNode<Key, T, Compare, Alloc> * end = NULL;
	bool	is_left = 0;

	while (!tmp_root->is_end)
	{
		if (_compare(val.first, tmp_root->pair.first))
			next = &(tmp_root->left);
		else if (_compare(tmp_root->pair.first, val.first))
		{
			if (tmp_root->parent && _compare(val.first, tmp_root->parent->pair.first))
				next = &(tmp_root->right);
			else
				next = &(tmp_root->parent);
		}
		else
			return (iterator(tmp_root));
		if (*next == NULL)
		{
			*next = _create_node(val, 0);
			++_size;
			(*next)->parent = tmp_root;
			return (iterator(*next));
		}
		else if ((*next)->is_end)
		{
			end = *next;
			if ((end)->parent->left == end)
				is_left = 1;
			*next = _create_node(val, 0);
			if (is_left)
				(*next)->left = end;
			else
				(*next)->right = end;
			(end)->parent = *next;
			++_size;
			(*next)->parent = tmp_root;
			return (iterator(*next));
		}
		tmp_root = *next;
	}
	return (insert(val).first);
}

/* range			(3)	*/
template <class Key, class T, class Compare, class Alloc>
template <class InputIterator>
void	ft::map<Key, T, Compare, Alloc>::insert(InputIterator first, InputIterator last)
{
	InputIterator tmp;

	while (first != last)
	{
		tmp = first;
		first++;
		insert(*tmp);
	}
}

/* (1)	*/
template <class Key, class T, class Compare, class Alloc>
void	ft::map<Key, T, Compare, Alloc>::erase(typename ft::map<Key, T, Compare, Alloc>::iterator position)
{
	PNode<Key, T, Compare, Alloc> * parent = position.getCurrent()->parent;
	bool was_left = parent && parent->left == position.getCurrent();
	bool was_right = parent && parent->right == position.getCurrent();
	PNode<Key, T, Compare, Alloc> * left = position.getCurrent()->left;
	PNode<Key, T, Compare, Alloc> * right = position.getCurrent()->right;

	_node_alloc.destroy(position.getCurrent());
	_node_alloc.deallocate(position.getCurrent(), 1);
	position = NULL;

	if (parent == NULL)
	{
		if (left && right)
		{
			if (!left->is_end && !right->is_end)
			{
				_root = right;
				right->parent = parent;
				_reinsert_branch(left);
			}
			else if (left->is_end && right->is_end)
			{
				_node_alloc.destroy(left);
				_node_alloc.deallocate(left, 1);
				left = NULL;
				_root = right;
			}
			else if (left->is_end)
			{
				PNode<Key, T, Compare, Alloc> * tmp = right;
				while (tmp->left)
					tmp = tmp->left;
				tmp->left = left;
				left->parent = tmp;
				_root = tmp;
				tmp->parent = NULL;
			}
			else if (right->is_end)
			{
				PNode<Key, T, Compare, Alloc> * tmp = left;
				while (tmp->right)
					tmp = tmp->right;
				tmp->right = right;
				right->parent = tmp;
				_root = tmp;
				tmp->parent = NULL;
			}
		}
		else if (left && !right)
		{
			_root = left;
			left->parent = parent;
		}
		else if (!left && right)
		{
			_root = right;
			right->parent = parent;
		}
	}
	else
	{
		if (was_left)
		{
			if (left && left->is_end)
			{
				parent->left = left;
				left->parent = parent;
			}
			else
				parent->left = NULL;
		}
		else if (was_right)
		{
			if (right && right->is_end)
			{
				parent->right = right;
				right->parent = parent;
			}
			else
				parent->right = NULL;
		}
		if (left && !left->is_end)
			_reinsert_branch(left);
		if (right && !right->is_end)
			_reinsert_branch(right);
	}
	--_size;
}

/* (2)	*/
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type	ft::map<Key, T, Compare, Alloc>::erase(const typename ft::map<Key, T, Compare, Alloc>::key_type & k)
{
	PNode<Key, T, Compare, Alloc> * tmp;
	size_type	number = 0;

	while ((tmp = _find_node(std::pair<Key, T>(k, T()))))
	{
		erase(iterator(tmp));
		number++;
	}
	return (number);
}

/* (3)	*/
template <class Key, class T, class Compare, class Alloc>
void	ft::map<Key, T, Compare, Alloc>::erase(typename ft::map<Key, T, Compare, Alloc>::iterator first, typename ft::map<Key, T, Compare, Alloc>::iterator last)
{
	iterator tmp;

	while (first != last)
	{
		tmp = first;
		++first;
		erase(tmp);
	}
}

template <class Key, class T, class Compare, class Alloc>
void	ft::map<Key, T, Compare, Alloc>::swap(map & x)
{
	ft::map<Key, T, Compare, Alloc> tmp(x);
	x = *this;
	*this = tmp;
}

template <class Key, class T, class Compare, class Alloc>
void	ft::map<Key, T, Compare, Alloc>::clear(void)
{
	_destroy_branch(_root);
	_root = _create_node(std::pair<Key, T>(), 1);
	_size = 0;
}


/* Observers */
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::key_compare	ft::map<Key, T, Compare, Alloc>::key_comp(void) const
{
	return (_compare);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::value_compare	ft::map<Key, T, Compare, Alloc>::value_comp(void) const
{
	return (value_compare(_compare));
}


/* Operations */
/* (1)	*/
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator	ft::map<Key, T, Compare, Alloc>::find(const typename ft::map<Key, T, Compare, Alloc>::key_type & k)
{
	std::pair<key_type, T> tmp(k, T());
	if (_find_node(tmp) == NULL || _find_node(tmp) == end().getCurrent())
		return (iterator(end()));
	return (iterator(_find_node(tmp)));
}

/* (2)	*/
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator	ft::map<Key, T, Compare, Alloc>::find(const typename ft::map<Key, T, Compare, Alloc>::key_type & k) const
{
	std::pair<key_type, T> const tmp(k, T());
	if (_find_node(tmp) == NULL || _find_node(tmp) == end().getCurrent())
		return (const_iterator(end()));
	return (const_iterator(_find_node(tmp)));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type	ft::map<Key, T, Compare, Alloc>::count(const typename ft::map<Key, T, Compare, Alloc>::key_type & k) const
{
	std::pair<key_type, T> tmp(k, T());
	if (_find_node(tmp) == NULL || _find_node(tmp) == end().getCurrent())
		return (0);
	return (1);
}

/* (1)	*/
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator	ft::map<Key, T, Compare, Alloc>::lower_bound(const typename ft::map<Key, T, Compare, Alloc>::key_type & k)
{
	iterator begin = this->begin();
	iterator end = this->end();

	while (begin != end)
	{
		if ((!_compare(k, begin->first) && !_compare(begin->first, k)) || (_compare(k, begin->first)))
			return (iterator(begin));
		++begin;
	}
	return (begin);
}

/* (2)	*/
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator	ft::map<Key, T, Compare, Alloc>::lower_bound(const typename ft::map<Key, T, Compare, Alloc>::key_type & k) const
{
	const_iterator begin = this->begin();
	const_iterator end = this->end();

	while (begin != end)
	{
		if ((!_compare(k, begin->first) && !_compare(begin->first, k)) || (_compare(k, begin->first)))
			return (const_iterator(begin));
		++begin;
	}
	return (begin);

}

/* (1)	*/
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator	ft::map<Key, T, Compare, Alloc>::upper_bound(const typename ft::map<Key, T, Compare, Alloc>::key_type & k)
{
	iterator begin = this->begin();
	iterator end = this->end();

	while (begin != end)
	{
		if (!_compare(begin->first, k) && !(!_compare(k, begin->first) && !_compare(begin->first, k)))
			return (iterator(begin));
		++begin;
	}
	return (begin);
}

/* (2)	*/
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator	ft::map<Key, T, Compare, Alloc>::upper_bound(const typename ft::map<Key, T, Compare, Alloc>::key_type & k) const
{
	const_iterator begin = this->begin();
	const_iterator end = this->end();

	while (begin != end)
	{
		if (!_compare(begin->first, k) && !(!_compare(k, begin->first) && !_compare(begin->first, k)))
			return (const_iterator(begin));
		++begin;
	}
	return (begin);
}

/* (1)	*/
template <class Key, class T, class Compare, class Alloc>
std::pair<typename ft::map<Key, T, Compare, Alloc>::const_iterator, typename ft::map<Key, T, Compare, Alloc>::const_iterator>	ft::map<Key, T, Compare, Alloc>::equal_range (const typename ft::map<Key, T, Compare, Alloc>::key_type & k) const
{
	return (std::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
}

/* (2)	*/
template <class Key, class T, class Compare, class Alloc>
std::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, typename ft::map<Key, T, Compare, Alloc>::iterator>	ft::map<Key, T, Compare, Alloc>::equal_range (const typename ft::map<Key, T, Compare, Alloc>::key_type & k)
{
	return (std::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
}


/* --- Private functions --- */
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::value_type *	ft::map<Key, T, Compare, Alloc>::_try_add_node(typename ft::map<Key, T, Compare, Alloc>::value_type pair)
{
	PNode<Key, T, Compare, Alloc> * tmp_root = _root;
	PNode<Key, T, Compare, Alloc> ** next = NULL;
	PNode<Key, T, Compare, Alloc> * end = NULL;
	bool	is_left = 0;

	if (tmp_root->is_end)
	{
		end = tmp_root;
		_root = _create_node(pair, 0);
		_root->left = end;
		_root->right = _create_node(std::pair<Key, T>(), 1);
		(_root->left)->parent = _root;
		(_root->right)->parent = _root;
		++_size;
	}
	while (!tmp_root->is_end)
	{
		if (_compare(pair.first, tmp_root->pair.first))
			next = &(tmp_root->left);
		else if (_compare(tmp_root->pair.first, pair.first))
			next = &(tmp_root->right);
		else
			return (&(tmp_root->pair));
		if (*next == NULL)
		{
			*next = _create_node(pair, 0);
			++_size;
			(*next)->parent = tmp_root;
			return (&((*next)->pair));
		}
		else if ((*next)->is_end)
		{
			end = *next;
			if ((*next)->parent->left == end)
				is_left = 1;
			*next = _create_node(pair, 0);
			if (is_left)
				(*next)->left = end;
			else
				(*next)->right = end;
			(end)->parent = *next;
			++_size;
			(*next)->parent = tmp_root;
			return (&((*next)->pair));
		}
		tmp_root = *next;
	}
	return (&_root->pair);
}

template <class Key, class T, class Compare, class Alloc>
ft::PNode<Key, T, Compare, Alloc> *	ft::map<Key, T, Compare, Alloc>::_create_node(typename ft::map<Key, T, Compare, Alloc>::value_type pair, bool is_end)
{
	PNode<Key, T, Compare, Alloc> * new_node = _node_alloc.allocate(static_cast<size_type>(1));
	_node_alloc.construct(new_node, PNode<Key, T, Compare, Alloc>(pair.first, pair.second, is_end));
	return (new_node);
}

template <class Key, class T, class Compare, class Alloc>
ft::PNode<Key, T, Compare, Alloc> *	ft::map<Key, T, Compare, Alloc>::_find_node(const value_type & pair) const
{
	PNode<Key, T, Compare, Alloc> * tmp_root = _root;
	PNode<Key, T, Compare, Alloc> ** next = NULL;

	if (!_root)
		return (_root);
	while (tmp_root)
	{
		if (_compare(pair.first, tmp_root->pair.first))
			next = &(tmp_root->left);
		else if (_compare(tmp_root->pair.first, pair.first))
			next = &(tmp_root->right);
		else
			return (tmp_root);
		if (*next == NULL)
			return (*next);
		tmp_root = *next;
	}
	return (tmp_root);
}

template <class Key, class T, class Compare, class Alloc>
void	ft::map<Key, T, Compare, Alloc>::_reinsert_branch(PNode<Key, T, Compare, Alloc> * node)
{
	PNode<Key, T, Compare, Alloc> * tmp_root = _root;
	PNode<Key, T, Compare, Alloc> ** next = NULL;
	PNode<Key, T, Compare, Alloc> * end = NULL;
	bool	is_left = 0;

	if (tmp_root->is_end)
	{
		end = tmp_root;
		_root = node;
		_root->left = end;
		_root->right = _create_node(std::pair<Key, T>(), 1);
		(_root->left)->parent = _root;
		(_root->right)->parent = _root;
	}
	while (!tmp_root->is_end)
	{
		
		if (_compare(node->pair.first, tmp_root->pair.first))
			next = &(tmp_root->left);
		else if (_compare(tmp_root->pair.first, node->pair.first))
			next = &(tmp_root->right);
		else
			return ;
		if (*next == NULL)
		{
			*next = node;
			(*next)->parent = tmp_root;
			return ;
		}
		else if ((*next)->is_end)
		{
			end = *next;
			if ((*next)->parent->left == end)
				is_left = 1;
			*next = node;
			if (is_left)
				(*next)->left = end;
			else
				(*next)->right = end;
			(end)->parent = *next;
			(*next)->parent = tmp_root;
			return ;
		}
		tmp_root = *next;
	}
	return ;
}

template <class Key, class T, class Compare, class Alloc>
void	ft::map<Key, T, Compare, Alloc>::_destroy_branch(PNode<Key, T, Compare, Alloc> * node)
{
	if (node)
	{
		if (node->left)
			_destroy_branch(node->left);
		if (node->right)
			_destroy_branch(node->right);
		_node_alloc.destroy(node);
		_node_alloc.deallocate(node, 1);
		node = NULL;
	}
}
