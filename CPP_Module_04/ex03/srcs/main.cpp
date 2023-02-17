/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:15:32 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/17 21:34:49 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/AMateria.hpp"
#include "../incs/Ice.hpp"
#include "../incs/Cure.hpp"
#include "../incs/ICharacter.hpp"
#include "../incs/Character.hpp"
#include "../incs/IMateriaSource.hpp"
#include "../incs/MateriaSource.hpp"

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"

int main(int argc, char **argv)
{
	(void)argv;
	/* error check: argument */
	if (argc != 1)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}

	{
		std::cout << RED << "[ TEST 1 ]" << BLACK << std::endl;
	
		IMateriaSource*	src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter*	me = new Character("me");
		AMateria*	tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	
	{
		std::cout << RED << "[ TEST 2 ]" << BLACK << std::endl;
	
		IMateriaSource*	source = new MateriaSource();
		source->learnMateria(new Ice());
		source->learnMateria(new Cure());
		source->learnMateria(new Cure());
		source->learnMateria(new Ice());

		ICharacter*	rabbit = new Character("rabbit");
		AMateria*	tmp;
		tmp = source->createMateria("cure"); //0
		rabbit->equip(tmp);
		tmp = source->createMateria("cure"); //1
		rabbit->equip(tmp);
		tmp = source->createMateria("ice"); //2
		rabbit->equip(tmp);
		tmp = source->createMateria("cure"); //3
		rabbit->equip(tmp);
		tmp = source->createMateria("cure"); //no more slot
		rabbit->equip(tmp);
		delete tmp;

		ICharacter*	chick = new Character("chick");
		rabbit->use(0, *chick);
		rabbit->use(1, *chick);
		rabbit->use(2, *chick);
		rabbit->use(3, *chick);
		rabbit->use(4, *chick); //don't do anything

		delete chick;
		delete rabbit;
		delete source;
	}

	return (0);
}
