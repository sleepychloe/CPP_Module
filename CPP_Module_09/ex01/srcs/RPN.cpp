/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:54:34 by yhwang            #+#    #+#             */
/*   Updated: 2023/03/29 05:15:57 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/RPN.hpp"

RPN::RPN(std::string input)
{
	parse(input);
}

RPN::RPN(const RPN& rpn)
{
	*this = rpn;
}

RPN& RPN::operator=(const RPN& rpn)
{
	if (this == &rpn)
		return (*this);
	this->_input = rpn.get_input();
	this->_temp = rpn.get_temp();
	return (*this);
}

RPN::~RPN()
{
}

const char*	RPN::EmptyInputException::what(void) const throw()
{
	return ("input is empty");
}

const char*	RPN::InvalidInputException::what(void) const throw()
{
	return ("invalid input foramt");
}

const char*	RPN::InvalidCharacterException::what(void) const throw()
{
	return ("found invalid character(s)");
}

RPN::IterableQueue<std::string>	RPN::get_input(void) const
{
	return (this->_input);
}

RPN::IterableQueue<long>	RPN::get_temp(void) const
{
	return (this->_temp);
}

int	RPN::check_int(std::string str)
{
	long	num;

	for (int i = 0; i < (int)str.length(); i++)
	{
		if (!('0' <= str[i] && str[i] <= '9'))
		{
			if (!(str[0] == '-'))
				return (0);
		}
	}
	num = atol(str.c_str());
	if (num < -2147483648 || num > 2147483647)
		return (0);
	return (1);
}

int	RPN::check_operator(std::string str)
{
	const char*	char_str = str.c_str();

	if ((strncmp(char_str, "+", 1) == 0 && strlen(char_str) == 1)
		|| (strncmp(char_str, "-", 1) == 0 && strlen(char_str) == 1)
		|| (strncmp(char_str, "*", 1) == 0 && strlen(char_str) == 1)
		|| (strncmp(char_str, "/", 1) == 0 && strlen(char_str) == 1))
		return (1);
	return (0);
}

double	RPN::do_operation(void)
{
	double		n1;
	double		n2;
	double		res = 0;
	std::string	op[10] = {"", };
	int		i = 0;

	if (_temp.size() < 2)
		throw (InvalidInputException());
	
	while (_input.size() >= 1 && check_operator(_input.front()))
	{
		op[i] = _input.front();
		_input.pop();
		i++;
	}

	if (i != (int)_temp.size() - 1)
		throw (InvalidInputException());

	i--;
	n1 = _temp.front();
	_temp.pop();
	n2 = _temp.front();
	_temp.pop();
	while (i >= 0)
	{
		if (op[i] == "+")
			res = n1 + n2;
		else if (op[i] == "-")
			res = n1 - n2;
		else if (op[i] == "*")
			res = n1 * n2;
		else if (op[i] == "/")
			res = n1 / n2;
		if (i >= 1)
		{
			n1 = res;
			n2 = _temp.front();
			_temp.pop();
		}
		i--;
	}
	_temp.push(res);
	return (res);
}

int	RPN::rpn_calculate(void)
{
	double	res;
	long	res_long;

	while (1)
	{
		while (!check_operator(_input.front()))
		{
			if (check_int(_input.front()))
			{
				_temp.push(atoi((_input.front()).c_str()));
				_input.pop();
			}
		}
		res = do_operation();
		if (_input.empty() == true)
			break ;
	}
	if (res == (long)res)
	{
		res_long = (long)res;
		std::cout << res_long << std::endl;
	}
	else
		std::cout << res << std::endl;
	return (0);
}

void	RPN::parse(std::string input)
{
	std::stringstream	ss(input);
	int		i = 0;
	std::string	token[100] = {"", };

	if (input == "")
		throw (EmptyInputException());
	while (!ss.eof())
	{
		std::getline(ss, token[i], ' ');
		if (token[i] != "")
			_input.push(token[i]);
		i++;
	}
	for (RPN::IterableQueue<std::string>::iterator iter = _input.begin();
		iter != _input.end(); iter++)
	{
		if ((!check_int(*iter) && !check_operator(*iter)))
			throw (InvalidCharacterException());
		if ((iter == _input.begin() && !check_int(*iter))
			|| (iter == _input.begin() + 1 && !check_int(*iter))
			|| (iter == _input.end() - 1 && !check_operator(*iter)))
			throw (InvalidInputException());
	}
	rpn_calculate();
}
