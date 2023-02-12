/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 00:12:34 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/12 13:19:10 by yhwang           ###   ########.fr       */
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

	/* test 1: P is inside the triangle */
	Point point_inside_triangle(5, 1);

	std::cout << "╔═══════════════════════════════════════════════╗" << std::endl;
	std::cout << "║ test 1                                        ║" << std::endl;
	std::cout << "║ point P is insde the triangle                 ║" << std::endl;
	std::cout << "╠═══════════════════════════════════════════════╣" << std::endl;
	std::cout << "║ A(0, 0), B(10, 0), C(10, 10), P(5, 1)         ║" << std::endl;
	std::cout << "╠═══════════════════════════════════════════════╣" << std::endl;
	std::cout << "║ ";
	bsp(Point(0, 0), Point(10, 0), Point(10, 10), point_inside_triangle);
	std::cout << "╚═══════════════════════════════════════════════╝" << std::endl;

	/* test 2: P is out of the triangle */
	Point point_out_of_triangle(12, 1);

	std::cout << "╔═══════════════════════════════════════════════╗" << std::endl;
	std::cout << "║ test 2                                        ║" << std::endl;
	std::cout << "║ point P is out of the triangle                ║" << std::endl;
	std::cout << "╠═══════════════════════════════════════════════╣" << std::endl;
	std::cout << "║ A(0, 0), B(10, 0), C(10, 10), P(12, 1)        ║" << std::endl;
	std::cout << "╠═══════════════════════════════════════════════╣" << std::endl;
	std::cout << "║ ";
	bsp(Point(0, 0), Point(10, 0), Point(10, 10), point_out_of_triangle);
	std::cout << "╚═══════════════════════════════════════════════╝" << std::endl;

	/* test 3: P is on the vertice of the triangle */
	Point point_on_vertice(10, 10);

	std::cout << "╔═══════════════════════════════════════════════╗" << std::endl;
	std::cout << "║ test 3                                        ║" << std::endl;
	std::cout << "║ point P is on the vertice of the triangle     ║" << std::endl;
	std::cout << "╠═══════════════════════════════════════════════╣" << std::endl;
	std::cout << "║ A(0, 0), B(10, 0), C(10, 10), P(10, 10)       ║" << std::endl;
	std::cout << "╠═══════════════════════════════════════════════╣" << std::endl;
	std::cout << "║ ";
	bsp(Point(0, 0), Point(10, 0), Point(10, 10), point_on_vertice);
	std::cout << "╚═══════════════════════════════════════════════╝" << std::endl;

	/* test 4: P is on the edge of the triangle */
	Point point_on_edge(5, 0);

	std::cout << "╔═══════════════════════════════════════════════╗" << std::endl;
	std::cout << "║ test 4                                        ║" << std::endl;
	std::cout << "║ point P is on the edge of the triangle        ║" << std::endl;
	std::cout << "╠═══════════════════════════════════════════════╣" << std::endl;
	std::cout << "║ A(0, 0), B(10, 0), C(10, 10), P(5, 0)         ║" << std::endl;
	std::cout << "╠═══════════════════════════════════════════════╣" << std::endl;
	std::cout << "║ ";
	bsp(Point(0, 0), Point(10, 0), Point(10, 10), point_on_edge);
	std::cout << "╚═══════════════════════════════════════════════╝" << std::endl;


	return (0);
}
