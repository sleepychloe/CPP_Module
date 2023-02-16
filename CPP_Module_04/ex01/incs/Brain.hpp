/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:56:35 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/16 05:10:35 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class	Brain
{
public:
	Brain();
	Brain(const Brain& brain);
	Brain& operator=(const Brain &brain);
	~Brain();

private:
	std::string	_ideas[100];

	void		_set_ideas(std::string ideas);
};

#endif
