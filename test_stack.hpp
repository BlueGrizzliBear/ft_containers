#include "main.hpp"

template <template <class T, class Container = std::deque<T> > class container, class T>
std::stringstream *	test_stack_container(std::string const & cont_name)
{
	container<T>					_cont;
	container<T, std::list<T> >		_cont_list;
	container<T, std::vector<T> >	_cont_vector;
	container<T, std::deque<T> >	_cont_deque;
	std::string 	test_name;
	static int		a = 0;

	switch (++a)
	{
/* Constructors */
		case 1: {	container<T> cont;
					test_name = "Displaying stack with standard underlying container";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL;
					*ss << test_name << ENDL;
					while (!cont.empty())
					{
						*ss << "At the top of the stack:|" << cont.top() << "|\n";
						*ss << "Poping the top . . .\n";
						cont.pop();
					}
					*ss << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 2: {	container<T, std::list<T> > cont_l;
					test_name = "Displaying stack with list underlying container";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont_l;" << ENDL;
					*ss << test_name << ENDL;
					while (!cont_l.empty())
					{
						*ss << "At the top of the stack:|" << cont_l.top() << "|\n";
						*ss << "Poping the top . . .\n";
						cont_l.pop();
					}
					*ss << "Size = " << cont_l.size() << ENDL << ENDL;
					return (ss); }

		case 3: {	container<T, std::vector<T> > cont_v;
					test_name = "Displaying stack with vector underlying container";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont_v;" << ENDL;
					*ss << test_name << ENDL;
					while (!cont_v.empty())
					{
						*ss << "At the top of the stack:|" << cont_v.top() << "|\n";
						*ss << "Poping the top . . .\n";
						cont_v.pop();
					}
					*ss << "Size = " << cont_v.size() << ENDL << ENDL;
					return (ss); }

		case 4: {	container<T, std::deque<T> > cont_d;
					test_name = "Displaying stack with deque underlying container";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont_v;" << ENDL;
					*ss << test_name << ENDL;
					while (!cont_d.empty())
					{
						*ss << "At the top of the stack:|" << cont_d.top() << "|\n";
						*ss << "Poping the top . . .\n";
						cont_d.pop();
					}
					*ss << "Size = " << cont_d.size() << ENDL << ENDL;
					return (ss); }

		case 5: {	container<T> cont(_cont);
					test_name = "Displaying stack with standard underlying container";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL;
					*ss << test_name << ENDL;
					while (!cont.empty())
					{
						*ss << "At the top of the stack:|" << cont.top() << "|\n";
						*ss << "Poping the top . . .\n";
						cont.pop();
					}
					*ss << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

		case 6: {	container<T, std::list<T> > cont_l(_cont_list);
					test_name = "Displaying stack with list underlying container";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont_l;" << ENDL;
					*ss << test_name << ENDL;
					while (!cont_l.empty())
					{
						*ss << "At the top of the stack:|" << cont_l.top() << "|\n";
						*ss << "Poping the top . . .\n";
						cont_l.pop();
					}
					*ss << "Size = " << cont_l.size() << ENDL << ENDL;
					return (ss); }

		case 7: {	container<T, std::vector<T> > cont_v(_cont_vector);
					test_name = "Displaying stack with vector underlying container";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont_v;" << ENDL;
					*ss << test_name << ENDL;
					while (!cont_v.empty())
					{
						*ss << "At the top of the stack:|" << cont_v.top() << "|\n";
						*ss << "Poping the top . . .\n";
						cont_v.pop();
					}
					*ss << "Size = " << cont_v.size() << ENDL << ENDL;
					return (ss); }

		case 8: {	container<T, std::deque<T> > cont_d(_cont_deque);
					test_name = "Displaying stack with deque underlying container";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont_v;" << ENDL;
					*ss << test_name << ENDL;
					while (!cont_d.empty())
					{
						*ss << "At the top of the stack:|" << cont_d.top() << "|\n";
						*ss << "Poping the top . . .\n";
						cont_d.pop();
					}
					*ss << "Size = " << cont_d.size() << ENDL << ENDL;
					return (ss); }


/* Destructor */
		case 9: {	int * a = new int(42);
					container<T> *cont = new container<T>();	cont->push(*a);	delete cont;
					test_name = "*cont = new container<T>();	cont->push(*a);	delete cont;";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " " + test_name << ENDL;
					*ss << "int a (should be persistent) = " << *a << ENDL << ENDL;
					delete a;
					return (ss); }

/* Operator= */
		case 10: {	container<T> cont;	container<T> contbis;	cont.push(42);	contbis.push(24);	cont = contbis;
					test_name = "cont;	container<T> contbis;	cont.push(42);	contbis.push(24);	cont = contbis;";
					_cont = cont;
					break;	}

		case 11: {	container<T> cont;	container<T> contbis;	contbis.push(24);	cont = contbis;
					test_name = "cont;	container<T> contbis;	contbis.push(24);	cont = contbis;";
					_cont = cont;
					break;	}

		case 12: {	container<T> cont;	container<T> contbis;	cont.push(42);	cont = contbis;
					test_name = "cont;	container<T> contbis;	cont.push(42);	cont = contbis;";
					_cont = cont;
					break;	}

/* Capacity */
		case 13: {	container<T> cont;
					test_name = "cont.empty()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << cont.empty() << ENDL << ENDL;
					return (ss); }

		case 14: {	container<T> cont;	cont.push(42);
					test_name = "cont.empty()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push(42);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "True(1) or False(0) = " << cont.empty() << ENDL << ENDL;
					return (ss); }

		case 15: {	container<T> cont;	cont.push(42);
					test_name = "cont.size()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push(42);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "Size = " << cont.size() << ENDL << ENDL;
					return (ss); }

/* Element access */
		case 16: {	container<T> cont;	cont.push(42);	cont.push(23);	cont.push(5);
					test_name = "Display top()";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push(42);	cont.push(23);	cont.push(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "cont.top() (should be 5) = " << cont.top() << ENDL << ENDL;
					return (ss); }

		case 17: {	container<T> cont;	cont.push(42);	cont.push(23);	cont.push(5);
					cont.top() = -13;
					test_name = "Assign to reference : cont.top() = -13";
					std::stringstream * ss = new std::stringstream();
					*ss << cont_name + " cont;	cont.push(42);	cont.push(23);	cont.push(5);" << ENDL;
					*ss << test_name << ENDL;
					*ss << "cont.top() (should be -13) = " << cont.top() << ENDL << ENDL;
					return (ss); }

/* Modifiers */
	/* push, pop */
		case 18: {	container<T> cont;	cont.push(12);
					test_name = "cont;	cont.push(12);";
					_cont = cont;
					break;	}

		case 19: {	container<T> cont;	cont.push(1);	cont.push(2);	cont.push(3);	cont.pop();
					test_name = "cont;	cont.push(1);	cont.push(2);	cont.push(3);	cont.pop();";
					_cont = cont;
					break;	}
					
/* Non-member function overloads */
	/* operator== */
		case 137: {	container<T> cont;	cont.push(1);	container<T> contb;	contb.push(1);
					test_name = cont_name + " " + "cont;	cont.push(1);	container<T> contb;	contb.push(1);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont == contb) (0 = no, 1 = yes): " << (cont == contb) << ENDL;
					return (ss); }

		case 138: {	container<T> cont;	cont.push(1);	container<T> contb;	contb.push(2);
					test_name = cont_name + " " + "cont;	cont.push(1);	container<T> contb;	contb.push(2);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont == contb) (0 = no, 1 = yes): " << (cont == contb) << ENDL;
					return (ss); }

		case 139: {	container<T> cont;	container<T> contb;	contb.push(1);
					test_name = cont_name + " " + "cont;	container<T> contb;	contb.push(1);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont == contb) (0 = no, 1 = yes): " << (cont == contb) << ENDL;
					return (ss); }

		case 140: {	container<T> cont;	cont.push(1);	container<T> contb;
					test_name = cont_name + " " + "cont;	cont.push(1);	container<T> contb;";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont == contb) (0 = no, 1 = yes): " << (cont == contb) << ENDL;
					return (ss); }

	/* operator!= */
		case 141: {	container<T> cont;	cont.push(1);	container<T> contb;	contb.push(1);
					test_name = cont_name + " " + "cont;	cont.push(1);	container<T> contb;	contb.push(1);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont != contb) (0 = no, 1 = yes): " << (cont != contb) << ENDL;
					return (ss); }

		case 142: {	container<T> cont;	cont.push(1);	container<T> contb;	contb.push(2);
					test_name = cont_name + " " + "cont;	cont.push(1);	container<T> contb;	contb.push(2);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont != contb) (0 = no, 1 = yes): " << (cont != contb) << ENDL;
					return (ss); }

		case 143: {	container<T> cont;	container<T> contb;	contb.push(1);
					test_name = cont_name + " " + "cont;	container<T> contb;	contb.push(1);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont != contb) (0 = no, 1 = yes): " << (cont != contb) << ENDL;
					return (ss); }

		case 144: {	container<T> cont;	cont.push(1);	container<T> contb;
					test_name = cont_name + " " + "cont;	cont.push(1);	container<T> contb;";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont != contb) (0 = no, 1 = yes): " << (cont != contb) << ENDL;
					return (ss); }

	/* operator< */
		case 145: {	container<T> cont;	cont.push(1);	container<T> contb;	contb.push(1);
					test_name = cont_name + " " + "cont;	cont.push(1);	container<T> contb;	contb.push(1);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont < contb) (0 = no, 1 = yes): " << (cont < contb) << ENDL;
					return (ss); }

		case 146: {	container<T> cont;	cont.push(1);	container<T> contb;	contb.push(2);
					test_name = cont_name + " " + "cont;	cont.push(1);	container<T> contb;	contb.push(2);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont < contb) (0 = no, 1 = yes): " << (cont < contb) << ENDL;
					return (ss); }

		case 147: {	container<T> cont;	container<T> contb;	contb.push(1);
					test_name = cont_name + " " + "cont;	container<T> contb;	contb.push(1);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont < contb) (0 = no, 1 = yes): " << (cont < contb) << ENDL;
					return (ss); }

		case 148: {	container<T> cont;	cont.push(1);	container<T> contb;
					test_name = cont_name + " " + "cont;	cont.push(1);	container<T> contb;";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont < contb) (0 = no, 1 = yes): " << (cont < contb) << ENDL;
					return (ss); }

	/* operator<= */
		case 149: {	container<T> cont;	cont.push(1);	container<T> contb;	contb.push(1);
					test_name = cont_name + " " + "cont;	cont.push(1);	container<T> contb;	contb.push(1);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont <= contb) (0 = no, 1 = yes): " << (cont <= contb) << ENDL;
					return (ss); }

		case 150: {	container<T> cont;	cont.push(1);	container<T> contb;	contb.push(2);
					test_name = cont_name + " " + "cont;	cont.push(1);	container<T> contb;	contb.push(2);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont <= contb) (0 = no, 1 = yes): " << (cont <= contb) << ENDL;
					return (ss); }

		case 151: {	container<T> cont;	container<T> contb;	contb.push(1);
					test_name = cont_name + " " + "cont;	container<T> contb;	contb.push(1);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont <= contb) (0 = no, 1 = yes): " << (cont <= contb) << ENDL;
					return (ss); }

		case 152: {	container<T> cont;	cont.push(1);	container<T> contb;
					test_name = cont_name + " " + "cont;	cont.push(1);	container<T> contb;";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont <= contb) (0 = no, 1 = yes): " << (cont <= contb) << ENDL;
					return (ss); }

	/* operator> */
		case 153: {	container<T> cont;	cont.push(1);	container<T> contb;	contb.push(1);
					test_name = cont_name + " " + "cont;	cont.push(1);	container<T> contb;	contb.push(1);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont > contb) (0 = no, 1 = yes): " << (cont > contb) << ENDL;
					return (ss); }

		case 154: {	container<T> cont;	cont.push(1);	container<T> contb;	contb.push(2);
					test_name = cont_name + " " + "cont;	cont.push(1);	container<T> contb;	contb.push(2);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont > contb) (0 = no, 1 = yes): " << (cont > contb) << ENDL;
					return (ss); }

		case 155: {	container<T> cont;	container<T> contb;	contb.push(1);
					test_name = cont_name + " " + "cont;	container<T> contb;	contb.push(1);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont > contb) (0 = no, 1 = yes): " << (cont > contb) << ENDL;
					return (ss); }

		case 156: {	container<T> cont;	cont.push(1);	container<T> contb;
					test_name = cont_name + " " + "cont;	cont.push(1);	container<T> contb;";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont > contb) (0 = no, 1 = yes): " << (cont > contb) << ENDL;
					return (ss); }

	/* operator>= */
		case 157: {	container<T> cont;	cont.push(1);	container<T> contb;	contb.push(1);
					test_name = cont_name + " " + "cont;	cont.push(1);	container<T> contb;	contb.push(1);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont >= contb) (0 = no, 1 = yes): " << (cont >= contb) << ENDL;
					return (ss); }

		case 158: {	container<T> cont;	cont.push(1);	container<T> contb;	contb.push(2);
					test_name = cont_name + " " + "cont;	cont.push(1);	container<T> contb;	contb.push(2);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont >= contb) (0 = no, 1 = yes): " << (cont >= contb) << ENDL;
					return (ss); }

		case 159: {	container<T> cont;	container<T> contb;	contb.push(1);
					test_name = cont_name + " " + "cont;	container<T> contb;	contb.push(1);";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont >= contb) (0 = no, 1 = yes): " << (cont >= contb) << ENDL;
					return (ss); }

		case 160: {	container<T> cont;	cont.push(1);	container<T> contb;
					test_name = cont_name + " " + "cont;	cont.push(1);	container<T> contb;";
					std::stringstream * ss = new std::stringstream();
					*ss << test_name << ENDL;
					*ss << "(cont >= contb) (0 = no, 1 = yes): " << (cont >= contb) << ENDL;
					return (ss); }

	}
	return (print_stack(_cont, cont_name + " " + test_name));
}

template <template <class T, class Container = std::deque<T> > class mycontainerT,
template <class T, class Container = std::deque<T> > class stdcontainerT, class T>
void	stack_tester(std::string const & title, std::string const & type)
{
	std::string	category;

	COUT << BLUE << "*--- testing " + title + type + " . . . ---*" << RENDL;

	category = "=> Constructors: ";
	COUT << category;	
	for (int i = 1; i <= 8; i++)
		print_result(test_stack_container<stdcontainerT, T>(title + type), test_stack_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Destructors: ";
	COUT << category;	
	for (int i = 1; i <= 1; i++)
		print_result(test_stack_container<stdcontainerT, T>(title + type), test_stack_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Operator=: ";
	COUT << category;	
	for (int i = 1; i <= 3; i++)
		print_result(test_stack_container<stdcontainerT, T>(title + type), test_stack_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Capacity: ";
	COUT << category;	
	for (int i = 1; i <= 3; i++)
		print_result(test_stack_container<stdcontainerT, T>(title + type), test_stack_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Element Access: ";
	COUT << category;	
	for (int i = 1; i <= 2; i++)
		print_result(test_stack_container<stdcontainerT, T>(title + type), test_stack_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Modifiers: ";
	COUT << category;	
	for (int i = 1; i <= 2; i++)
		print_result(test_stack_container<stdcontainerT, T>(title + type), test_stack_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	category = "=> Non-member function overloads: ";
	COUT << category;	
	for (int i = 1; i <= 24; i++)
		print_result(test_stack_container<stdcontainerT, T>(title + type), test_stack_container<mycontainerT, T>(title + type), i, category);
	COUT << ENDL;

	std::cout << "COMPLETE !" << std::endl;
}
