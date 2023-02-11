/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:06:23 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/09 06:24:37 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#define RED	"\x1b[31m"
#define BLACK	"\x1b[0m"

#include <iostream>
#include <string>

class Harl
{
public:
	Harl();
	void	complain(std::string level);
	~Harl();

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	int	get_harl_level(std::string level);
};

#endif
