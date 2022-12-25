/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:05:05 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/25 08:38:24 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/main.hpp"

int	main(int argc, char **argv)
{
	PhoneBook	PhoneBook;
	std::string	input;
	std::string	check;
	if (argc != 1)
		argument_err_exit();
	while (1)
	{
		print_msg(CYAN, "Please type a command: ADD, SEARCH, or EXIT");
		show_prompt('>');
		std::getline(std::cin, input);
		if (input == "")
		{
			print_msg(RED, "Input should not be empty");
			continue ;
		}
		if (input != "ADD" && input != "SEARCH" && input != "EXIT")
		{
			print_msg(RED, "Invalid command");
			continue ;
		}
		if (input == "ADD" || input == "SEARCH" || input == "EXIT")
		{
			print_msg(YELLOW, "You selected ", input);
			if (input == "EXIT")
				print_msg(CYAN, "After quitting the program you will lose the contacts forever");
			print_msg(CYAN, "if you want to ", input, ", please type Y. Otherwise, please type N");
			show_prompt('>');
			std::getline(std::cin, check);
			while (check != "Y" && check != "N")
			{
				print_msg(RED, "Invalid command: Please type Y or N");
				show_prompt('>');
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
					print_msg(YELLOW, "* PROGRAM EXIT *");
					break ;
				}
			}
			else if (check == "N")
				continue ;
		}
	}
	return (0);
}
