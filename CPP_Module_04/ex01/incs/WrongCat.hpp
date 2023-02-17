/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:52:35 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/16 23:53:26 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include <iostream>
#include <string>
#include "./WrongAnimal.hpp"

class	WrongCat: public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat& wrongcat);
	WrongCat& operator=(const WrongCat& wrongcat);
	~WrongCat();

	void	makeSound(void) const;
};

#endif
