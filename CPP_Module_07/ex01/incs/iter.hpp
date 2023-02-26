/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 03:21:43 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/26 05:40:28 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstdlib>
#include <iostream>

template <typename T>
void	print_element(T const &element)
{
	std::cout << element << std::endl;
}

template <typename T>
void	iter(T *array, std::size_t len, void (*f)(T const &))
{
	for (std::size_t i = 0; i < len; i++)
		f(array[i]);
}

#endif
