/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:43:32 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/15 02:57:29 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/DiamondTrap.hpp"

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"

DiamondTrap::DiamondTrap(): ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap:\tDefault constructor called" << std::endl;
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "DiamondTrap:\t"
		<< get_name() << " String constructor called" << std::endl;
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap): ClapTrap(diamondtrap), FragTrap(diamondtrap), ScavTrap(diamondtrap)
{
	std::cout << "DiamondTrap:\t"
		<< this->_name << " Copy constructor called" << std::endl;
	this->_name = diamondtrap.get_name();
	this->_hit_points = diamondtrap.get_hit_points();
	this->_energy_points = diamondtrap.get_energy_points();
	this->_attack_damage = diamondtrap.get_attack_damage();
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondtrap)
{
	std::cout << "DiamondTrap:\t"
		<< get_name() << " Copy assignment operator called" << std::endl;
	if (this == &diamondtrap)
		return (*this);
	ClapTrap::operator=(diamondtrap);
	this->_name = diamondtrap.get_name();
	this->_hit_points = diamondtrap.get_hit_points();
	this->_energy_points = diamondtrap.get_energy_points();
	this->_attack_damage = diamondtrap.get_attack_damage();
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap:\t"
		<< get_name() << " Destructor called" << std::endl;
}

void	DiamondTrap::set_name(std::string name)
{
	_name = name;
	ClapTrap::_name = name + "_clap_name";
}

std::string	DiamondTrap::get_name(void) const
{
	return (_name);
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap:\t"
		<< get_name() << " says;" << std::endl
		<< "\tHello, I am diamond trap " << RED << get_name() << BLACK << std::endl
		<< "\tmy parents are scav trap and frag trap." << std::endl
		<< "\tand my grandparent is clap trap named "
		<< RED << ClapTrap::get_name() << BLACK << std::endl;
}
