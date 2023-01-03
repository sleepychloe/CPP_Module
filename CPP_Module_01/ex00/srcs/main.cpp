/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 03:55:37 by yhwang            #+#    #+#             */
/*   Updated: 2023/01/03 05:24:43 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}

	/* zombie on the stack */
	Zombie	stackZombie_main = Zombie("stackZombie_main");
	stackZombie_main.announce();
	
	/* zombie on the heap */
	Zombie	*heapZombie_main = newZombie("heapZombie_main");
	heapZombie_main->announce();
	delete heapZombie_main;

	/*
	if you want to allocate zombie on the stack, write zombie name
		starts with lowercase s as a parameter of the function randomChump.
	if you want to allocate zombie on the heap, write zombie name
		starts with lowercase h as a parameter of the function randomChump.
	if a zombie name doesn't start with s nor h,
		the zombie will be allocated on the stack automatically.
	*/
	randomChump("s0");
	randomChump("s1");
	randomChump("h0");
	randomChump("h1");
	randomChump("r");
	return (0);
}
