/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:26:14 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/14 21:31:21 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "../incs/ClapTrap.hpp"
#include "../incs/ScavTrap.hpp"
#include "../incs/FragTrap.hpp"

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

typedef struct s_trap
{
	int		n;
	ClapTrap	*claptrap_player;
	ScavTrap	*scavtrap_player;
	FragTrap	*fragtrap_player;
	std::string	player[3];
	int		flag;
	int		flag_attacked;
}	t_trap;

int	get_player_name(t_trap *trap)
{
	std::cout << YELLOW
		<< "There will be 3 players for this game." << std::endl
		<< "First player is clap trap player," << std::endl
		<< "Second player is scav trap player," << std::endl
		<< "And third player is frag trap player" << BLACK << std::endl;
	for (int i = 0; i < trap->n; i++)
	{
		while (1)
		{
			std::cout << CYAN << "Please type a name for player" << BLACK << std::endl
				<< "    > ";
			std::getline(std::cin, trap->player[i]);
			if (std::cin.eof())
			{
				std::cout << "^D" << std::endl;
				delete trap->claptrap_player;
				delete trap->scavtrap_player;
				delete trap->fragtrap_player;
				return (1);
			}
			if (trap->player[i] == "")
			{
				std::cout << RED
					<< "Error: command should not be empty" << BLACK << std::endl;
				continue ;
			}
			else if (trap->player[i] == "EXIT")
			{
				std::cout << CYAN << "EXIT" << BLACK << std::endl;
				delete trap->claptrap_player;
				delete trap->scavtrap_player;
				delete trap->fragtrap_player;
				return (1);
			}
			else
			{
				if (trap->claptrap_player->get_name() == trap->player[i])
					trap->player[i] = "";
				if (trap->scavtrap_player->get_name() == trap->player[i])
					trap->player[i] = "";
				if (trap->player[i] == "")
				{
					std::cout << RED
						<< "Error: each player's name should be different"
						<< BLACK << std::endl;
					continue ;
				}
				break ;
			}
		}
	}
	trap->claptrap_player->set_name(trap->player[0]);
	std::cout << YELLOW
		<< "Player name is "
		<< trap->claptrap_player->get_name()
		<< "(clap trap)" << BLACK << std::endl;

	trap->scavtrap_player->set_name(trap->player[1]);
	std::cout << YELLOW
		<< "Player name is "
		<< trap->scavtrap_player->get_name()
		<< "(scav trap)" << BLACK << std::endl;

	trap->fragtrap_player->set_name(trap->player[2]);
	std::cout << YELLOW
		<< "Player name is "
		<< trap->fragtrap_player->get_name()
		<< "(frag trap)" << BLACK << std::endl;
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

void	show_player_status(t_trap *trap)
{
	if (trap->flag == 0)
		std::cout << RED << "\tplayer " << trap->claptrap_player->get_name() << std::endl
			<< YELLOW << "\thit points: " << trap->claptrap_player->get_hit_points() << std::endl
			<< "\tenergy points: " << trap->claptrap_player->get_energy_points() << BLACK << std::endl;
	else if (trap->flag == 1)
		std::cout << RED << "\tplayer " << trap->scavtrap_player->get_name() << std::endl
			<< YELLOW << "\thit points: " << trap->scavtrap_player->get_hit_points() << std::endl
			<< "\tenergy points: " << trap->scavtrap_player->get_energy_points() << BLACK << std::endl;
	else
		std::cout << RED << "\tplayer " << trap->fragtrap_player->get_name() << std::endl
			<< YELLOW << "\thit points: " << trap->fragtrap_player->get_hit_points() << std::endl
			<< "\tenergy points: " << trap->fragtrap_player->get_energy_points() << BLACK << std::endl;
}

void	execute_attack(t_trap *trap)
{
	if (trap->flag == 0 && trap->flag_attacked == 1) //clap attacks scav
	{
		trap->claptrap_player->attack(trap->scavtrap_player->get_name());
		trap->scavtrap_player->takeDamage(trap->claptrap_player->get_attack_damage());
	}
	else if (trap->flag == 0 && trap->flag_attacked == 2) //clap attacks frag
	{
		trap->claptrap_player->attack(trap->fragtrap_player->get_name());
		trap->fragtrap_player->takeDamage(trap->claptrap_player->get_attack_damage());
	}
	else if (trap->flag == 1 && trap->flag_attacked == 0) //scav attacks clap
	{
		trap->scavtrap_player->attack(trap->claptrap_player->get_name());
		trap->claptrap_player->takeDamage(trap->scavtrap_player->get_attack_damage());
	}
	else if (trap->flag == 1 && trap->flag_attacked == 2) //scav attacks frag
	{
		trap->scavtrap_player->attack(trap->fragtrap_player->get_name());
		trap->fragtrap_player->takeDamage(trap->scavtrap_player->get_attack_damage());
	}
	else if (trap->flag == 2 && trap->flag_attacked == 0) //frag attacks clap
	{
		trap->fragtrap_player->attack(trap->claptrap_player->get_name());
		trap->claptrap_player->takeDamage(trap->fragtrap_player->get_attack_damage());
	}
	else //frag attacks scav
	{
		trap->fragtrap_player->attack(trap->scavtrap_player->get_name());
		trap->scavtrap_player->takeDamage(trap->fragtrap_player->get_attack_damage());
	}
}

int	attack(t_trap *trap)
{
	std::string	attacked_player = "";
	trap->flag_attacked = -1;
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
			delete trap->claptrap_player;
			delete trap->scavtrap_player;
			delete trap->fragtrap_player;
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
			delete trap->claptrap_player;
			delete trap->scavtrap_player;
			delete trap->fragtrap_player;
			return (1);
		}
		else
		{
			for (int i = 0; i < trap->n; i++)
			{
				if (attacked_player == trap->player[i])
					trap->flag_attacked = i;
			}
			if (trap->flag_attacked == trap->flag)
			{
				std::cout << RED
					<< "Error: you cannot attack yourself" << BLACK << std::endl;
				continue ;
			}
			else if (trap->flag_attacked == -1)
			{
				std::cout << RED
					<< "Error: invalid command" << BLACK << std::endl;
				continue ;
			}
			execute_attack(trap);
			show_player_status(trap);
			break ;
		}
	}
	return (0);
}

int	repaire(t_trap *trap)
{

	std::string	amount_repaire = "";
	int		repaire;
	while (1)
	{
		if (trap->flag == 0)
			std::cout << CYAN
				<< "Please type a number for being repaired for player "
				<< trap->claptrap_player->get_name() << std::endl
				<< "(the number should be more than 0)" << BLACK << std::endl
				<< "    > ";
		else if (trap->flag == 1)
			std::cout << CYAN
				<< "Please type a number for being repaired for player "
				<< trap->scavtrap_player->get_name() << std::endl
				<< "(the number should be more than 0)" << BLACK << std::endl
				<< "    > ";
		else
			std::cout << CYAN
				<< "Please type a number for being repaired for player "
				<< trap->fragtrap_player->get_name() << std::endl
				<< "(the number should be more than 0)" << BLACK << std::endl
				<< "    > ";
		
		std::getline(std::cin, amount_repaire);
		if (std::cin.eof())
		{
			std::cout << "^D" << std::endl;
			delete trap->claptrap_player;
			delete trap->scavtrap_player;
			delete trap->fragtrap_player;
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
			delete trap->claptrap_player;
			delete trap->scavtrap_player;
			delete trap->fragtrap_player;
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
			if (trap->flag == 0)
				trap->claptrap_player->beRepaired(repaire);
			else if (trap->flag == 1)
				trap->scavtrap_player->beRepaired(repaire);
			else
				trap->fragtrap_player->beRepaired(repaire);
			show_player_status(trap);
			break ;
		}
	}
	return (0);
}

int	select_act(t_trap *trap)
{
	std::string	command = "";
	while (1)
	{
		if (trap->flag == 0)
			std::cout << CYAN
			<< "Please type ATTACK or REPAIR for player "
			<< trap->claptrap_player->get_name() << BLACK << std::endl
			<< "    > ";
		else if (trap->flag == 1)
			std::cout << CYAN
				<< "Please type ATTACK or REPAIR or GATE_KEEPER_MODE for player "
				<< trap->scavtrap_player->get_name() << BLACK << std::endl
				<< "    > ";
		else
			std::cout << CYAN
				<< "Please type ATTACK or REPAIR or HIGH_FIVES for player "
				<< trap->fragtrap_player->get_name() << BLACK << std::endl
				<< "    > ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << "^D" << std::endl;
			delete trap->claptrap_player;
			delete trap->scavtrap_player;
			delete trap->fragtrap_player;
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
			show_player_status(trap);
			
			if (trap->flag == 0) //craptrap
			{
				/* attack: normal operation */
				if (trap->claptrap_player->get_energy_points() > 0
					&& trap->claptrap_player->get_hit_points() > 0)
				{
					if (attack(trap))
						return (1);
				}
				/* attack: error: no energy points */
				else if (trap->claptrap_player->get_energy_points() <= 0)
				{
					std::cout << RED
						<< trap->claptrap_player->get_name()
						<< " does not have any energy points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
						break ;
				}
				/* attack: error: no hit points */
				else if (trap->claptrap_player->get_hit_points() <= 0)
				{
					std::cout << RED
						<< trap->claptrap_player->get_name()
						<< " does not have any energy points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
						break ;
				}
				break ;
			}
			else if (trap->flag == 1) //scavtrap
			{
				/* attack: normal operation */
				if (trap->scavtrap_player->get_energy_points() > 0
					&& trap->scavtrap_player->get_hit_points() > 0)
				{
					if (attack(trap))
						return (1);
				}
				/* attack: error: no energy points */
				else if (trap->scavtrap_player->get_energy_points() <= 0)
				{
					std::cout << RED
						<< trap->scavtrap_player->get_name()
						<< " does not have any energy points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
						break ;
				}
				/* attack: error: no hit points */
				else if (trap->scavtrap_player->get_hit_points() <= 0)
				{
					std::cout << RED
						<< trap->scavtrap_player->get_name()
						<< " does not have any energy points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
						break ;
				}
				break ;
			}
			else //fragtrap
			{
				/* attack: normal operation */
				if (trap->fragtrap_player->get_energy_points() > 0
					&& trap->fragtrap_player->get_hit_points() > 0)
				{
					if (attack(trap))
						return (1);
				}
				/* attack: error: no energy points */
				else if (trap->fragtrap_player->get_energy_points() <= 0)
				{
					std::cout << RED
						<< trap->fragtrap_player->get_name()
						<< " does not have any energy points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
						break ;
				}
				/* attack: error: no hit points */
				else if (trap->scavtrap_player->get_hit_points() <= 0)
				{
					std::cout << RED
						<< trap->fragtrap_player->get_name()
						<< " does not have any energy points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
						break ;
				}
				break ;
			}
		}
		else if (command == "REPAIR")
		{
			show_player_status(trap);
			if (trap->flag == 0) //craptrap
			{
				/* repaire: normal operation */
				if (trap->claptrap_player->get_energy_points() > 0
					&& trap->claptrap_player->get_hit_points() > 0)
				{
					if (repaire(trap))
						return (1);
				}
				/* repaire: error: no energy points */
				else if (trap->claptrap_player->get_energy_points() <= 0)
				{
					std::cout << RED
						<< trap->claptrap_player->get_name()
						<< " does not have any energy points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
					break ;
				}
				/* repaire: error: no hit points */
				else if (trap->claptrap_player->get_hit_points() <= 0)
				{
					std::cout << RED
						<< trap->claptrap_player->get_name()
						<< " does not have any hit points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
					break ;
				}
				break ;
			}
			else if (trap->flag == 1) //scavtrap
			{
				/* repaire: normal operation */
				if (trap->scavtrap_player->get_energy_points() > 0
					&& trap->scavtrap_player->get_hit_points() > 0)
				{
					if (repaire(trap))
						return (1);
				}
				/* repaire: error: no energy points */
				else if (trap->scavtrap_player->get_energy_points() <= 0)
				{
					std::cout << RED
						<< trap->scavtrap_player->get_name()
						<< " does not have any energy points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
					break ;
				}
				/* repaire: error: no hit points */
				else if (trap->scavtrap_player->get_hit_points() <= 0)
				{
					std::cout << RED
						<< trap->scavtrap_player->get_name()
						<< " does not have any hit points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
					break ;
				}
				break ;
			}
			else //fragtrap
			{
				/* repaire: normal operation */
				if (trap->fragtrap_player->get_energy_points() > 0
					&& trap->fragtrap_player->get_hit_points() > 0)
				{
					if (repaire(trap))
						return (1);
				}
				/* repaire: error: no energy points */
				else if (trap->fragtrap_player->get_energy_points() <= 0)
				{
					std::cout << RED
						<< trap->fragtrap_player->get_name()
						<< " does not have any energy points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
					break ;
				}
				/* repaire: error: no hit points */
				else if (trap->fragtrap_player->get_hit_points() <= 0)
				{
					std::cout << RED
						<< trap->fragtrap_player->get_name()
						<< " does not have any hit points" << std::endl
						<< "he cannot take any action" << BLACK << std::endl;
					break ;
				}
				break ;
			}
			
		}
		else if (command == "GATE_KEEPER_MODE" && trap->flag == 1)
		{
			trap->scavtrap_player->guardGate();
			break ;
		}
		else if (command == "HIGH_FIVES" && trap->flag == 2)
		{
			trap->fragtrap_player->highFivesGuys();
			break ;
		}
		else if (command == "EXIT")
		{
			std::cout << CYAN << "EXIT" << BLACK << std::endl;
			delete trap->claptrap_player;
			delete trap->scavtrap_player;
			delete trap->fragtrap_player;
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

	/*
	3 players:	1st: craptrap
			2nd: scavtrap
			3rd: fragtrap
	*/
	t_trap	trap;
	trap.n = 3;
	trap.claptrap_player = new ClapTrap();
	trap.scavtrap_player = new ScavTrap();
	trap.fragtrap_player = new FragTrap();

	if (get_player_name(&trap))
		return (0);
	
	std::cout << "here\n";//
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
			delete trap.claptrap_player;
			delete trap.scavtrap_player;
			delete trap.fragtrap_player;
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
			delete trap.claptrap_player;
			delete trap.scavtrap_player;
			delete trap.fragtrap_player;
			return (0);
		}
		else
		{
			for (int i = 0; i < trap.n; i++)
			{
				if (selected_player == trap.player[i])
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
				if (select_act(&trap))
					return (0);
			}
		}
	}

	delete trap.claptrap_player;
	delete trap.scavtrap_player;
	delete trap.fragtrap_player;
	
	return (0);
}
