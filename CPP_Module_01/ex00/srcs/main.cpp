/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:55:37 by yhwang            #+#    #+#             */
/*   Updated: 2023/01/25 09:55:48 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.h"

int	main(int argc, char **argv)
{
	(void)argv;
	/* error check: argument */
	if (argc != 1)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}

	/* zombie on the stack */
	Zombie	stackZombie_main = Zombie("stackZombie_main");
	stackZombie_main.announce();
	std::cout << std::endl;

	/* zombie on the heap */
	std::cout << RED;
	Zombie	*heapZombie_main = newZombie("heapZombie_main");
	heapZombie_main->announce();
	delete heapZombie_main;
	std::cout << BLACK << std::endl;

	/*
	if you want to allocate zombie on the stack, write zombie name
		starts with lowercase s as a parameter of the function randomChump.
	if you want to allocate zombie on the heap, write zombie name
		starts with lowercase h as a parameter of the function randomChump.
	if a zombie name doesn't start with s nor h,
		the zombie will be allocated on the stack automatically.
	*/
	/* stack */
	randomChump("s0");
	std::cout << std::endl;

	/* stack */
	randomChump("s1");
	std::cout << std::endl;

	/* heap */
	std::cout << RED;
	randomChump("h0");
	std::cout << BLACK << std::endl;

	/* heap */
	std::cout << RED;
	randomChump("h1");
	std::cout << BLACK << std::endl;

	/* stack */
	randomChump("r");
	std::cout << std::endl;

	return (0);
}
