/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:57:19 by yhwang            #+#    #+#             */
/*   Updated: 2023/01/25 09:55:35 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
public:
	Zombie();
	Zombie(std::string name);
	std::string	get_zombie_name();
	void		announce(void);
	~Zombie();

private:
	std::string	_name;
};

#endif
