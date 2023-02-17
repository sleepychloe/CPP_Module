/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:55:28 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/16 23:55:41 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: Default constructor called" << std::endl;
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
