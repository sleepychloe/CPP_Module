/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:20:40 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/17 03:52:31 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Ice.hpp"

Ice::Ice(): AMateria("ice")
{
}

Ice::Ice(const Ice& ice): AMateria(ice)
{
	*this = ice;
}

Ice& Ice::operator=(const Ice& ice)
{
	if (this == &ice)
		return (*this);
	AMateria::operator=(ice);
	return (*this);
}

Ice::~Ice()
{
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
		<< std::endl;
}
