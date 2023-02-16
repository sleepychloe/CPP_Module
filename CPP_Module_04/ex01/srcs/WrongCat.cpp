/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:54:53 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/16 00:50:58 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "WrongCat: Default constructor called" << std::endl;
	setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &wrongcat): WrongAnimal(wrongcat)
{
	std::cout << "WrongCat: Copy constructor called" << std::endl;
	*this = wrongcat;
}

WrongCat& WrongCat::operator=(const WrongCat &wrongcat)
{
	std::cout << "WrongCat: Copy assignment called" << std::endl;
	if (this == &wrongcat)
		return (*this);
	WrongAnimal::operator=(wrongcat);
	this->_type = wrongcat.getType();
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << RED
		<< "WrongCat: I am a wrong cat" << BLACK << std::endl;
}
