/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:10:03 by yhwang            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/03 02:33:35 by yhwang           ###   ########.fr       */
=======
/*   Updated: 2022/12/26 13:32:38 by yhwang           ###   ########.fr       */
>>>>>>> cf163e47c8b8b5f8d073afca102b1d6b600ae970
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

	print_msg(YELLOW, "* YOU ARE ADDING A NEW CONTACT *");
	if (_num_contact <= MAX_CONTACT)
		print_msg(CYAN, "The number of current contact: ", _num_contact);
	else
		print_msg(CYAN, "The number of current contact: 8");
	if (_num_contact < MAX_CONTACT)
	{
		if (_num_contact == 0)
			print_msg(CYAN, "Adding 1st contact");
		else if (_num_contact == 1)
			print_msg(CYAN, "Adding 2nd contact");
		else if (_num_contact == 2)
			print_msg(CYAN, "Adding 3rd contact");
		else
			print_msg(CYAN, "Adding ", _num_contact + 1, "th contact");
	}
	else
	{
		print_msg(CYAN, "The limit of the number of contact is 8");
		print_msg(CYAN, "The oldest one will be replaced by the new one");
		if (_num_contact % (MAX_CONTACT) == 0)
			print_msg(CYAN, "Replacing 1st contact");
		else if (_num_contact % (MAX_CONTACT) == 1)
			print_msg(CYAN, "Replacing 2nd contact");
		else if (_num_contact % (MAX_CONTACT) == 2)
			print_msg(CYAN, "Replacing 3rd contact");
		else
			print_msg(CYAN, "Replacing ", _num_contact % (MAX_CONTACT) + 1, "th contact");
	}
	Contact.add();
	_Contact[_num_contact % MAX_CONTACT] = Contact;
	_num_contact++;
}

void	PhoneBook::search(void)
{
	std::string	input;
	std::string	check;
	int		int_input;

	show_phonebook_list();
	if (_num_contact == 0)
		return ;
	while (1)
	{
		print_msg(CYAN, "Please type a index number you want to see more");
		show_prompt('>');
		std::getline(std::cin, input);
		if (input.length() != 1 || !(0 <= input[0] - 48 && input[0] - 48 <= 9))
		{
			print_msg(RED, "Invalid command");
			continue ;
		}
		if (input[0] - 48 == 0
			|| (_num_contact <= 8 && input[0] - 48 > _num_contact)
			|| (_num_contact > 8 && input[0] - 48 > 8))
		{
			print_msg(RED, "Index is out of range");
			continue ;
		}
		print_msg(YELLOW, "You selected index ", input[0] - 48);
		print_msg(CYAN, "If it is right, please type Y. Otherwise, please type N");
		show_prompt('>');
		std::getline(std::cin, check);
		while (check != "Y" && check != "N")
		{
			print_msg(RED, "Invalid command: Please type Y or N");
			show_prompt('>');
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

void	PhoneBook::show_phonebook_list(void)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;

	if (_num_contact == 0)
	{
		print_msg(RED, "Phonebook is empty now");
		print_msg(RED, "Please add at least one contact and then search");
	}
	else
	{
		print_msg(YELLOW, "* YOU ARE SEARCHING PHONE BOOK *");
		std::cout << CYAN
			<< std::setw(10) << "index" << '|'
			<< std::setw(10) << "first name" << '|'
			<< std::setw(10) << "last name" << '|'
			<< std::setw(10) << "nickname" << BLACK << std::endl;
		print_msg(CYAN, "-------------------------------------------");
		for (int i = 0; i < _num_contact; i++)
		{
			first_name = _Contact[i % MAX_CONTACT].get_value(FIRST_NAME);
			last_name = _Contact[i % MAX_CONTACT].get_value(LAST_NAME);
			nickname = _Contact[i % MAX_CONTACT].get_value(NICKNAME);
			if (first_name.length() > 10)
			{
				first_name = first_name.substr(0, 9);
				first_name += '.';
			}
			if (last_name.length() > 10)
			{
				last_name = last_name.substr(0, 9);
				last_name += '.';
			}
			if (nickname.length() > 10)
			{
				nickname = nickname.substr(0, 9);
				nickname += '.';
			}
			if (i <= 7)
			{
				std::cout << CYAN
					<< std::setw(10) << (i % MAX_CONTACT) + 1 << '|'
					<< std::setw(10) << first_name << '|'
					<< std::setw(10) << last_name << '|'
					<< std::setw(10) << nickname  << BLACK << std::endl;
			}
		}
	}
}
