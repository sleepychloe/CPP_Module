/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:16:39 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/20 03:51:37 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/AForm.hpp"
#include "../incs/ShrubberyCreationForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/PresidentialPardonForm.hpp"

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

int	form_check_exception(AForm *aform)
{
	try
	{
		if (aform->get_grade_sign() < 1 || aform->get_grade_execute() < 1
			|| aform->get_grade_sign() > 150 || aform->get_grade_execute() > 150)
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
		ShruberryCreationForm	s("target");
		AForm	*f1 = &s;
		if (!form_check_exception(f1))
			std::cout << *f1;

		std::cout << YELLOW << "f2: " << BLACK;
		RobotomyRequestForm	r("target");
		AForm	*f2 = &r;
		if (!form_check_exception(f2))
			std::cout << *f2;

		std::cout << YELLOW << "f3: " << BLACK;
		PresidentialPardonForm	p("target");
		AForm	*f3 = &p;
		if (!form_check_exception(f3))
			std::cout << *f3;
	}	
	std::cout << CYAN << "═══════════════════════════════════════════════════════════════════════════════════════════════════════" << BLACK << std::endl;
	
	{
		std::cout << CYAN << "[ test 2: ShruberryCreationForm ]" << BLACK << std::endl;

		std::cout << YELLOW << "a: " << BLACK;
		Bureaucrat a("a", 147);
		bureaucrat_check_exception(&a, "");

		std::cout << YELLOW << "b: " << BLACK;
		Bureaucrat b("b", 140);
		bureaucrat_check_exception(&b, "");

		std::cout << YELLOW << "c: " << BLACK;
		Bureaucrat c("c", 10);
		bureaucrat_check_exception(&c, "");

		std::cout << YELLOW << "f: " << BLACK;
		ShruberryCreationForm	s("rabbit");
		AForm	*f = &s;
		if (!form_check_exception(f))
			std::cout << *f;


		std::cout << YELLOW << "c tries to execute f: " << BLACK;
		c.executeForm(*f); //c can't execute f without signing

		std::cout << YELLOW << "a tries to sign f: " << BLACK;
		a.signForm(*f); //a can't sign

		std::cout << YELLOW << "a tries to execute f: " << BLACK;
		a.executeForm(*f); //a can't execute

		std::cout << YELLOW << "b tries to sign f: " << BLACK;
		b.signForm(*f); //b signs f

		std::cout << YELLOW << "b tries to execute f: " << BLACK;
		b.executeForm(*f); //b can't execute

		std::cout << YELLOW << "c tries to sign f: " << BLACK;
		c.signForm(*f); //f already signed

		std::cout << YELLOW << "c tries to execute f: " << BLACK;
		c.executeForm(*f); //c executes f

		std::cout << YELLOW << "f: " << BLACK;
		std::cout << *f;
	}
	std::cout << CYAN << "═══════════════════════════════════════════════════════════════════════════════════════════════════════" << BLACK << std::endl;
	
	{
		std::cout << CYAN << "[ test 3: RobotomyRequestForm ]" << BLACK << std::endl;

		std::cout << YELLOW << "a: " << BLACK;
		Bureaucrat a("a", 80);
		bureaucrat_check_exception(&a, "");

		std::cout << YELLOW << "b: " << BLACK;
		Bureaucrat b("b", 70);
		bureaucrat_check_exception(&b, "");

		std::cout << YELLOW << "c: " << BLACK;
		Bureaucrat c("c", 40);
		bureaucrat_check_exception(&c, "");

		std::cout << YELLOW << "f: " << BLACK;
		RobotomyRequestForm	r("chick");
		AForm	*f = &r;
		if (!form_check_exception(f))
			std::cout << *f;


		std::cout << YELLOW << "c tries to execute f: " << BLACK;
		c.executeForm(*f); //c can't execute f without signing

		std::cout << YELLOW << "a tries to sign f: " << BLACK;
		a.signForm(*f); //a can't sign

		std::cout << YELLOW << "a tries to execute f: " << BLACK;
		a.executeForm(*f); //a can't execute

		std::cout << YELLOW << "b tries to sign f: " << BLACK;
		b.signForm(*f); //b signs f

		std::cout << YELLOW << "b tries to execute f: " << BLACK;
		b.executeForm(*f); //b can't execute

		std::cout << YELLOW << "c tries to sign f: " << BLACK;
		c.signForm(*f); //f already signed

		std::cout << YELLOW << "c tries to execute f: " << BLACK;
		c.executeForm(*f); //c executes f

		std::cout << YELLOW << "f: " << BLACK;
		std::cout << *f;
	}
	std::cout << CYAN << "═══════════════════════════════════════════════════════════════════════════════════════════════════════" << BLACK << std::endl;

	{
		std::cout << CYAN << "[ test 4: PresidentialPardonForm ]" << BLACK << std::endl;

		std::cout << YELLOW << "a: " << BLACK;
		Bureaucrat a("a", 30);
		bureaucrat_check_exception(&a, "");

		std::cout << YELLOW << "b: " << BLACK;
		Bureaucrat b("b", 10);
		bureaucrat_check_exception(&b, "");

		std::cout << YELLOW << "c: " << BLACK;
		Bureaucrat c("c", 1);
		bureaucrat_check_exception(&c, "");

		std::cout << YELLOW << "f: " << BLACK;
		PresidentialPardonForm	p("shark");
		AForm	*f = &p;
		if (!form_check_exception(f))
			std::cout << *f;


		std::cout << YELLOW << "c tries to execute f: " << BLACK;
		c.executeForm(*f); //c can't execute f without signing

		std::cout << YELLOW << "a tries to sign f: " << BLACK;
		a.signForm(*f); //a can't sign

		std::cout << YELLOW << "a tries to execute f: " << BLACK;
		a.executeForm(*f); //a can't execute

		std::cout << YELLOW << "b tries to sign f: " << BLACK;
		b.signForm(*f); //b signs f

		std::cout << YELLOW << "b tries to execute f: " << BLACK;
		b.executeForm(*f); //b can't execute

		std::cout << YELLOW << "c tries to sign f: " << BLACK;
		c.signForm(*f); //f already signed

		std::cout << YELLOW << "c tries to execute f: " << BLACK;
		c.executeForm(*f); //c executes f

		std::cout << YELLOW << "f1: " << BLACK;
		std::cout << *f;
	}
	return (0);
}
