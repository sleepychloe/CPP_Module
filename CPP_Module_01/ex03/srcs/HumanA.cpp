/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:58:54 by yhwang            #+#    #+#             */
/*   Updated: 2023/01/30 08:46:25 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/HumanA.hpp"

HumanA::HumanA(Weapon& weapon) : _weapon(weapon)
{
}

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
}

std::string	HumanA::get_human_name(void)
{
	return (_name);
}

std::string	HumanA::get_weapon_type(void)
{
	return (_weapon.getType());
}

void	HumanA::attack(void)
{
	std::cout << get_human_name() << " attacks with their "
		<< get_weapon_type() << std::endl;
}

HumanA::~HumanA()
{
}
