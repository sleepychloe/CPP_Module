/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 05:35:36 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/15 06:38:04 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog:\tConstructor called" << std::endl;
	setType("Dog");
}

Dog::Dog(const Dog& dog): Animal(dog)
{
	std::cout << "Dog:\tCopy constructor called" << std::endl;
	*this = dog;
}

Dog& Dog::operator=(const Dog& dog)
{
	std::cout << "Dog:\tCopy assignment operator called" << std::endl;
	if (this == &dog)
		return (*this);
	Animal::operator=(dog);
	this->_type = dog.getType();
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog:\tDestructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog:\tI am a dog" << std::endl;
}
