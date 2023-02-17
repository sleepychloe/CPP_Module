/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:54:58 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/17 21:45:22 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Animal.hpp"
#include "../incs/Dog.hpp"
#include "../incs/Cat.hpp"

#include "../incs/Brain.hpp"
#include <iomanip>

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
	
	/* test 1*/
	{
		std::cout << RED << "[ EX01 TEST 1 ]" << BLACK << std::endl;
		int	n = 10;
		Animal	*animal[n];
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
				animal[i] = new Dog();
			else
				animal[i] = new Cat();
		}
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				std::cout << CYAN << "TYPE: " << animal[i]->getType() << ": ";
				animal[i]->makeSound();
				std::cout << BLACK;
			}
			else
			{
				std::cout << YELLOW << "TYPE: " << animal[i]->getType() << ": ";
				animal[i]->makeSound();
				std::cout << BLACK;
			}
		}
		for (int i = 0; i < n; i++)
			delete animal[i];
	}
	std::cout << std::endl;

	/* test 2 */
	{
		std::cout << RED << "[ EX01 TEST 2 ]" << BLACK << std::endl;
		
		{
			/* dog */
			std::cout << YELLOW << "test 1: dog class:" << BLACK << std::endl;
			Dog	dog_1;
			Dog	dog_2 = dog_1;
			std::cout << "╔═════╦═════════════════╦═══════════════╗" << std::endl;
			std::cout << "║ idx ║ brain: dog_1\t║ brain: dog_2\t║" << std::endl;
			std::cout << "╠═════╬═════════════════╬═══════════════╣" << std::endl;
			for (int i = 0; i < 100; i++)
				std::cout << "║ " << std::setw(3) << i + 1
					<< " ║ " << CYAN << dog_1.get_brain() + i << BLACK
					<< "\t║ " << YELLOW << dog_2.get_brain() + i<< BLACK
					<< "\t║" << std::endl;
			std::cout << "╚═════╩═════════════════╩═══════════════╝" << std::endl;	
		}
		std::cout << std::endl;
		{
			/* cat */
			std::cout << YELLOW << "test 2: cat class:" << BLACK << std::endl;
			Cat	cat_1;
			Cat	cat_2 = cat_1;
			std::cout << "╔═════╦═════════════════╦═══════════════╗" << std::endl;
			std::cout << "║ idx ║ brain: cat_1\t║ brain: cat_2\t║" << std::endl;
			std::cout << "╠═════╬═════════════════╬═══════════════╣" << std::endl;
			for (int i = 0; i < 100; i++)
				std::cout << "║ " << std::setw(3) << i + 1
					<< " ║ " << CYAN << cat_1.get_brain() + i << BLACK
					<< "\t║ " << YELLOW << cat_2.get_brain() + i<< BLACK
					<< "\t║" << std::endl;
			std::cout << "╚═════╩═════════════════╩═══════════════╝" << std::endl;
		}
	}
	return (0);
}
