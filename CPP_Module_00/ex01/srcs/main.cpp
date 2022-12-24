/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:05:05 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/24 11:06:04 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/main.hpp"

int	main(int argc, char **argv)
{
	PhoneBook	PhoneBook;
	std::string	input;
	std::string	check;
	if (argc != 1)
	{
		std::cerr << RED << "Argumet error: (command: ./phonebook)" << BLACK << std::endl;
		return (1);
	}
	while (1)
	{
		std::cout << CYAN << "Please type the command\n(command: ADD, SEARCH, EXIT)" << BLACK << std::endl;
		std::getline(std::cin, input);
		if (input == "")
		{
			std::cout << RED << "Input should not be empty: " << BLACK;
			continue ;
		}
		if (input != "ADD" && input != "SEARCH" && input != "EXIT")
		{
			std::cout << RED << "Invalid command: " << BLACK;
			continue ;
		}
		if (input == "ADD" || input == "SEARCH" || input == "EXIT")
		{
			std::cout << YELLOW << "You selected " << input << BLACK << std::endl;
			std::cout << BLUE << "If you want to " << input << ", please type Y. Otherwise, please type N" << BLACK <<  std::endl;
			std::getline(std::cin, check);
			while (check != "Y" && check != "N")
			{
				std::cout << RED << "Invalid command: Please type Y or N" << BLACK << std::endl;
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
					std::cout << YELLOW << "EXIT" << BLACK << std::endl;
					break ;
				}
			}
			else if (check == "N")
				continue ;
		}
	}
	return (0);
}
