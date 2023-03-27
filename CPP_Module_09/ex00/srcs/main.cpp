/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:52:55 by yhwang            #+#    #+#             */
/*   Updated: 2023/03/27 02:08:08 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: could not open file." << BLACK << std::endl;
		return (1);
	}

	std::string	input_file = argv[1];

	std::ifstream	f_read_data;
	std::ifstream	f_read_input;

	f_read_data.open("data.csv", std::ios::in);
	f_read_input.open(input_file.c_str(), std::ios::in);

	if (f_read_data.fail())
	{
		std::cerr << RED << "Error: could not open database file." << BLACK << std::endl;
		return (1);
	}
	if (input_file == "data.csv")
	{
		f_read_data.close();
		std::cerr << RED << "Error: please put proper input file." << BLACK << std::endl;
		return (1);
	}
	if (f_read_input.fail())
	{
		f_read_data.close();
		std::cerr << RED << "Error: could not open file." << BLACK << std::endl;
		return (1);
	}

	BitcoinExchange	bitcoin(&f_read_data);
	bitcoin.print_result(&f_read_input);

	f_read_data.close();
	f_read_input.close();
	return (0);
}
