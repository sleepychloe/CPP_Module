/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:51:48 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/16 23:52:43 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "./Animal.hpp"
#include "./Brain.hpp"

class	Cat: public Animal
{
public:
	Cat();
	Cat(const Cat& cat);
	Cat& operator=(const Cat& cat);
	~Cat();

	virtual void	makeSound(void) const;
	Brain*		get_brain(void);

private:
	Brain*		_brain;
};

#endif
