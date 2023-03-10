/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:41:35 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/14 21:41:44 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <string>
#include <iostream>

class	ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& claptrap);
	ClapTrap& operator=(const ClapTrap& claptrap);
	~ClapTrap();

	void		set_name(std::string name);
	std::string	get_name(void) const;
	int		get_hit_points(void) const;
	int		get_energy_points(void) const;
	int		get_attack_damage(void) const;

	void		attack(const std::string &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	
protected:
	std::string	_name;
	int		_hit_points;
	int		_energy_points;
	int		_attack_damage;

};

#endif
