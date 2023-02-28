/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 07:50:44 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/28 06:37:47 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

class	Span
{
public:
	Span(unsigned int size);
	Span(const Span& span);
	Span& operator=(const Span& span);
	~Span();

	class	SpanIsFullException: public std::exception
	{
	public:
		virtual const char*	what(void) const throw();
	};
	
	class	SpanIsEmptyException: public std::exception
	{
	public:
		virtual const char*	what(void) const throw();
	};

	class	SpanOnlyHasOneElementException: public std::exception
	{
		virtual const char*	what(void) const throw();
	};

	unsigned int		get_size(void) const;
	std::vector<int>	get_vector(void) const;
	
	void			addNumber(int num);
	unsigned int		shortestSpan(void);
	unsigned int		longestSpan(void);

	void			print(void);
	void			fill(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	
private:
	unsigned int		_size;
	std::vector<int>	_vector;
};

#endif
