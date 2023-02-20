/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 00:55:36 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/20 01:34:24 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"

# define BLACK			"\x1b[0m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

int	check_exception(Bureaucrat *bureaucrat, std::string flag)
{
	try
	{
		if (flag == "increment")
			bureaucrat->increment_grade();
		else if (flag == "decrement")
			bureaucrat->decrement_grade();
		
		if (bureaucrat->getGrade() < 1
			|| bureaucrat->getGrade() > 150)
			throw (std::exception());
		std::cout << *bureaucrat;
	}
	catch (std::exception& e)
	{
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argv;
	/* error check: argument */
	if (argc != 1)
	{
		std::cout << RED << "Argument error" << BLACK << std::endl;
		return (1);
	}
	
	{
		std::cout << CYAN << "[ test 1 ]" << BLACK << std::endl;
		Bureaucrat	a("a", 42);
		if (!check_exception(&a, ""))
		{
			std::cout << YELLOW << "(increment grade)" << BLACK << std::endl;
			check_exception(&a, "increment");
		}
	}
	std::cout << std::endl;

	{
		std::cout << CYAN << "[ test 2 ]" << BLACK << std::endl;
		Bureaucrat	b("b", 42);
		if (!check_exception(&b, ""))
		{
			std::cout << YELLOW << "(decrement grade)" << BLACK << std::endl;
			check_exception(&b, "decrement");
		}
	}
	std::cout << std::endl;

	{
		std::cout << CYAN << "[ test 3 ]" << BLACK << std::endl;
		Bureaucrat	c("c", 1);
		if (!check_exception(&c, ""))
		{
			std::cout << YELLOW << "(increment grade)" << BLACK << std::endl;
			check_exception(&c, "increment");
		}
	}
	std::cout << std::endl;

	{
		std::cout << CYAN << "[ test 4 ]" << BLACK << std::endl;
		Bureaucrat	d("d", 1);
		if (!check_exception(&d, ""))
		{
			std::cout << YELLOW << "(decrement grade)" << BLACK << std::endl;
			check_exception(&d, "decrement");
		}
	}
	std::cout << std::endl;

	{
		std::cout << CYAN << "[ test 5 ]" << BLACK << std::endl;
		Bureaucrat	e("e", 150);
		if (!check_exception(&e, ""))
		{
			std::cout << YELLOW << "(increment grade)" << BLACK << std::endl;
			check_exception(&e, "increment");
		}
	}
	std::cout << std::endl;

	{
		std::cout << CYAN << "[ test 6 ]" << BLACK << std::endl;
		Bureaucrat	f("f", 150);
		if (!check_exception(&f, ""))
		{
			std::cout << YELLOW << "(decrement grade)" << BLACK << std::endl;
			check_exception(&f, "decrement");
		}
	}
	std::cout << std::endl;

	{
		std::cout << CYAN << "[ test 7 ]" << BLACK << std::endl;
		Bureaucrat	g("g", 0);
		if (!check_exception(&g, ""))
		{
			std::cout << YELLOW << "(increment grade)" << BLACK << std::endl;
			check_exception(&g, "increment");
		}
	}
	std::cout << std::endl;

	{
		std::cout << CYAN << "[ test 8 ]" << BLACK << std::endl;
		Bureaucrat	h("h", 151);
		if (!check_exception(&h, ""))
		{
			std::cout << YELLOW << "(increment grade)" << BLACK << std::endl;
			check_exception(&h, "increment");
		}
	}
	return (0);
}
