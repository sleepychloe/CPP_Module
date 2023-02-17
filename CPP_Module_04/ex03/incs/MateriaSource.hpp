/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:45:54 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/17 05:06:02 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

#include "./IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource& materiasource);
	MateriaSource& operator=(const MateriaSource& materiasource);
	~MateriaSource();

	void		learnMateria(AMateria* m);
	AMateria*	createMateria(std::string const& type);

private:
	AMateria*	_materia[4];
};

#endif
