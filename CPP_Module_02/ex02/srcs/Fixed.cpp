/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:59:30 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/09 19:39:40 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"

Fixed::Fixed(): _value(0)
{
}

Fixed::Fixed(const int i)
{
	_value = i << _bits;
}

Fixed::Fixed(const float f)
{
	_value = (int)roundf(f * (1 << _bits));
}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	if (this == &fixed)
		return (*this);
	this->_value = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	float	f;
	f = ((float)(_value )) / (1 << _bits);
	return (f);
}

int	Fixed::toInt(void) const
{
	int	i;

	i = _value >> _bits;
	return (i);
}

bool	Fixed::operator>(const Fixed& fixed) const
{
	if (this->_value > fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& fixed) const
{
	if (this->_value < fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& fixed) const
{
	if (this->_value >= fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& fixed) const
{
	if (this->_value <= fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& fixed) const
{
	if (this->_value == fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& fixed) const
{
	if (this->_value != fixed.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& fixed) const
{
	if (fixed.toFloat() > 0)
		return (Fixed(this->toFloat() / fixed.toFloat()));
	std::cout << "You cannot divided by 0" << std::endl;
	return (-9999);
}

Fixed	Fixed::operator++(int)
{
	Fixed	fixed(*this);
	++*this;
	return (fixed);
}

Fixed&	Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	fixed(*this);
	--*this;
	return (fixed);
}

Fixed&	Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed&	Fixed::min(Fixed &l, Fixed &r)
{
	if (l.getRawBits() < r.getRawBits())
		return (l);
	return (r);
}

const Fixed& Fixed::min(const Fixed &l, const Fixed &r)
{
	if (l.getRawBits() < r.getRawBits())
		return (l);
	return (r);
}

Fixed&	Fixed::max(Fixed &l, Fixed &r)
{
	if (l.getRawBits() > r.getRawBits())
		return (l);
	return (r);
}

const Fixed& Fixed::max(const Fixed &l, const Fixed &r)
{
	if (l.getRawBits() > r.getRawBits())
		return (l);
	return (r);
}

std::ostream	&operator<<(std::ostream &ostream, Fixed const &fixed)
{
	ostream << fixed.toFloat();
	return (ostream);
}
