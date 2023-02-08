/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_line.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:30:07 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/06 14:44:19 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/replace.h"

std::string	replace_line(std::string line, std::string s1, std::string s2)
{
	std::string	new_line = "";
	int		pos = 0;
	int		find = 0;

	while (1)
	{
		find = line.find(s1, pos);
		if (find == -1)
		{
			new_line += line.substr(pos, std::string::npos);
			break ;
		}
		new_line += line.substr(pos, find - pos);
		new_line += s2;
		pos += (find - pos + s1.length());
	}
	return (new_line);
}
