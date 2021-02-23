#include "./main.hpp"

template <template <class T, class Alloc = std::allocator<T> > class container, class T>
std::stringstream *	test_list_container(std::string const & cont_name)
{
	container<T>	_cont;
	std::string 	test_name;
	static int		a = 0;

	switch (++a)
	{
/* Constructors */
		case 1: {	container<T> cont;
					test_name = "cont";
					_cont = cont;
					break;	}

		case 2: {	container<T> cont(0);
					test_name = "cont(0)";
					_cont = cont;
					break;	}

		case 3: {	container<T> cont(1);
					test_name = "cont(1)";
					_cont = cont;
					break;	}

		case 4: {	container<T> cont(5);
					test_name = "cont(5)";
					_cont = cont;
					break;	}

		case 5: {	container<T> cont(5, -1);
					test_name = "cont(5, -1)";
					_cont = cont;
					break;	}

		case 6: {	T Arr[] = {39, 40, 41, 42};
					container<T> cont(Arr, Arr + 4);
					test_name = "cont(Arr, Arr + 4)";
					_cont = cont;
					break;	}

		case 7: {	container<T> cont_cpy(5, 42);
					container<T> cont(cont_cpy);
					test_name = "cont2(cont_cpy)";
					_cont = cont;
					break;	}

/* Destructor */
		case 8: {	int * a = new int(42);
					container<T> *cont = new container<T>(3, *a);	delete cont;
					test_name = "*cont = new container<T>(3, a);	delete cont;";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " " + test_name << ENDL;
					*ss << "int a (should be persistent) = " << *a << ENDL << ENDL;
					delete a;
					return (ss); }

/* Operator= */
		case 9: {	container<T> cont(5, 42);	container<T> contbis(3, 23);	cont = contbis;
					test_name = "cont(5, 42);	container<T> contbis(3, 23);	cont = contbis;";
					_cont = cont;
					break;	}

		case 10: {	container<T> cont(5, 42);	container<T> contbis(0);	cont = contbis;
					test_name = "cont(5, 42);	container<T> contbis(0);	cont = contbis;";
					_cont = contbis;
					break;	}

/* Iterators */
	/* iterator : begin, end, iterating through iterators, operator-> and operator* */
		case 11: {	container<T> cont;
					test_name = "cont.begin() == cont.end()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (cont.begin() == cont.end()) << ENDL << ENDL;
					return (ss); }

		case 12: {	container<T> cont;	cont.push_front(42);	cont.push_front(23);
					typename container<T>::iterator begin = cont.begin();
					test_name = "*begin == cont.front()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_front(42);	cont.push_front(23);" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (*begin == cont.front()) << ENDL << ENDL;
					return (ss); }

		case 13: {	container<T> cont;	cont.push_front(42);	cont.push_front(23);
					typename container<T>::iterator end = cont.end();	--end;
					test_name = "*(--end) == cont.back()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_front(42);	cont.push_front(23);" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (*end == cont.back()) << ENDL << ENDL;
					return (ss); }

		case 14: {	container<T> cont;	cont.push_front(42);	cont.push_front(23);	cont.push_front(5);
					typename container<T>::iterator begin = cont.begin();
					typename container<T>::iterator end = cont.end();
					test_name = "Displaying list with ::iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_front(42);	cont.push_front(23);	cont.push_front(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << *begin << " ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 15: {	container<T> cont;	cont.push_front(42);	cont.push_front(23);
					typename container<T>::iterator begin = cont.begin();
					typename container<T>::iterator end = cont.end();	--end;
					test_name = "Display *(cont.begin()) and *(cont.end())";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_front(42);	cont.push_front(23);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 23) = " << *begin << ENDL;
					*ss << "Value (should be 42) = " << *end << ENDL << ENDL;
					return (ss); }

		case 16: {	container<T> * cont = new container<T>();	cont->push_front(42);	cont->push_front(23);
					typename container<T>::iterator begin = cont->begin();
					typename container<T>::iterator end = cont->end();	--end;
					test_name = "Display cont->begin() and cont->begin()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont = new container<T>();	cont->push_front(42);	cont->push_front(23);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 23) = " << *begin << ENDL;
					*ss << "Value (should be 42) = " << *end << ENDL << ENDL;
					delete cont;
					return (ss); }

	/* const_iterator : begin, end, iterating through iterators, operator-> and operator* */
		case 17: {	container<T> const cont;
					test_name = "cont.begin() == cont.end()";
					typename container<T>::const_iterator begin = cont.begin();
					typename container<T>::const_iterator end = cont.end();
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " const cont;" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (begin == end) << ENDL << ENDL;
					return (ss); }

		case 18: {	container<T> cont_tmp;	cont_tmp.push_front(42);	cont_tmp.push_front(23);	container<T> const cont(cont_tmp);
					typename container<T>::const_iterator begin = cont.begin();
					test_name = "*begin == cont.front()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont_tmp;	cont_tmp.push_front(42);	cont_tmp.push_front(23);	container<T> const cont(cont_tmp);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (*begin == cont.front()) << ENDL << ENDL;
					return (ss); }

		case 19: {	container<T> cont_tmp;	cont_tmp.push_front(42);	cont_tmp.push_front(23);	container<T> const cont(cont_tmp);
					typename container<T>::const_iterator end = cont.end();	--end;
					test_name = "*(--end) == cont.back()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont_tmp;	cont_tmp.push_front(42);	cont_tmp.push_front(23);	container<T> const cont(cont_tmp);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (*end == cont.back()) << ENDL << ENDL;
					return (ss); }

		case 20: {	container<T> cont_tmp;	cont_tmp.push_front(42);	cont_tmp.push_front(23);	container<T> const cont(cont_tmp);
					typename container<T>::const_iterator begin = cont.begin();
					typename container<T>::const_iterator end = cont.end();
					test_name = "Displaying list with ::iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont_tmp;	cont_tmp.push_front(42);	cont_tmp.push_front(23);	container<T> const cont(cont_tmp);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << *begin << " ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 21: {	container<T> cont_tmp;	cont_tmp.push_front(42);	cont_tmp.push_front(23);	container<T> const cont(cont_tmp);
					typename container<T>::const_iterator begin = cont.begin();
					typename container<T>::const_iterator end = cont.end();	--end;
					test_name = "Display *(cont.begin()) and *(cont.end())";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont_tmp;	cont_tmp.push_front(42);	cont_tmp.push_front(23);	container<T> const cont(cont_tmp);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 23) = " << *begin << ENDL;
					*ss << "Value (should be 42) = " << *end << ENDL << ENDL;
					return (ss); }

		case 22: {	container<T> * cont_tmp = new container<T>();	cont_tmp->push_front(42);	cont_tmp->push_front(23);	container<T> const * cont(cont_tmp);
					typename container<T>::const_iterator begin = cont->begin();
					typename container<T>::const_iterator end = cont->end();	--end;
					test_name = "Display cont->begin() and cont->begin()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont_tmp = new container<T>();	cont_tmp->push_front(42);	cont_tmp->push_front(23);	container<T> const * cont = new container<T>(cont_tmp);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 23) = " << *begin << ENDL;
					*ss << "Value (should be 42) = " << *end << ENDL << ENDL;
					delete cont_tmp;
					return (ss); }

	/* reverse_iterator : begin, end, iterating through iterators, operator-> and operator* */
		case 23: {	container<T> cont;
					test_name = "cont.rbegin() == cont.rend()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (cont.rbegin() == cont.rend()) << ENDL << ENDL;
					return (ss); }

		case 24: {	container<T> cont;	cont.push_front(42);	cont.push_front(23);
					typename container<T>::reverse_iterator rbegin = cont.rbegin();
					test_name = "*rbegin == cont.end()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_front(42);	cont.push_front(23);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (*rbegin == cont.back()) << ENDL << ENDL;
					return (ss); }

		case 25: {	container<T> cont;	cont.push_front(42);	cont.push_front(23);
					typename container<T>::reverse_iterator rend = cont.rend();	--rend;
					test_name = "*(--rend) == cont.front()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_front(42);	cont.push_front(23);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (*rend == cont.front()) << ENDL << ENDL;
					return (ss); }

		case 26: {	container<T> cont;	cont.push_front(42);	cont.push_front(23);	cont.push_front(5);
					typename container<T>::reverse_iterator rbegin = cont.rbegin();
					typename container<T>::reverse_iterator rend = cont.rend();
					test_name = "Displaying list with ::iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_front(42);	cont.push_front(23);	cont.push_front(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					while (rbegin != rend)
					{
						*ss << *rbegin << " ";
						++rbegin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 27: {	container<T> cont;	cont.push_front(42);	cont.push_front(23);
					typename container<T>::reverse_iterator rbegin = cont.rbegin();
					typename container<T>::reverse_iterator rend = cont.rend();	--rend;
					test_name = "Display *(cont.begin()) and *(cont.end())";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_front(42);	cont.push_front(23);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 23) = " << *rbegin << ENDL;
					*ss << "Value (should be 42) = " << *rend << ENDL << ENDL;
					return (ss); }

		case 28: {	container<T> * cont = new container<T>();	cont->push_front(42);	cont->push_front(23);
					typename container<T>::reverse_iterator rbegin = cont->rbegin();
					typename container<T>::reverse_iterator rend = cont->rend();	--rend;
					test_name = "Display cont->begin() and cont->begin()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont = new container<T>();	cont->push_front(42);	cont->push_front(23);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 23) = " << *rbegin << ENDL;
					*ss << "Value (should be 42) = " << *rend << ENDL << ENDL;
					delete cont;
					return (ss); }

	/* const_reverse_iterator : begin, end, iterating through iterators, operator-> and operator* */
		case 29: {	container<T> const cont;
					test_name = "cont.rbegin() == cont.rend()";
					typename container<T>::const_reverse_iterator begin = cont.rbegin();
					typename container<T>::const_reverse_iterator end = cont.rend();
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " const cont;" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (begin == end) << ENDL << ENDL;
					return (ss); }

		case 30: {	container<T> cont_tmp;	cont_tmp.push_front(42);	cont_tmp.push_front(23);	container<T> const cont(cont_tmp);
					typename container<T>::const_reverse_iterator rbegin = cont.rbegin();
					test_name = "*rbegin == cont.end()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont_tmp;	cont_tmp.push_front(42);	cont_tmp.push_front(23);	container<T> const cont(cont_tmp);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (*rbegin == cont.back()) << ENDL << ENDL;
					return (ss); }

		case 31: {	container<T> cont_tmp;	cont_tmp.push_front(42);	cont_tmp.push_front(23);	container<T> const cont(cont_tmp);
					typename container<T>::const_reverse_iterator rend = cont.rend();	--rend;
					test_name = "*(--rend) == cont.front()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont_tmp;	cont_tmp.push_front(42);	cont_tmp.push_front(23);	container<T> const cont(cont_tmp);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (*rend == cont.front()) << ENDL << ENDL;
					return (ss); }

		case 32: {	container<T> cont_tmp;	cont_tmp.push_front(42);	cont_tmp.push_front(23);	cont_tmp.push_front(5);	container<T> const cont(cont_tmp);
					typename container<T>::const_reverse_iterator rbegin = cont.rbegin();
					typename container<T>::const_reverse_iterator rend = cont.rend();
					test_name = "Displaying list with ::iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont_tmp;	cont_tmp.push_front(42);	cont_tmp.push_front(23);	cont_tmp.push_front(5);	container<T> const cont(cont_tmp);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					while (rbegin != rend)
					{
						*ss << *rbegin << " ";
						++rbegin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 33: {	container<T> cont_tmp;	cont_tmp.push_front(42);	cont_tmp.push_front(23);	container<T> const cont(cont_tmp);
					typename container<T>::const_reverse_iterator rbegin = cont.rbegin();
					typename container<T>::const_reverse_iterator rend = cont.rend();	--rend;
					test_name = "Display *(cont.begin()) and *(cont.end())";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont_tmp;	cont_tmp.push_front(42);	cont_tmp.push_front(23);	container<T> const cont(cont_tmp);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 23) = " << *rbegin << ENDL;
					*ss << "Value (should be 42) = " << *rend << ENDL << ENDL;
					return (ss); }

		case 34: {	container<T> * cont_tmp = new container<T>();	cont_tmp->push_front(42);	cont_tmp->push_front(23);	container<T> const * cont(cont_tmp);
					typename container<T>::const_reverse_iterator rbegin = cont->rbegin();
					typename container<T>::const_reverse_iterator rend = cont->rend();	--rend;
					test_name = "Display cont->begin() and cont->begin()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont_tmp = new container<T>();	cont_tmp->push_front(42);	cont_tmp->push_front(23);	container<T> const * cont = new container<T>(cont_tmp);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 23) = " << *rbegin << ENDL;
					*ss << "Value (should be 42) = " << *rend << ENDL << ENDL;
					delete cont_tmp;
					return (ss); }

/* Capacity */
		case 35: {	container<T> cont;
					test_name = "cont.empty()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << cont.empty() << ENDL << ENDL;
					return (ss); }

		case 36: {	container<T> cont(4, 42);
					test_name = "cont.empty()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(4, 42);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << cont.empty() << ENDL << ENDL;
					return (ss); }

		case 37: {	container<T> cont(4, 42);
					test_name = "cont.size()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(4, 42);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 38: {	container<T> cont(4, 42);
					test_name = "cont.max_size()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(4, 42);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL << ENDL;
					return (ss); }

		case 39: {	container<T> cont;
					test_name = "cont.max_size()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL << ENDL;
					return (ss); }

		case 40: {	container<T> cont(0);
					test_name = "cont.max_size()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(0);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL << ENDL;
					return (ss); }

/* Element access */
		case 41: {	container<T> cont;	cont.push_front(42);	cont.push_front(23);	cont.push_front(5);
					test_name = "Display cont.front()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_front(42);	cont.push_front(23);	cont.push_front(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "cont.front() (should be 5) = " << cont.front() << ENDL << ENDL;
					return (ss); }

		case 42: {	container<T> cont;	cont.push_front(42);	cont.push_front(23);	cont.push_front(5);
					cont.front() = -13;
					test_name = "Assign to reference : cont.front() = -13";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_front(42);	cont.push_front(23);	cont.push_front(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "cont.front() (should be -13) = " << cont.front() << ENDL << ENDL;
					return (ss); }

		case 43: {	container<T> cont;
					cont.front() = -13;
					test_name = "Assign to reference : cont.front() = -13";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL;
					*ss << test_name << ENDL;
					*ss << "cont.front() (should be -13) = " << cont.front() << ENDL << ENDL;
					return (ss); }

		case 44: {	container<T> cont;	cont.push_front(42);	cont.push_front(23);	cont.push_front(5);
					test_name = "Display cont.back()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_front(42);	cont.push_front(23);	cont.push_front(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "cont.back() (should be 42) = " << cont.back() << ENDL << ENDL;
					return (ss); }

		case 45: {	container<T> cont;	cont.push_front(42);	cont.push_front(23);	cont.push_front(5);
					cont.back() = -13;
					test_name = "Assign to reference : cont.back() = -13";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_front(42);	cont.push_front(23);	cont.push_front(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "cont.back() (should be -13) = " << cont.back() << ENDL << ENDL;
					return (ss); }

		case 46: {	container<T> cont;
					cont.back() = -13;
					test_name = "Assign to reference : cont.back() = -13";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL;
					*ss << test_name << ENDL;
					*ss << "cont.back() (should be -13) = " << cont.back() << ENDL << ENDL;
					return (ss); }

/* Modifiers */
	/* assign */
		case 47: {	container<T> cont(5, 42);	cont.assign(7, 3);
					test_name = "cont(5, 42);	cont.assign(7, 3);";
					_cont = cont;
					break;	}

		case 48: {	container<T> cont(5, 42);	container<T> cont_new(7, 3);
					typename container<T>::iterator begin = cont_new.begin();
					typename container<T>::iterator end = cont_new.end();
					cont.assign(begin, end);
					test_name = "cont(5, 42);	container<T> cont_new(7, 3);	typename container<T>::iterator begin = cont_new.begin();	typename container<T>::iterator end = cont_new.end();	cont.assign(begin, end);";
					_cont = cont;
					break;	}

	/* push_front, push_back, pop_front, pop_back */
		case 49: {	container<T> cont(5, 42);	cont.push_front(12);
					test_name = "cont(5, 42);	cont.push_front(12);";
					_cont = cont;
					break;	}

		case 50: {	container<T> cont(5, 42);	cont.push_back(12);
					test_name = "cont(5, 42);	cont.push_back(12);";
					_cont = cont;
					break;	}
					
		case 51: {	container<T> cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	cont.pop_front();
					test_name = "cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	cont.pop_front();";
					_cont = cont;
					break;	}
					
		case 52: {	container<T> cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	cont.pop_back();
					test_name = "cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	cont.pop_back();";
					_cont = cont;
					break;	}
					
	/* insert */
		case 53: {	container<T> cont(5, 42);	typename container<T>::iterator begin = cont.begin();	cont.insert(begin, 23);
					test_name = "cont(5, 42);	typename container<T>::iterator begin = cont.begin();	cont.insert(begin, 23);";
					_cont = cont;
					break;	}
					
		case 54: {	container<T> cont(5, 42);	typename container<T>::iterator begin = cont.begin();	begin++;	cont.insert(begin, 23);
					test_name = "cont(5, 42);	typename container<T>::iterator begin = cont.begin();	begin++;	cont.insert(begin, 23);";
					_cont = cont;
					break;	}
					
		case 55: {	container<T> cont(5, 42);	typename container<T>::iterator end = cont.end();	cont.insert(end, 23);
					test_name = "cont(5, 42);	typename container<T>::iterator end = cont.end();	cont.insert(end, 23);";
					_cont = cont;
					break;	}
					
		case 56: {	container<T> cont(5, 42);	typename container<T>::iterator end = cont.end();	end--;	cont.insert(end, 23);
					test_name = "cont(5, 42);	typename container<T>::iterator end = cont.end();	end--;	cont.insert(end, 23);";
					_cont = cont;
					break;	}
					
		case 57: {	container<T> cont(5, 42);	typename container<T>::iterator end = cont.end();	end--;	cont.insert(end, 3, 23);
					test_name = "cont(5, 42);	typename container<T>::iterator end = cont.end();	end--;	cont.insert(end, 3, 23);";
					_cont = cont;
					break;	}

	/* erase */
		case 58: {	container<T> cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	typename container<T>::iterator begin = cont.begin();	cont.erase(begin);
					test_name = "cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	typename container<T>::iterator begin = cont.begin();	cont.erase(begin);";
					_cont = cont;
					break;	}

		case 59: {	container<T> cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	typename container<T>::iterator begin = cont.begin();	begin++;	cont.erase(begin);
					test_name = "cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	typename container<T>::iterator begin = cont.begin();	begin++;	cont.erase(begin);";
					_cont = cont;
					break;	}

		case 60: {	container<T> cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	typename container<T>::iterator last = cont.end();	last--; cont.erase(last);
					test_name = "cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	typename container<T>::iterator last = cont.end();	last--; cont.erase(last);";
					_cont = cont;
					break;	}

		case 61: {	container<T> cont(5, 42);	typename container<T>::iterator begin = cont.begin();	begin++;	typename container<T>::iterator end = cont.end();	end--;	cont.erase(begin, end);
					test_name = "cont(5, 42);	typename container<T>::iterator begin = cont.begin();	begin++;	typename container<T>::iterator end = cont.end();	end--;	cont.erase(begin, end);";
					_cont = cont;
					break;	}

	/* swap */
		case 62: {	container<T> cont(5, 42);	container<T> contb(3, 23);	cont.swap(contb);
					std::stringstream * ss = new std::stringstream();
					std::stringstream * ss1 = print_cont(cont, "container cont");
					std::stringstream * ss2 = print_cont(contb, "container contb");
					*ss << cont_name + "cont(5, 42);	container<T> contb(3, 23);	cont.swap(contb);" << ENDL;
					*ss << ss1->str() << ENDL;
					*ss << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }
		
		case 63: {	container<T> cont(5, 42);	container<T> contb(0);	cont.swap(contb);
					std::stringstream * ss1 = print_cont(cont, "container cont");
					std::stringstream * ss2 = print_cont(contb, "container contb");
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont(5, 42);	container<T> contb(3, 23);	cont.swap(contb);" << ENDL;
					*ss << ss1->str() << ENDL;
					*ss << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }
		
	/* resize */
		case 64: {	container<T> cont(5, 42);	cont.resize(3, 23);
					test_name = "cont(5, 42);	cont.resize(3, 23);";
					_cont = cont;
					break;	}

		case 65: {	container<T> cont(5, 42);	cont.resize(8, 12);
					test_name = "cont(5, 42);	cont.resize(8, 12);";
					_cont = cont;
					break;	}

		case 66: {	container<T> cont(5, 42);	cont.resize(5, 12);
					test_name = "cont(5, 42);	cont.resize(5, 12);";
					_cont = cont;
					break;	}

		case 67: {	container<T> cont(5, 42);	cont.resize(5);
					test_name = "cont(5, 42);	cont.resize(5);";
					_cont = cont;
					break;	}

		case 68: {	container<T> cont(5, 42);	cont.resize(3);
					test_name = "cont(5, 42);	cont.resize(3);";
					_cont = cont;
					break;	}

		case 69: {	container<T> cont(5, 42);	cont.resize(8);
					test_name = "cont(5, 42);	cont.resize(8);";
					_cont = cont;
					break;	}

		case 70: {	container<T> cont(5, 42);	cont.resize(0);
					test_name = "cont(5, 42);	cont.resize(0);";
					_cont = cont;
					break;	}
	/* clear */
		case 71: {	container<T> cont(5, 42);	cont.clear();
					test_name = "cont(5, 42);	cont.clear();";
					_cont = cont;
					break;	}

		case 72: {	container<T> cont(0);	cont.clear();
					test_name = "cont(5, 42);	cont.clear();";
					_cont = cont;
					break;	}

/* Operations */
	/* splice - entire list */
		case 73: {	container<T> cont(5, 42);	container<T> contb(3, 23);	typename container<T>::iterator begin = cont.begin();	cont.splice(begin, contb);
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont(5, 42);	container<T> contb(3, 23);	typename container<T>::iterator begin = cont.begin();	cont.splice(begin, contb);" << ENDL;
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << ss1->str() << ENDL << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }

		case 74: {	container<T> cont(5, 42);	container<T> contb(3, 23);	typename container<T>::iterator begin = cont.begin();	begin++;	cont.splice(begin, contb);
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont(5, 42);	container<T> contb(3, 23);	typename container<T>::iterator begin = cont.begin();	begin++;	cont.splice(begin, contb);" << ENDL;
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << ss1->str() << ENDL << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }

		case 75: {	container<T> cont(5, 42);	container<T> contb(0);	typename container<T>::iterator begin = cont.begin();	begin++;	cont.splice(begin, contb);
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont(5, 42);	container<T> contb(0);	typename container<T>::iterator begin = cont.begin();	begin++;	cont.splice(begin, contb);" << ENDL;
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << ss1->str() << ENDL << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }

		case 76: {	container<T> cont(5, 42);	container<T> contb(3, 23);	typename container<T>::iterator end = cont.end();	cont.splice(end, contb);
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont(5, 42);	container<T> contb(3, 23);	typename container<T>::iterator end = cont.end();	cont.splice(end, contb);" << ENDL;
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << ss1->str() << ENDL << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }

		case 77: {	container<T> cont(5, 42);	container<T> contb(0);	typename container<T>::iterator end = cont.end();	cont.splice(end, contb);
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont(5, 42);	container<T> contb(0);	typename container<T>::iterator end = cont.end();	cont.splice(end, contb);" << ENDL;
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << ss1->str() << ENDL << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }

		case 78: {	container<T> cont(0);	container<T> contb(0);	typename container<T>::iterator end = cont.end();	cont.splice(end, contb);
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont(0);	container<T> contb(0);	typename container<T>::iterator end = cont.end();	cont.splice(end, contb);" << ENDL;
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << ss1->str() << ENDL << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }

		case 79: {	container<T> cont(0);	container<T> contb(3, 23);	typename container<T>::iterator end = cont.end();	cont.splice(end, contb);
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont(0);	container<T> contb(3, 23);	typename container<T>::iterator end = cont.end();	cont.splice(end, contb);" << ENDL;
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << ss1->str() << ENDL << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }

	/* splice - single element */
		case 80: {	container<T> cont(5, 42);	container<T> contb(1, 1);	contb.push_back(2);	typename container<T>::iterator begin = cont.begin();	begin++;	typename container<T>::iterator beginb = contb.begin();	beginb++;	cont.splice(begin, contb, beginb);
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont(5, 42);	container<T> contb(1, 1);	contb.push_back(2);	typename container<T>::iterator begin = cont.begin();	begin++;	typename container<T>::iterator beginb = contb.begin();	beginb++;	cont.splice(begin, contb, beginb);" << ENDL;
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << ss1->str() << ENDL << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }

		case 81: {	container<T> cont(5, 42);	container<T> contb(1, 1);	typename container<T>::iterator begin = cont.begin();	begin++;	typename container<T>::iterator beginb = contb.begin();	cont.splice(begin, contb, beginb);
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont(5, 42);	container<T> contb(1, 1);	typename container<T>::iterator begin = cont.begin();	begin++;	typename container<T>::iterator beginb = contb.begin();	cont.splice(begin, contb, beginb);" << ENDL;
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << ss1->str() << ENDL << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }

		case 82: {	container<T> cont(5, 42);	container<T> contb(1, 1);	contb.push_back(2);	typename container<T>::iterator end = cont.end();	typename container<T>::iterator beginb = contb.begin();	beginb++;	cont.splice(end, contb, beginb);
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont(5, 42);	container<T> contb(1, 1);	contb.push_back(2);	typename container<T>::iterator end = cont.end();	typename container<T>::iterator beginb = contb.begin();	beginb++;	cont.splice(end, contb, beginb);" << ENDL;
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << ss1->str() << ENDL << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }

		case 83: {	container<T> cont(0);	container<T> contb(1, 1);	contb.push_back(2);	typename container<T>::iterator end = cont.end();	typename container<T>::iterator beginb = contb.begin();	beginb++;	cont.splice(end, contb, beginb);
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont(5, 42);	container<T> contb(1, 1);	contb.push_back(2);	typename container<T>::iterator end = cont.end();	typename container<T>::iterator beginb = contb.begin();	beginb++;	cont.splice(end, contb, beginb);" << ENDL;
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << ss1->str() << ENDL << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }

		case 84: {	container<T> cont(5, 42);	container<T> contb(1, 1);	typename container<T>::iterator end = cont.end();	typename container<T>::iterator beginb = contb.begin();	cont.splice(end, contb, beginb);
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont(5, 42);	container<T> contb(1, 1);	typename container<T>::iterator end = cont.end();	typename container<T>::iterator beginb = contb.begin();	cont.splice(end, contb, beginb);" << ENDL;
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << ss1->str() << ENDL << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }

	/* splice - element range */
		case 85: {	container<T> cont(5, 42);	container<T> contb(12, 23);	typename container<T>::iterator end = cont.end();	typename container<T>::iterator beginb = contb.begin();	typename container<T>::iterator endb = contb.end();	cont.splice(end, contb, beginb, endb);
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont(5, 42);	container<T> contb(12, 23);	typename container<T>::iterator end = cont.end();	typename container<T>::iterator beginb = contb.begin();	typename container<T>::iterator endb = contb.end();	cont.splice(end, contb, beginb, endb);" << ENDL;
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << ss1->str() << ENDL << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }

		case 86: {	container<T> cont(5, 42);	container<T> contb(12, 23);	typename container<T>::iterator begin = cont.begin();	typename container<T>::iterator beginb = contb.begin();	typename container<T>::iterator endb = contb.end();	cont.splice(begin, contb, beginb, endb);
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont(5, 42);	container<T> contb(12, 23);	typename container<T>::iterator begin = cont.begin();	typename container<T>::iterator beginb = contb.begin();	typename container<T>::iterator endb = contb.end();	cont.splice(begin, contb, beginb, endb);" << ENDL;
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << ss1->str() << ENDL << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }

		case 87: {	container<T> cont(0);	container<T> contb(12, 23);	typename container<T>::iterator begin = cont.begin();	typename container<T>::iterator beginb = contb.begin();	typename container<T>::iterator endb = contb.end();	cont.splice(begin, contb, beginb, endb);
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont(0);	container<T> contb(12, 23);	typename container<T>::iterator begin = cont.begin();	typename container<T>::iterator beginb = contb.begin();	typename container<T>::iterator endb = contb.end();	cont.splice(begin, contb, beginb, endb);" << ENDL;
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << ss1->str() << ENDL << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }

		case 88: {	container<T> cont(5, 42);	container<T> contb(0);	typename container<T>::iterator begin = cont.begin();	typename container<T>::iterator beginb = contb.begin();	typename container<T>::iterator endb = contb.end();	cont.splice(begin, contb, beginb, endb);
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont(5, 42);	container<T> contb(0);	typename container<T>::iterator begin = cont.begin();	typename container<T>::iterator beginb = contb.begin();	typename container<T>::iterator endb = contb.end();	cont.splice(begin, contb, beginb, endb);" << ENDL;
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << ss1->str() << ENDL << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }

		case 89: {	container<T> cont(0);	container<T> contb(0);	typename container<T>::iterator begin = cont.begin();	typename container<T>::iterator beginb = contb.begin();	typename container<T>::iterator endb = contb.end();	cont.splice(begin, contb, beginb, endb);
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont(0);	container<T> contb(0);	typename container<T>::iterator begin = cont.begin();	typename container<T>::iterator beginb = contb.begin();	typename container<T>::iterator endb = contb.end();	cont.splice(begin, contb, beginb, endb);" << ENDL;
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << ss1->str() << ENDL << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }

	/* remove */
		case 90: {	container<T> cont(5, 42);	cont.remove(42);
					test_name = "cont(5, 42);	cont.remove(42);";
					_cont = cont;
					break;	}

		case 91: {	container<T> cont(0);	cont.remove(42);
					test_name = "cont(0);	cont.remove(42);";
					_cont = cont;
					break;	}

		case 92: {	container<T> cont(0);	cont.remove(0);
					test_name = "cont(0);	cont.remove(0);";
					_cont = cont;
					break;	}

		case 93: {	container<T> cont(1, 1);	cont.push_back(2);	cont.push_back(3);	cont.remove(2);
					test_name = "cont(1, 1);	cont.push_back(2);	cont.push_back(3);	cont.remove(2);";
					_cont = cont;
					break;	}

	/* remove_if */
		case 94: {	container<T> cont(5, 42);	Predicate<T> pred(T(42));	cont.remove_if(pred);
					test_name = "cont(5, 42);	Predicate pred;	cont.remove_if(pred);";
					_cont = cont;
					break;	}

		case 95: {	container<T> cont(5, 41);	cont.push_back(42);	Predicate<T> pred(T(42));	cont.remove_if(pred);
					test_name = "cont(5, 41);	cont.push_back(42);	Predicate<T> pred(T(42));	cont.remove_if(pred);";
					_cont = cont;
					break;	}

		case 96: {	container<T> cont(1, 1);	Predicate<T> pred(T(0));	cont.remove_if(pred);
					test_name = "cont(1, 1);	Predicate<T> pred(T(0));	cont.remove_if(pred);";
					_cont = cont;
					break;	}

		case 97: {	container<T> cont(0);	Predicate<T> pred(T(0));	cont.remove_if(pred);
					test_name = "cont(0);	Predicate<T> pred(T(0));	cont.remove_if(pred);";
					_cont = cont;
					break;	}

		case 98: {	container<T> cont(0);	Predicate<T> pred(T(42));	cont.remove_if(pred);
					test_name = "cont(0);	Predicate<T> pred(T(42));	cont.remove_if(pred);";
					_cont = cont;
					break;	}

	/* unique */
		case 99: {	container<T> cont(1, 1);	cont.push_back(1);	cont.push_back(2);	cont.push_back(2);	cont.unique();
					test_name = "cont(1, 1);	cont.push_back(1);	cont.push_back(2);	cont.push_back(2);	cont.unique();";
					_cont = cont;
					break;	}

		case 100: {	container<T> cont(5, 42);	cont.unique();
					test_name = "cont(5, 42);	cont.unique();";
					_cont = cont;
					break;	}

		case 101: {	container<T> cont(1, 1);	cont.push_back(2);	cont.push_back(1);	cont.push_back(2);	cont.unique();
					test_name = "cont(1, 1);	cont.push_back(2);	cont.push_back(1);	cont.push_back(2);	cont.unique();";
					_cont = cont;
					break;	}

		case 102: {	container<T> cont(1, 1);	cont.push_back(2);	cont.push_back(3);	cont.push_back(4);	cont.unique();
					test_name = "cont(1, 1);	cont.push_back(2);	cont.push_back(3);	cont.push_back(4);	cont.unique();";
					_cont = cont;
					break;	}

		case 103: {	container<T> cont(0);	cont.unique();
					test_name = "cont(0);	cont.unique();";
					_cont = cont;
					break;	}

		case 104: {	container<T> cont(5, 0);	cont.unique();
					test_name = "cont(5, 0);	cont.unique();";
					_cont = cont;
					break;	}

		case 105: {	container<T> cont(1, 40);	cont.push_back(41);	cont.push_back(42);	cont.push_back(43);		cont.push_back(44);	BinaryPredicate<T> pred(T(42));	cont.unique(pred);
					test_name = "cont(1, 40);	cont.push_back(41);	cont.push_back(42);	cont.push_back(43);		cont.push_back(44);	BinaryPredicate<T> pred(T(42));	cont.unique(pred);";
					_cont = cont;
					break;	}

		case 106: {	container<T> cont(5, 42);	BinaryPredicate<T> pred(T(42));	cont.unique(pred);
					test_name = "cont(5, 42);	BinaryPredicate<T> pred(T(42));	cont.unique(pred);";
					_cont = cont;
					break;	}

		case 107: {	container<T> cont(1, 1);	cont.push_back(1);	cont.push_back(2);	cont.push_back(2);	BinaryPredicate<T> pred(T(1));	cont.unique(pred);
					test_name = "cont(1, 1);	cont.push_back(1);	cont.push_back(2);	cont.push_back(2);	BinaryPredicate<T> pred(T(1));	cont.unique(pred);";
					_cont = cont;
					break;	}

		case 108: {	container<T> cont(1, 1);	cont.push_back(2);	cont.push_back(1);	cont.push_back(2);	BinaryPredicate<T> pred(T(1));	cont.unique(pred);
					test_name = "cont(1, 1);	cont.push_back(2);	cont.push_back(1);	cont.push_back(2);	BinaryPredicate<T> pred(T(1));	cont.unique(pred);";
					_cont = cont;
					break;	}

		case 109: {	container<T> cont(1, 1);	cont.push_back(2);	cont.push_back(3);	cont.push_back(4);	BinaryPredicate<T> pred(T(42));	cont.unique(pred);
					test_name = "cont(1, 1);	cont.push_back(2);	cont.push_back(3);	cont.push_back(4);	BinaryPredicate<T> pred(T(42));	cont.unique(pred);";
					_cont = cont;
					break;	}

		case 110: {	container<T> cont(5, 23);	BinaryPredicate<T> pred(T(42));	cont.unique(pred);
					test_name = "cont(5, 23);	BinaryPredicate<T> pred(T(42));	cont.unique(pred);";
					_cont = cont;
					break;	}

		case 111: {	container<T> cont(0);	BinaryPredicate<T> pred(T(42));	cont.unique(pred);
					test_name = "cont(0);	BinaryPredicate<T> pred(T(42));	cont.unique(pred);";
					_cont = cont;
					break;	}

		case 112: {	container<T> cont(1, 1);	BinaryPredicate<T> pred(T(42));	cont.unique(pred);
					test_name = "cont(1, 1);	BinaryPredicate<T> pred(T(42));	cont.unique(pred);";
					_cont = cont;
					break;	}

	/* merge */
		case 113: {	container<T> cont(1, 1);	cont.push_back(2);	container<T> contb(1, 42);	contb.push_back(43);	contb.push_back(44);	cont.merge(contb);
					test_name = "cont(1, 1);	cont.push_back(2);	container<T> contb(1, 42);	contb.push_back(43);	contb.push_back(44);	cont.merge(contb);";
					_cont = cont;
					break;	}

		case 114: {	container<T> cont(5, 42);	container<T> contb(3, 23);	cont.merge(contb);
					test_name = "cont(5, 42);	container<T> contb(3, 23);	cont.merge(contb);";
					_cont = cont;
					break;	}

		case 115: {	container<T> cont(0);	container<T> contb(3, 23);	cont.merge(contb);
					test_name = "cont(0);	container<T> contb(3, 23);	cont.merge(contb);";
					_cont = cont;
					break;	}

		case 116: {	container<T> cont(5, 42);	container<T> contb(0);	cont.merge(contb);
					test_name = "cont(5, 42);	container<T> contb(0);	cont.merge(contb);";
					_cont = cont;
					break;	}

		case 117: {	container<T> cont(1, 23);	container<T> contb(3, 23);	typename container<T>::iterator begin = cont.begin();	cont.merge(contb);	typename container<T>::iterator other_begin = cont.begin();	
					test_name = cont_name + " " + "cont(1, 23);	container<T> contb(3, 23);	typename container<T>::iterator begin = cont.begin();	cont.merge(contb);	typename container<T>::iterator other_begin = cont.begin();";
					std::stringstream * ss = new std::stringstream();
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << test_name << ENDL;
					*ss << ss1->str() << ss2->str() << "Equal or Not (strict weak ordering)= |" << (begin == other_begin) << "|" << ENDL << ENDL;					
					delete ss1;	delete ss2;
					return (ss); }

		case 118: {	container<T> cont(1, 23);	container<T> contb(3, 23);	cont.merge(contb);
					test_name = "cont(1, 23);	container<T> contb(3, 23);	cont.merge(contb);";
					_cont = cont;
					break;	}

		case 119: {	container<T> cont(1, 1);	cont.push_back(2);	container<T> contb(1, 42);	contb.push_back(43);	contb.push_back(44);	Compare<T> comp;	cont.merge(contb, comp);
					test_name = "cont(1, 1);	cont.push_back(2);	container<T> contb(1, 42);	contb.push_back(43);	contb.push_back(44);	Compare<T> comp;	cont.merge(contb, comp);";
					_cont = cont;
					break;	}

		case 120: {	container<T> cont(5, 42);	container<T> contb(3, 23);	Compare<T> comp;	cont.merge(contb, comp);
					test_name = "cont(5, 42);	container<T> contb(3, 23);	Compare<T> comp;	cont.merge(contb, comp);";
					_cont = cont;
					break;	}

		case 121: {	container<T> cont(0);	container<T> contb(3, 23);	Compare<T> comp;	cont.merge(contb, comp);
					test_name = "cont(0);	container<T> contb(3, 23);	Compare<T> comp;	cont.merge(contb, comp);";
					_cont = cont;
					break;	}

		case 122: {	container<T> cont(1, 23);	container<T> contb(3, 23);	Compare<T> comp;	typename container<T>::iterator begin = cont.begin();	cont.merge(contb, comp);	typename container<T>::iterator other_begin = cont.begin();	
					test_name = cont_name + " " + "cont(1, 23);	container<T> contb(3, 23);	Compare<T> comp;	typename container<T>::iterator begin = cont.begin();	cont.merge(contb, comp);	typename container<T>::iterator other_begin = cont.begin();";
					std::stringstream * ss = new std::stringstream();
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << test_name << ENDL;
					*ss << ss1->str() << ss2->str() << "Equal or Not (strict weak ordering)= |" << (begin == other_begin) << "|" << ENDL << ENDL;					
					delete ss1;	delete ss2;
					return (ss); }

	/* sort */
		case 123: {	container<T> cont(0);	cont.sort();
					test_name = "cont(0);	cont.sort();";
					_cont = cont;
					break;	}

		case 124: {	container<T> cont(1, 1);	cont.sort();
					test_name = "cont(1, 1);	cont.sort();";
					_cont = cont;
					break;	}

		case 125: {	container<T> cont(5, 42);	cont.sort();
					test_name = "cont(5, 42);	cont.sort();";
					_cont = cont;
					break;	}

		case 126: {	container<T> cont(1, 1);	cont.push_back(2);	cont.push_back(3);	cont.sort();
					test_name = "cont(1, 1);	cont.push_back(2);	cont.push_back(3);	cont.sort();";
					_cont = cont;
					break;	}

		case 127: {	container<T> cont(1, 3);	cont.push_back(2);	cont.push_back(1);	cont.sort();
					test_name = "cont(1, 3);	cont.push_back(2);	cont.push_back(1);	cont.sort();";
					_cont = cont;
					break;	}

		case 128: {	container<T> cont(0);	Compare<T> comp;	cont.sort(comp);
					test_name = "cont(0);	Compare<T> comp;	cont.sort(comp);";
					_cont = cont;
					break;	}

		case 129: {	container<T> cont(1, 1);	Compare<T> comp;	cont.sort(comp);
					test_name = "cont(1, 1);	Compare<T> comp;	cont.sort(comp);";
					_cont = cont;
					break;	}

		case 130: {	container<T> cont(5, 42);	Compare<T> comp;	cont.sort(comp);
					test_name = "cont(1, 1);	Compare<T> comp;	cont.sort(comp);";
					_cont = cont;
					break;	}

		case 131: {	container<T> cont(1, 1);	cont.push_back(2);	cont.push_back(3);	Compare<T> comp;	cont.sort(comp);
					test_name = "cont(1, 1);	cont.push_back(2);	cont.push_back(3);	Compare<T> comp;	cont.sort(comp);";
					_cont = cont;
					break;	}

		case 132: {	container<T> cont(1, 3);	cont.push_back(2);	cont.push_back(1);	Compare<T> comp;	cont.sort(comp);
					test_name = "cont(1, 3);	cont.push_back(2);	cont.push_back(1);	Compare<T> comp;	cont.sort(comp);";
					_cont = cont;
					break;	}

	/* reverse */
		case 133: {	container<T> cont(1, 3);	cont.push_back(2);	cont.push_back(1);	cont.reverse();
					test_name = "cont(1, 3);	cont.push_back(2);	cont.push_back(1);	cont.reverse();";
					_cont = cont;
					break;	}

		case 134: {	container<T> cont(5, 42);	cont.reverse();
					test_name = "cont(5, 42);	cont.reverse();";
					_cont = cont;
					break;	}

		case 135: {	container<T> cont(0);	cont.reverse();
					test_name = "cont(0);	cont.reverse();";
					_cont = cont;
					break;	}

		case 136: {	container<T> cont(1, 1);	cont.reverse();
					test_name = "cont(1, 1);	cont.reverse();";
					_cont = cont;
					break;	}

/* Non-member function overloads */
	/* operator== */
		case 137: {	container<T> cont(1, 3);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 3);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont == contb) (0 = no, 1 = yes): " << (cont == contb) << ENDL;
					return (ss); }

		case 138: {	container<T> cont(1, 42);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 42);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont == contb) (0 = no, 1 = yes): " << (cont == contb) << ENDL;
					return (ss); }

		case 139: {	container<T> cont(0);	container<T> contb(0);
					test_name = cont_name + " " + "cont(0);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont == contb) (0 = no, 1 = yes): " << (cont == contb) << ENDL;
					return (ss); }

		case 140: {	container<T> cont(5, 42);	container<T> contb(0);
					test_name = cont_name + " " + "cont(5, 42);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont == contb) (0 = no, 1 = yes): " << (cont == contb) << ENDL;
					return (ss); }

	/* operator!= */
		case 141: {	container<T> cont(1, 3);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 3);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont != contb) (0 = no, 1 = yes): " << (cont != contb) << ENDL;
					return (ss); }

		case 142: {	container<T> cont(1, 42);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 42);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont != contb) (0 = no, 1 = yes): " << (cont != contb) << ENDL;
					return (ss); }

		case 143: {	container<T> cont(0);	container<T> contb(0);
					test_name = cont_name + " " + "cont(0);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont != contb) (0 = no, 1 = yes): " << (cont != contb) << ENDL;
					return (ss); }

		case 144: {	container<T> cont(5, 42);	container<T> contb(0);
					test_name = cont_name + " " + "cont(5, 42);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont != contb) (0 = no, 1 = yes): " << (cont != contb) << ENDL;
					return (ss); }

	/* operator< */
		case 145: {	container<T> cont(1, 3);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 3);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont < contb) (0 = no, 1 = yes): " << (cont < contb) << ENDL;
					return (ss); }

		case 146: {	container<T> cont(1, 42);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 42);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont < contb) (0 = no, 1 = yes): " << (cont < contb) << ENDL;
					return (ss); }

		case 147: {	container<T> cont(0);	container<T> contb(0);
					test_name = cont_name + " " + "cont(0);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont < contb) (0 = no, 1 = yes): " << (cont < contb) << ENDL;
					return (ss); }

		case 148: {	container<T> cont(5, 42);	container<T> contb(0);
					test_name = cont_name + " " + "cont(5, 42);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont < contb) (0 = no, 1 = yes): " << (cont < contb) << ENDL;
					return (ss); }

	/* operator<= */
		case 149: {	container<T> cont(1, 3);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 3);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont <= contb) (0 = no, 1 = yes): " << (cont <= contb) << ENDL;
					return (ss); }

		case 150: {	container<T> cont(1, 42);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 42);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont <= contb) (0 = no, 1 = yes): " << (cont <= contb) << ENDL;
					return (ss); }

		case 151: {	container<T> cont(0);	container<T> contb(0);
					test_name = cont_name + " " + "cont(0);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont <= contb) (0 = no, 1 = yes): " << (cont <= contb) << ENDL;
					return (ss); }

		case 152: {	container<T> cont(5, 42);	container<T> contb(0);
					test_name = cont_name + " " + "cont(5, 42);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont <= contb) (0 = no, 1 = yes): " << (cont <= contb) << ENDL;
					return (ss); }

	/* operator> */
		case 153: {	container<T> cont(1, 3);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 3);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont > contb) (0 = no, 1 = yes): " << (cont > contb) << ENDL;
					return (ss); }

		case 154: {	container<T> cont(1, 42);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 42);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont > contb) (0 = no, 1 = yes): " << (cont > contb) << ENDL;
					return (ss); }

		case 155: {	container<T> cont(0);	container<T> contb(0);
					test_name = cont_name + " " + "cont(0);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont > contb) (0 = no, 1 = yes): " << (cont > contb) << ENDL;
					return (ss); }

		case 156: {	container<T> cont(5, 42);	container<T> contb(0);
					test_name = cont_name + " " + "cont(5, 42);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont > contb) (0 = no, 1 = yes): " << (cont > contb) << ENDL;
					return (ss); }

	/* operator>= */
		case 157: {	container<T> cont(1, 3);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 3);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont >= contb) (0 = no, 1 = yes): " << (cont >= contb) << ENDL;
					return (ss); }

		case 158: {	container<T> cont(1, 42);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 42);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont >= contb) (0 = no, 1 = yes): " << (cont >= contb) << ENDL;
					return (ss); }

		case 159: {	container<T> cont(0);	container<T> contb(0);
					test_name = cont_name + " " + "cont(0);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont >= contb) (0 = no, 1 = yes): " << (cont >= contb) << ENDL;
					return (ss); }

		case 160: {	container<T> cont(5, 42);	container<T> contb(0);
					test_name = cont_name + " " + "cont(5, 42);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont >= contb) (0 = no, 1 = yes): " << (cont >= contb) << ENDL;
					return (ss); }

	/* swap(list) */
		case 161: {	container<T> cont(5, 42);	container<T> contb(3, 23);	swap(cont, contb);
					test_name = cont_name + " " + "cont(5, 42);	container<T> contb(3, 23);	swap(cont, contb);";
					std::stringstream * ss = new std::stringstream();
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << test_name << ENDL;
					*ss << ss1->str() << ss2->str() << ENDL << ENDL;					
					delete ss1;	delete ss2;
					return (ss); }

		case 162: {	container<T> cont(5, 42);	container<T> contb(0);	swap(cont, contb);
					test_name = cont_name + " " + "cont(5, 42);	container<T> contb(3, 23);	swap(cont, contb);";
					std::stringstream * ss = new std::stringstream();
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << test_name << ENDL;
					*ss << ss1->str() << ss2->str() << ENDL << ENDL;					
					delete ss1;	delete ss2;
					return (ss); }

		case 163: {	container<T> cont(0);	container<T> contb(0);	swap(cont, contb);
					test_name = cont_name + " " + "cont(5, 42);	container<T> contb(3, 23);	swap(cont, contb);";
					std::stringstream * ss = new std::stringstream();
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << test_name << ENDL;
					*ss << ss1->str() << ss2->str() << ENDL << ENDL;					
					delete ss1;	delete ss2;
					return (ss); }
	}
	return (print_cont(_cont, cont_name + " " + test_name));
}

template <template <class T, class Alloc = std::allocator<T> > class mycontainerT,
template <class T, class Alloc = std::allocator<T> > class stdcontainerT, class T>
void	list_tester(std::string const & title, std::string const & type)
{
	std::string	category;

	COUT << BLUE << "*--- testing " + title + type + " . . . ---*" << RENDL;

	category = "=> Constructors: ";
	COUT << category;	
	for (int i = 1; i <= 7; i++)
		print_result(test_list_container<stdcontainerT, T>(title + type), test_list_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Destructors: ";
	COUT << category;	
	for (int i = 1; i <= 1; i++)
		print_result(test_list_container<stdcontainerT, T>(title + type), test_list_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Operator=: ";
	COUT << category;	
	for (int i = 1; i <= 2; i++)
		print_result(test_list_container<stdcontainerT, T>(title + type), test_list_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Iterators: ";
	COUT << category;	
	for (int i = 1; i <= 6; i++)
		print_result(test_list_container<stdcontainerT, T>(title + type), test_list_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Constant Iterators: ";
	COUT << category;	
	for (int i = 1; i <= 6; i++)
		print_result(test_list_container<stdcontainerT, T>(title + type), test_list_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Reverse Iterators: ";
	COUT << category;	
	for (int i = 1; i <= 6; i++)
		print_result(test_list_container<stdcontainerT, T>(title + type), test_list_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Constant Reverse Iterators: ";
	COUT << category;	
	for (int i = 1; i <= 6; i++)
		print_result(test_list_container<stdcontainerT, T>(title + type), test_list_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Capacity: ";
	COUT << category;	
	for (int i = 1; i <= 6; i++)
		print_result(test_list_container<stdcontainerT, T>(title + type), test_list_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Element Access: ";
	COUT << category;	
	for (int i = 1; i <= 6; i++)
		print_result(test_list_container<stdcontainerT, T>(title + type), test_list_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Modifiers: ";
	COUT << category;	
	for (int i = 1; i <= 26; i++)
		print_result(test_list_container<stdcontainerT, T>(title + type), test_list_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Operations: ";
	COUT << category;	
	for (int i = 1; i <= 64; i++)
		print_result(test_list_container<stdcontainerT, T>(title + type), test_list_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Non-member function overloads: ";
	COUT << category;	
	for (int i = 1; i <= 27; i++)
		print_result(test_list_container<stdcontainerT, T>(title + type), test_list_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	std::cout << "COMPLETE !" << std::endl;
}
