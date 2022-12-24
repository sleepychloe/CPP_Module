/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:05:05 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/24 04:58:35 by yhwang           ###   ########.fr       */
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
		std::cout << "Please type the command\n(command: ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, input);
		if (input == "")
		{
			std::cout << "Input should not be empty: ";
			continue ;
		}
		if (input != "ADD" && input != "SEARCH" && input != "EXIT")
		{
			std::cout << "Invalid command: ";
			continue ;
		}
		if (input == "ADD" || input == "SEARCH" || input == "EXIT")
		{
			std::cout << "You selected " << input << std::endl;
			std::cout << "If you want to " << input << ", please type Y. Otherwise, please type N" << std::endl;
			std::getline(std::cin, check);
			while (check != "Y" && check != "N")
			{
				std::cout << "Invalid command: Please type Y or N" << std::endl;
				std::getline(std::cin, check);
			}
			if (check == "Y")
			{
				if (input == "ADD")
					PhoneBook.add();
				else if (input == "SEARCH")
					PhoneBook.search();
				else
				{
					std::cout << "EXIT" << std::endl;
					break ;
				}
			}
			else if (check == "N")
				continue ;
		}
	}
	return (0);
}
