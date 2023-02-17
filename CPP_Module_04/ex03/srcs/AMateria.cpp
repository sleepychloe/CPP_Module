/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:15:27 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/17 21:35:21 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const &type): _type(type)
{
}

AMateria::AMateria(const AMateria& amateria)
{
	*this = amateria;
}

AMateria& AMateria::operator=(const AMateria& amateria)
{
	if (this == &amateria)
		return (*this);
	this->_type = amateria.getType();
	return (*this);
}

AMateria::~AMateria()
{
}

std::string const&	AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "amateria used on " << target.getName() << std::endl;
}
