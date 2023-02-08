/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:43:47 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/06 20:41:18 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Harl.h"

int	main(int argc, char **argv)
{
	(void)argv;
	/* error check: argument error */
	if (argc != 1)
	{
		std::cout << "Argument error" << std::endl
			<< "(command: ./harl)" << std::endl;
		return (1);
	}

	Harl Harl;

	Harl.complain("DEBUG");
	std::cout << std::endl;

	Harl.complain("INFO");
	std::cout << std::endl;

	Harl.complain("WARNING");
	std::cout << std::endl;

	Harl.complain("ERROR");
	std::cout << std::endl;

	return (0);
}