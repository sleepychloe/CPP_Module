/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 07:10:54 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/15 07:11:14 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class	Animal
{
public:
	Animal();
	Animal(const Animal& animal);
	Animal& operator=(const Animal& animal);
	~Animal();

	void		setType(std::string type);
	std::string	getType(void) const;
	void		makeSound(void) const;

protected:
	std::string	_type;
};

#endif
