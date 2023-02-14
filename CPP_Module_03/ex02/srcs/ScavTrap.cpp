/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:27:33 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/14 20:11:22 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.hpp"

ScavTrap::ScavTrap(): _gate_keeper(false)
{
	std::cout << "ScavTrap: Default constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name), _gate_keeper(false)
{
	std::cout << "ScavTrap: "
		<< get_name() << " String constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap): ClapTrap(scavtrap)
{
	std::cout << "ScavTrap: "
		<< get_name() << " Copy constructor called" << std::endl;
	this->_name = scavtrap.get_name();
	this->_hit_points = scavtrap.get_hit_points();
	this->_energy_points = scavtrap.get_energy_points();
	this->_attack_damage = scavtrap.get_attack_damage();
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavtrap)
{
	std::cout << "ScavTrap: "
		<< get_name() << " Copy assignment operator called" << std::endl;
	if (this == &scavtrap)
		return (*this);
	this->_name = scavtrap.get_name();
	this->_hit_points = scavtrap.get_hit_points();
	this->_energy_points = scavtrap.get_energy_points();
	this->_attack_damage = scavtrap.get_attack_damage();
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: "
		<< get_name() << " Destructor called" << std::endl;
}

bool	ScavTrap::get_gate_keeper(void)
{
	return(_gate_keeper);
}

void	ScavTrap::attack(const std::string &target)
{
	if (_energy_points >= 5 && _hit_points)
	{
		std::cout << "ScavTrap: " << get_name()
			<< " attacks " << target << ", causing "
			<< get_attack_damage() << " points of damage!" << std::endl;
		_energy_points -= 5;
	}
	else if (!(_energy_points >= 5))
		std::cout << "ScavTrap: " << get_name() << " cannot attack" << target
			<< "(not enough energy points)" << std::endl;
	else
		std::cout << "ScavTrap: " << get_name() << " cannot attack" << target
			<< "(not enough hit points)" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (get_gate_keeper() == false)
	{
		std::cout << "ScavTrap: " << get_name()
			<< " is in gate keeper mode" << std::endl;
		_gate_keeper = true;
		
	}
	else
		std::cout << "ScavTrap: " << get_name()
			<< " is already in gate keeper mode" << std::endl;
}
