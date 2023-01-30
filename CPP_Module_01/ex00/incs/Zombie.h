/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:20:41 by yhwang            #+#    #+#             */
/*   Updated: 2023/01/25 09:55:40 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"

#include <string>
#include <iostream>
#include "./Zombie.hpp"

void		randomChump(std::string name);
Zombie		*newZombie(std::string name);
int		main(int argc, char **argv);

#endif
