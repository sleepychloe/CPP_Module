/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:55:00 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/16 00:48:23 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog: Default constructor called" << std::endl;
	_brain = new Brain();
	setType("Dog");
}

Dog::Dog(const Dog& dog): Animal(dog)
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	_brain = new Brain();
	*this = dog;
}

Dog& Dog::operator=(const Dog& dog)
{
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	if (this == &dog)
		return (*this);
	Animal::operator=(dog);
	this->_brain = dog._brain;
	this->_type = dog.getType();
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
	delete _brain;
}

void	Dog::makeSound(void) const
{
	std::cout << RED
		<< "Dog: I am a dog" << BLACK << std::endl;
}
