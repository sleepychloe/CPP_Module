/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 00:12:43 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/12 13:18:25 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Point.hpp"

/*
area of triangle using p1(x1, y1), p2(x2, y2), p3(x3, y3)
	: abs((x1y2 + x2y3 + x3y1) - (x2y1 + x3y2 + x1y3)) / 2
*/
Fixed	get_triangle_area(Point const p1, Point const p2, Point const p3)
{
	Fixed	temp1;
	Fixed	temp2;
	Fixed	area;

	temp1 = ((p1.get_value_x() * p2.get_value_y())
		+ (p2.get_value_x() * p3.get_value_y())
		+ p3.get_value_x() * p1.get_value_y()) / 2;
	temp2 = (p2.get_value_x() * p1.get_value_y()
		+ p3.get_value_x() * p2.get_value_y()
		+ p1.get_value_x() * p3.get_value_y()) / 2;
	area = temp1 - temp2;
	if (area < Fixed(0))
		area = area * -1;
	return (area);
}

/* equation of straight line(when there are 2 points P(px, py), Q(qx, qy))
	: (y - py) = ((qy - py / qx - px)) * (x - px) 
*/
int	line_equation_solved(Point const p, Point const q, Point const point)
{
	Fixed	delta_x = (q.get_value_x() - p.get_value_x());
	Fixed	delta_y = (q.get_value_y() - p.get_value_y());
	if (delta_x != 0)
	{
		Fixed	slope = delta_y / delta_x;

		Fixed	equation_left = point.get_value_y() - p.get_value_y();
		Fixed	equation_right = slope * (point.get_value_x() - p.get_value_x());

		if (equation_left == equation_right)
			return (1);
	}
	return (0);
}

int	check_triangle_edge(Point const a, Point const b, Point const c, Point const point)
{
	if (line_equation_solved(a, b, point) || line_equation_solved(b, c, point)
		|| line_equation_solved(c, b, point))
		return (1);
	return (0);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	area_abc = get_triangle_area(a, b, c);
	Fixed	Point_a_b = get_triangle_area(point, a, b);
	Fixed	Point_b_c = get_triangle_area(point, b, c);
	Fixed	Point_c_a = get_triangle_area(point, c, a);

	if (a == point || b == point || c == point)
	{
		std::cout << "the point is on the vertice of the triangle\t║" << std::endl;
		return (false);
	}
	if (area_abc == (Point_a_b + Point_b_c + Point_c_a))
	{
		if (check_triangle_edge(a, b, c, point))
		{
			std::cout << "the point is on the edge of the triangle\t║" << std::endl;
			return (false);
		}
		std::cout << "the point is inside the triangle\t\t║" << std::endl;
		return (true);
	}
	std::cout << "the point is out of the triangle\t\t║" << std::endl;
	return (false);
}
