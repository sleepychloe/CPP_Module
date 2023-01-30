/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:45:47 by yhwang            #+#    #+#             */
/*   Updated: 2023/01/25 09:56:29 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>
#include <sstream>
#include "./Zombie.hpp"

Zombie		*zombieHorde(int N, std::string name);
int		check_int(std::string str);
int		check_alpha(std::string str);
int		main(int argc, char **argv);

#endif
