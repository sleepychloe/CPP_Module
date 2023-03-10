/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:48:54 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/06 12:42:18 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_H
# define REPLACE_H

#include <iostream>
#include <fstream>
#include <string>

int		main(int argc, char **argv);
std::string     replace_line(std::string line, std::string s1, std::string s2);

#endif
