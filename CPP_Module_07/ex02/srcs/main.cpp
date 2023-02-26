/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 03:36:40 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/26 05:52:42 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../incs/Array.hpp"

#define MAX_VAL 750
int	main(int argc, char**argv)
{
	(void)argv;
	/* error check: argument */
	if (argc != 1)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}

	Array<int>	numbers(MAX_VAL);
	int*		mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int	value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << "numbers[i] = " << numbers[i] << ", mirror[i] = " << mirror[i]
			<< ", ";
		if (numbers[i] == mirror[i])
			std::cout << "SAME VALUE" << std::endl;
	}

	//SCOPE
	Array<int>	tmp = numbers;
	Array<int>	test(tmp);
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << "tmp[i] = " << tmp[i] << ", test[i] = " << test[i]
			<< ", ";
		if (numbers[i] == mirror[i] && mirror[i] == tmp[i] && tmp[i] == test[i])
			std::cout << "SAME VALUE" << std::endl;
		else
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return (1);
		}
	}

	try
	{
		numbers[-2] = 0;
		std::cout << "numbers[2] = " << numbers[-2] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		numbers[MAX_VAL] = 0;
		std::cout << "numbers[MAX_VAL] = " << numbers[MAX_VAL] << std::endl;
		std::cout << "mirror[MAX_VAL] = " << mirror[MAX_VAL]
			<< ", tmp[MAX_VAL] = " << tmp[MAX_VAL]
			<< ", test[MAX_VAL] = " << test[MAX_VAL] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		numbers[MAX_VAL - 1] = 0;
		std::cout << "numbers[MAX_VAL - 1] = " << numbers[MAX_VAL - 1] << std::endl;
		std::cout << "mirror[MAX_VAL - 1] = " << mirror[MAX_VAL - 1]
			<< ", tmp[MAX_VAL - 1] = " << tmp[MAX_VAL - 1]
			<< ", test[MAX_VAL - 1] = " << test[MAX_VAL - 1] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
		numbers[i] = rand();
	
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << "numbers[i] = " << numbers[i]
			<< ", mirror[i] = " << mirror[i]
			<< ", tmp[i] = " << tmp[i]
			<< ", test[i] = " << test[i] << std::endl;
	}

	delete[] mirror;

	return (0);
}
