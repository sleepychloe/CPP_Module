/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:52:49 by yhwang            #+#    #+#             */
/*   Updated: 2023/03/27 02:51:17 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream* f_read_data)
{
	save_data(f_read_data);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& bitcoinexchange)
{
	*this = bitcoinexchange;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& bitcoinexchange)
{
	if (this == &bitcoinexchange)
		return (*this);
	this->_data = get_data();
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

std::map<int, double>	BitcoinExchange::get_data(void) const
{
	return (this->_data);
}

void	BitcoinExchange::save_data(std::ifstream *f_read_data)
{
	std::string		line = "";

	while (std::getline(*f_read_data, line))
	{
		if (line.find("date") != std::string::npos || line.find("exchange_rate") != std::string::npos)
			continue ;

		std::stringstream	ss_key_value(line);
		std::string		key_value[2] = {"", };
		std::string		temp[3] = {"", };
		int			i = 0;

		while (!ss_key_value.eof())
		{
			std::getline(ss_key_value, key_value[i], ',');
			if (i == 0)
			{
				std::stringstream	ss_key(key_value[0]);
				int	j = 0;
				while (!ss_key.eof())
				{
					std::getline(ss_key, temp[j], '-');
					j++;
				}
				key_value[0] = "";
				key_value[0].append(temp[0]).append(temp[1]).append(temp[2]);
			}
			i++;
		}
		_data.insert(std::pair<int, double>(atoi(key_value[0].c_str()), atof(key_value[1].c_str())));
	}
}

int	BitcoinExchange::empty_string_check(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (!(str[i] == ' ' || str[i] == '\t'))
			return (1);
	}
	return (0);
}

int	BitcoinExchange::string_check(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (std::isdigit(str[i] - 48))
			return (1);
	}
	return (0);
}

int	BitcoinExchange::string_check(std::string str, char c)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (std::isdigit(str[i] - 48))
		{
			if (str[i] != c)
				return (1);
		}
	}
	return (0);
}

int	BitcoinExchange::check_key_value(std::string *temp, std::string value, std::string line)
{
	if (string_check(temp[0]) || string_check(temp[1]) || string_check(temp[2]) || string_check(value, '.'))
	{
		std::cout << RED << "Error: bad input" << YELLOW << " => " << line << BLACK << std::endl;
		return (1);
	}

	if (temp[1][0] == '0')
		temp[1] = temp[1].substr(1, std::string::npos);
	if (temp[2][0] == '0')
		temp[2] = temp[2].substr(1, std::string::npos);

	int	year = atoi(temp[0].c_str());
	int	month = atoi(temp[1].c_str());
	int	day = atoi(temp[2].c_str());

	/* check key */
	if (year < 1900)
	{
		std::cout << RED << "Error: invalid year(1900 <= year)" BLACK << std::endl;
		return (1);
	}
	if (!(1 <= month && month <= 12))
	{
		std::cout << RED << "Error: invalid month(1 <= month <= 12)" << BLACK << std::endl;
		return (1);
	}
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		
		if (!(1 <= day && day <= 31))
		{
			std::cout << RED << "Error: invalid day(1 <= ";
			if (month == 1)
				std::cout << "January <= 31)" << BLACK << std::endl;
			else if (month == 3)
				std::cout << "March <= 31)" << BLACK << std::endl;
			else if (month == 5)
				std::cout << "May <= 31)" << BLACK << std::endl;
			else if (month == 7)
				std::cout << "July <= 31)" << BLACK << std::endl;
			else if (month == 8)
				std::cout << "August <= 31)" << BLACK << std::endl;
			else if (month == 10)
				std::cout << "October <= 31)" << BLACK << std::endl;
			else if (month == 12)
				std::cout << "December <= 31)" << BLACK << std::endl;
			return (1);
		}	
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (!(1 <= day && day <= 30))
		{
			std::cout << RED << "Error: invalid day(1 <= ";
			if (month == 4)
				std::cout << "April <= 30)" << BLACK << std::endl;
			else if (month == 6)
				std::cout << "June <= 30)" << BLACK << std::endl;
			else if (month == 9)
				std::cout << "September <= 30)" << BLACK << std::endl;
			else if (month == 11)
				std::cout << "November <= 30)" << BLACK << std::endl;
			return (1);
		}
	}
	if (year % 4 == 0 && month == 2)
	{
		if (!(1 <= day && day <= 29))
		{
			std::cout << RED <<
				"Error: invalid day(1 <= February <= 29 in this year)" << BLACK << std::endl;
			return (1);
		}
	}
	if (year % 4 != 0 && month == 2)
	{
		if (!(1 <= day && day <= 28))
		{
			std::cout << RED << "Error: invalid day(1 <= February <= 28)" << BLACK << std::endl;
			return (1);
		}
	}
	
	/* check_value */
	if (0 > atof(value.c_str()))
	{
		std::cout << RED << "Error: not a positive number." << BLACK << std::endl;
		return (1);
	}
	if (atof(value.c_str()) >= 2147483648)
	{
		std::cout << RED << "Error: too large number." << BLACK << std::endl;
		return (1);
	}
	return (0);
}

void	BitcoinExchange::print_valid_result(std::string key, std::string value, std::string key_print)
{
	int	map_key = atoi(key.c_str());
	double	map_value = -1;

	std::map<int, double>::iterator	iter = this->_data.begin();
	int	start_date = (*iter).first;
	int	start_date_dd = start_date % 100;
	int	start_date_mm = (start_date % 10000) / 100;
	int	start_date_yyyy = start_date / 10000;

	iter = this->_data.end();
	iter--;
	int	end_date = (*iter).first;
	int	end_date_dd = end_date % 100;
	int	end_date_mm = (end_date % 10000) / 100;
	int	end_date_yyyy = end_date / 10000;

	while (1)
	{
		if (map_value != -1)
			break ;
		if (map_key < start_date)
		{
			std::cout << RED << "Error: invalid date: the first date in the database is "
				<< start_date_yyyy << "-" << std::setw(2) << std::setfill('0')
				<< start_date_mm << "-" << std::setw(2) << std::setfill('0') << start_date_dd << ".";
			break ;
		}
		
		for (iter = this->_data.begin(); iter != this->_data.end(); iter++)
		{
			if ((*iter).first == map_key)
			{
				map_value = (*iter).second;
				break ;
			}
		}
		map_key--;
	}
	if (map_value != -1)
		std::cout << key_print << "=> " << value << " = " << atof(value.c_str()) * map_value;
	if (atoi(key.c_str()) > end_date)
		std::cout << CYAN << " (the last date in the database is "
			<< end_date_yyyy << "-" << std::setw(2) << std::setfill('0')
			<< end_date_mm << "-" << std::setw(2) << std::setfill('0') << end_date_dd
			<< ". calculated with end date.)";
	std::cout << BLACK << std::endl;
}

void	BitcoinExchange::print_result(std::ifstream *f_read_input)
{
	std::string		line = "";
	std::string		key_value[2] = {"", };
	std::string		temp[3] = {"", };
	std::string		key = "";

	while (std::getline(*f_read_input, line))
	{
		if (line == "" || !empty_string_check(line) || line.find("date") != std::string::npos || line.find("value") != std::string::npos)
			continue ;
		if (line.find("|") == std::string::npos)
		{
			std::cout << RED << "Error: bad input" << YELLOW << " => " << line << BLACK << std::endl;
			continue ;
		}

		std::stringstream	ss_key_value(line);
		int			i = 0;
		while (!ss_key_value.eof())
		{
			std::getline(ss_key_value, key_value[i], '|');
			if (i == 0)
			{
				std::stringstream	ss_key(key_value[0]);
				int	j = 0;
				while (!ss_key.eof())
				{
					std::getline(ss_key, temp[j], '-');
					j++;
				}
				temp[2] = temp[2].substr(0, temp[2].length() - 1);
				key = key_value[0];
				key_value[0] = "";
				key_value[0].append(temp[0]).append(temp[1]).append(temp[2]);
			}
			if (i == 1 && key_value[1] != "")
				key_value[1] = key_value[1].substr(1, std::string::npos);
			i++;
		}
		if (temp[1] == "" || temp[2] == "" || key_value[1] == "")
		{
			std::cout << RED << "Error: bad input" << YELLOW << " => " << line << BLACK << std::endl;
			continue ;
		}
		if (check_key_value(temp, key_value[1], line))
			continue ;
		print_valid_result(key_value[0], key_value[1], key);
	}
}
