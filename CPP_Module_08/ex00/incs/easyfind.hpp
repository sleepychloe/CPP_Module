/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 07:04:43 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/27 07:37:49 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

#include <stdexcept>
#include <algorithm>

class	NoOccurrenceIsFoundException: public std::exception
{
public:
	virtual const char*	what(void) const throw()
	{
		return ("No occurrence is found");
	}
};

template <typename T>
typename T::iterator	easyfind(T& container, int value)
{
	typename T::iterator	res = std::find(container.begin(), container.end(), value);
	if (res == container.end())
		throw (NoOccurrenceIsFoundException());
	return (res);
}

#endif
