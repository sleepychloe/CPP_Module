/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:54:34 by yhwang            #+#    #+#             */
/*   Updated: 2023/03/27 06:09:47 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/RPN.hpp"

RPN::RPN(int argc, char **argv)
{
	parse(argc, argv);
}

RPN::RPN(const RPN& rpn)
{
	*this = rpn;
}

RPN& RPN::operator=(const RPN& rpn)
{
	if (this == &rpn)
		return (*this);
	this->_data = rpn.get_data();
	return (*this);
}

RPN::~RPN()
{
}

int	RPN::check_int(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (!('0' <= str[i] && str[i] <= '9'))
		{
			if (!(str[0] == '-'))
				return (1);
		}
	}
	return (0);
}

RPN::IterableQueue<int>	RPN::get_data(void) const
{
	return (this->_data);
}

void	RPN::parse(int argc, char **argv)
{
	RPN::IterableQueue<std::string>	data;

	for (int i = 0; i < argc - 1; i++)
	{
		std::stringstream	ss(argv[i + 1]);
		int		j = 0;
		std::string	token[100] = {"", };
		while (!ss.eof())
		{
			std::getline(ss, token[j], ' ');
			data.push(token[j]);
			j++;
		}
	}
	RPN::IterableQueue<std::string>::iterator iter;
	for (iter = data.begin(); iter != data.end(); iter++)
	{
		if (!(*iter == "+" || *iter == "-" || *iter == "*" || *iter == "/"))
		{
			if (check_int(*iter))
			{
				std::cout << *iter << std::endl;
				throw (std::exception());
				return ;
			}
			else
			{
				std::cout << *iter << std::endl;
			}
		}
	}

	iter = data.begin();
	char	op;
	int	n[9] = {0, };
	int	res;
	int	i = 0;
	while (1)
	{
		while (*iter == "+" || *iter == "-" || *iter == "*" || *iter == "/")
		{
			n[i] = _data.front();
			_data.pop();
			iter++;
		}
		op = *iter;
		if (op == '+')
		{
			//here
		}
	}
	
}
