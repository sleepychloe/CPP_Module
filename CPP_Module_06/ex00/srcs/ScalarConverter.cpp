/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 05:52:05 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/20 18:11:43 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScalarConverter.hpp"

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"

ScalarConverter::ScalarConverter(std::string str): _original_str(str),
			_char(0), _int(0), _float(0.0f), _double(0.0),
			_char_str(""), _int_str(""), _float_str(""), _double_str("")
{
	parse();
}

ScalarConverter::ScalarConverter(const ScalarConverter& scalarconverter)
{
	*this = scalarconverter;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& scalarconverter)
{
	if (this == &scalarconverter)
		return (*this);
	this->_original_str = scalarconverter._original_str;
	this->_char = scalarconverter._char;
	this->_int = scalarconverter._int;
	this->_float = scalarconverter._float;
	this->_double = scalarconverter._double;
	this->_char_str = scalarconverter._char_str;
	this->_int_str = scalarconverter._int_str;
	this->_float_str = scalarconverter._float_str;
	this->_double_str = scalarconverter._double_str;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

const char*	ScalarConverter::ImpossibleException::what(void) const throw()
{
	return ("impossible");
}

const char*	ScalarConverter::NonDisplyableException::what(void) const throw()
{
	return ("Non displayable");
}


const char*	ScalarConverter::OutOfRangeException::what(void) const throw()
{
	return ("out of range");
}

void	ScalarConverter::parse(void)
{
	check_char(_original_str);
	check_int(_original_str);
	check_float_double(_original_str);
	check_special(_original_str);
}

int	ScalarConverter::check_ascii_range(std::string str, int n1, int n2)
{
	int	length = str.length();
	for (int i = 0; i < length; i++)
	{
		if (!(n1 <= str[i] && str[i] <= n2))
			return (0);
	}
	return (1);
}

int	ScalarConverter::check_ascii_range(std::string str, int n1, int n2, char c)
{
	int	length = str.length();
	for (int i = 0; i < length; i++)
	{
		if (!((n1 <= str[i] && str[i] <= n2) || str[i] == c))
			return (0);
	}
	return (1);
}

int	ScalarConverter::check_char_valid(std::string str)
{
	int	length = str.length();
	for (int i = 0; i < length; i++)
	{
		if (i == 0
			&& !(('0' <= str[i] && str[i] <= '9') || str[i] == '+' || str[i] == '-'))
			return (0);
		if (!(('0' <= str[i] && str[i] <= '9') || str[i] == '.'))
			return (0);
	}
	return (1);
}

void	ScalarConverter::check_char(std::string str)
{
	try
	{
		if (str.length() > 1 && str[str.length() - 1] == 'f')
			str = str.substr(0, str.length() - 1);
		if (str.length() > 1 && str[0] == '+')
			str = str.substr(1, str.length());
		if ((!isprint(str[0]) && str.length() == 1)
			|| (check_ascii_range(str, '0', '9') && str.length() == 1))
			throw (NonDisplyableException());
		if (!(isprint(atol(str.c_str())) && check_char_valid(str)) && str.length() > 1)
			throw (NonDisplyableException());
		if (atol(str.c_str()) != atof(str.c_str()))
			throw (NonDisplyableException());
		if (str.length() == 1)
			_char = str[0];
		else
			_char = atol(str.c_str());
		_int = static_cast<int>(_char);
		_float = static_cast<float>(_char);
		_double = static_cast<double>(_char);
	}
	catch (std::exception& e)
	{
		_char_str = e.what();
	}
}

int	ScalarConverter::check_int_zero(std::string str)
{
	if (str[0] == '0')
	{
		if (str[1] && str[1] == '.')
		{
			if (str[str.length() - 1] == '.')
				return (0);
			std::string	temp = str.substr(2, str.length());
			int		length = temp.length();

			for (int i = 0; i < length; i++)
			{
				if (!(temp[i] == '0'))
					return (0);
			}
		}
	}
	return (1);
}

int	ScalarConverter::check_int_str(std::string str)
{
	int	length = str.length();

	if (('0' <= str[0] && str[0] <= '9'))
	{
		for (int i = 0; i < length; i++)
		{
			if (!check_ascii_range(str, '0', '9'))
				return (0);
		}
	}
	return (1);
}

void	ScalarConverter::check_int(std::string str)
{
	if (str[str.length() - 1] == 'f')
		str = str.substr(0, str.length() - 1);
	std::string	temp;
	if ((str[0] == '+' || str[0] == '-'))
		temp = str.substr(1, str.length());
	else
		temp = str;

	try
	{
		if (!(isdigit(str[0]) || str[0] == '+' || str[0] == '-'))
			throw (ImpossibleException());
		if (!(check_float_double_str(temp)
			&& atol(str.c_str()) == atof(str.c_str())))
			throw (ImpossibleException());
		if (atol(str.c_str()) == 0 && str.length() == 1)
			_int = 0;
		if (atol(str.c_str()) != 0)
		{
			if (atol(str.c_str()) < INT_MIN
				|| atol(str.c_str()) > INT_MAX)
				throw (OutOfRangeException());
			_int = atoi(str.c_str());
		}
		_double = static_cast<double>(_int);
		_float = static_cast<float>(_int);
	}
	catch(const std::exception& e)
	{
		_int_str = e.what();
	}
}

int	ScalarConverter::check_float_double_str(std::string str)
{
	int	length = str.length();
	int	point_flag = 0;
	
	if (('0' <= str[0] && str[0] <= '9'))
	{
		for (int i = 0; i < length; i++)
		{
			if (!check_ascii_range(str, '0', '9', '.'))
				return (0);
		}
		for (int i = 0; i < length; i++)
		{
			if (str[i] == '.')
				point_flag++;
		}
		if(point_flag > 1)
			return (0);
	}
	return (1);
}

void	ScalarConverter::check_float_double(std::string str)
{
	if (is_special(str))
		return ;
	if (str[str.length() - 1] == 'f')
		str = str.substr(0, str.length() - 1);

	std::string	temp;
	if ((str[0] == '+' || str[0] == '-'))
		temp = str.substr(1, str.length());
	else
		temp = str;
	
	try
	{
		if (!(isdigit(str[0]) || str[0] == '+' || str[0] == '-')
			|| str[0] == '.' || str[str.length() - 1] == '.')
			throw (ImpossibleException());
		if (!check_float_double_str(temp))
			throw (ImpossibleException());
		if (atof(str.c_str()) == 0 && str.length() == 1)
		{
			_float = 0;
			_double = 0;
		}
		if (atof(str.c_str()) != 0)
		{
			_float = atof(str.c_str());
			_double = static_cast<double>(_float);
		}
		if ((str.substr(0, 5) == "+inff" || str.substr(0, 5) == "-inff"
			|| str.substr(0, 5) == "+nanf" || str.substr(0, 5) == "-nanf")
			&& str.length() != 4)
			throw (ImpossibleException());
	}
	catch(const std::exception& e)
	{
		_float_str =  e.what();
		_double_str = e.what();
	}
}

int	ScalarConverter::is_special(std::string str)
{
	if ((str == "nan" || str == "inf") && str.length() == 3)
		return (1);
	if ((str == "+nan" || str == "-nan"
		|| str == "+inf" || str == "-inf"
		|| str == "nanf" || str == "inff") && str.length() == 4)
		return (1);
	if ((str == "+nanf" || str == "-nanf"
		|| str == "+inff" || str == "-inff") && str.length() == 5)
		return (1);
	return (0);
}

void	ScalarConverter::check_special(std::string str)
{
	double	n;

	try
	{
		if (is_special(str))
		{
			if (str == "+nan" || str == "-nan" || str == "+nanf" || str == "-nanf"
				|| str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
			{
				if (str == "-nan" || str == "-nanf" || str == "-inf" || str == "-inff")
					n = -1 * atof((str.substr(1, str.length() - 1)).c_str());
				else
					n = atof((str.substr(1, str.length() - 1)).c_str());
			}
			else if (str == "nan" || str == "nanf" || str == "inf" || str == "inff")
				n = atof(str.c_str());
			else
				throw (ImpossibleException());

			if ((std::isnan(n) || std::isinf(n) || std::isinf(-1 * n)))
			{
				_char_str = "impossible";
				_int_str = "impossible";
				_float = static_cast<float>(n);
				_double = static_cast<double>(n);
			}
		}
	}
	catch(const std::exception& e)
	{
		_float_str = "impossible";
		_double_str = "impossible";
	}
}

void	ScalarConverter::convert(void)
{
	std::cout << "char: ";
	if (_char_str != "")
		std::cout << _char_str << std::endl;
	else
		std::cout << "'" << _char << "'" << std::endl;
	
	std::cout << "int: ";
	if (_int_str != "")
		std::cout << _int_str << std::endl;
	else
		std::cout << _int << std::endl;

	std::cout << "float: ";
	if (_float_str != "")
		std::cout << _float_str << std::endl;
	else
	{
		if (std::isnan(_float) || std::isinf(_float) || isinff(-1 * _float))
			std::cout << _float << "f" << std::endl;
		else if (_float == (int)_float)
			std::cout << _float << ".0f" << std::endl;
		else
			std::cout << _float << "f" << std::endl;
	}

	std::cout << "double: ";
	if (_double_str != "")
		std::cout << _double_str << std::endl;
	else
	{
		if (_float == (int)_float)
			std::cout << _double << ".0" << std::endl;
		else	
			std::cout << _double << std::endl;
	}
}
