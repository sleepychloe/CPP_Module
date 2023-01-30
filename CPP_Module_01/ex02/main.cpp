/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:59:45 by yhwang            #+#    #+#             */
/*   Updated: 2023/01/25 10:50:19 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	(void)argv;
	/* error check: argument */
	if (argc != 1)
	{
		std::cout << "error: Argument error" << std::endl;
		return (1);
	}

	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "╔═══════════════════════════════╦══════════════════╗" << std::endl;

	std::cout << "║ address of string\t\t║ " << &string << "   ║" << std::endl;
	std::cout << "║ address held by stringPTR\t║ " << stringPTR << "   ║" << std::endl;
	std::cout << "║ address held by stringREF\t║ " << &stringREF << "   ║" << std::endl;
	
	std::cout << "╠═══════════════════════════════╬══════════════════╣" << std::endl;

	std::cout << "║ value of string\t\t║ " << string << " ║" << std::endl;
	std::cout << "║ value pointed to by stringPTR\t║ " << *stringPTR << " ║" << std::endl;
	std::cout << "║ value pointed to by stringREF\t║ " << stringREF << " ║" << std::endl;

	std::cout << "╚═══════════════════════════════╩══════════════════╝" << std::endl;
	
	return (0);
}