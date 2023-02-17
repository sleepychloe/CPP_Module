/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:20:08 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/17 03:32:06 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "./AMateria.hpp"
#include "./ICharacter.hpp"

class	Ice: public AMateria
{
public:
	Ice();
	Ice(const Ice& ice);
	Ice& operator=(const Ice& ice);
	~Ice();

	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target);
};

#endif
