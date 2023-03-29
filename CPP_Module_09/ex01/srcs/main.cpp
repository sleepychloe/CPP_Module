/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:54:38 by yhwang            #+#    #+#             */
/*   Updated: 2023/03/29 04:19:36 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: Argument error" << BLACK << std::endl;
		return (1);
	}

	try
	{
		RPN	rpn(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Error: " << e.what() << BLACK << std::endl;
	}
	return (0);
}
