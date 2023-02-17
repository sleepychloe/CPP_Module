/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:20:25 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/17 03:53:24 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cure.hpp"

Cure::Cure(): AMateria("cure")
{
}

Cure::Cure(const Cure& cure): AMateria(cure)
{
	*this = cure;
}

Cure& Cure::operator=(const Cure& cure)
{
	if (this == &cure)
		return (*this);
	AMateria::operator=(cure);
	return (*this);
}

Cure::~Cure()
{
}

AMateria*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *"
		<< std::endl;
}
