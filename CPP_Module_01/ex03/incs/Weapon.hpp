/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:58:59 by yhwang            #+#    #+#             */
/*   Updated: 2023/01/30 07:53:36 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class	Weapon
{
public:
	Weapon();
	Weapon(std::string type);
	const std::string&	getType(void);
	void			setType(std::string type);
	~Weapon();

private:
	std::string	_type;
};

#endif
