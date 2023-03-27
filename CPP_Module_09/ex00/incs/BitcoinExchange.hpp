/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:52:11 by yhwang            #+#    #+#             */
/*   Updated: 2023/03/27 03:48:20 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <map>
#include <iterator>

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

class	BitcoinExchange
{
public:
	BitcoinExchange(std::ifstream* f_read_data);
	BitcoinExchange(const BitcoinExchange& bitcoinexchange);
	BitcoinExchange& operator=(const BitcoinExchange& bitcoinexchange);
	~BitcoinExchange();

	std::map<int, double>	get_data(void) const;

	void			print_result(std::ifstream *f_read_input);
	
private:
	BitcoinExchange();

	void			save_data(std::ifstream* f_read_data);
	int			empty_string_check(std::string str);
	int			string_check(std::string str);
	int			string_check(std::string str, char c);
	int			check_key_value(std::string *temp, std::string value, std::string line);
	void			print_valid_result(std::string key, std::string value, std::string key_print);

	std::map<int, double>	_data;

};

#endif
