/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 05:33:58 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/15 06:38:14 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Animal.hpp"

Animal::Animal(): _type("Animal")
{
	std::cout << "Animal:\tDefault constructor called" << std::endl;
}

Animal::Animal(const Animal& animal)
{
	std::cout << "Animal:\tCopy constructor called" << std::endl;
	*this = animal;
}

Animal& Animal::operator=(const Animal& animal)
{
	std::cout << "Animal:\tCopy assignment operator called" << std::endl;
	if (this == &animal)
		return (*this);
	this->_type = animal.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal:\tDestructor called" << std::endl;
}

void	Animal::setType(std::string type)
{
	_type = type;
}

std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal:\ti am a just animal" << std::endl;
}
