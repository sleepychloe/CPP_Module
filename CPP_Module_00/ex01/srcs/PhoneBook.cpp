/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:10:03 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/24 11:24:54 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_num_contact = 0;
}

void	PhoneBook::add(void)
{
	Contact		Contact;

	std::cout << YELLOW << "* You are adding a new contact *" << BLACK << std::endl;
	if (_num_contact <= MAX_CONTACT)
		std::cout << BLUE << "The number of current contact: " << _num_contact << BLACK << std::endl;
	else
		std::cout << BLUE << "The number of current contact: 8" << BLACK << std::endl;
	if (_num_contact < MAX_CONTACT)
	{
		if (_num_contact == 0)
			std::cout << BLUE << "Adding 1st contact" << BLACK << std::endl;
		else if (_num_contact == 1)
			std::cout << BLUE << "Adding 2nd contact" << BLACK << std::endl;
		else if (_num_contact == 2)
			std::cout << BLUE << "Adding 3rd contact" << BLACK << std::endl;
		else
			std::cout << BLUE << "Adding " << _num_contact + 1 << "th contact" << BLACK << std::endl;
	}
	else
	{
		std::cout << BLUE << "The limit of the number of contacts is 8. the oldest one will be replaced by the new one" << BLACK << std::endl;
		if (_num_contact % (MAX_CONTACT) == 0)
			std::cout << BLUE << "Replacing 1st contact" << BLACK << std::endl;
		else if (_num_contact % (MAX_CONTACT) == 1)
			std::cout << BLUE << "Replacing 2nd contact" << BLACK << std::endl;
		else if (_num_contact % (MAX_CONTACT) == 2)
			std::cout << BLUE << "Replacing 3rd contact" << BLACK << std::endl;
		else
			std::cout << BLUE << "Replacing " << _num_contact % (MAX_CONTACT) + 1 << "th contact" << BLACK << std::endl;
	}
	Contact.add();
	_Contact[_num_contact % MAX_CONTACT] = Contact;
	_num_contact++;
}

void	PhoneBook::show_phonebook_list(void)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;

	std::cout << YELLOW << "* You are searching phonebook *" << BLACK << std::endl;
	if (_num_contact == 0)
		std::cout << BLUE << "Phonebook is empty now" << BLACK << std::endl;
	else
	{
		std::cout << BLUE << std::setw(10) << "index" << '|' << std::setw(10) << "first name" << '|';
		std::cout << std::setw(10) << "last name" << '|' << std::setw(10) << "nickname" << BLACK << std::endl;
		for (int i = 0; i < _num_contact; i++)
		{
			first_name = _Contact[i % MAX_CONTACT].get_value(FIRST_NAME);
			last_name = _Contact[i % MAX_CONTACT].get_value(LAST_NAME);
			nickname = _Contact[i % MAX_CONTACT].get_value(NICKNAME);
			if (first_name.length() > 10)
			{
				for (int i = first_name.length(); i > 10; i--)
					first_name.pop_back();
				first_name[9] = '.';
			}
			if (last_name.length() > 10)
			{
				for (int i = last_name.length(); i > 10; i--)
					last_name.pop_back();
				last_name[9] = '.';
			}
			if (nickname.length() > 10)
			{
				for (int i = nickname.length(); i > 10; i--)
					nickname.pop_back();
				nickname[9] = '.';
			}
			if (i <= 7)
			{
				std::cout << BLUE << std::setw(10) << (i % MAX_CONTACT) + 1 << '|' << std::setw(10) << first_name << '|';
				std::cout << std::setw(10) << last_name << '|' << std::setw(10) << nickname << BLACK << std::endl;
			}
		}
	}
}

void	PhoneBook::search(void)
{
	std::string	input;
	std::string	check;
	int		int_input;

	show_phonebook_list();
	while (1)
	{
		std::cout << BLUE << "Please type a index number you want to see more" << BLACK << std::endl;
		std::getline(std::cin, input);
		if (input.length() != 1 || !(0 <= input[0] - 48 && input[0] - 48 <= 9))
		{
			std::cout << RED << "Invalid command: " << BLACK;
			continue ;
		}
		if (input[0] - 48 == 0 || (_num_contact <= 8 && input[0] - 48 > _num_contact)
			|| (_num_contact > 8 && input[0] - 48 > 8))
		{
			std::cout << RED << "Index is out of range: " << BLACK;
			continue ;
		}
		std::cout << YELLOW << "You selected index " << input[0] - 48 << BLACK << std::endl;
		std::cout << BLUE << "If it is right, please type Y. Otherwise, please type N" << BLACK << std::endl;
		std::getline(std::cin, check);
		while (check != "Y" && check != "N")
		{
			std::cout << RED << "Invalid command: Please type Y or N" << BLACK << std::endl;
			std::getline(std::cin, check);
		}
		if (check == "Y")
			break ;
		else if (check == "N")
			continue ;
	}
	int_input = input[0] - 48;
	if (int_input <= 8)
		_Contact[int_input - 1].search();
	else
		_Contact[(int_input % MAX_CONTACT) - 1].search();
}

PhoneBook::~PhoneBook()
{
	
}
