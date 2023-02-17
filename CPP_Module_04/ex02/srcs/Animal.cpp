/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:54:01 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/17 00:30:59 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Animal.hpp"

Animal::Animal(): _type("Animal")
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(const Animal& animal)
{
	std::cout << "Animal: Copy constructor called" << std::endl;
	*this = animal;
}

Animal& Animal::operator=(const Animal& animal)
{
	std::cout << "Animal: Copy assignment operator called" << std::endl;
	if (this == &animal)
		return (*this);
	this->_type = animal.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor called" << std::endl;
}

void	Animal::setType(std::string type)
{
	_type = type;
}

std::string	Animal::getType(void) const
{
	return (_type);
}

// void	Animal::makeSound(void) const
// {
// 	std::cout << "Animal: i am a just animal" << std::endl;
// }
