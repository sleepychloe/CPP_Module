/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:02:57 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/17 21:40:56 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "./AMateria.hpp"
#include "./ICharacter.hpp"

class	Character: public ICharacter
{
public:
	Character(std::string const &name);
	Character(const Character& character);
	Character& operator=(const Character& character);
	~Character();

	virtual std::string const&	getName() const;
	virtual void			equip(AMateria* m);
	virtual void			unequip(int idx);
	virtual void			use(int idx, ICharacter& target);

private:
	AMateria	*_materia[4];
	std::string	_name;
};

#endif
