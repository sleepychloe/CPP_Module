/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 05:35:22 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/15 06:19:59 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "./Animal.hpp"

class	Dog: public Animal
{
public:
	Dog();
	Dog(const Dog& dog);
	Dog& operator=(const Dog& dog);
	~Dog();

	void	makeSound(void) const;
};

#endif
