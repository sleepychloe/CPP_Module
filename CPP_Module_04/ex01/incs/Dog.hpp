/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:52:40 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/16 00:01:47 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "./Animal.hpp"
#include "./Brain.hpp"

class	Dog: public Animal
{
public:
	Dog();
	Dog(const Dog& dog);
	Dog& operator=(const Dog& dog);
	~Dog();

	virtual void	makeSound(void) const;

private:
	Brain*		_brain;
};

#endif
