/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:05:05 by yhwang            #+#    #+#             */
/*   Updated: 2023/01/20 23:20:22 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/main.hpp"

int	main(int argc, char **argv)
{
	PhoneBook	PhoneBook;
	std::string	input;
	std::string	check;

	(void)argv;

	/* error check: argument: when argc is not 1, return 1 */
	if (argc != 1)
	{
		argument_err_exit();
		return (1);
	}

	while (1)
	{
		print_msg(CYAN, "Please type a command: ADD, SEARCH, or EXIT");
		show_prompt('>');
		std::getline(std::cin, input);

		/* error check: eof */
		if (std::cin.eof())
		{
			print_eof_msg();
			break ;
		}
		/* error check: empty string */
		else if (input == "")
		{
			print_empty_str_msg();
			continue ;
		}
		/* error check: envalid command */
		else if (input != "ADD" && input != "SEARCH" && input != "EXIT")
		{
			print_invalid_cmd_msg();
			continue ;
		}
		/* normal operation: ADD, SEARCH, or EXIT */
		else
		{
			print_msg(YELLOW, "You selected ", input);
			if (input == "EXIT")
				print_msg(CYAN, "After quitting the program you will lose the contacts forever");
			print_msg(CYAN, "if you want to ", input, ", please type Y. Otherwise, please type N");
			show_prompt('>');

			std::getline(std::cin, check);

			/* error check */
			while (check != "Y" && check != "N")
			{
				/* error check: eof */
				if (std::cin.eof())
				{
					print_eof_msg();
					return (0);
				}
				else
				{
					/* error check: empty string */
					if (check == "")
						print_empty_str_msg();
					/* error check: invalid command */
					else
						print_msg(RED, "Invalid command: Please type Y or N");
					show_prompt('>');
					std::getline(std::cin, check);
				}
			}
			/* normal operation: Y or N */
			if (check == "Y")
			{
				if (input == "ADD")
				{
					if (PhoneBook.add())
						return (0);
				}
				else if (input == "SEARCH")
				{
					if (PhoneBook.search())
						return (0);
				}
				else
				{
					print_msg(YELLOW, "* PROGRAM EXIT *");
					break ;
				}
			}
			else
				continue ;
		}
	}
	return (0);
}
