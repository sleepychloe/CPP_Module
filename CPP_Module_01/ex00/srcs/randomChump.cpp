/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:56:54 by yhwang            #+#    #+#             */
/*   Updated: 2023/01/25 09:55:58 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.h"

void	randomChump(std::string name)
{
	if (name[0] == 's')
	{
		Zombie	stackZombie = Zombie(name);
		stackZombie.announce();
	}
	else if (name[0] == 'h')
	{
		Zombie	*heapZombie = newZombie(name);
		heapZombie->announce();
		delete heapZombie;
	}
	else
	{
		Zombie	stackZombie = Zombie(name);
		stackZombie.announce();
	}
}
