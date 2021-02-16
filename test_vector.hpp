#include "main.hpp"


template <template <class T, class Alloc = std::allocator<T> > class container, class T>
std::stringstream *	test_vector_container(std::string const & cont_name)
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
	/* iterator : begin, end, iterating through iterators, operator-> and operator* and the others */
		case 11: {	container<T> cont;
					test_name = "cont.begin() == cont.end()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (cont.begin() == cont.end()) << ENDL << ENDL;
					return (ss); }

		case 12: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);
					typename container<T>::iterator begin = cont.begin();
					test_name = "*begin == cont.front()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (*begin == cont.front()) << ENDL << ENDL;
					return (ss); }

		case 13: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);
					typename container<T>::iterator end = cont.end();	--end;
					test_name = "*(--end) == cont.back()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (*end == cont.back()) << ENDL << ENDL;
					return (ss); }

		case 14: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::iterator begin = cont.begin();
					typename container<T>::iterator end = cont.end();
					test_name = "Displaying vector with ::iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << *begin << " ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 15: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);
					typename container<T>::iterator begin = cont.begin();
					typename container<T>::iterator end = cont.end();	--end;
					test_name = "Display *(cont.begin()) and *(cont.end())";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 23) = " << *begin << ENDL;
					*ss << "Value (should be 42) = " << *end << ENDL << ENDL;
					return (ss); }

		case 16: {	container<T> * cont = new container<T>();	cont->push_back(42);	cont->push_back(23);
					typename container<T>::iterator begin = cont->begin();
					typename container<T>::iterator end = cont->end();	--end;
					test_name = "Display cont->begin() and cont->begin()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont = new container<T>();	cont->push_back(42);	cont->push_back(23);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 23) = " << *begin << ENDL;
					*ss << "Value (should be 42) = " << *end << ENDL << ENDL;
					delete cont;
					return (ss); }

		case 17: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1);
					typename container<T>::iterator begin = cont.begin();
					typename container<T>::iterator end = cont.end();
					test_name = "Displaying vector with ::iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << *begin << " ";
						begin = begin + 2;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 18: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::iterator begin = cont.begin();	begin++;	begin++;
					test_name = "Displaying vector with ::iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					*ss << *begin << " ";
					begin = begin + (-2);
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 19: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::iterator begin = cont.begin();
					test_name = "Displaying vector with ::iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					*ss << *begin << " ";
					begin = begin + (-2);
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 20: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::iterator begin = cont.begin();
					test_name = "Displaying vector with ::iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					*ss << *begin << " ";
					begin = begin - (-2);
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 21: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1);
					typename container<T>::iterator begin = cont.begin();
					typename container<T>::iterator end = cont.end();
					test_name = "Displaying vector with ::iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << *begin << " ";
						begin = 2 + begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 22: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::iterator begin = cont.begin();	begin++;	begin++;
					test_name = "Displaying vector with ::iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					*ss << *begin << " ";
					begin = -2 + begin;
					*ss << *begin << " ";
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 23: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::iterator begin = cont.begin();
					typename container<T>::iterator end = cont.end();
					test_name = "Displaying vector with ::iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					*ss << "ptrdiff is :" << (begin - (end - 1)) << std::endl;
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 24: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::iterator begin = cont.begin();
					typename container<T>::iterator end = cont.end();
					typename container<T>::iterator it = cont.begin();	it++;	it++;
					test_name = "Displaying vector with ::iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying inequalities" << ENDL;
					while (begin != end)
					{
						*ss << "|" << *begin << "| compared to |" << *it << "|" << ENDL;
						if (begin < it)
							*ss << "begin < it" << ENDL;
						if (begin > it)
							*ss << "begin > it" << ENDL;
						if (begin <= it)
							*ss << "begin <= it" << ENDL;
						if (begin >= it)
							*ss << "begin >= it" << ENDL;
						begin++;
					}
					return (ss); }

		case 25: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1);
					typename container<T>::iterator begin = cont.begin();
					typename container<T>::iterator end = cont.end();
					test_name = "Displaying vector with ::iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << *begin << " ";
						begin += 2;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 26: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::iterator begin = cont.begin();	begin++;	begin++;
					test_name = "Displaying vector with ::iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					*ss << *begin << " ";
					begin -= 2;
					*ss << *begin << " ";
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 27: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::iterator begin = cont.begin();
					test_name = "Displaying vector with ::iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					size_t i = 0;
					*ss << begin[i] << " ";
					begin += 2;
					*ss << begin[i] << " ";
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 28: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::iterator begin = cont.begin();
					test_name = "Displaying vector with ::iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Accessing through begin[2] = |" << begin[2] << "| " << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }


	/* const_iterator : begin, end, iterating through iterators, operator-> and operator* */
		case 29: {	container<T> const cont;
					test_name = "cont.begin() == cont.end()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " const cont;" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (cont.begin() == cont.end()) << ENDL << ENDL;
					return (ss); }

		case 30: {	container<T> cont;	cont.push_back(42);	cont.push_back(23); container<T> const contb(cont);
					typename container<T>::const_iterator begin = contb.begin();
					test_name = "*begin == cont.front()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23); container<T> const contb(cont);" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (*begin == contb.front()) << ENDL << ENDL;
					return (ss); }

		case 31: {	container<T> cont;	cont.push_back(42);	cont.push_back(23); container<T> const contb(cont);
					typename container<T>::const_iterator end = contb.end();	--end;
					test_name = "*(--end) == cont.back()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23); container<T> const contb(cont);" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (*end == contb.back()) << ENDL << ENDL;
					return (ss); }

		case 32: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5); container<T> const contb(cont);
					typename container<T>::const_iterator begin = contb.begin();
					typename container<T>::const_iterator end = contb.end();
					test_name = "Displaying vector with ::const_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5); container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << *begin << " ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 33: {	container<T> cont;	cont.push_back(42);	cont.push_back(23); container<T> const contb(cont);
					typename container<T>::const_iterator begin = contb.begin();
					typename container<T>::const_iterator end = contb.end();	--end;
					test_name = "Display *(cont.begin()) and *(cont.end())";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23); container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 23) = " << *begin << ENDL;
					*ss << "Value (should be 42) = " << *end << ENDL << ENDL;
					return (ss); }

		case 34: {	container<T> * cont = new container<T>();	cont->push_back(42);	cont->push_back(23); container<T> const * contb(cont);
					typename container<T>::const_iterator begin = contb->begin();
					typename container<T>::const_iterator end = contb->end();	--end;
					test_name = "Display cont->begin() and cont->begin()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont = new container<T>();	cont->push_back(42);	cont->push_back(23);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 23) = " << *begin << ENDL;
					*ss << "Value (should be 42) = " << *end << ENDL << ENDL;
					delete cont;
					return (ss); }

		case 35: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1); container<T> const contb(cont);
					typename container<T>::const_iterator begin = contb.begin();
					typename container<T>::const_iterator end = contb.end();
					test_name = "Displaying vector with ::const_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1); container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << *begin << " ";
						begin = begin + 2;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 36: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5); container<T> const contb(cont);
					typename container<T>::const_iterator begin = contb.begin();	begin++;	begin++;
					test_name = "Displaying vector with ::const_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5); container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					*ss << *begin << " ";
					begin = begin + (-2);
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 37: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5); container<T> const contb(cont);
					typename container<T>::const_iterator begin = contb.begin();
					test_name = "Displaying vector with ::const_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5); container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					*ss << *begin << " ";
					begin = begin + (-2);
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 38: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5); container<T> const contb(cont);
					typename container<T>::const_iterator begin = contb.begin();
					test_name = "Displaying vector with ::const_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5); container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					*ss << *begin << " ";
					begin = begin - (-2);
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 39: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1); container<T> const contb(cont);
					typename container<T>::const_iterator begin = contb.begin();
					typename container<T>::const_iterator end = contb.end();
					test_name = "Displaying vector with ::const_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1); container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << *begin << " ";
						begin = 2 + begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 40: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5); container<T> const contb(cont);
					typename container<T>::const_iterator begin = contb.begin();	begin++;	begin++;
					test_name = "Displaying vector with ::const_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5); container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					*ss << *begin << " ";
					begin = -2 + begin;
					*ss << *begin << " ";
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 41: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5); container<T> const contb(cont);
					typename container<T>::const_iterator begin = contb.begin();
					typename container<T>::const_iterator end = contb.end();
					test_name = "Displaying vector with ::const_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5); container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					*ss << "ptrdiff is : " << (begin - (end - 1)) << " ]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 42: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5); container<T> const contb(cont);
					typename container<T>::const_iterator begin = contb.begin();
					typename container<T>::const_iterator end = contb.end();
					typename container<T>::const_iterator it = contb.begin();	it++;	it++;
					test_name = "Displaying vector with ::const_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5); container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying inequalities" << ENDL;
					while (begin != end)
					{
						*ss << "|" << *begin << "| compared to|" << *it << "|" << ENDL;
						if (begin < it)
							*ss << "begin < it" << ENDL;
						if (begin > it)
							*ss << "begin > it" << ENDL;
						if (begin <= it)
							*ss << "begin <= it" << ENDL;
						if (begin >= it)
							*ss << "begin >= it" << ENDL;
						begin++;
					}
					return (ss); }

		case 43: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1); container<T> const contb(cont);
					typename container<T>::const_iterator begin = contb.begin();
					typename container<T>::const_iterator end = contb.end();
					test_name = "Displaying vector with ::const_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1); container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << *begin << " ";
						begin += 2;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 44: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);
					typename container<T>::const_iterator begin = contb.begin();	begin++;	begin++;
					test_name = "Displaying vector with ::const_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					*ss << *begin << " ";
					begin -= 2;
					*ss << *begin << " ";
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 45: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);
					typename container<T>::const_iterator begin = contb.begin();
					test_name = "Displaying vector with ::const_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					size_t i = 0;
					*ss << begin[i] << " ";
					begin += 2;
					*ss << begin[i] << " ";
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 46: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);
					typename container<T>::const_iterator begin = contb.begin();
					test_name = "Displaying vector with ::iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Accessing through begin[2] = |" << begin[2] << "| " << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }


	/* reverse iterator : rbegin, rend, iterating through iterators, operator-> and operator* and the others */
		case 47: {	container<T> cont;
					test_name = "cont.rbegin() == cont.rend()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (cont.rbegin() == cont.rend()) << ENDL << ENDL;
					return (ss); }

		case 48: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);
					typename container<T>::reverse_iterator begin = cont.rbegin();
					test_name = "*begin == cont.back()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (*begin == cont.back()) << ENDL << ENDL;
					return (ss); }

		case 49: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);
					typename container<T>::reverse_iterator end = cont.rend();	--end;
					test_name = "*(--rend) == cont.front()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (*end == cont.front()) << ENDL << ENDL;
					return (ss); }

		case 50: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::reverse_iterator begin = cont.rbegin();
					typename container<T>::reverse_iterator end = cont.rend();
					test_name = "Displaying vector with ::reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << *begin << " ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 51: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);
					typename container<T>::reverse_iterator begin = cont.rbegin();
					typename container<T>::reverse_iterator end = cont.rend();	--end;
					test_name = "Display *(cont.begin()) and *(cont.end())";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 23) = " << *begin << ENDL;
					*ss << "Value (should be 42) = " << *end << ENDL << ENDL;
					return (ss); }

		case 52: {	container<T> * cont = new container<T>();	cont->push_back(42);	cont->push_back(23);
					typename container<T>::reverse_iterator begin = cont->rbegin();
					typename container<T>::reverse_iterator end = cont->rend();	--end;
					test_name = "Display cont->begin() and cont->begin()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont = new container<T>();	cont->push_back(42);	cont->push_back(23);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 23) = " << *begin << ENDL;
					*ss << "Value (should be 42) = " << *end << ENDL << ENDL;
					delete cont;
					return (ss); }

		case 53: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1);
					typename container<T>::reverse_iterator begin = cont.rbegin();
					typename container<T>::reverse_iterator end = cont.rend();
					test_name = "Displaying vector with ::reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying elements with unary plus [begin = begin + 2] = |";
					while (begin != end)
					{
						*ss << *begin << " ";
						begin = begin + 2;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 54: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::reverse_iterator begin = cont.rbegin();	begin++;	begin++;
					test_name = "Displaying vector with ::reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying unary plus [begin = begin + 2] = |";
					begin = begin + (-2);
					*ss << "|" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 55: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::reverse_iterator begin = cont.rend(); begin--;
					test_name = "Displaying vector with ::reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying unary plus [begin = begin + (-2)] = |";
					begin = begin + (-2);
					*ss << "|" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 56: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::reverse_iterator begin = cont.rbegin();
					test_name = "Displaying vector with ::reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying unary minus [begin = begin - (-2)] = |";
					begin = begin - (-2);
					*ss << "|" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 57: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1);
					typename container<T>::reverse_iterator begin = cont.rbegin();
					typename container<T>::reverse_iterator end = cont.rend();
					test_name = "Displaying vector with ::reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Iterating through addition (begin = 2 + begin) = [";
					while (begin != end)
						begin = 2 + begin;
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 58: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::reverse_iterator begin = cont.rbegin();	begin++;	begin++;
					test_name = "Displaying vector with ::reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying through subtraction (begin = -2 + begin) = [";
					*ss << *begin << " ";
					begin = -2 + begin;
					*ss << *begin << " ";
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 59: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::reverse_iterator begin = cont.rbegin();
					typename container<T>::reverse_iterator end = cont.rend();
					test_name = "Displaying vector with ::reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying pointer difference ((begin - (end - 1))): |" << (begin - (end - 1)) << "|" << ENDL << ENDL;
					return (ss); }

		case 60: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::reverse_iterator begin = cont.rbegin();
					typename container<T>::reverse_iterator end = cont.rend();
					typename container<T>::reverse_iterator it = cont.rbegin();	it++;	it++;
					test_name = "Displaying vector with ::reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying inequalities" << ENDL;
					while (begin != end)
					{
						*ss << "|" << *begin << "| compared to |" << *it << "|" << ENDL;
						if (begin < it)
							*ss << "begin < it" << ENDL;
						if (begin > it)
							*ss << "begin > it" << ENDL;
						if (begin <= it)
							*ss << "begin <= it" << ENDL;
						if (begin >= it)
							*ss << "begin >= it" << ENDL;
						begin++;
					}
					*ss << ENDL << ENDL;
					return (ss); }

		case 61: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1);
					typename container<T>::reverse_iterator begin = cont.rbegin();
					typename container<T>::reverse_iterator end = cont.rend();
					test_name = "Displaying vector with ::reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying elements through addition-assignment (begin += 2;) = [";
					while (begin != end)
					{
						*ss << *begin << " ";
						begin += 2;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 62: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::reverse_iterator begin = cont.rbegin();	begin++;	begin++;
					test_name = "Displaying vector with ::reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying elements through subtraction-assignment (begin -= 2;) = [";
					*ss << *begin << " ";
					begin -= 2;
					*ss << *begin << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 63: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::reverse_iterator begin = cont.rend();	
					begin--;
					test_name = "Displaying vector with ::reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying elements through subtraction-assignment (rend -= 2;) = [";
					size_t i = 0;
					begin -= 2;
					*ss << begin[i] << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 64: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					typename container<T>::reverse_iterator begin = cont.rbegin();
					test_name = "Displaying vector with ::reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Accessing through begin[2] = |" << begin[2] << "| " << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }


	/* constant reverse iterator : rbegin, rend, iterating through iterators, operator-> and operator* and the others */
		case 65: {	container<T> const cont;
					test_name = "cont.rbegin() == cont.rend()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (cont.rbegin() == cont.rend()) << ENDL << ENDL;
					return (ss); }

		case 66: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	container<T> const contb(cont);
					typename container<T>::const_reverse_iterator begin = contb.rbegin();
					test_name = "*begin == cont.back()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	container<T> const contb(cont);" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (*begin == contb.back()) << ENDL << ENDL;
					return (ss); }

		case 67: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	container<T> const contb(cont);
					typename container<T>::const_reverse_iterator end = contb.rend();	--end;
					test_name = "*(--rend) == contb.front()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	container<T> const contb(cont);" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (*end == contb.front()) << ENDL << ENDL;
					return (ss); }

		case 68: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);
					typename container<T>::const_reverse_iterator begin = contb.rbegin();
					typename container<T>::const_reverse_iterator end = contb.rend();
					test_name = "Displaying vector with ::const_reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << *begin << " ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << contb.size() << ENDL << ENDL;
					return (ss); }

		case 69: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	container<T> const contb(cont);
					typename container<T>::const_reverse_iterator begin = contb.rbegin();
					typename container<T>::const_reverse_iterator end = contb.rend();	--end;
					test_name = "Display *(contb.begin()) and *(contb.end())";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 23) = " << *begin << ENDL;
					*ss << "Value (should be 42) = " << *end << ENDL << ENDL;
					return (ss); }

		case 70: {	container<T> * cont = new container<T>();	cont->push_back(42);	cont->push_back(23);	container<T> const * contb(cont);
					typename container<T>::const_reverse_iterator begin = contb->rbegin();
					typename container<T>::const_reverse_iterator end = contb->rend();	--end;
					test_name = "Display contb->begin() and contb->begin()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont = new container<T>();	cont->push_back(42);	cont->push_back(23);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 23) = " << *begin << ENDL;
					*ss << "Value (should be 42) = " << *end << ENDL << ENDL;
					delete cont;
					return (ss); }

		case 71: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1);	container<T> const contb(cont);
					typename container<T>::const_reverse_iterator begin = contb.rbegin();
					typename container<T>::const_reverse_iterator end = contb.rend();
					test_name = "Displaying vector with ::const_reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying elements with unary plus [begin = begin + 2] = |";
					while (begin != end)
					{
						*ss << *begin << " ";
						begin = begin + 2;
					}
					*ss << "]" << ENDL << "Size = " << contb.size() << ENDL << ENDL;
					return (ss); }

		case 72: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);
					typename container<T>::const_reverse_iterator begin = contb.rbegin();	begin++;	begin++;
					test_name = "Displaying vector with ::const_reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying unary plus [begin = begin + 2] = |";
					begin = begin + (-2);
					*ss << "|" << ENDL << "Size = " << contb.size() << ENDL << ENDL;
					return (ss); }

		case 73: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);
					typename container<T>::const_reverse_iterator begin = contb.rend(); begin--;
					test_name = "Displaying vector with ::const_reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying unary plus [begin = begin + (-2)] = |";
					begin = begin + (-2);
					*ss << "|" << ENDL << "Size = " << contb.size() << ENDL << ENDL;
					return (ss); }

		case 74: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);
					typename container<T>::const_reverse_iterator begin = contb.rbegin();
					test_name = "Displaying vector with ::const_reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying unary minus [begin = begin - (-2)] = |";
					begin = begin - (-2);
					*ss << "|" << ENDL << "Size = " << contb.size() << ENDL << ENDL;
					return (ss); }

		case 75: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1);	container<T> const contb(cont);
					typename container<T>::const_reverse_iterator begin = contb.rbegin();
					typename container<T>::const_reverse_iterator end = contb.rend();
					test_name = "Displaying vector with ::const_reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Iterating through addition (begin = 2 + begin) = [";
					while (begin != end)
						begin = 2 + begin;
					*ss << "]" << ENDL << "Size = " << contb.size() << ENDL << ENDL;
					return (ss); }

		case 76: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);
					typename container<T>::const_reverse_iterator begin = contb.rbegin();	begin++;	begin++;
					test_name = "Displaying vector with ::const_reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying through subtraction (begin = -2 + begin) = [";
					*ss << *begin << " ";
					begin = -2 + begin;
					*ss << *begin << " ";
					*ss << "]" << ENDL << "Size = " << contb.size() << ENDL << ENDL;
					return (ss); }

		case 77: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);
					typename container<T>::const_reverse_iterator begin = contb.rbegin();
					typename container<T>::const_reverse_iterator end = contb.rend();
					test_name = "Displaying vector with ::const_reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying pointer difference ((begin - (end - 1))): |" << (begin - (end - 1)) << "|" << ENDL << ENDL;
					return (ss); }

		case 78: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);
					typename container<T>::const_reverse_iterator begin = contb.rbegin();
					typename container<T>::const_reverse_iterator end = contb.rend();
					typename container<T>::const_reverse_iterator it = contb.rbegin();	it++;	it++;
					test_name = "Displaying vector with ::const_reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying inequalities" << ENDL;
					while (begin != end)
					{
						*ss << "|" << *begin << "| compared to |" << *it << "|" << ENDL;
						if (begin < it)
							*ss << "begin < it" << ENDL;
						if (begin > it)
							*ss << "begin > it" << ENDL;
						if (begin <= it)
							*ss << "begin <= it" << ENDL;
						if (begin >= it)
							*ss << "begin >= it" << ENDL;
						begin++;
					}
					*ss << ENDL << ENDL;
					return (ss); }

		case 79: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1);	container<T> const contb(cont);
					typename container<T>::const_reverse_iterator begin = contb.rbegin();
					typename container<T>::const_reverse_iterator end = contb.rend();
					test_name = "Displaying vector with ::const_reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	cont.push_back(1);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying elements through addition-assignment (begin += 2;) = [";
					while (begin != end)
					{
						*ss << *begin << " ";
						begin += 2;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 80: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);
					typename container<T>::const_reverse_iterator begin = contb.rbegin();	begin++;	begin++;
					test_name = "Displaying vector with ::const_reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying elements through subtraction-assignment (begin -= 2;) = [";
					*ss << *begin << " ";
					begin -= 2;
					*ss << *begin << "]" << ENDL << "Size = " << contb.size() << ENDL << ENDL;
					return (ss); }

		case 81: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);
					typename container<T>::const_reverse_iterator begin = contb.rend();	begin--;
					test_name = "Displaying vector with ::const_reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Displaying elements through subtraction-assignment (rend -= 2;) = [";
					size_t i = 0;
					begin -= 2;
					*ss << begin[i] << "]" << ENDL << "Size = " << contb.size() << ENDL << ENDL;
					return (ss); }

		case 82: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);
					typename container<T>::const_reverse_iterator begin = contb.rbegin();
					test_name = "Displaying vector with ::const_reverse_iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Accessing through begin[2] = |" << begin[2] << "| " << ENDL << "Size = " << contb.size() << ENDL << ENDL;
					return (ss); }

/* Capacity */
	/* size */
		case 83: {	container<T> cont(4, 42);
					test_name = "cont.size();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(4, 42);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 84: {	container<T> cont;
					test_name = "cont.size();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 85: {	container<T> cont(0);
					test_name = "cont.size();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(0);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

	/* max_size */
		case 86: {	container<T> cont(4, 42);
					test_name = "cont.max_size();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(4, 42);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL << ENDL;
					return (ss); }

		case 87: {	container<T> cont;
					test_name = "cont.max_size();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL << ENDL;
					return (ss); }

		case 88: {	container<T> cont(0);
					test_name = "cont.max_size();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(0);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL << ENDL;
					return (ss); }

	/* resize */
		case 89: {	container<T> cont(4, 42);	cont.resize(3);
					test_name = "cont.resize(3);";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(4, 42);" << ENDL << test_name << ENDL;
					*ss << "After resize, Size = " << cont.size() << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL;
					*ss << "Capacity = " << cont.capacity() << ENDL << ENDL;
					return (ss); }

		case 90: {	container<T> cont(4, 42);	cont.resize(6);
					test_name = "cont.resize(6);";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(4, 42);" << ENDL << test_name << ENDL;
					*ss << "After resize, Size = " << cont.size() << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL;
					*ss << "Capacity = " << cont.capacity() << ENDL << ENDL;
					return (ss); }

		case 91: {	container<T> cont(4, 42);	cont.resize(0);
					test_name = "cont.resize(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(4, 42);" << ENDL << test_name << ENDL;
					*ss << "After resize, Size = " << cont.size() << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL;
					*ss << "Capacity = " << cont.capacity() << ENDL << ENDL;
					return (ss); }

		case 92: {	container<T> cont;	cont.resize(3);
					test_name = "cont.resize(3);";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL << test_name << ENDL;
					*ss << "After resize, Size = " << cont.size() << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL;
					*ss << "Capacity = " << cont.capacity() << ENDL << ENDL;
					return (ss); }

		case 93: {	container<T> cont;	cont.resize(0);
					test_name = "cont.resize(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL << test_name << ENDL;
					*ss << "After resize, Size = " << cont.size() << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL;
					*ss << "Capacity = " << cont.capacity() << ENDL << ENDL;
					return (ss); }

		case 94: {	container<T> cont(4, 42);	cont.resize(3, -1);
					test_name = "cont.resize(3, -1);";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(4, 42);" << ENDL << test_name << ENDL;
					*ss << "After resize, Size = " << cont.size() << ENDL << "Max_size = " << cont.max_size() << ENDL << ENDL;
					return (ss); }

		case 95: {	container<T> cont(4, 42);	cont.resize(6, -1);
					test_name = "cont.resize(3, -1);";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(4, 42);" << ENDL << test_name << ENDL;
					*ss << "After resize, Size = " << cont.size() << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL;
					*ss << "Capacity = " << cont.capacity() << ENDL << ENDL;
					return (ss); }

		case 96: {	container<T> cont(4, 42);	cont.resize(0, -1);
					test_name = "cont.resize(0, -1);";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(4, 42);" << ENDL << test_name << ENDL;
					*ss << "After resize, Size = " << cont.size() << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL;
					*ss << "Capacity = " << cont.capacity() << ENDL << ENDL;
					return (ss); }

		case 97: {	container<T> cont;	cont.resize(3, -1);
					test_name = "cont.resize(3, -1);";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL << test_name << ENDL;
					*ss << "After resize, Size = " << cont.size() << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL;
					*ss << "Capacity = " << cont.capacity() << ENDL << ENDL;
					return (ss); }

		case 98: {	container<T> cont;	cont.resize(0, -1);
					test_name = "cont.resize(0, -1);";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL << test_name << ENDL;
					*ss << "After resize, Size = " << cont.size() << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL;
					*ss << "Capacity = " << cont.capacity() << ENDL << ENDL;
					return (ss); }

	/* capacity */
		case 99: {	container<T> cont(4, 42);
					test_name = "cont.capacity();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(4, 42);" << ENDL << test_name << ENDL;
					*ss << "Capacity = " << cont.capacity() << ENDL << ENDL;
					return (ss); }

		case 100: {	container<T> cont(0);
					test_name = "cont.capacity();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(0);" << ENDL << test_name << ENDL;
					*ss << "Capacity = " << cont.capacity() << ENDL << ENDL;
					return (ss); }

		case 101: {	container<T> cont;
					test_name = "cont.capacity();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL << test_name << ENDL;
					*ss << "Capacity = " << cont.capacity() << ENDL << ENDL;
					return (ss); }

	/* empty */
		case 102: {	container<T> cont;
					test_name = "cont.empty();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << cont.empty() << ENDL << ENDL;
					return (ss); }

		case 103: {	container<T> cont(4, 42);
					test_name = "cont.empty();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(4, 42);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << cont.empty() << ENDL << ENDL;
					return (ss); }

		case 104: {	container<T> cont(0, 42);
					test_name = "cont.empty();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(0, 42);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << cont.empty() << ENDL << ENDL;
					return (ss); }

	/* reserve */
		case 105: {	container<T> cont(4, 42);	cont.reserve(3);
					test_name = "cont.reserve(3);";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(4, 42);" << ENDL << test_name << ENDL;
					*ss << "After reserve, Size = " << cont.size() << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL;
					*ss << "Capacity = " << cont.capacity() << ENDL << ENDL;
					return (ss); }

		case 106: {	container<T> cont(4, 42);	cont.reserve(6);
					test_name = "cont.reserve(6);";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(4, 42);" << ENDL << test_name << ENDL;
					*ss << "After reserve, Size = " << cont.size() << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL;
					*ss << "Capacity = " << cont.capacity() << ENDL << ENDL;
					return (ss); }

		case 107: {	container<T> cont(4, 42);	cont.reserve(0);
					test_name = "cont.reserve(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(4, 42);" << ENDL << test_name << ENDL;
					*ss << "After reserve, Size = " << cont.size() << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL;
					*ss << "Capacity = " << cont.capacity() << ENDL << ENDL;
					return (ss); }

		case 108: {	container<T> cont;	cont.reserve(3);
					test_name = "cont.reserve(3);";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL << test_name << ENDL;
					*ss << "After reserve, Size = " << cont.size() << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL;
					*ss << "Capacity = " << cont.capacity() << ENDL << ENDL;
					return (ss); }

		case 109: {	container<T> cont;	cont.reserve(0);
					test_name = "cont.reserve(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL << test_name << ENDL;
					*ss << "After reserve, Size = " << cont.size() << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL;
					*ss << "Capacity = " << cont.capacity() << ENDL << ENDL;
					return (ss); }

		case 110: {	container<T> cont;
					test_name = "cont.reserve(cont.max_size() + 1);";
					std::stringstream * ss = new std::stringstream();
					try
					{
						cont.reserve(cont.max_size() + 1);
					}
					catch(std::length_error & e)
					{
						*ss << "Error message: |" << e.what() << "|\n";
					}
					*ss << cont_name + " cont;" << ENDL << test_name << ENDL;
					*ss << "After reserve, Size = " << cont.size() << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL;
					*ss << "Capacity = " << cont.capacity() << ENDL << ENDL;
					return (ss); }

/* Element Access */
	/* operator[] for non constant container */
		case 111: {	container<T> cont(1, 42);	cont.push_back(23);	cont.push_back(12);
					test_name = "Displaying cont[0] cont[1] cont[2]";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(1, 42);	cont.push_back(23));	cont.push_back(12));" << ENDL << test_name << ENDL;
					*ss << cont[0] << ENDL;
					*ss << cont[1] << ENDL;
					*ss << cont[2] << ENDL;
					return (ss); }

		case 112: {	container<T> cont(1, 42);	cont.push_back(23);	cont.push_back(12);
					test_name = "Displaying cont[2], modifying cont[2], displaying cont[2]";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(1, 42);	cont.push_back(23));	cont.push_back(12));" << ENDL << test_name << ENDL;
					*ss << cont[2] << ENDL;
					cont[2] = 2;
					*ss << cont[2] << ENDL;
					return (ss); }

	/* operator[] for constant container */
		case 113: {	container<T> cont(1, 42);	cont.push_back(23);	cont.push_back(12);	container<T> const contb(cont);
					test_name = "Displaying contb[0] contb[1] contb[2]";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(1, 42);	cont.push_back(23));	cont.push_back(12));	container<T> const contb(cont);" << ENDL << test_name << ENDL;
					*ss << contb[0] << ENDL;
					*ss << contb[1] << ENDL;
					*ss << contb[2] << ENDL;
					return (ss); }

	/* at for non constant container */
		case 114: {	container<T> cont(1, 42);	cont.push_back(23);	cont.push_back(12);
					test_name = "Displaying cont.at(0), cont.at(1), cont.at(2)";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(1, 42);	cont.push_back(23));	cont.push_back(12));" << ENDL << test_name << ENDL;
					*ss << cont.at(0) << ENDL;
					*ss << cont.at(1) << ENDL;
					*ss << cont.at(2) << ENDL;
					return (ss); }

		case 115: {	container<T> cont(1, 42);	cont.push_back(23);	cont.push_back(12);
					test_name = "Displaying cont.at(2), modifyng cont.at(2), displaying cont.at(2)";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(1, 42);	cont.push_back(23));	cont.push_back(12));" << ENDL << test_name << ENDL;
					*ss << cont.at(2) << ENDL;
					cont.at(2) = 2;
					*ss << cont.at(2) << ENDL;
					return (ss); }

		case 116: {	container<T> cont(1, 42);	cont.push_back(23);	cont.push_back(12);
					test_name = "Displaying cont.at(-1)";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(1, 42);	cont.push_back(23));	cont.push_back(12));" << ENDL << test_name << ENDL;
					try
					{
						*ss << cont.at(-1) << ENDL;
					}
					catch(const std::exception& e)
					{
						*ss << "Error message: |" << e.what() << "|\n";
					}
					return (ss); }

		case 117: {	container<T> cont(1, 42);	cont.push_back(23);	cont.push_back(12);
					test_name = "Displaying cont.at(10)";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(1, 42);	cont.push_back(23));	cont.push_back(12));" << ENDL << test_name << ENDL;
					try
					{
						*ss << cont.at(10) << ENDL;
					}
					catch(const std::exception& e)
					{
						*ss << "Error message: |" << e.what() << "|\n";
					}
					return (ss); }

	/* at for constant container */
		case 118: {	container<T> cont(1, 42);	cont.push_back(23);	cont.push_back(12);	container<T> const contb(cont);
					test_name = "Displaying contb.at(0), contb.at(1), contb.at(2)";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(1, 42);	cont.push_back(23));	cont.push_back(12));	container<T> const contb(cont);" << ENDL << test_name << ENDL;
					*ss << contb.at(0) << ENDL;
					*ss << contb.at(1) << ENDL;
					*ss << contb.at(2) << ENDL;
					return (ss); }

		case 119: {	container<T> cont(1, 42);	cont.push_back(23);	cont.push_back(12);	container<T> const contb(cont);
					test_name = "Displaying contb.at(-1)";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(1, 42);	cont.push_back(23));	cont.push_back(12));	container<T> const contb(cont);" << ENDL << test_name << ENDL;
					try
					{
						*ss << contb.at(-1) << ENDL;
					}
					catch(const std::exception& e)
					{
						*ss << "Error message: |" << e.what() << "|\n";
					}
					return (ss); }

		case 120: {	container<T> cont(1, 42);	cont.push_back(23);	cont.push_back(12);	container<T> const contb(cont);
					test_name = "Displaying contb.at(10)";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(1, 42);	cont.push_back(23));	cont.push_back(12));	container<T> const contb(cont);" << ENDL << test_name << ENDL;
					try
					{
						*ss << contb.at(10) << ENDL;
					}
					catch(const std::exception& e)
					{
						*ss << "Error message: |" << e.what() << "|\n";
					}
					return (ss); }

	/* front on non-constant container */
		case 121: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					test_name = "Display cont.front()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "cont.front() (should be 42) = " << cont.front() << ENDL << ENDL;
					return (ss); }

		case 122: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					cont.front() = -13;
					test_name = "Assign to reference : cont.front() = -13";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "cont.front() (should be -13) = " << cont.front() << ENDL << ENDL;
					return (ss); }

	/* front on constant container */
		case 123: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);
					test_name = "Display contb.front()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "contb.front() (should be 42) = " << contb.front() << ENDL << ENDL;
					return (ss); }

	/* back on non-constant container */
		case 124: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					test_name = "Display cont.back()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "cont.back() (should be 5) = " << cont.back() << ENDL << ENDL;
					return (ss); }

		case 125: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);
					cont.back() = -13;
					test_name = "Assign to reference : cont.back() = -13";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "cont.back() (should be -13) = " << cont.back() << ENDL << ENDL;
					return (ss); }

	/* back on constant container */
		case 126: {	container<T> cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);
					test_name = "Display contb.back()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push_back(42);	cont.push_back(23);	cont.push_back(5);	container<T> const contb(cont);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "contb.back() (should be 5) = " << contb.back() << ENDL << ENDL;
					return (ss); }

/* Modifiers */
	/* assign */
		case 127: {	container<T> cont(5, 42);	container<T> cont_new(7, 3);	typename container<T>::iterator begin = cont_new.begin();	typename container<T>::iterator end = cont_new.end();	cont.assign(begin, end);
					test_name = cont_name + " cont(5, 42);	container<T> cont_new(7, 3);	typename container<T>::iterator begin = cont_new.begin();	typename container<T>::iterator end = cont_new.end();	cont.assign(begin, end);";
					std::stringstream * ss = new std::stringstream();
					std::stringstream *ss1 = print_cont(cont, "Displaying elements");
					*ss << test_name << ENDL;
					*ss << "Max_size() = |" << cont.max_size() << "|\n";
					*ss << "Capacity() = |" << cont.capacity() << "|\n";
					*ss << ss1->str() << ENDL << ENDL;					
					delete ss1;
					return (ss); }

		case 128: {	container<T> cont(5, 42);	cont.assign(7, 3);
					test_name = cont_name + " cont(5, 42);	cont.assign(7, 3);";
					std::stringstream * ss = new std::stringstream();
					std::stringstream *ss1 = print_cont(cont, "Displaying elements");
					*ss << test_name << ENDL;
					*ss << "Max_size() = |" << cont.max_size() << "|\n";
					*ss << "Capacity() = |" << cont.capacity() << "|\n";
					*ss << ss1->str() << ENDL << ENDL;					
					delete ss1;
					return (ss); }

		case 129: {	container<T> cont(5, 42);	cont.assign(1, 3);
					test_name = cont_name + " cont(5, 42);	cont.assign(1, 3);";
					std::stringstream * ss = new std::stringstream();
					std::stringstream *ss1 = print_cont(cont, "Displaying elements");
					*ss << test_name << ENDL;
					*ss << "Max_size() = |" << cont.max_size() << "|\n";
					*ss << "Capacity() = |" << cont.capacity() << "|\n";
					*ss << ss1->str() << ENDL << ENDL;					
					delete ss1;
					return (ss); }

	/* push_back, pop_back */
		case 130: {	container<T> cont(5, 42);	cont.push_back(12);
					test_name = "cont(5, 42);	cont.push_back(12);";
					_cont = cont;
					break;	}

		case 131: {	container<T> cont;	cont.push_back(12);
					test_name = "cont;	cont.push_back(12);";
					_cont = cont;
					break;	}
					
		case 132: {	container<T> cont(1, 0);	cont.pop_back();
					test_name = "cont(1, 0);	cont.pop_back();";
					_cont = cont;
					break;	}
					
		case 133: {	container<T> cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	cont.pop_back();
					test_name = "cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	cont.pop_back();";
					_cont = cont;
					break;	}
					
	/* insert */
		case 134: {	container<T> cont(5, 42);	typename container<T>::iterator begin = cont.begin();	cont.insert(begin, 23);
					test_name = "cont(5, 42);	typename container<T>::iterator begin = cont.begin();	cont.insert(begin, 23);";
					_cont = cont;
					break;	}
					
		case 135: {	container<T> cont(5, 42);	typename container<T>::iterator begin = cont.begin();	begin++;	cont.insert(begin, 23);
					test_name = "cont(5, 42);	typename container<T>::iterator begin = cont.begin();	begin++;	cont.insert(begin, 23);";
					_cont = cont;
					break;	}
					
		case 136: {	container<T> cont(5, 42);	typename container<T>::iterator end = cont.end();	cont.insert(end, 23);
					test_name = "cont(5, 42);	typename container<T>::iterator end = cont.end();	cont.insert(end, 23);";
					_cont = cont;
					break;	}
					
		case 137: {	container<T> cont(5, 42);	typename container<T>::iterator end = cont.end();	end--;	cont.insert(end, 23);
					test_name = "cont(5, 42);	typename container<T>::iterator end = cont.end();	end--;	cont.insert(end, 23);";
					_cont = cont;
					break;	}
					
		case 138: {	container<T> cont(5, 42);	typename container<T>::iterator end = cont.end();	end--;	cont.insert(end, 3, 23);
					test_name = "cont(5, 42);	typename container<T>::iterator end = cont.end();	end--;	cont.insert(end, 3, 23);";
					_cont = cont;
					break;	}

		case 139: {	container<T> cont(5, 42);	typename container<T>::iterator end = cont.end();	container<T> contb(3, 28);	typename container<T>::iterator first = contb.begin();	typename container<T>::iterator last = contb.end();	end--;	cont.insert(end, first, last);
					test_name = "cont(5, 42);	typename container<T>::iterator end = cont.end();	container<T> contb(3, 28);	typename container<T>::iterator first = contb.begin();	typename container<T>::iterator last = contb.end();	end--;	cont.insert(end, first, last);";
					_cont = cont;
					break;	}

	/* erase */
		case 140: {	container<T> cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	typename container<T>::iterator begin = cont.begin();	cont.erase(begin);
					test_name = "cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	typename container<T>::iterator begin = cont.begin();	cont.erase(begin);";
					_cont = cont;
					break;	}

		case 141: {	container<T> cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	typename container<T>::iterator begin = cont.begin();	begin++;	cont.erase(begin);
					test_name = "cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	typename container<T>::iterator begin = cont.begin();	begin++;	cont.erase(begin);";
					_cont = cont;
					break;	}

		case 142: {	container<T> cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	typename container<T>::iterator last = cont.end();	last--; cont.erase(last);
					test_name = "cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	typename container<T>::iterator last = cont.end();	last--; cont.erase(last);";
					_cont = cont;
					break;	}

		case 143: {	container<T> cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	cont.push_back(4);	cont.push_back(5);	typename container<T>::iterator begin = cont.begin();	begin++;	typename container<T>::iterator end = cont.end();	end--;	cont.erase(begin, end);
					test_name = "cont;	cont.push_back(1);	cont.push_back(2);	cont.push_back(3);	cont.push_back(4);	cont.push_back(5);	typename container<T>::iterator begin = cont.begin();	begin++;	typename container<T>::iterator end = cont.end();	end--;	cont.erase(begin, end);";
					_cont = cont;
					break;	}

	/* swap */
		case 144: {	container<T> cont(5, 42);	container<T> contb(3, 23);	cont.swap(contb);
					std::stringstream * ss = new std::stringstream();
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << cont_name + "cont(5, 42);	container<T> contb(3, 23);	cont.swap(contb);" << ENDL;
					*ss << ss1->str() << ENDL;
					*ss << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }

		case 145: {	container<T> cont(5, 42);	container<T> contb(0);	cont.swap(contb);
					std::stringstream * ss = new std::stringstream();
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << cont_name + "cont(5, 42);	container<T> contb(3, 23);	cont.swap(contb);" << ENDL;
					*ss << ss1->str() << ENDL;
					*ss << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }
		
		case 146: {	container<T> cont(0);	container<T> contb(5, 42);	cont.swap(contb);
					std::stringstream * ss = new std::stringstream();
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << cont_name + "cont(0);	container<T> contb(5, 42);	cont.swap(contb);" << ENDL;
					*ss << ss1->str() << ENDL;
					*ss << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }
		
		case 147: {	container<T> cont;	container<T> contb(5, 42);	cont.swap(contb);
					std::stringstream * ss = new std::stringstream();
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << cont_name + "cont;	container<T> contb(5, 42);	cont.swap(contb);" << ENDL;
					*ss << ss1->str() << ENDL;
					*ss << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }
		
		case 148: {	container<T> cont(5, 42);	container<T> contb;	cont.swap(contb);
					std::stringstream * ss = new std::stringstream();
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << cont_name + "cont(5, 42);	container<T> contb;	cont.swap(contb);" << ENDL;
					*ss << ss1->str() << ENDL;
					*ss << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }
		
		case 149: {	container<T> cont;	container<T> contb;	cont.swap(contb);
					std::stringstream * ss = new std::stringstream();
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << cont_name + "cont;	container<T> contb;	cont.swap(contb);" << ENDL;
					*ss << ss1->str() << ENDL;
					*ss << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }
		
	/* clear */
		case 150: {	container<T> cont(5, 42);	cont.clear();
					test_name = "cont(5, 42);	cont.clear();";
					_cont = cont;
					break;	}

		case 151: {	container<T> cont(0);	cont.clear();
					test_name = "cont(0);	cont.clear();";
					_cont = cont;
					break;	}

		case 152: {	container<T> cont;	cont.clear();
					test_name = "cont;	cont.clear();";
					_cont = cont;
					break;	}

/* Non-member function overloads */
	/* operator== */
		case 153: {	container<T> cont(1, 3);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 3);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont == contb) (0 = no, 1 = yes): " << (cont == contb) << ENDL;
					return (ss); }

		case 154: {	container<T> cont(1, 42);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 42);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont == contb) (0 = no, 1 = yes): " << (cont == contb) << ENDL;
					return (ss); }

		case 155: {	container<T> cont(0);	container<T> contb(0);
					test_name = cont_name + " " + "cont(0);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont == contb) (0 = no, 1 = yes): " << (cont == contb) << ENDL;
					return (ss); }

		case 156: {	container<T> cont(5, 42);	container<T> contb(0);
					test_name = cont_name + " " + "cont(5, 42);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont == contb) (0 = no, 1 = yes): " << (cont == contb) << ENDL;
					return (ss); }

	/* operator!= */
		case 157: {	container<T> cont(1, 3);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 3);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont != contb) (0 = no, 1 = yes): " << (cont != contb) << ENDL;
					return (ss); }

		case 158: {	container<T> cont(1, 42);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 42);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont != contb) (0 = no, 1 = yes): " << (cont != contb) << ENDL;
					return (ss); }

		case 159: {	container<T> cont(0);	container<T> contb(0);
					test_name = cont_name + " " + "cont(0);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont != contb) (0 = no, 1 = yes): " << (cont != contb) << ENDL;
					return (ss); }

		case 160: {	container<T> cont(5, 42);	container<T> contb(0);
					test_name = cont_name + " " + "cont(5, 42);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont != contb) (0 = no, 1 = yes): " << (cont != contb) << ENDL;
					return (ss); }

	/* operator< */
		case 161: {	container<T> cont(1, 3);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 3);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont < contb) (0 = no, 1 = yes): " << (cont < contb) << ENDL;
					return (ss); }

		case 162: {	container<T> cont(1, 42);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 42);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont < contb) (0 = no, 1 = yes): " << (cont < contb) << ENDL;
					return (ss); }

		case 163: {	container<T> cont(0);	container<T> contb(0);
					test_name = cont_name + " " + "cont(0);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont < contb) (0 = no, 1 = yes): " << (cont < contb) << ENDL;
					return (ss); }

		case 164: {	container<T> cont(5, 42);	container<T> contb(0);
					test_name = cont_name + " " + "cont(5, 42);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont < contb) (0 = no, 1 = yes): " << (cont < contb) << ENDL;
					return (ss); }

	/* operator<= */
		case 165: {	container<T> cont(1, 3);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 3);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont <= contb) (0 = no, 1 = yes): " << (cont <= contb) << ENDL;
					return (ss); }

		case 166: {	container<T> cont(1, 42);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 42);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont <= contb) (0 = no, 1 = yes): " << (cont <= contb) << ENDL;
					return (ss); }

		case 167: {	container<T> cont(0);	container<T> contb(0);
					test_name = cont_name + " " + "cont(0);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont <= contb) (0 = no, 1 = yes): " << (cont <= contb) << ENDL;
					return (ss); }

		case 168: {	container<T> cont(5, 42);	container<T> contb(0);
					test_name = cont_name + " " + "cont(5, 42);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont <= contb) (0 = no, 1 = yes): " << (cont <= contb) << ENDL;
					return (ss); }

	/* operator> */
		case 169: {	container<T> cont(1, 3);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 3);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont > contb) (0 = no, 1 = yes): " << (cont > contb) << ENDL;
					return (ss); }

		case 170: {	container<T> cont(1, 42);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 42);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont > contb) (0 = no, 1 = yes): " << (cont > contb) << ENDL;
					return (ss); }

		case 171: {	container<T> cont(0);	container<T> contb(0);
					test_name = cont_name + " " + "cont(0);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont > contb) (0 = no, 1 = yes): " << (cont > contb) << ENDL;
					return (ss); }

		case 172: {	container<T> cont(5, 42);	container<T> contb(0);
					test_name = cont_name + " " + "cont(5, 42);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont > contb) (0 = no, 1 = yes): " << (cont > contb) << ENDL;
					return (ss); }

	/* operator>= */
		case 173: {	container<T> cont(1, 3);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 3);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont >= contb) (0 = no, 1 = yes): " << (cont >= contb) << ENDL;
					return (ss); }

		case 174: {	container<T> cont(1, 42);	container<T> contb(1, 3);
					test_name = cont_name + " " + "cont(1, 42);	container<T> contb(1, 3);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont >= contb) (0 = no, 1 = yes): " << (cont >= contb) << ENDL;
					return (ss); }

		case 175: {	container<T> cont(0);	container<T> contb(0);
					test_name = cont_name + " " + "cont(0);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont >= contb) (0 = no, 1 = yes): " << (cont >= contb) << ENDL;
					return (ss); }

		case 176: {	container<T> cont(5, 42);	container<T> contb(0);
					test_name = cont_name + " " + "cont(5, 42);	container<T> contb(0);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont >= contb) (0 = no, 1 = yes): " << (cont >= contb) << ENDL;
					return (ss); }

	/* swap(vector) */
		case 177: {	container<T> cont(5, 42);	container<T> contb(3, 23);	swap(cont, contb);
					test_name = cont_name + " " + "cont(5, 42);	container<T> contb(3, 23);	swap(cont, contb);";
					std::stringstream * ss = new std::stringstream();
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << test_name << ENDL;
					*ss << ss1->str() << ss2->str() << ENDL << ENDL;					
					delete ss1;	delete ss2;
					return (ss); }

		case 178: {	container<T> cont(5, 42);	container<T> contb(0);	swap(cont, contb);
					test_name = cont_name + " " + "cont(5, 42);	container<T> contb(3, 23);	swap(cont, contb);";
					std::stringstream * ss = new std::stringstream();
					std::stringstream *ss1 = print_cont(cont, "container cont");
					std::stringstream *ss2 = print_cont(contb, "container contb");
					*ss << test_name << ENDL;
					*ss << ss1->str() << ss2->str() << ENDL << ENDL;					
					delete ss1;	delete ss2;
					return (ss); }

		case 179: {	container<T> cont(0);	container<T> contb(0);	swap(cont, contb);
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
void	vector_tester(std::string const & title, std::string const & type)
{
	std::string	category;

	COUT << BLUE << "*--- testing " + title + type + " . . . ---*" << RENDL;

	category = "=> Constructors: ";
	COUT << category;	
	for (int i = 1; i <= 7; i++)
		print_result(test_vector_container<stdcontainerT, T>(title + type), test_vector_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Destructors: ";
	COUT << category;	
	for (int i = 1; i <= 1; i++)
		print_result(test_vector_container<stdcontainerT, T>(title + type), test_vector_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Operator=: ";
	COUT << category;	
	for (int i = 1; i <= 2; i++)
		print_result(test_vector_container<stdcontainerT, T>(title + type), test_vector_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Iterators: ";
	COUT << category;	
	for (int i = 1; i <= 18; i++)
		print_result(test_vector_container<stdcontainerT, T>(title + type), test_vector_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Constant Iterators: ";
	COUT << category;	
	for (int i = 1; i <= 18; i++)
		print_result(test_vector_container<stdcontainerT, T>(title + type), test_vector_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Reverse Iterators: ";
	COUT << category;	
	for (int i = 1; i <= 18; i++)
		print_result(test_vector_container<stdcontainerT, T>(title + type), test_vector_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Constant Reverse Iterators: ";
	COUT << category;	
	for (int i = 1; i <= 18; i++)
		print_result(test_vector_container<stdcontainerT, T>(title + type), test_vector_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Capacity: ";
	COUT << category;	
	for (int i = 1; i <= 28; i++)
		print_result(test_vector_container<stdcontainerT, T>(title + type), test_vector_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Element Access: ";
	COUT << category;	
	for (int i = 1; i <= 16; i++)
		print_result(test_vector_container<stdcontainerT, T>(title + type), test_vector_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Modifiers: ";
	COUT << category;
	for (int i = 1; i <= 26; i++)
		print_result(test_vector_container<stdcontainerT, T>(title + type), test_vector_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Non-member function overloads: ";
	COUT << category;	
	for (int i = 1; i <= 27; i++)
		print_result(test_vector_container<stdcontainerT, T>(title + type), test_vector_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	std::cout << "COMPLETE !" << std::endl;
}

void vector_test(void)
{
	vector_tester<ft::vector, std::vector, int>("vector", "<int>");
	// tester<ft::vector, std::vector, char>("vector", "<char>");
	// tester<ft::vector, std::vector, float>("vector", "<float>");
}