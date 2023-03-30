/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:01:56 by yhwang            #+#    #+#             */
/*   Updated: 2023/03/30 05:13:18 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	parse(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe& pmergeme)
{
	*this = pmergeme;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& pmergeme)
{
	if (this == &pmergeme)
		return (*this);
	this->_vector_container = pmergeme.get_vector_container();
	this->_list_container = pmergeme.get_list_container();
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

std::vector<int>	PmergeMe::get_vector_container(void) const
{
	return (_vector_container);
}

std::list<int>	PmergeMe::get_list_container(void) const
{
	return (_list_container);
}

int	PmergeMe::check_int(char *str)
{
	long		num;
	std::string	err_msg = "";

	for (int i = 0; i < (int)strlen(str); i++)
	{
		if (!('0' <= str[i] && str[i] <= '9'))
		{
			err_msg.append("found invalid character(s): ");
			err_msg.append(str);
			throw (err_msg);
		}
	}
	num = atol(str);
	if (num < 0 || num > 2147483647)
	{
		err_msg.append("number is out of range: ");
		err_msg.append(str);
		throw (err_msg);
	}
	return (1);
}

void	PmergeMe::parse(int argc, char **argv)
{
	for (int i = 1; i < argc ; i++)
	{
		if (check_int(argv[i]))
		{
			_vector_container.push_back(atoi(argv[i]));
			_list_container.push_back(atoi(argv[i]));
		}
	}
}

void	PmergeMe::print_vector_container(void)
{
	for (std::vector<int>::iterator iter = _vector_container.begin();
		iter != _vector_container.end(); iter++)
		std::cout << CYAN << *iter << " ";
	std::cout << BLACK << std::endl;
}

void	PmergeMe::print_list_container(void)
{
	for (std::list<int>::iterator iter = _list_container.begin();
		iter != _list_container.end(); iter++)
		std::cout << YELLOW << *iter << " ";
	std::cout << BLACK << std::endl;
}

void	PmergeMe::merge_vector(int left, int right)
{
	std::cout << "left: " << _vector_container.at(left) << ", right: " << _vector_container.at(right) << std::endl;
}

void	PmergeMe::split_vector(int left, int right)
{
	if (right == left + 1)
		return ;

	int	mid = (left + right) / 2;

	split_vector(left, mid);
	split_vector(mid, right);
	merge_vector(left, right);
}

void	PmergeMe::merge_sort_vector(void)
{
	split_vector(0, _vector_container.size() - 1);
}

void	PmergeMe::insert_sort_vector(void)
{
	
}

void	PmergeMe::merge_insert_sort_vector(void)
{

}

void	PmergeMe::merge_sort_list(void)
{

}

void	PmergeMe::insert_sort_list(void)
{
	
}

void	PmergeMe::merge_insert_sort_list(void)
{

}
