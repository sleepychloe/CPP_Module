/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:04:04 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/20 03:47:05 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"

# define BLACK			"\x1b[0m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

int	bureaucrat_check_exception(Bureaucrat *bureaucrat, std::string flag)
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

int	form_check_exception(Form *form)
{
	try
	{
		if (form->get_grade_sign() < 1 || form->get_grade_execute() < 1
			|| form->get_grade_sign() > 150 || form->get_grade_execute() > 150)
			throw (std::exception());
	}
	catch(const std::exception& e)
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
		
		std::cout << YELLOW << "f1: " << BLACK;
		Form	f1("f1", 10, 10);
		if (!form_check_exception(&f1))
			std::cout << f1;

		std::cout << YELLOW << "f2: " << BLACK;
		Form	f2("f2", 0, 10);
		if (!form_check_exception(&f2))
			std::cout << f2;

		std::cout << YELLOW << "f3: " << BLACK;
		Form	f3("f3", 1, 151);
		if (!form_check_exception(&f3))
			std::cout << f3;
	}	
	std::cout << std::endl;
	
	{
		std::cout << CYAN << "[ test 2 ]" << BLACK << std::endl;

		std::cout << YELLOW << "a: " << BLACK;
		Bureaucrat	a("a", 10);
		bureaucrat_check_exception(&a, "");

		std::cout << YELLOW << "f1: " << BLACK;
		Form	f1("f1", 10, 10);
		if (!form_check_exception(&f1))
			std::cout << f1;

		std::cout << YELLOW << "a tries to sign f1: " << BLACK;
		a.signForm(f1); //a sign f1
		std::cout << YELLOW << "a tries to sign f1: " << BLACK;
		a.signForm(f1); //already signed
		std::cout << YELLOW << "a tries to sign f1: " << BLACK;
		a.signForm(f1); //already signed

		std::cout << YELLOW << "f1: " << BLACK;
		std::cout << f1;

		std::cout << std::endl;

		std::cout << YELLOW << "b: " << BLACK;
		Bureaucrat	b("b", 40);
		bureaucrat_check_exception(&b, "");

		std::cout << YELLOW << "f2: " << BLACK;
		Form	f2("f2", 20, 10);
		if (!form_check_exception(&f2))
			std::cout << f2;

		std::cout << YELLOW << "b tries to sign f2: " << BLACK;
		b.signForm(f2);
		std::cout << YELLOW << "f2: " << BLACK;
		std::cout << f2;

		std::cout << YELLOW << "a tries to sign f2: " << BLACK;
		a.signForm(f2);
		std::cout << YELLOW << "f2: " << BLACK;
		std::cout << f2;	
	}	
	return (0);
}
