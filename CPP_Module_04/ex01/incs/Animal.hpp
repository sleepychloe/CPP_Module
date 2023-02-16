/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:52:44 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/15 23:53:31 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"

class	Animal
{
public:
	Animal();
	Animal(const Animal& animal);
	Animal& operator=(const Animal& animal);
	virtual ~Animal();

	void		setType(std::string type);
	std::string	getType(void) const;
	virtual void		makeSound(void) const;

protected:
	std::string	_type;
};

#endif
