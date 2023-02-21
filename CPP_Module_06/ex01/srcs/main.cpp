/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 06:16:27 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/21 07:05:08 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../incs/Serializer.hpp"

# define BLACK			"\x1b[0m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

int	main(int argc, char **argv)
{
	(void)argv;
	/* error check: argument */
	if (argc != 1)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}

	Data		original;
	original.u1 = 123;
	original.u2 = 2147483647;
	original.u3 = -2147483648;

	Serializer	serializer;

	uintptr_t	data_addr = serializer.serialize(&original);
	Data*		converted = serializer.deserialize(data_addr);

	std::cout << "address of original:\t" << CYAN << &original << BLACK << std::endl;
	std::cout << "result of serialize:\t" << data_addr << std::endl;
	std::cout << "result of deserialize:\t" << CYAN << converted << BLACK << std::endl;

	std::cout << "(before serializing) "
		<< "\tu1: " << YELLOW << original.u1 << BLACK
		<< ", u2: " << YELLOW << original.u2 << BLACK
		<< ", u3: " << YELLOW << original.u3 << BLACK << std::endl;
	std::cout << "(after deserializing)"
		<< "\tu1: " << YELLOW << converted->u1 << BLACK
		<< ", u2: " << YELLOW << converted->u2 << BLACK
		<< ", u3: " << YELLOW << converted->u3 << BLACK << std::endl;

	return (0);
}
