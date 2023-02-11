/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 00:12:30 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/11 01:17:52 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "../incs/Fixed.hpp"

class	Point
{
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& point);
	Point& operator=(const Point& point);
	~Point();

	Fixed	get_value_x(void) const;
	Fixed	get_value_y(void) const;

	bool	operator==(const Point& point) const;

private:
	const Fixed	_x;
	const Fixed	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
