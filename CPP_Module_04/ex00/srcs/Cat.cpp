/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 05:35:43 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/16 00:03:38 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat: Default constructor called" << std::endl;
	setType("Cat");
}

Cat::Cat(const Cat &cat): Animal(cat)
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	*this = cat;
}

Cat& Cat::operator=(const Cat &cat)
{
	std::cout << "Cat: Copy assignment called" << std::endl;
	if (this == &cat)
		return (*this);
	Animal::operator=(cat);
	this->_type = cat.getType();
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << RED
		<< "Cat: I am a cat" << BLACK << std::endl;
}
