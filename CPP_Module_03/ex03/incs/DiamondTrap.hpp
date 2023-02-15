/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:43:29 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/15 02:33:54 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

#include <iostream>
#include <string>
#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

class	DiamondTrap: public FragTrap, public ScavTrap
{
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& diamondtrap);
	DiamondTrap& operator=(const DiamondTrap& diamondtrap);
	~DiamondTrap();

	void			set_name(const std::string name);
	std::string		get_name(void) const;
	void			attack(const std::string &target);
	void			whoAmI(void);
	
private:
	std::string	_name;
};

#endif
