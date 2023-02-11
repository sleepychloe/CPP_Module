/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 00:12:34 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/11 02:13:21 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Point.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 5);
	Point point(5,0);

	if (bsp(a, b, c, point) == 1)
		std::cout << "ok" << std::endl;
	
	return (0);
}
