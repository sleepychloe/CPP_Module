/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:39:55 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/12 20:20:53 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "../incs/ClapTrap.hpp"

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

void	get_player_number(int *n, std::string *num_player)
{
	while(1)
	{
		std::cout << CYAN << "Please type a number of players"
			<< "(1 < number < 10)" << BLACK << std::endl;
		std::getline(std::cin, *num_player);
		if (std::cin.eof())
		{
			std::cout << "^D" << std::endl;
			break ;
		}
		else if (*num_player == "")
		{
			std::cout << CYAN << "Error: player number should not be empty" << BLACK << std::endl;
			continue ;
		}
		else
		{
			if ((*num_player).length() != 1 || !((2 <= (*num_player)[0] - 48) && (*num_player)[0] - 48 <= 9))
			{
				std::cout << CYAN << "Error: invalid command" << BLACK << std::endl;
				continue ;
			}
			else
			{
				std::stringstream ss;
				ss << *num_player;
				ss >> *n;
				break ;
				
				
			}
		}
	}
}

void	get_player_name(int n, ClapTrap claptrap_player[n], std::string player[n])
{
	for (int i = 0; i < n; i++)
	{
		while (1)
		{
			std::cout << CYAN << "Please type a name for player" << BLACK << std::endl;
			std::getline(std::cin, player[i]);
			if (std::cin.eof())
			{
				std::cout << "^D" << std::endl;
				break ;
			}
			else if (player[i] == "")
			{
				std::cout << CYAN << "Player name should not be empty" << BLACK << std::endl;
				continue ;
			}
			else
			{
				claptrap_player[i].set_name(player[i]);
				break ;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << YELLOW << "Player name is " << claptrap_player[i].get_name() << BLACK << std::endl;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;

	/* error check: argument */
	if (argc != 1)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}

	int		n = 0;
	std::string	num_player = "";

	get_player_number(&n, &num_player);
	ClapTrap claptrap_player[n];

	std::string player[n];
	get_player_name(n, claptrap_player, player);
	
	return (0);
}
