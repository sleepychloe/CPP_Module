/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:05:05 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/23 23:43:15 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/main.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;
	std::string	input;
	std::string	check;
	while (1)
	{
		std::cout << "Please enter the command" << std::endl;
		std::getline(std::cin, input);
		std::cout <<"your input is : " << input << "\n" << "\tIf it is right, please type Y. Otherwise, type N" << std::endl;
		std::getline(std::cin, check);
		if (check == "N")
			continue ;
		else if (check != "Y")
		{
			while (check != "Y" && check != "N")
			{
				std::cout << "Please enter Y or N" << std::endl;
				std::getline(std::cin, check);
				if (check != "Y")
					continue ;
			}
		}
		if (input == "ADD")
			PhoneBook.add();
		else if (input == "SEARCH")
			std::cout << "input is search" << std::endl;
		else if (input == "EXIT")
		{
			std::cout << "Exit" << std::endl;
			break ;
		}
		else
		{
			std::cout << "Invalid command" << std::endl;
			continue ;
		}
	}
	return (0);
}