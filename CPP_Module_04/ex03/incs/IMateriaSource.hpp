/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:46:43 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/17 05:05:11 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MATERIA_SOURCE_HPP
# define I_MATERIA_SOURCE_HPP

#include "./AMateria.hpp"

class	IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void 		learnMateria(AMateria*) = 0;
	virtual	AMateria*	createMateria(std::string const& type) = 0;
};

#endif
