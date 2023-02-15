/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 05:33:26 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/15 06:05:06 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Animal.hpp"
#include "../incs/Dog.hpp"
#include "../incs/Cat.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	/* error: argument error */
	if (argc != 1)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	return (0);
}