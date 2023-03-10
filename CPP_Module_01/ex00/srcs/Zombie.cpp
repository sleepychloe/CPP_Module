/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:56:35 by yhwang            #+#    #+#             */
/*   Updated: 2023/01/25 09:56:03 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(std::string name)
{
	_name = name;
}

std::string	Zombie::get_zombie_name(void)
{
	return (_name);
}

void	Zombie::announce(void)
{
	std::cout << get_zombie_name()
		<< ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << get_zombie_name() << " is destroyed" << std::endl;
}
