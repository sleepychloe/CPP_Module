/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 03:36:40 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/28 02:42:52 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../incs/Array.hpp"

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

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
	
	{
		std::cout << CYAN << "[ test 1 ]" << BLACK << std::endl;

		Array<int>	numbers(MAX_VAL);
		int*		mirror = new int[MAX_VAL];

		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int	value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
	
		int	flag = 0;
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (numbers[i] != mirror[i])
				flag++;
		}

		//SCOPE
		Array<int>	tmp = numbers;
		Array<int>	test(tmp);
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << "tmp[i] = " << YELLOW << tmp[i] << BLACK
				<< ", test[i] = " << YELLOW << test[i] << BLACK << ", ";
			if (numbers[i] == mirror[i] && mirror[i] == tmp[i] && tmp[i] == test[i])
				std::cout << CYAN << "SAME VALUE" << BLACK << std::endl;
			else
			{
				std::cerr << RED
					<< "didn't save the same value!!"
					<< BLACK << std::endl;
				return (1);
			}
		}

		std::cout << std::endl;

		try
		{
			numbers[-2] = 0;
			std::cout << "numbers[2] = " << numbers[-2] << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}

		std::cout << std::endl;

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
			std::cerr << RED << e.what() << BLACK << std::endl;
		}

		std::cout << std::endl;

		try
		{
			numbers[MAX_VAL - 1] = 0;
			std::cout << "numbers[MAX_VAL - 1] = "
				<< YELLOW << numbers[MAX_VAL - 1] << BLACK << std::endl;

			std::cout << "mirror[MAX_VAL - 1] = "
				<< CYAN << mirror[MAX_VAL - 1] << BLACK
				<< ", tmp[MAX_VAL - 1] = "
				<< CYAN << tmp[MAX_VAL - 1] << BLACK
				<< ", test[MAX_VAL - 1] = "
				<< CYAN << test[MAX_VAL - 1] << BLACK << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}

		std::cout << std::endl;

		for (int i = 0; i < MAX_VAL; i++)
			numbers[i] = rand();
		
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << "numbers[i] = "
				<< YELLOW << numbers[i] << BLACK
				<< ", mirror[i] = "
				<< CYAN << mirror[i] << BLACK
				<< ", tmp[i] = "
				<< CYAN << tmp[i] << BLACK
				<< ", test[i] = "
				<< CYAN << test[i] << BLACK << std::endl;
		}

		delete[] mirror;
	}
	
	std::cout << std::endl;

	{
		std::cout << CYAN << "[ test 2 ]" << BLACK << std::endl;
		
		Array<int>	empty;

		if (empty.get_array() == NULL)
			std::cout << RED << "array is empty" << BLACK << std::endl;
	}
	return (0);
}
