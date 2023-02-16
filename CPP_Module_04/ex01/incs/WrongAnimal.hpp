/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:52:37 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/15 23:53:50 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"

class	WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& wronganimal);
	WrongAnimal& operator=(const WrongAnimal& wronganimal);
	~WrongAnimal();

	void		setType(std::string type);
	std::string	getType(void) const;
	void		makeSound(void) const;

protected:
	std::string	_type;
};

#endif
