/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:46:09 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/17 05:12:30 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		_materia[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& materiasource)
{
	*this = materiasource;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& materiasource)
{
	if (this == &materiasource)
		return (*this);
	for (int i = 0; i < 4; i++)
		this->_materia[i] = materiasource._materia[i];
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] != NULL)
			delete _materia[i];
	}
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] == NULL)
		{
			_materia[i] = m;
			return ;
		}
	}
	std::cout << "there's no slot to learn new materia" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] != NULL && _materia[i]->getType() == type)
			return (_materia[i]->clone());
	}
	return (0);
}
