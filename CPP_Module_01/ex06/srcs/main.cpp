/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:06:17 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/07 14:58:26 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Harl.h"

int	main(int argc, char **argv)
{
	/* error check: argument error */
	if (argc != 2)
	{
		std::cout << "Error: Argument error" << std::endl
			<< "(command: ./HarlFilter msg_you_want_to_put)"
			<< std::endl;
		return (1);
	}

	std::string level = argv[1];
	
	Harl	Harl;
	Harl.complain(level);

	return (0);
}
