/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 00:11:39 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/11 00:11:45 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
public:
	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed& fixed);
	Fixed& operator=(const Fixed& fixed);
	~Fixed();

	int		getRawBits(void) const;
	void		setRawBits(int const raw);

	float		toFloat(void) const;
	int		toInt(void) const;

	bool		operator>(const Fixed& fixed) const;
	bool		operator<(const Fixed& fixed) const;
	bool		operator>=(const Fixed& fixed) const;
	bool		operator<=(const Fixed& fixed) const;
	bool		operator==(const Fixed& fixed) const;
	bool		operator!=(const Fixed& fixed) const;

	Fixed		operator+(const Fixed &fixed) const;
	Fixed		operator-(const Fixed &fixed) const;
	Fixed		operator*(const Fixed &fixed) const;
	Fixed		operator/(const Fixed &fixed) const;

	Fixed		operator++(int);	// prefix increment
	Fixed		&operator++(void);	// postfix increment
	Fixed		operator--(int);	// prifix decrement
	Fixed		&operator--(void);	// postfix decrement

	static		Fixed& min(Fixed &l, Fixed &r);
	static const	Fixed& min(const Fixed &l, const Fixed &r);
	static		Fixed& max(Fixed &l, Fixed &r);
	static const	Fixed& max(const Fixed &l, const Fixed &r);
	
private:
	int			_value;
	static const int	_bits = 8;

};

std::ostream&	operator<<(std::ostream &ostream, Fixed const &fixed);

#endif
