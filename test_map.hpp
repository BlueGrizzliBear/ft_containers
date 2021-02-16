#include "main.hpp"

template <template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > > class container, class Key, class T>
std::stringstream *	test_map_container(std::string const & cont_name)
{
	container<Key, T>	_cont;
	std::pair<Key, T> some_values[] = {std::make_pair(1, "a"), std::make_pair(-11, "b"), std::make_pair(42, "c"), std::make_pair(-23, "d"), std::make_pair(-18, "e"), std::make_pair(154, "f")};
	std::string 	test_name;
	static int		a = 0;

	switch (++a)
	{
/* Constructors */
		case 1: {	container<Key, T> cont;
					test_name = "cont";
					_cont = cont;
					break;	}

		case 2: {	container<Key, T> cont;	cont[1];	cont[2];	typename container<Key, T>::iterator beg = cont.begin();	typename container<Key, T>::iterator end = cont.end();	container<Key, T> contb(beg, end);
					test_name = "cont;	cont[1];	cont[2];	typename container<Key, T>::iterator beg = cont.begin();	typename container<Key, T>::iterator end = cont.end();	container<Key, T> contb(beg, end);";
					_cont = contb;
					break;	}

		case 3: {	container<Key, T> cont;	cont[1];	cont[1];	typename container<Key, T>::iterator beg = cont.begin();	typename container<Key, T>::iterator end = cont.end();	container<Key, T> contb(beg, end);
					test_name = "cont;	cont[1];	cont[1];	typename container<Key, T>::iterator beg = cont.begin();	typename container<Key, T>::iterator end = cont.end();	container<Key, T> contb(beg, end);";
					_cont = contb;
					break;	}

		case 4: {	container<Key, T> cont;	typename container<Key, T>::iterator beg = cont.begin();	typename container<Key, T>::iterator end = cont.end();	container<Key, T> contb(beg, end);
					test_name = "cont;	cont[1];	cont[2];	typename container<Key, T>::iterator beg = cont.begin();	typename container<Key, T>::iterator end = cont.end();	container<Key, T> cont(beg, end);";
					_cont = contb;
					break;	}

		case 5: {	std::pair<Key, T> Arr[] = {std::make_pair(1, "a"), std::make_pair(-12, "b"), std::make_pair(42, "c"), std::make_pair(-42, "d"), std::make_pair(-142, "e"), std::make_pair(-2, "f")};
					container<Key, T> cont(Arr, Arr + 4);
					test_name = "cont(Arr, Arr + 4)";
					_cont = cont;
					break;	}

		case 6: {	std::pair<Key, T> Arr[] = {std::make_pair(1, "a"), std::make_pair(2, "b"), std::make_pair(3, "c"), std::make_pair(4, "d")};
					container<Key, T> cont(Arr, Arr + 4);
					test_name = "cont(Arr, Arr + 4)";
					_cont = cont;
					break;	}

		case 7: {	container<Key, T> cont;	cont[1]; cont[2];	container<Key, T> contb(cont);
					test_name = "cont;	cont[1]; cont[2];	container<Key, T> contb(cont);";
					_cont = contb;
					break;	}

/* Destructor */
		case 8: {	std::pair<Key, T> * a[2];
					a[0] = new std::pair<Key, T>(std::make_pair(1, "a"));
					a[1] = new std::pair<Key, T>(std::make_pair(1, "b"));
					container<Key, T> *cont = new container<Key, T>(*a, *a + 1);	delete cont;
					test_name = "*cont = new container<Key, T>(3, a);	delete cont;";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " " + test_name << ENDL;
					*ss << "std::pair<Key, T> a[0] (should be persistent) a[0].first|" << (*a[0]).first << "| and a[0].second|" << (*a[0]).second << "|" << ENDL << ENDL;
					delete a[0];	delete a[1];
					return (ss); }

/* Operator= */
		case 9: {	container<Key, T> cont;	cont[1]; cont[2];	container<Key, T> contbis;	contbis[3]; contbis[4];	cont = contbis;
					test_name = "cont;	cont[1]; cont[2];	container<Key, T> contbis;	contbis[3]; contbis[4];	cont = contbis;";
					_cont = cont;
					break;	}

		case 10: {	container<Key, T> cont;	cont[1]; cont[2];	container<Key, T> contbis;	cont = contbis;
					test_name = "cont;	cont[1]; cont[2];	container<Key, T> contbis;	cont = contbis;";
					_cont = cont;
					break;	}

/* Iterators */
	/* iterator : begin, end, iterating through iterators, operator-> and operator* */
		case 11: {	container<Key, T> cont;
					test_name = "cont.begin() == cont.end()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (cont.begin() == cont.end()) << ENDL << ENDL;
					return (ss); }

		case 12: {	container<Key, T> cont;	cont.insert(cont.begin(), std::make_pair(51, "fifty-one"));
					test_name = "cont.begin() != cont.end()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(some_values, some_values + 3);" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (cont.begin() != cont.end()) << ENDL << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 13: {	container<Key, T> cont;
					test_name = "Displaying elements with iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 14: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);
					test_name = "Displaying elements with iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(some_values[0], some_values[3]);" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 15: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();	--end;
					test_name = "Display *(cont.begin()) and *(--cont.end()), using operator*";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(some_values[0], some_values[3]);" << ENDL << test_name << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 1) = (" << (*begin).first << ":" << (*begin).second << "|" << ENDL;
					*ss << "Value (should be 42) = " << (*end).first << ":" << (*end).second << "|" << ENDL;
					return (ss); }

		case 16: {	container<Key, T> * cont = new container<Key, T>();	cont->insert(&some_values[0], &some_values[3]);
					typename container<Key, T>::iterator begin = cont->begin();
					typename container<Key, T>::iterator end = cont->end();	--end;
					test_name = "Display *(cont.begin()) and *(--cont.end())";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " * cont = new container<Key, T>();	cont->insert(&some_values[0], &some_values[3]);" << ENDL << test_name << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 1) = (" << (*begin).first << ":" << (*begin).second << "|" << ENDL;
					*ss << "Value (should be 42) = " << (*end).first << ":" << (*end).second << "|" << ENDL;
					delete cont;
					return (ss); }

		case 17: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);
					test_name = "Displaying elements with iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(some_values[0], some_values[3]);" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						begin++;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 18: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);
					test_name = "Displaying elements with iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(some_values[0], some_values[3]);" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Elements = [ ";
					begin++;
					begin--;
					end--;
					end++;
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						begin++;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

	/* const_iterator : begin, end, iterating through iterators, operator-> and operator* */
		case 19: {	container<Key, T> const cont;
					test_name = "cont.begin() == cont.end()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " const cont;" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (cont.begin() == cont.end()) << ENDL << ENDL;
					return (ss); }

		case 20: {	container<Key, T> cont;	cont.insert(cont.begin(), std::make_pair(51, "fifty-one"));	container<Key, T> const contb(cont);	
					test_name = "contb.begin() != contb.end()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(cont.begin(), std::make_pair(51, \"fifty-one\"));	container<Key, T> const contb(cont);" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (contb.begin() != contb.end()) << ENDL << ENDL;
					typename container<Key, T>::const_iterator begin = contb.begin();
					typename container<Key, T>::const_iterator end = contb.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << contb.size() << ENDL << ENDL;
					return (ss); }

		case 21: {	container<Key, T> const cont;
					test_name = "Displaying elements with iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL << test_name << ENDL;
					typename container<Key, T>::const_iterator begin = cont.begin();
					typename container<Key, T>::const_iterator end = cont.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 22: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> const contb(cont);	
					test_name = "Displaying elements with iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> contb(cont);" << ENDL << test_name << ENDL;
					typename container<Key, T>::const_iterator begin = contb.begin();
					typename container<Key, T>::const_iterator end = contb.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << contb.size() << ENDL << ENDL;
					return (ss); }

		case 23: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> const contb(cont);
					typename container<Key, T>::const_iterator begin = contb.begin();
					typename container<Key, T>::const_iterator end = contb.end();	--end;
					test_name = "Display *(contb.begin()) and *(--contb.end()), using operator*";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> contb(cont);" << ENDL << test_name << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 1) = (" << (*begin).first << ":" << (*begin).second << "|" << ENDL;
					*ss << "Value (should be 42) = " << (*end).first << ":" << (*end).second << "|" << ENDL;
					return (ss); }

		case 24: {	container<Key, T> * cont = new container<Key, T>();	cont->insert(&some_values[0], &some_values[3]);	container<Key, T> const contb(*cont);
					typename container<Key, T>::const_iterator begin = contb.begin();
					typename container<Key, T>::const_iterator end = contb.end();	--end;
					test_name = "Display *(contb.begin()) and *(--contb.end())";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " * cont = new container<Key, T>();	cont->insert(&some_values[0], &some_values[3]);	container<Key, T> contb(cont);" << ENDL << test_name << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 1) = (" << (*begin).first << ":" << (*begin).second << "|" << ENDL;
					*ss << "Value (should be 42) = " << (*end).first << ":" << (*end).second << "|" << ENDL;
					delete cont;
					return (ss); }

		case 25: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> const contb(cont);
					test_name = "Displaying elements with iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> contb(cont);" << ENDL << test_name << ENDL;
					typename container<Key, T>::const_iterator begin = contb.begin();
					typename container<Key, T>::const_iterator end = contb.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						begin++;
					}
					*ss << "]" << ENDL << "Size = " << contb.size() << ENDL << ENDL;
					return (ss); }

		case 26: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> const contb(cont);
					test_name = "Displaying elements with iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> contb(cont);" << ENDL << test_name << ENDL;
					typename container<Key, T>::const_iterator begin = contb.begin();
					typename container<Key, T>::const_iterator end = contb.end();
					*ss << "Elements = [ ";
					begin++;
					begin--;
					end--;
					end++;
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						begin++;
					}
					*ss << "]" << ENDL << "Size = " << contb.size() << ENDL << ENDL;
					return (ss); }

	/* reverse_iterator : begin, end, iterating through iterators, operator-> and operator* */
		case 27: {	container<Key, T> cont;
					test_name = "cont.rbegin() == cont.rend()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (cont.rbegin() == cont.rend()) << ENDL << ENDL;
					return (ss); }

		case 28: {	container<Key, T> cont;	cont.insert(cont.begin(), std::make_pair(51, "fifty-one"));
					test_name = "cont.rbegin() != cont.rend()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(some_values, some_values + 3);" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (cont.rbegin() != cont.rend()) << ENDL << ENDL;
					typename container<Key, T>::reverse_iterator begin = cont.rbegin();
					typename container<Key, T>::reverse_iterator end = cont.rend();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 29: {	container<Key, T> cont;
					test_name = "Displaying elements with iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL << test_name << ENDL;
					typename container<Key, T>::reverse_iterator begin = cont.rbegin();
					typename container<Key, T>::reverse_iterator end = cont.rend();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 30: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);
					test_name = "Displaying elements with iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(some_values[0], some_values[3]);" << ENDL << test_name << ENDL;
					typename container<Key, T>::reverse_iterator begin = cont.rbegin();
					typename container<Key, T>::reverse_iterator end = cont.rend();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 31: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);
					typename container<Key, T>::reverse_iterator begin = cont.rbegin();
					typename container<Key, T>::reverse_iterator end = cont.rend();	--end;
					test_name = "Display *(cont.rbegin()) and *(--cont.rend()), using operator*";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(some_values[0], some_values[3]);" << ENDL << test_name << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 1) = (" << (*begin).first << ":" << (*begin).second << "|" << ENDL;
					*ss << "Value (should be 42) = " << (*end).first << ":" << (*end).second << "|" << ENDL;
					return (ss); }

		case 32: {	container<Key, T> * cont = new container<Key, T>();	cont->insert(&some_values[0], &some_values[3]);
					typename container<Key, T>::reverse_iterator begin = cont->rbegin();
					typename container<Key, T>::reverse_iterator end = cont->rend();	--end;
					test_name = "Display *(cont.rbegin()) and *(--cont.rend())";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " * cont = new container<Key, T>();	cont->insert(&some_values[0], &some_values[3]);" << ENDL << test_name << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 1) = (" << (*begin).first << ":" << (*begin).second << "|" << ENDL;
					*ss << "Value (should be 42) = " << (*end).first << ":" << (*end).second << "|" << ENDL;
					delete cont;
					return (ss); }

		case 33: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);
					test_name = "Displaying elements with iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(some_values[0], some_values[3]);" << ENDL << test_name << ENDL;
					typename container<Key, T>::reverse_iterator begin = cont.rbegin();
					typename container<Key, T>::reverse_iterator end = cont.rend();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						begin++;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 34: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);
					test_name = "Displaying elements with iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(some_values[0], some_values[3]);" << ENDL << test_name << ENDL;
					typename container<Key, T>::reverse_iterator begin = cont.rbegin();
					typename container<Key, T>::reverse_iterator end = cont.rend();
					*ss << "Elements = [ ";
					begin++;
					begin--;
					end--;
					end++;
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						begin++;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

	/* const_reverse_iterator : begin, end, iterating through iterators, operator-> and operator* */
		case 35: {	container<Key, T> const cont;
					test_name = "cont.rbegin() == cont.rend()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " const cont;" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (cont.rbegin() == cont.rend()) << ENDL << ENDL;
					return (ss); }

		case 36: {	container<Key, T> cont;	cont.insert(cont.begin(), std::make_pair(51, "fifty-one"));	container<Key, T> const contb(cont);	
					test_name = "contb.rbegin() != contb.rend()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(cont.begin(), std::make_pair(51, \"fifty-one\"));	container<Key, T> const contb(cont);" << ENDL << test_name << ENDL;
					*ss << "True(1) or False(0) = " << (contb.rbegin() != contb.rend()) << ENDL << ENDL;
					typename container<Key, T>::const_reverse_iterator begin = contb.rbegin();
					typename container<Key, T>::const_reverse_iterator end = contb.rend();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << contb.size() << ENDL << ENDL;
					return (ss); }

		case 37: {	container<Key, T> const cont;
					test_name = "Displaying elements with iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL << test_name << ENDL;
					typename container<Key, T>::const_reverse_iterator begin = cont.rbegin();
					typename container<Key, T>::const_reverse_iterator end = cont.rend();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 38: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> const contb(cont);	
					test_name = "Displaying elements with iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> contb(cont);" << ENDL << test_name << ENDL;
					typename container<Key, T>::const_reverse_iterator begin = contb.rbegin();
					typename container<Key, T>::const_reverse_iterator end = contb.rend();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << contb.size() << ENDL << ENDL;
					return (ss); }

		case 39: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> const contb(cont);
					typename container<Key, T>::const_reverse_iterator begin = contb.rbegin();
					typename container<Key, T>::const_reverse_iterator end = contb.rend();	--end;
					test_name = "Display *(contb.rbegin()) and *(--contb.rend()), using operator*";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> contb(cont);" << ENDL << test_name << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 1) = (" << (*begin).first << ":" << (*begin).second << "|" << ENDL;
					*ss << "Value (should be 42) = " << (*end).first << ":" << (*end).second << "|" << ENDL;
					return (ss); }

		case 40: {	container<Key, T> * cont = new container<Key, T>();	cont->insert(&some_values[0], &some_values[3]);	container<Key, T> const contb(*cont);
					typename container<Key, T>::const_reverse_iterator begin = contb.rbegin();
					typename container<Key, T>::const_reverse_iterator end = contb.rend();	--end;
					test_name = "Display *(contb.rbegin()) and *(--contb.rend())";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " * cont = new container<Key, T>();	cont->insert(&some_values[0], &some_values[3]);	container<Key, T> contb(cont);" << ENDL << test_name << ENDL;
					*ss << test_name << ENDL;
					*ss << "Value (should be 1) = (" << (*begin).first << ":" << (*begin).second << "|" << ENDL;
					*ss << "Value (should be 42) = " << (*end).first << ":" << (*end).second << "|" << ENDL;
					delete cont;
					return (ss); }

		case 41: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> const contb(cont);
					test_name = "Displaying elements with iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> contb(cont);" << ENDL << test_name << ENDL;
					typename container<Key, T>::const_reverse_iterator begin = contb.rbegin();
					typename container<Key, T>::const_reverse_iterator end = contb.rend();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						begin++;
					}
					*ss << "]" << ENDL << "Size = " << contb.size() << ENDL << ENDL;
					return (ss); }

		case 42: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> const contb(cont);
					test_name = "Displaying elements with iterator";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> contb(cont);" << ENDL << test_name << ENDL;
					typename container<Key, T>::const_reverse_iterator begin = contb.rbegin();
					typename container<Key, T>::const_reverse_iterator end = contb.rend();
					*ss << "Elements = [ ";
					begin++;
					begin--;
					end--;
					end++;
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						begin++;
					}
					*ss << "]" << ENDL << "Size = " << contb.size() << ENDL << ENDL;
					return (ss); }


/* Capacity */
	/* size */
		case 43: {	container<Key, T> cont;
					test_name = "cont.size();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 44: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);
					test_name = "cont.size();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 45: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[1]);
					test_name = "cont.size();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[1]);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

	/* max_size */
		case 46: {	container<Key, T> cont;
					test_name = "cont.max_size();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL << ENDL;
					return (ss); }

		case 47: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);
					test_name = "cont.max_size();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL << ENDL;
					return (ss); }

		case 48: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[1]);
					test_name = "cont.max_size();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[1]);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Max_size = " << cont.max_size() << ENDL << ENDL;
					return (ss); }

	/* empty */
		case 49: {	container<Key, T> cont;
					test_name = "cont.empty();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << cont.empty() << ENDL << ENDL;
					return (ss); }

		case 50: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);
					test_name = "cont.empty();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << cont.empty() << ENDL << ENDL;
					return (ss); }

		case 51: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[1]);
					test_name = "cont.empty();";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + "cont;	cont.insert(&some_values[0], &some_values[1]);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << cont.empty() << ENDL << ENDL;
					return (ss); }

/* Element Access */
	/* operator[] for non constant container */
		case 52: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);
					test_name = "Displaying cont[0] cont[1] cont[2]";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);" << ENDL << test_name << ENDL;
					*ss << "cont[0].second = " << cont[0] << ENDL;
					*ss << "cont[1].second = " << cont[1] << ENDL;
					*ss << "cont[2].second = " << cont[2] << ENDL;
					return (ss); }

		case 53: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);
					test_name = "Displaying cont[2], modifying cont[2], displaying cont[2]";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);" << ENDL << test_name << ENDL;
					*ss << "cont[1].second = " << cont[1] << ENDL;
					*ss << "cont[2].second = " << cont[2] << ENDL;
					cont[1] = "what";
					cont[2] = "42";
					*ss << "cont[1].second = " << cont[1] << ENDL;
					*ss << "cont[2].second = " << cont[2] << ENDL;
					return (ss); }

	/* operator[] for constant container */
		case 54: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> const contb(cont);
					test_name = "Displaying contb[0] contb[1] contb[2]";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont(1, 42);	cont.push_back(23));	cont.push_back(12));	container<Key, T> const contb(cont);" << ENDL << test_name << ENDL;
					*ss << "cont[0].second = " << cont[0] << ENDL;
					*ss << "cont[1].second = " << cont[1] << ENDL;
					*ss << "cont[2].second = " << cont[2] << ENDL;
					return (ss); }


/* Modifiers */	
	/* insert */
		case 55: {	container<Key, T> cont;	std::pair<typename container<Key, T>::iterator, bool> ret = cont.insert(some_values[3]);
					test_name = "Inserting val, displaying return";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	std::pair<typename container<Key, T>::iterator, bool> ret = cont.insert(some_values[3]);" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Return: iterator.second = |" << (*(ret.first)).second << "|" << ENDL;
					*ss << "Return: added new value (True = 1, False = 0) = |" << ret.second << "|" << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 56: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);	std::pair<typename container<Key, T>::iterator, bool> ret = cont.insert(some_values[3]);
					test_name = "Inserting val, displaying return";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);	std::pair<typename container<Key, T>::iterator, bool> ret = cont.insert(some_values[3]);" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Return: iterator.second = |" << (*(ret.first)).second << "|" << ENDL;
					*ss << "Return: added new value (True = 1, False = 0) = |" << ret.second << "|" << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 57: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);	std::pair<typename container<Key, T>::iterator, bool> ret = cont.insert(some_values[0]);
					test_name = "Inserting val, displaying return";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);	std::pair<typename container<Key, T>::iterator, bool> ret = cont.insert(some_values[0]);" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Return: iterator.second = |" << (*(ret.first)).second << "|" << ENDL;
					*ss << "Return: added new value (True = 1, False = 0) = |" << ret.second << "|" << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 58: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);	typename container<Key, T>::iterator ret = cont.insert(cont.begin(), some_values[3]);
					test_name = "Inserting val, displaying return";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);	std::pair<typename container<Key, T>::iterator, bool> ret = cont.insert(cont.begin(), some_values[3]);" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Return: iterator.first = |" << (*ret).second << "|" << ENDL;
					*ss << "Return: iterator.second = |" << (*ret).second << "|" << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 59: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);	typename container<Key, T>::iterator ret = cont.insert(cont.end(), some_values[3]);
					test_name = "Inserting val, displaying return";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);	std::pair<typename container<Key, T>::iterator, bool> ret = cont.insert(cont.end(), some_values[3]);" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Return: iterator.first = |" << (*ret).second << "|" << ENDL;
					*ss << "Return: iterator.second = |" << (*ret).second << "|" << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 60: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);	typename container<Key, T>::iterator ret = cont.insert(cont.end(), some_values[0]);
					test_name = "Inserting val, displaying return";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);	std::pair<typename container<Key, T>::iterator, bool> ret = cont.insert(cont.end(), some_values[0]);" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Return: iterator.first = |" << (*ret).second << "|" << ENDL;
					*ss << "Return: iterator.second = |" << (*ret).second << "|" << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 61: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);
					test_name = "Inserting val with iterators";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 62: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);	cont.insert(&some_values[0], &some_values[3]);	cont.insert(&some_values[3], &some_values[4]);
					test_name = "Inserting val with iterators";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[3]);	cont.insert(&some_values[0], &some_values[3]);	cont.insert(&some_values[3], &some_values[4]);" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

	/* erase */
		case 63: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);	cont.erase(cont.begin());
					test_name = "Removing first element";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]);	cont.erase(cont.begin());" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 64: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[1]);	cont.erase(cont.begin());
					test_name = "Removing first and only element";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[1]);	cont.erase(cont.begin());" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 65: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);	typename container<Key, T>::iterator beg = cont.begin();	beg++;	cont.erase(beg);
					test_name = "Removing second element";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]);	typename container<Key, T>::iterator beg = cont.begin();	beg++;	cont.erase(beg);" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 66: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);	typename container<Key, T>::iterator e = cont.end();	e--;	cont.erase(e);
					test_name = "Removing last element";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]);	typename container<Key, T>::iterator e = cont.end();	e--;	cont.erase(e);" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 67: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[1]);	typename container<Key, T>::iterator e = cont.end();	e--;	cont.erase(e);
					test_name = "Removing last and only element";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[1]);	typename container<Key, T>::iterator e = cont.end();	e--;	cont.erase(e);" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 68: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);	size_t ret = cont.erase(42);
					test_name = "Removing element with key 42, displaying ret";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]);	size_t ret = cont.erase(42);" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Ret from erase = |" << ret << "|" << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 69: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);	size_t ret = cont.erase(0);
					test_name = "Removing element with key 0, displaying ret";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]);	size_t ret = cont.erase(0);" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Ret from erase = |" << ret << "|" << ENDL;
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 70: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);	cont.erase(cont.begin(), cont.end());
					test_name = "Removing element from iterators";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]);	size_t ret = cont.erase(cont.begin(), cont.end());" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 71: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);	cont.erase(++(cont.begin()), --(cont.end()));
					test_name = "Removing element from iterators";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]);	size_t ret = cont.erase(++cont.begin(), --cont.end());" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 72: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);	cont.erase(++(cont.begin()), --(cont.end()));
					test_name = "Removing element from iterators";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]);	size_t ret = cont.erase(cont.begin()++, cont.end()--);" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

	/* swap */
		case 73: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> contb;	contb.insert(&some_values[3], &some_values[5]);	cont.swap(contb);
					std::stringstream * ss = new std::stringstream();
					std::stringstream * ss1 = print_map(cont, "container cont");
					std::stringstream * ss2 = print_map(contb, "container contb");
					*ss << cont_name + "cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> contb;	contb.insert(&some_values[3], &some_values[5]);	cont.swap(contb);" << ENDL;
					*ss << ss1->str() << ENDL;
					*ss << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }
		
		case 74: {	container<Key, T> cont;	container<Key, T> contb;	contb.insert(&some_values[3], &some_values[5]);	cont.swap(contb);
					std::stringstream * ss = new std::stringstream();
					std::stringstream * ss1 = print_map(cont, "container cont");
					std::stringstream * ss2 = print_map(contb, "container contb");
					*ss << cont_name + "cont;	container<Key, T> contb;	contb.insert(&some_values[3], &some_values[5]);	cont.swap(contb);" << ENDL;
					*ss << ss1->str() << ENDL;
					*ss << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }
	
		case 75: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> contb;	cont.swap(contb);
					std::stringstream * ss = new std::stringstream();
					std::stringstream * ss1 = print_map(cont, "container cont");
					std::stringstream * ss2 = print_map(contb, "container contb");
					*ss << cont_name + "cont;	cont.insert(&some_values[0], &some_values[3]);	container<Key, T> contb;	cont.swap(contb);" << ENDL;
					*ss << ss1->str() << ENDL;
					*ss << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }
		
		case 76: {	container<Key, T> cont;	container<Key, T> contb;	cont.swap(contb);
					std::stringstream * ss = new std::stringstream();
					std::stringstream * ss1 = print_map(cont, "container cont");
					std::stringstream * ss2 = print_map(contb, "container contb");
					*ss << cont_name + "cont;	container<Key, T> contb;	cont.swap(contb);" << ENDL;
					*ss << ss1->str() << ENDL;
					*ss << ss2->str() << ENDL;
					delete ss1;	delete ss2;
					return (ss); }
		
	/* clear */
		case 77: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);	cont.clear();
					test_name = "Clearing container";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]);	cont.clear();" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 78: {	container<Key, T> cont;	cont.clear();
					test_name = "Clearing empty container";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.clear();" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

/* Observers */
	/* key_comp */
		case 79: {	Compare<T> tmp2;	container<Key, T, Compare<T> > cont(tmp2);	Compare<T> tmp = cont.key_comp();
					test_name = "Testing key_comp";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	Compare tmp = cont.key_comp();" << ENDL << test_name << ENDL;
					typename container<Key, T, Compare<T> >::iterator begin = cont.begin();
					typename container<Key, T, Compare<T> >::iterator end = cont.end();
					*ss << "Elements = [ ";
					while (begin != end)
					{
						*ss << "(" << (*begin).first << ":" << (*begin).second << ") ";
						++begin;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

	/* value_comp */
		case 80: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);	typename container<Key, T>::value_compare tmp = cont.value_comp();
					test_name = "Testing value_comp";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]);	typename container<Key, T>::value_compare tmp = cont.value_comp();" << ENDL << test_name << ENDL;
					typename container<Key, T>::iterator begin = cont.begin();
					typename container<Key, T>::iterator begin2 = cont.begin(); begin2++;
					typename container<Key, T>::iterator end = cont.end();
					*ss << "Verifying Elements with value_compare = [ ";
					while (begin2 != end)
					{
						*ss << "(True = 1, False = 0) : |" << tmp(*begin, *begin2) << "| ";
						++begin;
						++begin2;
					}
					*ss << "]" << ENDL << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

/* Operations */
	/* find */
		case 81: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);
					test_name = "Testing find";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]);" << ENDL << test_name << ENDL;
					*ss << "Trying to find Elements" << ENDL;
					*ss << "Trying to find (1 : |" << cont.find(1)->second << "|)" << ENDL;
					*ss << "Trying to find (-11 : |" << cont.find(-11)->second << "|)" << ENDL;
					*ss << "Trying to find (42 : |" << cont.find(42)->second << "|)" << ENDL;
					*ss << "Trying to find (-23 : |" << cont.find(-23)->second << "|)" << ENDL;
					*ss << "Cannot find (0) so should be (True = 1) => " << (cont.end() == cont.find(0)) << ENDL;
					return (ss); }

		case 82: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);	container<Key, T> const contb(cont);
					test_name = "Testing find";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]);	container<Key, T> const contb(cont);" << ENDL << test_name << ENDL;
					*ss << "Trying to find Elements" << ENDL;
					*ss << "Trying to find (1 : |" << contb.find(1)->second << "|)" << ENDL;
					*ss << "Trying to find (-11 : |" << contb.find(-11)->second << "|)" << ENDL;
					*ss << "Trying to find (42 : |" << contb.find(42)->second << "|)" << ENDL;
					*ss << "Trying to find (-23 : |" << contb.find(-23)->second << "|)" << ENDL;
					*ss << "Cannot find (0) so should be (True = 1) => " << (contb.end() == contb.find(0)) << ENDL;
					return (ss); }

	/* count */
		case 83: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);
					test_name = "Testing count";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]);" << ENDL << test_name << ENDL;
					*ss << "Trying to count Elements coresponding to 1" << ENDL;
					*ss << "Number of '1' = |" << cont.count(1) << "|)" << ENDL;
					*ss << "Number of '-11' = |" << cont.count(-11) << "|)" << ENDL;
					*ss << "Number of '42' = |" << cont.count(42) << "|)" << ENDL;
					*ss << "Number of '0' (should be 0)= |" << cont.count(0) << "|)" << ENDL;
					return (ss); }

	/* lower_bound */
		case 84: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);
					test_name = "Testing lower_bound on non-const container";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]);" << ENDL << test_name << ENDL;
					*ss << "Is Lower_bound(-11) == end() (True = 1, False = 0) |" << (cont.lower_bound(-11) == cont.end()) << "|" << ENDL;
					*ss << "Dispalying Lower_bound(-11).first and Lower_bound(-11).second = (" << cont.lower_bound(-11)->first << ":" << cont.lower_bound(-11)->second << ")" << ENDL;
					*ss << "Is Lower_bound(-12) == end() (True = 1, False = 0) |" << (cont.lower_bound(-12) == cont.end()) << "|" << ENDL;
					*ss << "Dispalying Lower_bound(-12).first and Lower_bound(-12).second = (" << cont.lower_bound(-12)->first << ":" << cont.lower_bound(-12)->second << ")" << ENDL;
					*ss << "Is Lower_bound(0) == end() (True = 1, False = 0) |" << (cont.lower_bound(0) == cont.end()) << "|" << ENDL;
					*ss << "Dispalying Lower_bound(0).first and Lower_bound(0).second = (" << cont.lower_bound(0)->first << ":" << cont.lower_bound(0)->second << ")" << ENDL;
					*ss << "Is Lower_bound(1000) == end() (True = 1, False = 0) |" << (cont.lower_bound(1000) == cont.end()) << "|" << ENDL << ENDL;
					return (ss); }

		case 85: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);	container<Key, T> const contb(cont);
					test_name = "Testing lower_bound on const container";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]);	container<Key, T> const contb(cont);" << ENDL << test_name << ENDL;
					*ss << "Is Lower_bound(-11) == end() (True = 1, False = 0) |" << (contb.lower_bound(-11) == contb.end()) << "|" << ENDL;
					*ss << "Dispalying Lower_bound(-11).first and Lower_bound(-11).second = (" << contb.lower_bound(-11)->first << ":" << contb.lower_bound(-11)->second << ")" << ENDL;
					*ss << "Is Lower_bound(-12) == end() (True = 1, False = 0) |" << (contb.lower_bound(-12) == contb.end()) << "|" << ENDL;
					*ss << "Dispalying Lower_bound(-12).first and Lower_bound(-12).second = (" << contb.lower_bound(-12)->first << ":" << contb.lower_bound(-12)->second << ")" << ENDL;
					*ss << "Is Lower_bound(0) == end() (True = 1, False = 0) |" << (contb.lower_bound(0) == contb.end()) << "|" << ENDL;
					*ss << "Dispalying Lower_bound(0).first and Lower_bound(0).second = (" << contb.lower_bound(0)->first << ":" << contb.lower_bound(0)->second << ")" << ENDL;
					*ss << "Is Lower_bound(1000) == end() (True = 1, False = 0) |" << (contb.lower_bound(1000) == contb.end()) << "|" << ENDL << ENDL;
					return (ss); }

	/* upper_bound */
		case 86: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);
					test_name = "Testing upper_bound on non-const container";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]);" << ENDL << test_name << ENDL;
					*ss << "Is Upper_bound(-11) == end() (True = 1, False = 0) |" << (cont.upper_bound(-11) == cont.end()) << "|" << ENDL;
					*ss << "Dispalying Upper_bound(-11).first and Upper_bound(-11).second = (" << cont.upper_bound(-11)->first << ":" << cont.upper_bound(-11)->second << ")" << ENDL;
					*ss << "Is Upper_bound(-12) == end() (True = 1, False = 0) |" << (cont.upper_bound(-12) == cont.end()) << "|" << ENDL;
					*ss << "Dispalying Upper_bound(-12).first and Upper_bound(-12).second = (" << cont.upper_bound(-12)->first << ":" << cont.upper_bound(-12)->second << ")" << ENDL;
					*ss << "Is Upper_bound(0) == end() (True = 1, False = 0) |" << (cont.upper_bound(0) == cont.end()) << "|" << ENDL;
					*ss << "Dispalying Upper_bound(0).first and Upper_bound(0).second = (" << cont.upper_bound(0)->first << ":" << cont.upper_bound(0)->second << ")" << ENDL;
					*ss << "Is Upper_bound(1000) == end() (True = 1, False = 0) |" << (cont.upper_bound(1000) == cont.end()) << "|" << ENDL << ENDL;
					return (ss); }

		case 87: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);	container<Key, T> const contb(cont);
					test_name = "Testing upper_bound on const container";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]);	container<Key, T> const contb(cont);" << ENDL << test_name << ENDL;
					*ss << "Is Upper_bound(-11) == end() (True = 1, False = 0) |" << (contb.upper_bound(-11) == contb.end()) << "|" << ENDL;
					*ss << "Dispalying Upper_bound(-11).first and Upper_bound(-11).second = (" << contb.upper_bound(-11)->first << ":" << contb.upper_bound(-11)->second << ")" << ENDL;
					*ss << "Is Upper_bound(-12) == end() (True = 1, False = 0) |" << (contb.upper_bound(-12) == contb.end()) << "|" << ENDL;
					*ss << "Dispalying Upper_bound(-12).first and Upper_bound(-12).second = (" << contb.upper_bound(-12)->first << ":" << contb.upper_bound(-12)->second << ")" << ENDL;
					*ss << "Is Upper_bound(0) == end() (True = 1, False = 0) |" << (contb.upper_bound(0) == contb.end()) << "|" << ENDL;
					*ss << "Dispalying Upper_bound(0).first and Upper_bound(0).second = (" << contb.upper_bound(0)->first << ":" << contb.upper_bound(0)->second << ")" << ENDL;
					*ss << "Is Upper_bound(1000) == end() (True = 1, False = 0) |" << (contb.upper_bound(1000) == contb.end()) << "|" << ENDL << ENDL;
					return (ss); }

	/* equal_range */
		case 88: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);
					test_name = "Testing equal_range on non-const container";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]);" << ENDL << test_name << ENDL;					
					*ss << "Displaying first iterator of Equal Range on existent pair Equal_range(-11) (" << cont.equal_range(-11).first->first << ":" << cont.equal_range(-11).first->second << ")" << ENDL;
					*ss << "Displaying second iterator of Equal Range on existent pair Equal_range(-11) (" << cont.equal_range(-11).second->first << ":" << cont.equal_range(-11).second->second << ")" << ENDL;
					*ss << "Displaying Equal Range on non-existent pair Equal_range(0) (True = 1, False = 0) (" << (cont.equal_range(0).first == cont.end()) << ")" << ENDL;
					*ss << "Displaying Equal Range on non-existent pair Equal_range(0) (True = 1, False = 0) (" << (cont.equal_range(0).second == cont.end()) << ")" << ENDL;
					return (ss); }

		case 89: {	container<Key, T> cont;	cont.insert(&some_values[0], &some_values[5]);	container<Key, T> const contb(cont);
					test_name = "Testing equal_range on const container";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.insert(&some_values[0], &some_values[5]); contaner<Key, T> const contb(cont);" << ENDL << test_name << ENDL;					
					*ss << "Displaying first iterator of Equal Range on existent pair Equal_range(-11) (" << contb.equal_range(-11).first->first << ":" << contb.equal_range(-11).first->second << ")" << ENDL;
					*ss << "Displaying second iterator of Equal Range on existent pair Equal_range(-11) (" << contb.equal_range(-11).second->first << ":" << contb.equal_range(-11).second->second << ")" << ENDL;
					*ss << "Displaying Equal Range on non-existent pair Equal_range(0) (True = 1, False = 0) (" << (contb.equal_range(0).first == contb.end()) << ")" << ENDL;
					*ss << "Displaying Equal Range on non-existent pair Equal_range(0) (True = 1, False = 0) (" << (contb.equal_range(0).second == contb.end()) << ")" << ENDL;
					return (ss); }

	}
	return (print_map(_cont, cont_name + " " + test_name));
}

template <template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< std::pair<const Key, T> > > class mycontainerT,
template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< std::pair<const Key, T> > > class stdcontainerT, class Key, class T>
void	map_tester(std::string const & title, std::string const & type)
{
	std::string	category;

	COUT << BLUE << "*--- testing " + title + type + " . . . ---*" << RENDL;

	category = "=> Constructors: ";
	COUT << category;	
	for (int i = 1; i <= 7; i++)
		print_result(test_map_container<stdcontainerT, Key, T>(title + type), test_map_container<mycontainerT, Key, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Destructors: ";
	COUT << category;	
	for (int i = 1; i <= 1; i++)
		print_result(test_map_container<stdcontainerT, Key, T>(title + type), test_map_container<mycontainerT, Key, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Operator=: ";
	COUT << category;	
	for (int i = 1; i <= 2; i++)
		print_result(test_map_container<stdcontainerT, Key, T>(title + type), test_map_container<mycontainerT, Key, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Iterators: ";
	COUT << category;	
	for (int i = 1; i <= 8; i++)
		print_result(test_map_container<stdcontainerT, Key, T>(title + type), test_map_container<mycontainerT, Key, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Constant Iterators: ";
	COUT << category;	
	for (int i = 1; i <= 8; i++)
		print_result(test_map_container<stdcontainerT, Key, T>(title + type), test_map_container<mycontainerT, Key, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Reverse Iterators: ";
	COUT << category;	
	for (int i = 1; i <= 8; i++)
		print_result(test_map_container<stdcontainerT, Key, T>(title + type), test_map_container<mycontainerT, Key, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Constant Reverse Iterators: ";
	COUT << category;	
	for (int i = 1; i <= 8; i++)
		print_result(test_map_container<stdcontainerT, Key, T>(title + type), test_map_container<mycontainerT, Key, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Capacity: ";
	COUT << category;	
	for (int i = 1; i <= 9; i++)
		print_result(test_map_container<stdcontainerT, Key, T>(title + type), test_map_container<mycontainerT, Key, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Element Access: ";
	COUT << category;	
	for (int i = 1; i <= 3; i++)
		print_result(test_map_container<stdcontainerT, Key, T>(title + type), test_map_container<mycontainerT, Key, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Modifiers: ";
	COUT << category;
	for (int i = 1; i <= 24; i++)
		print_result(test_map_container<stdcontainerT, Key, T>(title + type), test_map_container<mycontainerT, Key, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Observers: ";
	COUT << category;
	for (int i = 1; i <= 2; i++)
		print_result(test_map_container<stdcontainerT, Key, T>(title + type), test_map_container<mycontainerT, Key, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Operations: ";
	COUT << category;
	for (int i = 1; i <= 9; i++)
		print_result(test_map_container<stdcontainerT, Key, T>(title + type), test_map_container<mycontainerT, Key, T>(title + type), i, category);
	COUT << ENDL;

	std::cout << "COMPLETE !" << std::endl;
}

void map_test(void)
{
	map_tester<ft::map, std::map, int, std::string>("map", "<int, std::string>");
}