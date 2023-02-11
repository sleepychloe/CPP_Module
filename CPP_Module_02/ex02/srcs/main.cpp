/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:00:02 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/11 00:01:38 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"
/*
int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		std::cout << "Arument error" << std::endl;
		return (1);
	}
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	return (0);
}
*/

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}

	Fixed	n1(3.14f);
	Fixed	n2(2.71f);
	
	std::cout << "╔═════════╦═════════════════════╗" << std::endl;
	std::cout << "║ n1      ║ " << n1 << "\t\t║" << std::endl;
	std::cout << "║ n2      ║ " << n2 << "\t\t║" << std::endl;
	std::cout << "╠═════════╩═════════════════════╣" << std::endl;

	/* test max, min */
	std::cout << "║ " << "Max value is " << Fixed::max(n1, n2) << "\t\t║" << std::endl;
	std::cout << "║ " << "Min value is " << Fixed::min(n1, n2) << "\t\t║" << std::endl;
	std::cout << "╠═════════╦═════════════════════╣" << std::endl;
	
	/* test + */
	Fixed add_1(n1 + n2);
	std::cout << "║ n1 + n2 ║ " << add_1 << "\t\t║" << std::endl;
	
	const Fixed add_1_const(n1 + n2);
	std::cout << "║ n1 + n2 ║ " << add_1_const << "\t\t║" << std::endl;

	Fixed add_2(n2 + n1);
	std::cout << "║ n2 + n1 ║ " << add_2 << "\t\t║" << std::endl;
	
	const Fixed add_2_const(n2 + n1);
	std::cout << "║ n2 + n1 ║ " << add_2_const << "\t\t║" << std::endl;
	std::cout << "╠═════════╩═════════════════════╣" << std::endl;

	/* compare (n1 + n2) and (n2 + n1) */
	Fixed	test_add(add_1 == add_2);
	Fixed	test_add_const(add_1_const == add_2_const);
	Fixed	test_add_compare_1(add_1 <= add_2);
	Fixed	test_add_const_compare_1(add_1_const <= add_2_const);
	Fixed	test_add_compare_2(add_1 >= add_2);
	Fixed	test_add_const_compare_2(add_1_const >= add_2_const);

	if ((test_add == 1 && test_add_const == 1)
		&& (test_add_compare_1 == 1 && test_add_const_compare_1 == 1)
		&& (test_add_compare_2 == 1 && test_add_const_compare_2 == 1))
		std::cout << "║ (n1 + n2) == (n2 + n1)\t║" << std::endl;
	std::cout << "╠═════════╦═════════════════════╣" << std::endl;

	/* test - */
	Fixed sub_1(n1 - n2);
	std::cout << "║ n1 - n2 ║ " << sub_1 << "\t\t║" << std::endl;

	const Fixed sub_1_const(n1 - n2);
	std::cout << "║ n1 - n2 ║ " << sub_1_const << "\t\t║" << std::endl;

	Fixed sub_2(n2 - n1);
	std::cout << "║ n2 - n1 ║ " << sub_2 << "\t\t║" << std::endl;

	const Fixed sub_2_const(n2 - n1);
	std::cout << "║ n2 - n1 ║ " << sub_2_const << "\t\t║" << std::endl;
	std::cout << "╠═════════╩═════════════════════╣" << std::endl;

	/* compare (n1 - n2) and (n2 - n1) */
	Fixed	test_sub(sub_1 != sub_2);
	Fixed	test_sub_const(sub_1_const != sub_2_const);
	Fixed	test_sub_compare_1(sub_1 < sub_2);
	Fixed	test_sub_const_compare_1(sub_1 < sub_2);
	Fixed	test_sub_compare_2(sub_1 > sub_2);
	Fixed	test_sub_const_compare_2(sub_1 > sub_2);

	if (test_sub == 1 && test_sub_const == 1)
		std::cout << "║ (n1 - n2) != (n2 - n1)\t║" << std::endl;
	
	if ((test_sub_compare_1 != test_sub_compare_2)
		&& (test_sub_const_compare_1 != test_sub_const_compare_2))
	{
		if (test_sub_compare_1 == 0)
			std::cout << "║ (n1 - n2) > (n2 - n1)\t\t║" << std::endl;
		else
			std::cout << "║ (n1 - n2) < (n2 - n1)\t\t║" << std::endl;
	}
	std::cout << "╠═════════╦═════════════════════╣" << std::endl;

	/* test * */
	Fixed mul_1(n1 * n2);
	std::cout << "║ n1 * n2 ║ " << mul_1 << "\t\t║" << std::endl;

	const Fixed mul_1_const(n1 * n2);
	std::cout << "║ n1 * n2 ║ " << mul_1_const << "\t\t║" << std::endl;

	Fixed mul_2(n2 * n1);
	std::cout << "║ n2 * n1 ║ " << mul_2 << "\t\t║" << std::endl;

	const Fixed mul_2_const(n2 * n1);
	std::cout << "║ n2 * n1 ║ " << mul_2_const << "\t\t║" << std::endl;
	std::cout << "╠═════════╩═════════════════════╣" << std::endl;

	/* compare (n1 * n2) and (n2 * n1) */
	Fixed	test_mul(mul_1 == mul_2);
	Fixed	test_mul_const(mul_1_const == mul_2_const);
	Fixed	test_mul_compare_1(mul_1 <= mul_2);
	Fixed	test_mul_const_compare_1(mul_1_const <= mul_2_const);
	Fixed	test_mul_compare_2(mul_1 >= mul_2);
	Fixed	test_mul_const_compare_2(mul_1_const >= mul_2_const);

	if ((test_mul == 1 && test_mul_const == 1)
		&& (test_mul_compare_1 == 1 && test_mul_const_compare_1 == 1)
		&& (test_mul_compare_2 == 1 && test_mul_const_compare_2 == 1))
		std::cout << "║ (n1 * n2) == (n2 * n1)\t║" << std::endl;


	if (n1 != (Fixed)0 && n2 != (Fixed)0)
	{
		std::cout << "╠═════════╦═════════════════════╣" << std::endl;

		/* test / */
		Fixed div_1(n1 / n2);
		std::cout << "║ n1 / n2 ║ " << div_1 << "\t\t║" << std::endl;

		const Fixed div_1_const(n1 / n2);
		std::cout << "║ n1 / n2 ║ " << div_1_const << "\t\t║" << std::endl;

		Fixed div_2(n2 / n1);
		std::cout << "║ n2 / n1 ║ " << div_2 << "\t\t║" << std::endl;

		const Fixed div_2_const(n2 / n1);
		std::cout << "║ n2 / n1 ║ " << div_2_const << "\t\t║" << std::endl;
		std::cout << "╠═════════╩═════════════════════╣" << std::endl;

		/* compare (n1 / n2) and (n2 / n1) */
		Fixed	test_div(div_1 != div_2);
		Fixed	test_div_const(div_1_const != div_2_const);
		Fixed	test_div_compare_1(div_1 < div_2);
		Fixed	test_div_const_compare_1(div_1 < div_2);
		Fixed	test_div_compare_2(div_1 > div_2);
		Fixed	test_div_const_compare_2(div_1 > div_2);

		if (test_div == 1 && test_div_const == 1)
			std::cout << "║ (n1 / n2) != (n2 / n1)\t║" << std::endl;
		
		if ((test_div_compare_1 != test_div_compare_2)
			&& (test_div_const_compare_1 != test_div_const_compare_2))
		{
			if (test_div_compare_1 == 0)
				std::cout << "║ (n1 / n2) > (n2 / n1)\t\t║" << std::endl;
			else
				std::cout << "║ (n1 / n2) < (n2 / n1)\t\t║" << std::endl;
		}
	}
	std::cout << "╠═════════╦═════════════════════╣" << std::endl;

	/* test ++, -- */
	Fixed	num1(3.1f);
	Fixed	num2(3.1f);
	Fixed	num3(2.7f);
	Fixed	num4(2.7f);

	std::cout << "║ num1    ║ " << num1 << "\t\t║" << std::endl;
	std::cout << "║ num2    ║ " << num2 << "\t\t║" << std::endl;
	std::cout << "║ num3    ║ " << num3 << "\t\t║" << std::endl;
	std::cout << "║ num4    ║ " << num4 << "\t\t║" << std::endl;
	std::cout << "╠═════════╩═════════════════════╣" << std::endl;

	Fixed	increase_prifix(++num1);
	Fixed	increase_postfix(num2++);
	Fixed	decrease_prifix(--num3);
	Fixed	decrease_postfix(num4--);

	std::cout << "║ ++n1    ║ " << num1 << "\t\t║" << std::endl;
	std::cout << "║ n2++    ║ " << num2 << "\t\t║" << std::endl;
	std::cout << "║ --n3    ║ " << num3 << "\t\t║" << std::endl;
	std::cout << "║ n4--    ║ " << num4 << "\t\t║" << std::endl;
	
	std::cout << "╚═══════════════════════════════╝" << std::endl;
	return (0);
}
