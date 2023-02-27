/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 07:50:50 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/27 14:09:06 by yhwang           ###   ########.fr       */
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
	this->_vector = span.get_vector();
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
		throw (SpanIsEmptyException());
	_vector.push_back(num);
}

unsigned int	Span::shortestSpan(void)
{
	if (_vector.size() == 0)
		throw (SpanIsEmptyException());
	if (_vector.size() == 1)
		throw (SpanOnlyHasOneElementException());

	unsigned int		shortest;
	std::vector<int>	temp;
	
	
	
}
