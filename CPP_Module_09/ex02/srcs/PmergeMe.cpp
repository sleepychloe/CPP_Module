/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:01:56 by yhwang            #+#    #+#             */
/*   Updated: 2023/04/22 15:15:58 by yhwang           ###   ########.fr       */
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
		std::cout << *iter << " ";
	std::cout << std::endl;
}

void	PmergeMe::print_list_container(void)
{
	for (std::list<int>::iterator iter = _list_container.begin();
		iter != _list_container.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

void	PmergeMe::combine_vector(int left, int mid, int right)
{
	int	l = mid - left + 1;
	int	r = right - mid;

	std::vector<int>	v_left(l);
	std::vector<int>	v_right(r);

	for (int i = 0; i < l; i++)
		v_left[i] = _vector_container.at(left + i);
	for (int i = 0; i < r; i++)
		v_right[i] = _vector_container.at(mid + 1 + i);

	int	x = 0;
	int	y = 0;
	int	z = left;
	while (x < l && y < r)
	{
		if (v_left[x] <= v_right[y])
			_vector_container.at(z) = v_left[x++];
		else
			_vector_container.at(z) = v_right[y++];
		z++;
	}
	while (x < l)
		_vector_container.at(z++) = v_left[x++];
	while (y < r)
		_vector_container.at(z++) = v_right[y++];
}

void	PmergeMe::combine_list(int left, int mid, int right)
{
	int	l = mid - left + 1;
	int	r = right - mid;

	int	l_left[l];
	int	l_right[r];

	std::list<int>::iterator	it_l = _list_container.begin();
	std::advance(it_l, left);
	for (int i = 0; i < l; i++)
	{
		l_left[i] = *it_l;
		it_l++;
	}
	std::list<int>::iterator	it_r = _list_container.begin();
	std::advance(it_r, mid + 1);
	for (int i = 0; i < r; i++)
	{
		l_right[i] = *it_r;
		it_r++;
	}

	int				x = 0;
	int				y = 0;
	std::list<int>::iterator	iter = _list_container.begin();
	std::advance(iter, left);
	while (x < l && y < r)
	{
		if (l_left[x] <= l_right[y])
			*iter = l_left[x++];
		else
			*iter = l_right[y++];
		iter++;
	}
	while (x < l)
	{
		*iter = l_left[x++];
		iter++;
	}
	while (y < r)
	{
		*iter = l_right[y++];
		iter++;
	}
}

void	PmergeMe::merge_sort(int left, int right, std::string container)
{
	if (left >= right)
		return ;

	int	mid = (left + right - 1) / 2;

	merge_sort(left, mid, container);
	merge_sort(mid + 1, right, container);
	if (container == "vector")
		combine_vector(left, mid, right);
	else if (container == "list")
		combine_list(left, mid, right);
}

void	PmergeMe::insert_sort(int left, int right, std::string container)
{
	if (container == "vector")
	{
		for (int i = left; i < right; i++)
		{
			for (int j = i + 1; j > left && _vector_container.at(j) < _vector_container.at(j - 1); j--)
				std::swap(_vector_container.at(j), _vector_container.at(j - 1));
		}
	}
	else if (container == "list")
	{
		std::list<int>::iterator	it_i = _list_container.begin();
		std::list<int>::iterator	it_j;
		std::list<int>::iterator	it;

		std::advance(it_i, left);
		for (int i = left; i < right; i++)
		{
			it_j = it_i;
			it_j++;
			for (int j = i + 1; j > left; j--)
			{
				it = it_j;
				it--;
				if (*it_j < *it)
					std::swap(*it_j, *it);
				it_j--;	
			}
			it_i++;
		}
	}
}

void	PmergeMe::sort_vector(void)
{
	long unsigned int	len = _vector_container.size();

	if (len <= 15)
		insert_sort(0, _vector_container.size() - 1, "vector");
	else
		merge_sort(0, _vector_container.size() - 1, "vector");
}

void	PmergeMe::sort_list(void)
{
	long unsigned int	len = _list_container.size();

	if (len <= 15)
		insert_sort(0, _list_container.size() - 1, "list");
	else
		merge_sort(0, _list_container.size() - 1, "list");
}