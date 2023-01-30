/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:58:56 by yhwang            #+#    #+#             */
/*   Updated: 2023/01/30 09:02:49 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Weapon.hpp"
#include "../incs/HumanA.hpp"
#include "../incs/HumanB.hpp"



int	main(int argc, char **argv)
{
	(void)argv;
	/* error check: argument */
	if (argc != 1)
		return (1);

	{
	/* HumanA */
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	}

	{
	/* HumanB */
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);	// need to make method setWeapon for HumanB class
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	}
	return (0);
}
