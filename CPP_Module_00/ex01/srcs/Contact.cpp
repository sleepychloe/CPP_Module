/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:54:49 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/24 09:45:11 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Contact.hpp"

Contact::Contact()
{
	_contact[FIRST_NAME] = "";
	_contact[LAST_NAME] = "";
	_contact[NICKNAME] = "";
	_contact[PHONE_NUMBER] = "";
	_contact[DARKEST_SECRET] = "";
}

void	Contact::add_element(std::string *contact, int i)
{
	std::string	str;

	if (i == 0)
		str = "first name";
	else if (i == 1)
		str = "last name";
	else if (i == 2)
		str = "nickname";
	else if (i == 3)
		str = "phone number";
	else
		str = "darkest secret";
	while (1)
	{
		std::cout << "Please type " << str << std::endl;
		std::getline(std::cin, contact[i]);
		if (contact[i] == "")
		{
			std::cout << str << " should not be empty: ";
			continue ;
		}
		else
			break ;
	}
	if (i == FIRST_NAME || i == LAST_NAME || i == PHONE_NUMBER)
		check_valid_input(contact, i, str);
}

void	Contact::check_valid_input(std::string *contact, int i, std::string str)
{
	int		j;

	j = 0;
	if (i == FIRST_NAME || i == LAST_NAME)
	{
		while (j < contact[i].length())
		{			
			if (!((65 <= contact[i][j] && contact[i][j] <= 90)
				|| (97 <= contact[i][j] && contact[i][j] <= 122)))
			{
				std::cout << str << " should be consist of alphabets: ";
				std::cout << "Please type " << str << std::endl;
				std::getline(std::cin, contact[i]);
			}
			else
				j++;
		}
	}
	else if (i == PHONE_NUMBER)
	{
		while (j < contact[i].length())
		{			
			if (!(0 <= contact[i][j] - 48 && contact[i][j] - 48 <= 9))
			{
				std::cout << str << " should be consist of number: ";
				std::cout << "Please type " << str << std::endl;
				std::getline(std::cin, contact[i]);
			}
			else
				j++;
		}
	}
}

void	Contact::show_input(void)
{
	std::cout << "Your input is\n" << '\n';
	std::cout << "1. First name:\t\t" << _contact[FIRST_NAME] << '\n';
	std::cout << "2. Last name:\t\t" << _contact[LAST_NAME] << '\n';
	std::cout << "3. Nickname:\t\t" << _contact[NICKNAME] << '\n';
	std::cout << "4. Phone number:\t" << _contact[PHONE_NUMBER] << '\n';
	std::cout << "5. Darkest secret:\t" << _contact[DARKEST_SECRET] << '\n';
}

void	Contact::add(void)
{
	std::string	check;

	for (int i = 0; i < 5; i++)
		add_element(_contact, i);
	
	show_input();
	std::cout << "If you want to change something, please type the corresponding number\n";
	std::cout << "Otherwise, please type Y." << std::endl;
	while (1)
	{	
		std::getline(std::cin, check);
		if (check == "Y")
			break ;
		else if (check == "1")
			add_element(_contact, FIRST_NAME);
		else if (check == "2")
			add_element(_contact, LAST_NAME);
		else if (check == "3")
			add_element(_contact, NICKNAME);
		else if (check == "4")
			add_element(_contact, PHONE_NUMBER);
		else if (check == "5")
			add_element(_contact, DARKEST_SECRET);
		else
		{
			std::cout << "Invalid command: Please type again" << std::endl;
			continue ;
		}
		show_input();
		std::cout << "If you want to change something, please type the corresponding number\n";
		std::cout << "Otherwise, please type Y." << std::endl;
		continue ;
	}
}

std::string	Contact::get_value(int i)
{
	return (_contact[i]);
}

void	Contact::search(void)
{
	std::cout << "first name:\t\t" << get_value(FIRST_NAME) << std::endl;
	std::cout << "last name:\t\t" << get_value(LAST_NAME) << std::endl;
	std::cout << "nickname:\t\t" << get_value(NICKNAME) << std::endl;
	std::cout << "phone number:\t\t" << get_value(PHONE_NUMBER) << std::endl;
	std::cout << "darkest secret:\t\t" << get_value(DARKEST_SECRET) << std::endl;
}

Contact::~Contact()
{
	
}
