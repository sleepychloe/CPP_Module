/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:58:52 by yhwang            #+#    #+#             */
/*   Updated: 2023/01/30 09:01:14 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include <string>
#include <iostream>
#include "./Weapon.hpp"

class	HumanB
{
public:
	HumanB();
	HumanB(std::string name);
	void		setWeapon(Weapon &weapon);
	std::string	get_human_name(void);
	std::string	get_weapon_type(void);
	void		attack(void);
	~HumanB();

private:
	std::string	_name;
	Weapon*		_weapon;
};

#endif
