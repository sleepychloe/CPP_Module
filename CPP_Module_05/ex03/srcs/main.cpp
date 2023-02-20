/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:15:01 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/20 03:44:30 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/AForm.hpp"
#include "../incs/ShrubberyCreationForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/PresidentialPardonForm.hpp"
#include "../incs/Intern.hpp"

int	form_check_exception(AForm *aform)
{
	try
	{
		if (aform == NULL)
			throw (std::exception());
		std::cout << *aform;
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
	/* error check: arument */
	if (argc != 1)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}

	{
		std::cout << CYAN << "[ test ]" << BLACK << std::endl;

		Intern intern;
		
		std::cout << YELLOW << "f1: " << BLACK;
		AForm	*f1;
		f1 = intern.makeForm("shrubbery creation", "rabbit");
		if (!form_check_exception(f1))
			delete f1;

		std::cout << YELLOW << "f2: " << BLACK;
		AForm	*f2;
		f2 = intern.makeForm("robotomy request", "chick");
		if (form_check_exception(f2))
			delete f2;

		std::cout << YELLOW << "f3: " << BLACK;
		AForm	*f3;
		f3 = intern.makeForm("presidential pardon", "shark");
		if (form_check_exception(f3))
			delete f3;

		std::cout << YELLOW << "f4: " << BLACK;
		AForm	*f4;
		f4 = intern.makeForm("form", "target");
		if (form_check_exception(f4))
			delete f4;

		std::cout << YELLOW << "f5: " << BLACK;
		AForm	*f5;
		f5 = intern.makeForm("shrubbery creation", "");
		if (!form_check_exception(f5))
			delete f5;
	}
	return (0);
}