/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 01:18:21 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/26 05:12:23 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../incs/whatever.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	/* error check: argument error */
	if (argc != 1)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}

	/* test 1: int */
	int	a = 2;
	int	b = 3;
	std::cout  << "[ before swapping ] " << "a = " << a << ", b = " << b << std::endl;
	swap( a, b );
	std::cout <<  "[ after swapping  ] " << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << min( a, b ) << std::endl;
	std::cout << "max(a, b) = " << max( a, b ) << std::endl;
	std::cout << std::endl;

	/* test 2: double */
	double	c = 0.2;
	double	d = 0.3;
	std::cout  << "[ before swapping ] " << "c = " << c << ", d = " << d << std::endl;
	swap( c, d );
	std::cout <<  "[ after swapping  ] " << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << min( c, d ) << std::endl;
	std::cout << "max(c, d) = " << max( c, d ) << std::endl;
	std::cout << std::endl;

	/* test 3: float */
	float	e = 1.2f;
	float	f = 2.3f;
	std::cout  << "[ before swapping ] " << "e = " << e << ", f = " << f << std::endl;
	swap( e, f );
	std::cout <<  "[ after swapping  ] " << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) = " << min( e, f ) << std::endl;
	std::cout << "max(e, f) = " << max( e, f ) << std::endl;
	std::cout << std::endl;

	/* test 4: char */
	char	g = 'A';
	char	h = 'B';
	std::cout  << "[ before swapping ] " << "g = " << g << ", h = " << h << std::endl;
	swap( g, h );
	std::cout <<  "[ after swapping  ] " << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min(g, h) = " << min( g, h ) << std::endl;
	std::cout << "max(g, h) = " << max( g, h ) << std::endl;
	std::cout << std::endl;

	/* test 4: string */
	std::string	i = "string1";
	std::string	j = "string2";
	std::cout  << "[ before swapping ] " << "i = " << i << ", j = " << j << std::endl;
	swap( i, j );
	std::cout <<  "[ after swapping  ] " << "i = " << i << ", j = " << j << std::endl;
	std::cout << "min(i, j) = " << min( i, j ) << std::endl;
	std::cout << "max(i, j) = " << max( i, j ) << std::endl;

	return (0);
}
