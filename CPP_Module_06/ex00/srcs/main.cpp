/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 04:24:17 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/20 17:49:45 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	/* error check: argument */
	if (argc != 2)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}

	ScalarConverter s(argv[1]);
	s.convert();
	return (0);
}
