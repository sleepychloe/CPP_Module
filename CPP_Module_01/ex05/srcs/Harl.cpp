/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:43:49 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/07 14:15:39 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Harl.hpp"

Harl::Harl()
{
}

void	Harl::complain(std::string level)
{
	typedef void(Harl::*func_ptr)(void);
	
	func_ptr	func[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	level_list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level_list[i] == level)
		{
			(this->*func[i])();
			return ;
		}
	}
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << RED << "[ DEBUG ]" << BLACK << std::endl
		<< "I love having extra bacon" << std::endl
		<< "for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl
		<< "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << RED << "[ INFO ]" << BLACK << std::endl
		<< "I cannot believe adding extra bacon costs more money." << std::endl
		<< "You didn’t put enough bacon in my burger!" << std::endl
		<< "If you did, I wouldn’t be asking for more!" << std::endl;
		
	
}

void	Harl::warning(void)
{
	std::cout << RED << "[ WARNING ]" << BLACK << std::endl
		<< "I think I deserve to have some extra bacon for free." << std::endl
		<< "I’ve been coming for years whereas you started working here" << std::endl
		<< "since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << RED << "[ ERROR ]" << BLACK << std::endl
		<< "This is unacceptable!" << std::endl
		<< "I want to speak to the manager now." << std::endl;
}
