/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 07:11:27 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/15 07:11:38 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include <iostream>
#include <string>
#include "./Animal.hpp"

class	Cat: public Animal
{
public:
	Cat();
	Cat(const Cat& cat);
	Cat& operator=(const Cat& cat);
	~Cat();

	void	makeSound(void) const;
};

#endif
