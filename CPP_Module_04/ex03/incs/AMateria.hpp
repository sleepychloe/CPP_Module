/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:15:18 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/17 05:43:12 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

#include <iostream>
#include <string>
#include "./ICharacter.hpp"

class	ICharacter;

class	AMateria
{
public:
	AMateria(std::string const &type);
	AMateria(const AMateria& amateria);
	AMateria& operator=(const AMateria& amateria);
	virtual ~AMateria();

	std::string	const& getType() const;

	virtual		AMateria* clone() const = 0;
	virtual void	use(ICharacter& target);

protected:
	std::string	_type;

private:
	AMateria();
};

#endif
