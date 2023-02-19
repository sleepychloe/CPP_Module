/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:04:04 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/19 04:59:13 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"

# define BLACK			"\x1b[0m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

int	main(int argc, char **argv)
{
	(void)argv;
	/* error check: argument */
	if (argc != 1)
	{
		std::cout << RED << "Argument error" << BLACK << std::endl;
		return (1);
	}

	Bureaucrat a("a", 42);
	Form f1("f1", 44, 1);
	std::cout << f1;

	std::cout << std::endl;
	a.signForm(f1);
	// try
	// {
	// 	f1.beSigned(a);
	// }
	// catch (std::exception& e)
	// {
	// }
	
	// a.signForm(f1);
	// std::cout << std::endl;
	// a.signForm(f1);
	// std::cout << std::endl;
	// std::cout << f1;

	// a.signForm(f1);
	

	// std::cout << "---------------" << std::endl;


	// Bureaucrat b("b", 46);
	// Form f2("f2", 44, 1);
	// std::cout << f2;
	// try
	// {
	// 	f2.beSigned(b);
	// 	std::cout << std::endl;
	// }
	// catch (std::exception& e)
	// {
	// }
	// b.signForm(f2);
	// std::cout << f2;

	

	
	
	return (0);
}
