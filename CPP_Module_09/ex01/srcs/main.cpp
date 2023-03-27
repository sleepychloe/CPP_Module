/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:54:38 by yhwang            #+#    #+#             */
/*   Updated: 2023/03/27 05:40:57 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc < 1 || argc >= 10)
	{
		std::cerr << RED << "Error: Argument error" << BLACK << std::endl;
		return (1);
	}

	try
	{
		RPN	rpn(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
