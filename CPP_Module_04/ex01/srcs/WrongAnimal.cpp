/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:54:55 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/15 23:55:39 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("WrongAnimal")
{
	std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wronganimal)
{
	std::cout << "WrongAnimal: Copy constructor called" << std::endl;
	*this = wronganimal;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wronganimal)
{
	std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;
	if (this == &wronganimal)
		return (*this);
	this->_type = wronganimal.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor called" << std::endl;
}

void	WrongAnimal::setType(std::string type)
{
	_type = type;
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << RED
		<< "WrongAnimal: i am a wrong animal" << BLACK << std::endl;
}
