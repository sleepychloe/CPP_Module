/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:58:45 by yhwang            #+#    #+#             */
/*   Updated: 2023/01/30 10:00:52 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/HumanB.hpp"

HumanB::HumanB()
{
}

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

std::string	HumanB::get_human_name(void)
{
	return (_name);
}

std::string	HumanB::get_weapon_type(void)
{
	return (_weapon->getType());
}

void	HumanB::attack(void)
{
	std::cout << get_human_name() << " attacks with their "
		<< get_weapon_type() << std::endl;
}

HumanB::~HumanB()
{
}
