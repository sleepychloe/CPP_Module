/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 07:50:50 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/28 06:45:31 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Span.hpp"

Span::Span(unsigned int size): _size(size)
{
}

Span::Span(const Span& span)
{
	*this = span;
}

Span& Span::operator=(const Span& span)
{
	if (this == &span)
		return (*this);
	this->_size = span.get_size();
	this->_vector = std::vector<int>(span._vector);
	return (*this);
}

Span::~Span()
{
}

const char*	Span::SpanIsFullException::what(void) const throw()
{
	return ("Span is already full");
}

const char*	Span::SpanIsEmptyException::what(void) const throw()
{
	return ("Span is empty");
}

const char*	Span::SpanOnlyHasOneElementException::what(void) const throw()
{
	return ("Span has only one element");
}

unsigned int	Span::get_size(void) const
{
	return (_size);
}

std::vector<int>	Span::get_vector(void) const
{
	return (_vector);
}

void	Span::addNumber(int num)
{
	if (_vector.size() == get_size())
		throw (SpanIsFullException());
	_vector.push_back(num);
}

unsigned int	Span::shortestSpan(void)
{
	if (_vector.size() == 0)
		throw (SpanIsEmptyException());
	if (_vector.size() == 1)
		throw (SpanOnlyHasOneElementException());

	/* sort: ascending order */
	std::vector<int>	temp(_vector);
	std::sort(temp.begin(), temp.end());

	int	min = temp[1] - temp[0];
	for (std::vector<int>::iterator iter = temp.begin();
		iter != temp.end() - 1; iter++)
	{
		if (min > *(iter + 1) - *(iter))
			min = *(iter + 1) - *(iter);
	}
	return (min);
}

unsigned int	Span::longestSpan(void)
{
	if (_vector.size() == 0)
		throw (SpanIsEmptyException());
	if (_vector.size() == 1)
		throw (SpanOnlyHasOneElementException());

	int	max = *std::max_element(_vector.begin(), _vector.end());
	int	min = *std::min_element(_vector.begin(), _vector.end());
	return (max - min);
}

void	Span::print(void)
{
	for (std::vector<int> ::iterator iter = _vector.begin();
		iter != _vector.end(); iter++)
		std::cout << *iter << ' ';
	std::cout << std::endl;
}

void	Span::fill(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator iter = begin; iter != end; iter++)
		addNumber(*iter);
}
