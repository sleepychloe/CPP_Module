/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:29:55 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/17 21:29:26 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Character.hpp"

Character::Character(std::string const &name): _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		_materia[i] = NULL;
	}
}

Character::Character(const Character& character)
{
	*this = character;
}

Character& Character::operator=(const Character& character)
{
	if (this == &character)
		return (*this);
	this->_name = character.getName();
	for (int i = 0; i < 4; i++)
		this->_materia[i] = character._materia[i];
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] != NULL)
			delete _materia[i];
	}
}

std::string const&	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] == NULL)
		{
			_materia[i] = m;
			std::cout << "materia " << _materia[i]->getType()
				<< " equipped" << std::endl;
			return ;
		}
	}
	std::cout << "there's no slot for materia" << std::endl;
}

void	Character::unequip(int idx)
{
	_materia[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 3)
		_materia[idx]->use(target);
}
