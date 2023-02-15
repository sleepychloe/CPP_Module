/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 05:35:29 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/15 06:19:53 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

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
