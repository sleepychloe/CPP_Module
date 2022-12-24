/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:10:03 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/24 10:35:33 by yhwang           ###   ########.fr       */
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

	std::cout << "* You are adding a new contact *" << std::endl;
	if (_num_contact <= MAX_CONTACT)
		std::cout << "The number of current contact: " << _num_contact << std::endl;
	else
		std::cout << "The number of current contact: 8" << std::endl;
	if (_num_contact < MAX_CONTACT)
	{
		if (_num_contact == 0)
			std::cout << "Adding 1st contact" << std::endl;
		else if (_num_contact == 1)
			std::cout << "Adding 2nd contact" << std::endl;
		else if (_num_contact == 2)
			std::cout << "Adding 3rd contact" << std::endl;
		else
			std::cout << "Adding " << _num_contact + 1 << "th contact" << std::endl;
	}
	else
	{
		std::cout << "The limit of the number of contacts is 8. the oldest one will be replaced by the new one" << std::endl;
		if (_num_contact % (MAX_CONTACT) == 0)
			std::cout << "Replacing 1st contact" << std::endl;
		else if (_num_contact % (MAX_CONTACT) == 1)
			std::cout << "Replacing 2nd contact" << std::endl;
		else if (_num_contact % (MAX_CONTACT) == 2)
			std::cout << "Replacing 3rd contact" << std::endl;
		else
			std::cout << "Replacing " << _num_contact % (MAX_CONTACT) + 1 << "th contact" << std::endl;
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

	if (_num_contact == 0)
		std::cout << "Phonebook is empty now" << std::endl;
	else
	{
		std::cout << std::setw(10) << "index" << '|' << std::setw(10) << "first name" << '|';
		std::cout << std::setw(10) << "last name" << '|' << std::setw(10) << "nickname" << std::endl;
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
				std::cout << std::setw(10) << (i % MAX_CONTACT) + 1 << '|' << std::setw(10) << first_name << '|';
				std::cout << std::setw(10) << last_name << '|' << std::setw(10) << nickname << std::endl;
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
		std::cout << "Please type a index number you want to see more" << std::endl;
		std::getline(std::cin, input);
		if (input.length() != 1 || !(0 <= input[0] - 48 && input[0] - 48 <= 9))
		{
			std::cout << "Invalid command: ";
			continue ;
		}
		if ((_num_contact <= 8 && input[0] - 48 > _num_contact)
			|| (_num_contact > 8 && input[0] - 48 > 8))
		{
			std::cout << "Index is out of range: ";
			continue ;
		}
		std::cout << "You selected index " << input[0] - 48 << std::endl;
		std::cout << "If it is right, please type Y. Otherwise, please type N" << std::endl;
		std::getline(std::cin, check);
		while (check != "Y" && check != "N")
		{
			std::cout << "Invalid command: Please type Y or N" << std::endl;
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
