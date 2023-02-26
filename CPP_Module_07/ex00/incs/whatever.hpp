/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 01:18:05 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/26 01:30:48 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T& a, T&b)
{
	T temp = b;
	
	b = a;
	a = temp;
}

template <typename T>
T&	min(T& a, T& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T&	max(T& a, T& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif
