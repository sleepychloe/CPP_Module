/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 07:25:14 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/21 08:24:13 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../incs/Base.hpp"

# define BLACK			"\x1b[0m"
# define CYAN			"\x1b[36m"

int	main(int argc, char **argv)
{
	(void)argv;
	/* error check: argument */
	if (argc != 1)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}

	std::cout << CYAN << "[ Test: pointer]" << BLACK << std::endl;
	{
		Base	*base = generate();
		identify(base);
		std::cout << std::endl;
		delete base;
	}
	sleep(1);
	{
		Base	*base = generate();
		identify(base);
		std::cout << std::endl;
		delete base;
	}
	sleep(1);
	{
		Base	*base = generate();
		identify(base);
		std::cout << std::endl;
		delete base;
	}
	sleep(1);
	{
		Base	*base = generate();
		identify(base);
		std::cout << std::endl;
		delete base;
	}
	sleep(1);
	{
		Base	*base = generate();
		identify(base);
		std::cout << std::endl;
		delete base;
	}

	std::cout << CYAN << "[ Test: reference]" << BLACK << std::endl;
	sleep(1);
	{
		Base	*base = generate();
		identify(*base);
		std::cout << std::endl;
		delete base;
	}
	sleep(1);
	{
		Base	*base = generate();
		identify(*base);
		std::cout << std::endl;
		delete base;
	}
	sleep(1);
	{
		Base	*base = generate();
		identify(*base);
		std::cout << std::endl;
		delete base;
	}
	sleep(1);
	{
		Base	*base = generate();
		identify(*base);
		std::cout << std::endl;
		delete base;
	}
	sleep(1);
	{
		Base	*base = generate();
		identify(*base);
		std::cout << std::endl;
		delete base;
	}
	return (0);
}
