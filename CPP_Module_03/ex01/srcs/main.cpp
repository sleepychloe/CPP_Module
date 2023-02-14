/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:58:12 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:37 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "../incs/ClapTrap.hpp"
#include "../incs/ScavTrap.hpp"

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

typedef struct s_trap
{
	int		n;
	int		clap;
	int		scav;
	int		flag;
	int		flag_attacked;
}	t_trap;

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

int	get_player_name(t_trap trap, ClapTrap *claptrap_player, ScavTrap *scavtrap_player, std::string *player)
{
	/* don't be confused that n starts from 1, i starts from 0 */
	for (int i = 0; i < trap.n; i++)
	{
		int temp = i;
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
			if (player[i] == "")
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
				for (int j = 0; j < temp && trap.clap > 0; j++)
				{
					if (claptrap_player[j].get_name() == player[i])
						player[i] = "";
				}
				for (int k = 0; k < temp && trap.scav > 0; k++)
				{
					if (scavtrap_player[k].get_name() == player[i])
						player[i] = "";
				}
				if (player[i] == "")
				{
					std::cout << RED
						<< "Error: each player's name should be different"
						<< BLACK << std::endl;
					continue ;
				}
				if (i % 2 == 0) //i starts from 0, not 1
					claptrap_player[i / 2].set_name(player[i]);
				else if (i % 2 == 1)
					scavtrap_player[i / 2].set_name(player[i]);
				break ;
			}
		}
	}
	for (int i = 0; i < trap.n; i++)
	{
		if (i % 2 == 0)
			std::cout << YELLOW
				<< "Player name is "
				<< claptrap_player[i / 2].get_name()
				<< "(clap trap)" << BLACK << std::endl;
		else
			std::cout << YELLOW
				<< "Player name is "
				<< scavtrap_player[i / 2].get_name()
				<< "(scav trap)" << BLACK << std::endl;
	}
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

void	show_player_status(t_trap trap, ClapTrap *claptrap, ScavTrap *scavtrap)
{
	if (trap.flag % 2 == 0)
		std::cout << RED << "\tplayer " << claptrap[trap.flag / 2].get_name() << std::endl
			<< YELLOW << "\thit points: " << claptrap[trap.flag / 2].get_hit_points() << std::endl
			<< "\tenergy points: " << claptrap[trap.flag / 2].get_energy_points() << BLACK << std::endl;
	else
		std::cout << RED << "\tplayer " << scavtrap[trap.flag / 2].get_name() << std::endl
			<< YELLOW << "\thit points: " << scavtrap[trap.flag / 2].get_hit_points() << std::endl
			<< "\tenergy points: " << scavtrap[trap.flag / 2].get_energy_points() << BLACK << std::endl;
}

void	execute_attack(t_trap trap, ClapTrap *claptrap_player, ScavTrap *scavtrap_player)
{
	if (trap.flag % 2 == 0 && trap.flag_attacked % 2 == 0) //clap attacks clap
	{
		claptrap_player[trap.flag / 2].attack(claptrap_player[trap.flag_attacked / 2].get_name());
		claptrap_player[trap.flag_attacked / 2].takeDamage(claptrap_player[trap.flag / 2].get_attack_damage());
	}
	else if (trap.flag % 2 == 0 && trap.flag_attacked % 2 == 1) //clap attacks scav
	{
		claptrap_player[trap.flag / 2].attack(scavtrap_player[trap.flag_attacked / 2].get_name());
		scavtrap_player[trap.flag_attacked / 2].takeDamage(claptrap_player[trap.flag / 2].get_attack_damage());
	}
	else if (trap.flag % 2 == 1 && trap.flag_attacked % 2 == 0) //scav attacks calp
	{
		scavtrap_player[trap.flag / 2].attack(claptrap_player[trap.flag_attacked / 2].get_name());
		claptrap_player[trap.flag_attacked / 2].takeDamage(scavtrap_player[trap.flag / 2].get_attack_damage());
	}
	else //scav attakcs scav
	{
		scavtrap_player[trap.flag / 2].attack(scavtrap_player[trap.flag_attacked / 2].get_name());
		scavtrap_player[trap.flag_attacked / 2].takeDamage(scavtrap_player[trap.flag / 2].get_attack_damage());
	}
}

int	attack(t_trap trap, ClapTrap *claptrap_player, ScavTrap *scavtrap_player, std::string *player)
{
	std::string	attacked_player = "";
	trap.flag_attacked = -1;
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
			for (int i = 0; i < trap.n; i++)
			{
				if (attacked_player == player[i])
					trap.flag_attacked = i;
			}
			if (trap.flag_attacked == trap.flag)
			{
				std::cout << RED
					<< "Error: you cannot attack yourself" << BLACK << std::endl;
				continue ;
			}
			else if (trap.flag_attacked == -1)
			{
				std::cout << RED
					<< "Error: invalid command" << BLACK << std::endl;
				continue ;
			}
			execute_attack(trap, claptrap_player, scavtrap_player);
			show_player_status(trap, claptrap_player, scavtrap_player);
			break ;
		}
	}
	return (0);
}

int	repaire(t_trap trap, ClapTrap *claptrap_player, ScavTrap *scavtrap_player)
{

	std::string	amount_repaire = "";
	int		repaire;
	while (1)
	{
		if (trap.flag % 2 == 0)
			std::cout << CYAN
				<< "Please type a number for being repaired for player "
				<< claptrap_player[trap.flag / 2].get_name() << std::endl
				<< "(the number should be more than 0)" << BLACK << std::endl
				<< "    > ";
		else
			std::cout << CYAN
				<< "Please type a number for being repaired for player "
				<< scavtrap_player[trap.flag / 2].get_name() << std::endl
				<< "(the number should be more than 0)" << BLACK << std::endl
				<< "    > ";
		
		std::getline(std::cin, amount_repaire);
		if (std::cin.eof())
		{
			std::cout << "^D" << std::endl;
			return (1);
		}
		else if (amount_repaire == "")
		{
			std::cout << RED
				<< "Error: command should not be empty" << BLACK << std::endl;
			continue ;
		}
		else if (amount_repaire == "EXIT")
		{
			std::cout << CYAN << "EXIT" << BLACK << std::endl;
			return (1);
		}
		else if (check_int(amount_repaire))
		{
			std::cout << RED
				<< "Error: invalid command" << BLACK << std::endl;
			continue ;
		}
		else
		{
			std::stringstream	ss;
			ss << amount_repaire;
			ss >> repaire;
			if (repaire == 0)
			{
				std::cout << RED
					<< "Error: invalid command:" << BLACK << std::endl;
				continue ;
			}
			if (trap.flag % 2 == 0)
				claptrap_player[trap.flag / 2].beRepaired(repaire);
			else
				scavtrap_player[trap.flag / 2].beRepaired(repaire);
			show_player_status(trap, claptrap_player, scavtrap_player);
			break ;
		}
	}
	return (0);
}

int	select_act(t_trap trap, ClapTrap *claptrap_player, ScavTrap *scavtrap_player, std::string *player)
{
	std::string	command = "";
	while (1)
	{
		if (trap.flag % 2 == 0)
			std::cout << CYAN
			<< "Please type ATTACK or REPAIR for player "
			<< claptrap_player[trap.flag / 2].get_name() << BLACK << std::endl
			<< "    > ";
		else
			std::cout << CYAN
				<< "Please type ATTACK or REPAIR or GATE_KEEPER_MODE for player "
				<< scavtrap_player[trap.flag / 2].get_name() << BLACK << std::endl
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
			show_player_status(trap, claptrap_player, scavtrap_player);
			
			if (trap.flag % 2 == 0) //craptrap
			{
				/* attack: normal operation */
				if (claptrap_player[trap.flag / 2].get_energy_points() > 0
					&& claptrap_player[trap.flag / 2].get_hit_points() > 0)
				{
					if (attack(trap, claptrap_player, scavtrap_player, player))
						return (1);
				}
				/* attack: error: no energy points */
				else if (claptrap_player[trap.flag / 2].get_energy_points() <= 0)
				{
					std::cout << RED
						<< claptrap_player[trap.flag / 2].get_name()
						<< " does not have any energy points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
						break ;
				}
				/* attack: error: no hit points */
				else if (claptrap_player[trap.flag / 2].get_hit_points() <= 0)
				{
					std::cout << RED
						<< claptrap_player[trap.flag / 2].get_name()
						<< " does not have any energy points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
						break ;
				}
				break ;
			}
			else //scavtrap
			{
				/* attack: normal operation */
				if (scavtrap_player[trap.flag / 2].get_energy_points() > 0
					&& scavtrap_player[trap.flag / 2].get_hit_points() > 0)
				{
					if (attack(trap, claptrap_player, scavtrap_player, player))
						return (1);
				}
				/* attack: error: no energy points */
				else if (scavtrap_player[trap.flag / 2].get_energy_points() <= 0)
				{
					std::cout << RED
						<< scavtrap_player[trap.flag / 2].get_name()
						<< " does not have any energy points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
						break ;
				}
				/* attack: error: no hit points */
				else if (scavtrap_player[trap.flag / 2].get_hit_points() <= 0)
				{
					std::cout << RED
						<< scavtrap_player[trap.flag / 2].get_name()
						<< " does not have any energy points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
						break ;
				}
				break ;
			}
		}
		else if (command == "REPAIR")
		{
			show_player_status(trap, claptrap_player, scavtrap_player);
			if (trap.flag % 2 == 0) //craptrap
			{
				/* repaire: normal operation */
				if (claptrap_player[trap.flag / 2].get_energy_points() > 0
					&& claptrap_player[trap.flag / 2].get_hit_points() > 0)
				{
					if (repaire(trap, claptrap_player, scavtrap_player))
						return (1);
				}
				/* repaire: error: no energy points */
				else if (claptrap_player[trap.flag / 2].get_energy_points() <= 0)
				{
					std::cout << RED
						<< claptrap_player[trap.flag / 2].get_name()
						<< " does not have any energy points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
					break ;
				}
				/* repaire: error: no hit points */
				else if (claptrap_player[trap.flag / 2].get_hit_points() <= 0)
				{
					std::cout << RED
						<< claptrap_player[trap.flag / 2].get_name()
						<< " does not have any hit points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
					break ;
				}
				break ;
			}
			else //scavtrap
			{
				/* repaire: normal operation */
				if (scavtrap_player[trap.flag / 2].get_energy_points() > 0
					&& scavtrap_player[trap.flag / 2].get_hit_points() > 0)
				{
					if (repaire(trap, claptrap_player, scavtrap_player))
						return (1);
				}
				/* repaire: error: no energy points */
				else if (scavtrap_player[trap.flag / 2].get_energy_points() <= 0)
				{
					std::cout << RED
						<< scavtrap_player[trap.flag / 2].get_name()
						<< " does not have any energy points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
					break ;
				}
				/* repaire: error: no hit points */
				else if (scavtrap_player[trap.flag / 2].get_hit_points() <= 0)
				{
					std::cout << RED
						<< scavtrap_player[trap.flag / 2].get_name()
						<< " does not have any hit points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
					break ;
				}
				break ;
			}
			
		}
		else if (command == "GATE_KEEPER_MODE" && trap.flag % 2 == 1)
		{
			scavtrap_player[trap.flag / 2].guardGate();
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

	t_trap	trap;

	int		n = 0;
	std::string	num_player = "";
	if (get_player_number(&n, &num_player))
		return (0);
	
	/*
	n % 2 == 1: claptrap player
	n % 2 == 0: scavtrap player
	*/
	trap.n = n;
	if (trap.n % 2 == 0)
	{
		trap.clap = trap.n / 2;
		trap.scav = trap.n / 2;
	}
	else
	{
		trap.clap = trap.n / 2 + 1;
		trap.scav = trap.n / 2;
	}

	ClapTrap	claptrap_player[trap.clap];
	ScavTrap	scavtrap_player[trap.scav];
	std::string	player[trap.n];
	

	if (get_player_name(trap, claptrap_player, scavtrap_player, player))
		return (0);

	while (1)
	{
		/* select player */
		std::string selected_player = "";
		trap.flag = -1;
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
			for (int i = 0; i < trap.n; i++)
			{
				if (selected_player == player[i])
					trap.flag = i;
			}
			if (trap.flag == -1)
			{
				std::cout << RED
					<< "Error: invalid command" << BLACK << std::endl;
				continue ;
			}
			else
			{
				/* select acting */
				if (select_act(trap, claptrap_player, scavtrap_player, player))
					return (0);
			}
		}
	}
	
	return (0);
}
