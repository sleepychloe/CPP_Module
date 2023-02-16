/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 05:33:26 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/15 22:48:43 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Animal.hpp"
#include "../incs/Dog.hpp"
#include "../incs/Cat.hpp"
#include "../incs/WrongAnimal.hpp"
#include "../incs/WrongCat.hpp"

# define BLACK			"\x1b[0m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

int	main(int argc, char **argv)
{
	(void)argv;
	/* error: argument error */
	if (argc != 1)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}

	/* test: Animal */
	{
		std::cout << "══════════════════════════════════════════════════════════" << std::endl;
		std::cout << CYAN <<"[ ANIMAL TEST 1] " << BLACK << std::endl;
		std::cout << "══════════════════════════════════════════════════════════" << std::endl;

		/* animal sound will be printed */
		const Animal* animal = new Animal();
		std::cout << YELLOW << "TYPE: " << animal->getType() << BLACK << ": ";
		animal->makeSound();
		delete animal;

		std::cout << std::endl;

		/* dog sound will be printed */
		const Animal* dog = new Dog();
		std::cout << YELLOW << "TYPE: " << dog->getType() << BLACK << ": ";
		dog->makeSound();
		delete dog;

		std::cout << std::endl;

		/* cat sound will be printed */
		const Animal* cat = new Cat();
		std::cout << YELLOW << "TYPE: " << cat->getType() << BLACK << ": ";
		cat->makeSound();
		delete cat;

		std::cout << std::endl;
	}

	{
		std::cout << "══════════════════════════════════════════════════════════" << std::endl;
		std::cout << CYAN <<"[ ANIMAL TEST 2] " << BLACK << std::endl;
		std::cout << "══════════════════════════════════════════════════════════" << std::endl;

		/* animal sound will be printed */
		Animal a;
		std::cout << YELLOW << "TYPE: " << a.getType() << BLACK << ": ";
		a.makeSound();

		std::cout << std::endl;

		/* dog sound will be printed */
		Dog d;
		std::cout << YELLOW << "TYPE: " << d.getType() << BLACK << ": ";
		d.makeSound();

		std::cout << std::endl;

		/* cat sound will be printed */
		Cat c;
		std::cout << YELLOW << "TYPE: " << c.getType() << BLACK << ": ";
		c.makeSound();

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
		test_dog->makeSound();

		std::cout << std::endl;
		
		/* cat sound will be printed */
		Cat c;
		Cat *test_cat = &c;
		std::cout << YELLOW << "TYPE: " << test_cat->getType() << BLACK << ": ";
		test_cat->makeSound();

		std::cout << std::endl;
	}

	std::cout << std::endl;
	
	/* test: WrongAnimal */
	{
		std::cout << "══════════════════════════════════════════════════════════" << std::endl;
		std::cout << CYAN << "[ WRONG ANIMAL TEST 1 ]" << BLACK << std::endl;
		std::cout << "══════════════════════════════════════════════════════════" << std::endl;

		/* wrong animal sound will be printed */
		const WrongAnimal* wrong_animal  = new WrongAnimal();
		std::cout << YELLOW << "TYPE: " << wrong_animal->getType() << BLACK << ": ";
		wrong_animal->makeSound();
		delete wrong_animal;

		std::cout << std::endl;

		/* wrong animal sound will be printed */
		const WrongAnimal* wrong_cat = new WrongCat();
		std::cout << YELLOW << "TYPE: " << wrong_cat->getType() << BLACK << ": ";
		wrong_cat->makeSound();
		delete wrong_cat;

		std::cout << std::endl;
	}

	{
		std::cout << "══════════════════════════════════════════════════════════" << std::endl;
		std::cout << CYAN <<"[ WRONG ANIMAL TEST 2] " << BLACK << std::endl;
		std::cout << "══════════════════════════════════════════════════════════" << std::endl;

		/* wrong animal sound will be printed */
		WrongAnimal w_a;
		std::cout << YELLOW << "TYPE: " << w_a.getType() << BLACK << ": ";
		w_a.makeSound();
		
		std::cout << std::endl;

		/* wrong cat sound will be printed */
		WrongCat w_c;
		std::cout << YELLOW << "TYPE: " << w_c.getType() << BLACK << ": ";
		w_c.makeSound();

		std::cout << std::endl;

	}

	{
		std::cout << "══════════════════════════════════════════════════════════" << std::endl;
		std::cout << CYAN <<"[ WRONG ANIMAL TEST 3] " << BLACK << std::endl;
		std::cout << "══════════════════════════════════════════════════════════" << std::endl;
	
		/* wrong cat sound will be printed */
		WrongCat w_c;
		WrongCat *test_wrong_cat = &w_c;
		std::cout << YELLOW << "TYPE: " << test_wrong_cat->getType() << BLACK << ": ";
		test_wrong_cat->makeSound();

		std::cout << std::endl;

		/* wrong animal sound will be printed */
		WrongAnimal *a = &w_c;
		std::cout << YELLOW << "TYPE: " << a->getType() << BLACK << ": ";
		a->makeSound();

		std::cout << std::endl;
	}

	return (0);
}
