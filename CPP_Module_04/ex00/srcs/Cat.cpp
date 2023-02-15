/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 05:35:43 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/15 06:37:56 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat:\tconstructor called" << std::endl;
	setType("Cat");
}

Cat::Cat(const Cat &cat): Animal(cat)
{
	std::cout << "Cat:\tCopy constructor called" << std::endl;
	*this = cat;
}

Cat& Cat::operator=(const Cat &cat)
{
	std::cout << "Cat:\tCopy assignment called" << std::endl;
	if (this == &cat)
		return (*this);
	Animal::operator=(cat);
	this->_type = cat.getType();
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat:\tDestructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat:\tI am a cat" << std::endl;
}
