/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:39:55 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/13 01:48:36 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "../incs/ClapTrap.hpp"

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

int	get_player_number(int *n, std::string *num_player)
{
	while(1)
	{
		std::cout << CYAN
			<< "Please type a number of players"
			<< "(1 < number < 10)" << std::endl
			<< "(please type EXIT to quit this program)" << BLACK << std::endl
			<< "    > ";
		std::getline(std::cin, *num_player);
		if (std::cin.eof())
		{
			std::cout << "^D" << std::endl;
			return (1);
		}
		else if (*num_player == "")
		{
			std::cout << RED
				<< "Error: command should not be empty" << BLACK << std::endl;
			continue ;
		}
		else if (*num_player == "EXIT")
		{
			std::cout << CYAN << "EXIT" << BLACK << std::endl;
			return (1);
		}
		else
		{
			if ((*num_player).length() != 1
				|| !((2 <= (*num_player)[0] - 48) && (*num_player)[0] - 48 <= 9))
			{
				std::cout << RED
					<< "Error: invalid command" << BLACK << std::endl;
				continue ;
			}
			else
			{
				std::stringstream	ss;
				ss << *num_player;
				ss >> *n;
				break ;
				
				
			}
		}
	}
	return (0);
}

int	get_player_name(int n, ClapTrap *claptrap_player, std::string *player)
{
	for (int i = 0; i < n; i++)
	{
		while (1)
		{
			std::cout << CYAN
				<< "Please type a name for player" << BLACK << std::endl
				<< "    > ";
			std::getline(std::cin, player[i]);
			if (std::cin.eof())
			{
				std::cout << "^D" << std::endl;
				return (1);
			}
			else if (player[i] == "")
			{
				std::cout << RED
					<< "Error: command should not be empty" << BLACK << std::endl;
				continue ;
			}
			else if (player[i] == "EXIT")
			{
				std::cout << CYAN << "EXIT" << BLACK << std::endl;
				return (1);
			}
			else
			{
				claptrap_player[i].set_name(player[i]);
				break ;
			}
		}
	}

	for (int i = 0; i < n; i++)
		std::cout << YELLOW
			<< "Player name is "
			<< claptrap_player[i].get_name() << BLACK << std::endl;
	return (0);
}

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

void	show_player_status(ClapTrap *claptrap, int n)
{
	std::cout << RED << "\tplayer " << claptrap[n].get_name() << std::endl
		<< YELLOW << "\thit points: " << claptrap[n].get_hit_points() << std::endl
		<< "\tenergy points: " << claptrap[n].get_energy_points() << BLACK << std::endl;
}

int	attack(int n, ClapTrap *claptrap_player, std::string *player, int flag)
{
	std::string	attacked_player = "";
	int		flag_attacked = -1;
	while (1)
	{
		std::cout << CYAN
			<< "Please type a player that you want to attack"
			<< BLACK << std::endl
			<< "    > ";
		std::getline(std::cin, attacked_player);
		if (std::cin.eof())
		{
			std::cout << "^D" << std::endl;
			return (1);
		}
		else if (attacked_player == "")
		{
			std::cout << RED
				<< "Error: command should not be empty" << BLACK << std::endl;
			continue ;
		}
		else if (attacked_player == "EXIT")
		{
			std::cout << CYAN << "EXIT" << BLACK << std::endl;
			return (1);
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (attacked_player == player[i])
					flag_attacked = i;
			}
			if (flag_attacked == flag)
			{
				std::cout << RED
					<< "Error: you cannot attack yourself" << BLACK << std::endl;
				continue ;
			}
			else if (flag_attacked == -1)
			{
				std::cout << RED
					<< "Error: invalid command" << BLACK << std::endl;
				continue ;
			}
			claptrap_player[flag].attack(claptrap_player[flag_attacked].get_name());
			claptrap_player[flag_attacked].takeDamage(claptrap_player[flag].get_attack_damage());

			show_player_status(claptrap_player, flag);
			break ;
		}
	}
	return (0);
}

int	repare(ClapTrap *claptrap_player, int flag)
{

	std::string	amount_repare = "";
	int		repare;
	while (1)
	{
		std::cout << CYAN
			<< "Please type a number for being repaired for player "
			<< claptrap_player[flag].get_name() << std::endl
			<< "(the number should be more than 0)" << BLACK << std::endl
			<< "    > ";
		std::getline(std::cin, amount_repare);
		if (std::cin.eof())
		{
			std::cout << "^D" << std::endl;
			return (1);
		}
		else if (amount_repare == "")
		{
			std::cout << RED
				<< "Error: command should not be empty" << BLACK << std::endl;
			continue ;
		}
		else if (amount_repare == "EXIT")
		{
			std::cout << CYAN << "EXIT" << BLACK << std::endl;
			return (1);
		}
		else if (check_int(amount_repare))
		{
			std::cout << RED
				<< "Error: invalid command" << BLACK << std::endl;
			continue ;
		}
		else
		{
			std::stringstream	ss;
			ss << amount_repare;
			ss >> repare;
			if (repare == 0)
			{
				std::cout << RED
					<< "Error: invalid command" << BLACK << std::endl;
				continue ;
			}
			claptrap_player[flag].beRepaired(repare);

			show_player_status(claptrap_player, flag);
			break ;
		}
	}

	return (0);
}

int	select_act(int n, ClapTrap *claptrap_player, std::string *player, int flag)
{
	std::string	command = "";
	while (1)
	{
		std::cout << CYAN
			<< "Please type ATTACK or REPARE for player "
			<< claptrap_player[flag].get_name() << BLACK << std::endl
			<< "    > ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << "^D" << std::endl;
			return (1);
		}
		else if (command == "")
		{
			std::cout << RED
				<< "Error: command should not be empty" << BLACK << std::endl;
			continue ;
		}
		else if (command == "ATTACK")
		{
			show_player_status(claptrap_player, flag);

			/* attack: normal operation */
			if (claptrap_player[flag].get_energy_points() > 0
				&& claptrap_player[flag].get_hit_points() > 0)
			{
				if (attack(n, claptrap_player, player, flag))
					return (1);
			}
			/* attack: error: no energy point */
			else if (claptrap_player[flag].get_energy_points() == 0)
			{
				std::cout << CYAN
					<< claptrap_player[flag].get_name()
					<< " does not have any energy point" << std::endl
					<< "he cannot take any action" << BLACK << std::endl;
					break ;
			}
			/* attack: error: no hit point */
			else if (claptrap_player[flag].get_hit_points() == 0)
			{
				std::cout << CYAN
					<< claptrap_player[flag].get_name()
					<< " does not have any energy point" << std::endl
					<< "he cannot take any action" << BLACK << std::endl;
					break ;
			}
			break ;
		}
		else if (command == "REPARE")
		{
			show_player_status(claptrap_player, flag);
			/* repare: normal operation */
			if (claptrap_player[flag].get_energy_points() > 0
				&& claptrap_player[flag].get_hit_points() > 0)
			{
				if (repare(claptrap_player, flag))
					return (1);
			}
			/* repare: error: no energy point */
			else if (claptrap_player[flag].get_energy_points() == 0)
			{
				std::cout << CYAN
					<< claptrap_player[flag].get_name()
					<< " does not have any energy point" << std::endl
					<< "he cannot take any action" << BLACK << std::endl;
				break ;
			}
			/* repare: error: no hit point */
			else if (claptrap_player[flag].get_hit_points() == 0)
			{
				std::cout << CYAN
					<< claptrap_player[flag].get_name()
					<< " does not have any hit point" << std::endl
					<< "he cannot take any action" << BLACK << std::endl;
				break ;
			}
			break ;
		}
		else if (command == "EXIT")
		{
			std::cout << CYAN << "EXIT" << BLACK << std::endl;
			return (1);
		}
		else
		{
			std::cout << RED
				<< "Error: invalid command" << BLACK << std::endl;
			continue ;
		}
	}
	return (0);
}



int	main(int argc, char **argv)
{
	(void)argv;

	/* error check: argument */
	if (argc != 1)
	{
		std::cout << RED << "Error: argument error" << BLACK << std::endl;
		return (1);
	}

	int		 n = 0;
	std::string	num_player = "";
	if (get_player_number(&n, &num_player))
		return (0);

	ClapTrap	claptrap_player[n];
	std::string	player[n];
	if (get_player_name(n, claptrap_player, player))
		return (0);

	while (1)
	{
		/* select player */
		std::string selected_player = "";
		int flag = -1;
		std::cout << CYAN
			<< "Please type the name of player that you want to select"
			<< BLACK << std::endl
			<< "    > ";
		std::getline(std::cin, selected_player);
		if (std::cin.eof())
		{
			std::cout << "^D" << std::endl;
			return (0);
		}
		else if (selected_player == "")
		{
			std::cout << RED
				<< "Error: command should not be empty" << BLACK << std::endl;
			continue ;
		}
		else if (selected_player == "EXIT")
		{
			std::cout << CYAN << "EXIT" << BLACK << std::endl;
			return (0);
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (selected_player == player[i])
					flag = i;
			}
			if (flag == -1)
			{
				std::cout << RED
					<< "Error: invalid command" << BLACK << std::endl;
				continue ;
			}
			else
			{
				/* select acting */
				if (select_act(n, claptrap_player, player, flag))
					return (0);
			}
		}
	}
	
	return (0);
}
