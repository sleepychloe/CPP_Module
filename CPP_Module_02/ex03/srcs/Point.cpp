/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 00:12:17 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/11 01:49:39 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Point.hpp"
#include "../incs/Fixed.hpp"

Point::Point(): _x(0), _y(0)
{	
}

Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point(const Point& point): _x(point.get_value_x()), _y(point.get_value_y())
{
	*this = point;
}

Point& Point::operator=(const Point& point)
{
	if (this == &point)
		return (*this);
	(Fixed)this->_x = point.get_value_x();
	(Fixed)this->_y = point.get_value_y();
	return (*this);
}

Point::~Point()
{
}

Fixed	Point::get_value_x(void) const
{
	return (_x);
}

Fixed	Point::get_value_y(void) const
{
	return (_y);
}

bool	Point::operator==(const Point& point) const
{
	if (this->_x == point.get_value_x()
		&& this->_y == point.get_value_y())
		return (true);
	return (false);
}
