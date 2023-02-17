/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:20:15 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/17 03:31:48 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "./AMateria.hpp"
#include "./ICharacter.hpp"

class	Cure: public AMateria
{
public:
	Cure();
	Cure(const Cure& cure);
	Cure& operator=(const Cure& cure);
	~Cure();
	
	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target);
};

#endif
