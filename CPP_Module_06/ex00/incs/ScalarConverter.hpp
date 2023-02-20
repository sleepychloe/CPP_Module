/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 05:47:57 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/20 16:45:27 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cfloat>
#include <stdexcept>

class	ScalarConverter
{
public:
	ScalarConverter(std::string str);
	ScalarConverter(const ScalarConverter& scalarconverter);
	ScalarConverter& operator=(const ScalarConverter& scalarconverter);
	~ScalarConverter();

	class	ImpossibleException: public std::exception
	{
	public:
		virtual const char*	what(void) const throw();
	};

	class	NonDisplyableException: public std::exception
	{
	public:
		virtual const char*	what(void) const throw();
	};

	class	OutOfRangeException: public std::exception
	{
	public:
		virtual const char*	what(void) const throw();
	};

	void			convert(void);

private:
	std::string		_original_str;
	char			_char;
	int			_int;
	float			_float;
	double			_double;
	std::string		_char_str;
	std::string		_int_str;
	std::string		_float_str;
	std::string		_double_str;

	void			parse(void);

	int			check_ascii_range(std::string str, int n1, int n2);
	int			check_ascii_range(std::string str, int n1, int n2, char c);
	int			check_char_valid(std::string str);
	void			check_char(std::string str);
	int			check_int_str(std::string str);
	int			check_int_zero(std::string str);
	void			check_int(std::string str);
	int			check_float_double_str(std::string str);
	void			check_float_double(std::string str);
	int			is_special(std::string str);
	void			check_special(std::string str);

};

#endif
