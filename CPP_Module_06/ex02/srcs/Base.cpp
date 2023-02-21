/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 07:23:47 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/21 08:49:59 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Base.hpp"
#include "../incs/A.hpp"
#include "../incs/B.hpp"
#include "../incs/C.hpp"

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

Base::~Base()
{
}

Base*	generate(void)
{
	int	random;
	Base	*res;

	srand(time(NULL));
	random = rand() % 3;
	switch(random)
	{
		case 0:
			res = new A();
			std::cout << YELLOW << "A" << BLACK << "is returned " << std::endl;
			break ;
		case 1:
			res = new B();
			std::cout << YELLOW << "B" << BLACK << "is returned " << std::endl;
			break ;
		case 2:
			res = new C();
			std::cout << YELLOW << "C" << BLACK << "is returned " << std::endl;
			break ;
		default:
			res = NULL;
			std::cout << YELLOW << "D" << BLACK << "is returned " << std::endl;
			break ;
	}
	return (res);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "The actual type of the object pointed to by p is " << CYAN <<  "A" << BLACK << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "The actual type of the object pointed to by p is " << CYAN <<  "B" << BLACK << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "The actual type of the object pointed to by p is " << CYAN <<  "C" << BLACK << std::endl;
}

void	identify(Base &p)
{
	Base	base;
	try
	{
		base = dynamic_cast<A&>(p);
		std::cout << "The actual type of the object pointed to by p is " << CYAN <<  "A" << BLACK << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Error: A: " << e.what() << BLACK << std::endl;
	}

	try
	{
		base = dynamic_cast<B&>(p);
		std::cout << "The actual type of the object pointed to by p is " << CYAN <<  "B" << BLACK << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Error: B: " << e.what() << BLACK << std::endl;
	}

	try
	{
		base = dynamic_cast<C&>(p);
		std::cout << "The actual type of the object pointed to by p is " << CYAN <<  "C" << BLACK << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Error: C: " << e.what() << BLACK << std::endl;
	}
}
