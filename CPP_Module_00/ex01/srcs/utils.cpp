/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 07:44:06 by yhwang            #+#    #+#             */
/*   Updated: 2023/01/20 23:01:40 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/utils.hpp"

void	argument_err_exit(void)
{
	std::cerr << RED << "Argumet error: Please put valid command\n"
		<< "(command: ./phonebook)" << BLACK << std::endl;
}

void	print_msg(std::string color, std::string msg)
{
	std::cout << color << msg << BLACK << std::endl;
}

void	print_msg(std::string color, std::string msg, int n)
{
	std::cout << color << msg << n << BLACK << std::endl;
}

void	print_msg(std::string color, std::string msg1, int n, std::string msg2)
{
	std::cout << color << msg1 << n << msg2 << BLACK << std::endl;
}

void	print_msg(std::string color, std::string msg, std::string s)
{
	std::cout << color << msg << s << BLACK << std::endl;
}

void	print_msg(std::string color, std::string msg1, std::string s, std::string msg2)
{
	std::cout << color << msg1 << s << msg2 << BLACK << std::endl;
}

void	show_prompt(char c)
{
	std::cout << "    " << c << ' ';
}

/* error message */
void	print_eof_msg(void)
{
	std::cout << "^D" << std::endl;
}

void	print_empty_str_msg(void)
{
	print_msg(RED, "Input should not be empty");
}

void	print_invalid_cmd_msg(void)
{
	print_msg(RED, "Invalid command");
}
