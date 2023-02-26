/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 03:21:50 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/26 05:40:47 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "../incs/iter.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	/* error check: argument */
	if (argc != 1)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}

	/* test 1: int array */
	int	int_array[5] = {1, 2, 3, 4, 5};
	iter(int_array, 5, print_element);
	std::cout << std::endl;

	/* test 2: double array */
	double	double_array[5] = {0.1, 0.2, 0.3, 0.4, 0.5};
	iter(double_array, 5, print_element);
	std::cout << std::endl;

	float	float_array[5] = {2.1f, 2.2f, 2.3f, 2.4f, 2.5f};
	iter(float_array, 5, print_element);
	std::cout << std::endl;

	char	char_array[5] = {'a', 'b', 'c', 'd', 'e'};
	iter(char_array, 5, print_element);
	std::cout << std::endl;

	std::string	string_array[5] = {"string1", "string2", "string3", "string4", "string5"};
	iter(string_array, 5, print_element);
	return (0);
}
