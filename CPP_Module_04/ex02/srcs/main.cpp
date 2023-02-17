/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:54:46 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/17 00:38:01 by yhwang           ###   ########.fr       */
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

	{
		/* ex00: test: Animal */
		{
			std::cout << "══════════════════════════════════════════════════════════" << std::endl;
			std::cout << CYAN <<"[ ANIMAL TEST 1] " << BLACK << std::endl;
			std::cout << "══════════════════════════════════════════════════════════" << std::endl;

			/* it doesn't make sense that make animal object */
			// const Animal* animal = new Animal();
			// std::cout << YELLOW << "TYPE: " << animal->getType() << BLACK << ": ";
			// std::cout << RED;
			// animal->makeSound();
			// std::cout << BLACK;
			// delete animal;

			// std::cout << std::endl;

			/* dog sound will be printed */
			const Animal* dog = new Dog();
			std::cout << YELLOW << "TYPE: " << dog->getType() << BLACK << ": ";
			std::cout << RED;
			dog->makeSound();
			std::cout << BLACK;
			delete dog;

			std::cout << std::endl;

			/* cat sound will be printed */
			const Animal* cat = new Cat();
			std::cout << YELLOW << "TYPE: " << cat->getType() << BLACK << ": ";
			std::cout << RED;
			cat->makeSound();
			std::cout << BLACK;
			delete cat;

			std::cout << std::endl;
		}

		{
			std::cout << "══════════════════════════════════════════════════════════" << std::endl;
			std::cout << CYAN <<"[ ANIMAL TEST 2] " << BLACK << std::endl;
			std::cout << "══════════════════════════════════════════════════════════" << std::endl;

			/* it doesn't make sense that make animal object */
			// Animal a;
			// std::cout << YELLOW << "TYPE: " << a.getType() << BLACK << ": ";
			// std::cout << RED;
			// a.makeSound();
			// std::cout << BLACK;

			// std::cout << std::endl;

			/* dog sound will be printed */
			Dog d;
			std::cout << YELLOW << "TYPE: " << d.getType() << BLACK << ": ";
			std::cout << RED;
			d.makeSound();
			std::cout << BLACK;

			std::cout << std::endl;

			/* cat sound will be printed */
			Cat c;
			std::cout << YELLOW << "TYPE: " << c.getType() << BLACK << ": ";
			std::cout << RED;
			c.makeSound();
			std::cout << BLACK;

			std::cout << std::endl;
		}

		{
			std::cout << "══════════════════════════════════════════════════════════" << std::endl;
			std::cout << CYAN <<"[ ANIMAL TEST 3] " << BLACK << std::endl;
			std::cout << "══════════════════════════════════════════════════════════" << std::endl;
			
			/* dog sound will be printed */
			Dog d;
			Dog *test_dog = &d;
			std::cout << YELLOW << "TYPE: " << test_dog->getType() << BLACK << ": ";
			std::cout << RED;
			test_dog->makeSound();
			std::cout << BLACK;

			std::cout << std::endl;
			
			/* cat sound will be printed */
			Cat c;
			Cat *test_cat = &c;
			std::cout << YELLOW << "TYPE: " << test_cat->getType() << BLACK << ": ";
			std::cout << RED;
			test_cat->makeSound();
			std::cout << BLACK;

			std::cout << std::endl;
		}

	std::cout << std::endl;
	}
	
	/* ex01: test 1*/
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

	/* ex01: test 2 */
	{
		std::cout << RED << "[ EX01 TEST 2 ]" << BLACK << std::endl;
		
		{
			/* dog */
			std::cout << YELLOW << "test 1: dog class:" << BLACK << std::endl;
			Dog	dog_1;
			Dog	dog_2 = dog_1;
			std::cout << "╔═════╦════════════════╦════════════════╗" << std::endl;
			std::cout << "║ idx ║ brain: dog_1   ║ brain: dog_2   ║" << std::endl;
			std::cout << "╠═════╬════════════════╬════════════════╣" << std::endl;
			for (int i = 0; i < 100; i++)
				std::cout << "║ " << std::setw(3) << i + 1
					<< " ║ " << CYAN << dog_1.get_brain() + i << BLACK
					<< " ║ " << YELLOW << dog_2.get_brain() + i<< BLACK
					<< " ║" << std::endl;
			std::cout << "╚═════╩════════════════╩════════════════╝" << std::endl;	
		}
		std::cout << std::endl;
		{
			/* cat */
			std::cout << YELLOW << "test 2: cat class:" << BLACK << std::endl;
			Cat	cat_1;
			Cat	cat_2 = cat_1;
			std::cout << "╔═════╦════════════════╦════════════════╗" << std::endl;
			std::cout << "║ idx ║ brain: cat_1   ║ brain: cat_2   ║" << std::endl;
			std::cout << "╠═════╬════════════════╬════════════════╣" << std::endl;
			for (int i = 0; i < 100; i++)
				std::cout << "║ " << std::setw(3) << i + 1
					<< " ║ " << CYAN << cat_1.get_brain() + i << BLACK
					<< " ║ " << YELLOW << cat_2.get_brain() + i<< BLACK
					<< " ║" << std::endl;
			std::cout << "╚═════╩════════════════╩════════════════╝" << std::endl;
		}
	}
	return (0);
}
