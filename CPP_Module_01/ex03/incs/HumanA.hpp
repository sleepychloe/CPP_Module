/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:58:48 by yhwang            #+#    #+#             */
/*   Updated: 2023/01/30 08:46:14 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include <string>
#include <iostream>
#include "./Weapon.hpp"

class	HumanA
{
public:
	HumanA(Weapon& weapon);
	HumanA(std::string name, Weapon& weapon);
	std::string	get_human_name(void);
	std::string	get_weapon_type(void);
	void		attack(void);
	~HumanA();

private:
	std::string	_name;
	Weapon&		_weapon;
};

#endif
