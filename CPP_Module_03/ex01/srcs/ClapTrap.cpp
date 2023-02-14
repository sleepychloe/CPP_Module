/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:55:01 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/14 18:07:47 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

ClapTrap::ClapTrap(): _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap: Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name),
			_hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap: "
		<< get_name() << " String constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
{
	std::cout << "ClapTrap: "
		<< get_name() << " Copy constructor called" << std::endl;
	*this = claptrap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap)
{
	std::cout << "ClapTrap: "
		<< get_name() << " Copy assignment operator called" << std::endl;
	if (this == &claptrap)
		return (*this);
	this->_name = claptrap.get_name();
	this->_hit_points = claptrap.get_hit_points();
	this->_energy_points = claptrap.get_energy_points();
	this->_attack_damage = claptrap.get_attack_damage();
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: "
		<< get_name() << " Destructor called" << std::endl;
}

void	ClapTrap::set_name(std::string name)
{
	_name = name;
}

std::string	ClapTrap::get_name(void) const
{
	return (_name);
}

int	ClapTrap::get_hit_points(void) const
{
	return (_hit_points);
}

int	ClapTrap::get_energy_points(void) const
{
	return (_energy_points);
}

int	ClapTrap::get_attack_damage(void) const
{
	return (_attack_damage);
}

void	ClapTrap::attack(const std::string &target)
{
	if (_energy_points && _hit_points)
	{
		std::cout << "ClapTrap: " << get_name()
			<< " attacks " << target << ", causing "
			<< get_attack_damage() << " points of damage!" << std::endl;
		_energy_points--;
	}
	else if (!(_energy_points))
		std::cout << "ClapTrap: " << get_name() << " cannot attack" << target
			<< "(no energy points)" << std::endl;
	else
		std::cout << "ClapTrap: " << get_name() << " cannot attack" << target
			<< "(no hit points)" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap: " << get_name() << " takes "
		<< amount << " points of damage" << std::endl;
	_hit_points -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points && _hit_points)
	{
		std::cout << "ClapTrap: " << get_name() << " repaired " << amount
			<< " points of hit points" << std::endl;
		_hit_points += amount;
		_energy_points--;
	}
	else if (!(_energy_points))
		std::cout << "ClapTrap: " << get_name() << " cannot be repaired"
			<< "(no energy points)" << std::endl;
	else
		std::cout << "ClapTrap: " << get_name() << " cannot be repaired"
			<< "(no hit points)" << std::endl;
}
