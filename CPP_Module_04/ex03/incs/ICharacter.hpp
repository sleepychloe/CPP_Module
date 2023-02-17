/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:21:31 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/17 05:43:39 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_CHARACTER_HPP
# define I_CHARACTER_HPP

#include <iostream>
#include <string>
#include "./AMateria.hpp"

class	AMateria;

class	ICharacter
{
public:
	virtual ~ICharacter() {};
	virtual std::string const&	getName() const = 0;
	virtual void			equip(AMateria* m) = 0;
	virtual void			unequip(int idx) = 0;
	virtual void			use(int idx, ICharacter& target) = 0;
};

#endif
