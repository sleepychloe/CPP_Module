/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:52:11 by yhwang            #+#    #+#             */
/*   Updated: 2023/03/27 01:29:29 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <iterator>

class	BitcoinExchange
{
public:
	BitcoinExchange(std::ifstream* f_read_data);
	BitcoinExchange(const BitcoinExchange& bitcoinexchange);
	BitcoinExchange& operator=(const BitcoinExchange& bitcoinexchange);
	~BitcoinExchange();

	void			print_result(std::ifstream *f_read_input);
	
private:
	BitcoinExchange();
	std::map<int, double>	get_data(void) const;
	void			save_data(std::ifstream* f_read_data);
	int			check_key_value(std::string *temp, std::string value);
	void			print_valid_result(std::string key, std::string value, std::string key_print);

	std::map<int, double>	_data;

};

#endif
