/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:46:53 by yhwang            #+#    #+#             */
/*   Updated: 2023/01/25 09:56:52 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.h"

int	check_int(std::string str)
{
	int	len;

	len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (!((0 <= str[i] - 48) && str[i] - 48 <= 9))
			return (1);
	}
	return (0);
}

int	check_alpha(std::string str)
{
	int	len;

	len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (!((('a' <= str[i]) && (str[i] <= 'z'))
			|| (('A' <= str[i]) && (str[i] <= 'Z'))))
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argv;
	/* error check: argument */
	if (argc != 1)
	{
		std::cout << "error: Argument error" << std::endl;
		return (1);
	}

	/* get N */
	std::string	N_string;
	int		N_int;
	while (1)
	{
		std::cout << "Please type number N(N should be bigger than 0)" << std::endl;
		std::cout << "    > ";
		std::getline(std::cin, N_string);

		/* error check: eof */
		if (std::cin.eof())
		{
			std::cout << "^D" << std::endl;
			return (0);
		}

		/* error check: empty string */
		else if (N_string == "")
		{
			std::cout << "error: N cannot be empty" << std::endl;
			continue ;
		}

		/* error check: if N is integer or not */
		else if (check_int(N_string))
		{
			std::cout << "error: N must be consist of only number" << std::endl;
			continue ;
		}
		else
		{
			/* error check: range of N */
			std::stringstream ss;
			ss << N_string;
			ss >> N_int;
			
			/* normal operation */
			if (N_int > 0)
				break ;
		}
	}

	/* get zombie name */
	std::string	zombie_name;
	while (1)
	{
		std::cout << "Please type zombie name" << std::endl;
		std::cout << "    > ";
		std::getline(std::cin, zombie_name);

		/* error check: eof */
		if (std::cin.eof())
		{
			std::cout << "^D" << std::endl;
			return (0);
		}

		/* error check: empty string */
		else if (zombie_name == "")
		{
			std::cout << "error: zombie name cannot be empty" << std::endl;
			continue ;
		}
		
		/* error check: if zombie name is consist of alphabet */
		else if (check_alpha(zombie_name))
		{
			std::cout << "error: zombie name should be consist of alphabet" << std::endl;
			continue ;
		}

		/* normal operation */
		else
			break ;
	}

	Zombie *zombie = zombieHorde(N_int, zombie_name);
	for (int i = 0; i < N_int; i++)
		zombie[i].announce();
	delete [] zombie;
	return (0);
}
