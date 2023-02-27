/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 07:04:49 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/27 07:48:30 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "../incs/easyfind.hpp"

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

int	main(int argc, char **argv)
{
	(void)argv;
	/* error check: argument */
	if (argc != 1)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}

	{
		std::cout << CYAN << "[ test 1: vector ]" << BLACK << std::endl;
		
		std::vector<int>	vector;
		vector.push_back(100);
		vector.push_back(200);
		vector.push_back(300);
		vector.push_back(100);
		vector.insert(vector.begin(), 400);
		
		std::cout << YELLOW << "vector: ";
		for (std::vector<int> ::iterator iter = vector.begin();
			iter != vector.end(); iter++)
			std::cout << *iter << ' ';
		std::cout << BLACK << std::endl;

		try
		{
			std::cout << "position of first 100: "
				<< std::distance(vector.begin(), easyfind(vector, 100))
				<< std::endl;

		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}
		try
		{
			std::cout << "position of first 200: "
				<< std::distance(vector.begin(), easyfind(vector, 200))
				<< std::endl;

		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}
		try
		{
			std::cout << "position of first 300: "
				<< std::distance(vector.begin(), easyfind(vector, 300))
				<< std::endl;

		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}
		try
		{
			std::cout << "position of first 400: "
				<< std::distance(vector.begin(), easyfind(vector, 400))
				<< std::endl;

		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}
		try
		{
			std::cout << "position of first 700: "
				<< std::distance(vector.begin(), easyfind(vector, 700))
				<< std::endl;

		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}
	}
	std::cout << std::endl;
	
	{
		std::cout << CYAN << "[ test 2: list ]" << BLACK << std::endl;
		
		std::list<int>	list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.push_back(1);
		list.push_back(4);
		list.push_front(7);
		list.push_back(2);

		std::cout << YELLOW << "list: ";
		for (std::list<int> ::iterator iter = list.begin();
			iter != list.end(); iter++)
			std::cout << *iter << ' ';
		std::cout << BLACK << std::endl;

		try
		{
			std::cout << "position of first 1: "
				<< std::distance(list.begin(), easyfind(list, 1))
				<< std::endl;

		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}
		try
		{
			std::cout << "position of first 2: "
				<< std::distance(list.begin(), easyfind(list, 2))
				<< std::endl;

		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}
		try
		{
			std::cout << "position of first 3: "
				<< std::distance(list.begin(), easyfind(list, 3))
				<< std::endl;

		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}
		try
		{
			std::cout << "position of first 4: "
				<< std::distance(list.begin(), easyfind(list, 4))
				<< std::endl;

		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}
		try
		{
			std::cout << "position of first 7: "
				<< std::distance(list.begin(), easyfind(list, 7))
				<< std::endl;

		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}
		try
		{
			std::cout << "position of first 5: "
				<< std::distance(list.begin(), easyfind(list, 5))
				<< std::endl;

		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}
	}
	
	return (0);
}
