/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 06:33:38 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/09 19:07:52 by yhwang           ###   ########.fr       */
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
	
private:
	int			_value;
	static const int	_bits = 8;

};

std::ostream&	operator<<(std::ostream &ostream, Fixed const &fixed);

#endif
