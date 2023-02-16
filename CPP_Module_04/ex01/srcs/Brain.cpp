/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:56:29 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/16 05:10:56 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: Default constructor called" << std::endl;
	_set_ideas("BRAIN BRAIN");
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Brain: Copy constructor called" << std::endl;
	*this = brain;
}

Brain& Brain::operator=(const Brain& brain)
{
	std::cout << "Brain: Copy assignment operator called" << std::endl;
	if (this == &brain)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = brain._ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor called" << std::endl;
}

void	Brain::_set_ideas(std::string ideas)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = ideas += ((char)i + 49);
}
