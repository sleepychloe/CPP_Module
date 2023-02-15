/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:43:43 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/15 00:17:24 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap:\tDefault constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap:\t"
		<< get_name() << " String constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& fragtrap): ClapTrap(fragtrap)
{
	std::cout << "FragTrap:\t"
		<< get_name() << " Copy constructor called" << std::endl;
	this->_name = fragtrap.get_name();
	this->_hit_points = fragtrap.get_hit_points();
	this->_energy_points = fragtrap.get_energy_points();
	this->_attack_damage = fragtrap.get_attack_damage();
}

FragTrap& FragTrap::operator=(const FragTrap& fragtrap)
{
	std::cout << "FragTrap:\t"
		<< get_name() << " Copy assignment operator called" << std::endl;
	if (this == &fragtrap)
		return (*this);
	this->_name = fragtrap.get_name();
	this->_hit_points = fragtrap.get_hit_points();
	this->_energy_points = fragtrap.get_energy_points();
	this->_attack_damage = fragtrap.get_attack_damage();
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap:\t"
		<< get_name() << " Destructor called" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (_energy_points >= 10 && _hit_points)
	{
		std::cout << "FragTrap:\t" << get_name()
			<< " attacks " << target << ", causing "
			<< get_attack_damage() << " points of damage!" << std::endl;
		_energy_points -= 10;
	}
	else if (!(_energy_points >= 10))
		std::cout << "FragTrap:\t" << get_name() << " cannot attack " << target
			<< "(not enough energy points)" << std::endl;
	else
		std::cout << "FragTrap:\t" << get_name() << " cannot attack " << target
			<< "(not enough hit points)" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap:\t"
		<< get_name() << " wants to request you to high fives with him !" << std::endl;
}
