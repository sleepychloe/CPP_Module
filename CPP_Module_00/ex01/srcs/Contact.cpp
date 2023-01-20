/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:54:49 by yhwang            #+#    #+#             */
/*   Updated: 2023/01/20 23:31:14 by yhwang           ###   ########.fr       */
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

int	Contact::add(void)
{
	std::string	check;

	for (int i = 0; i < MAX_FIELD; i++)
	{
		if (add_element(_contact, i))
			return (1);
	}
	show_input();
	print_msg(CYAN, "If you want to change somethig, please type the corresponding number");
	print_msg(CYAN, "Otherwise, please type Y");
	while (1)
	{
		show_prompt('>');
		std::getline(std::cin, check);
		/* normal operation: 1, 2, 3, 4, or 5 */
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
		
		/* error */
		else
		{
			/* error check: eof */
			if (std::cin.eof())
			{
				print_eof_msg();
				return (1);
			}
			else
			{
				/* error check: empty string */
				if (check == "")
					print_empty_str_msg();
				/* error check: invalid comand */
				else
					print_invalid_cmd_msg();
			}
			continue ;
		}
		show_input();
		print_msg(CYAN, "If you want to change somethig, please type the corresponding number");
		print_msg(CYAN, "Otherwise, please type Y");
		continue ;
	}
	return (0);
}

std::string	Contact::get_value(int i)
{
	return (_contact[i]);
}

void	Contact::search(void)
{
	print_msg(YELLOW, "first name:\t  ", get_value(FIRST_NAME));
	print_msg(YELLOW, "last name:\t  ", get_value(LAST_NAME));
	print_msg(YELLOW, "nickname:\t  ", get_value(NICKNAME));
	print_msg(YELLOW, "phone number:\t  ", get_value(PHONE_NUMBER));
	print_msg(YELLOW, "darkest secret:\t  ", get_value(DARKEST_SECRET));
}

Contact::~Contact()
{
	
}

int	Contact::add_element(std::string *contact, int i)
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
		print_msg(YELLOW, "    Please type ", str);
		show_prompt(':');
		std::getline(std::cin, contact[i]);

		/* error check: eof */
		if (std::cin.eof())
		{
			print_eof_msg();
			return (1);
		}
		/* error check: empty string */
		else if (contact[i] == "")
		{
			print_msg(RED, "    ", str, " should not be empty");
			continue ;
		}
		/* normal orperation */
		else
			break ;
	}
	/* check error: invalid command */
	if (i == FIRST_NAME || i == LAST_NAME || i == PHONE_NUMBER)
		check_valid_input(contact, i, str);
	return (0);
}

void	Contact::check_valid_input(std::string *contact, int i, std::string str)
{
	int		j;

	j = 0;
	/* invalid command check: it should be consist of alphabets */
	if (i == FIRST_NAME || i == LAST_NAME)
	{
		while (j < (int)contact[i].length())
		{			
			if ((!((65 <= contact[i][j] && contact[i][j] <= 90)
				|| (97 <= contact[i][j] && contact[i][j] <= 122))))
			{
				print_msg(RED, "    ", str, " should be consist of alphabets");
				add_element(contact, i);
			}
			else
				j++;
		}
	}
	/* invalid command check: it should be consist of number */
	else if (i == PHONE_NUMBER)
	{
		while (j < (int)contact[i].length())
		{			
			if (!(0 <= contact[i][j] - 48 && contact[i][j] - 48 <= 9))
			{
				print_msg(RED, "    ", str, " should be consist of number");
				add_element(contact, i);
			}
			else
				j++;
		}
	}
}

void	Contact::show_input(void)
{
	print_msg(YELLOW, "Your input is");
	print_msg(YELLOW, "    1. First name:\t", _contact[FIRST_NAME]);
	print_msg(YELLOW, "    2. Last name:\t", _contact[LAST_NAME]);
	print_msg(YELLOW, "    3. Nickname:\t", _contact[NICKNAME]);
	print_msg(YELLOW, "    4. Phone number:\t", _contact[PHONE_NUMBER]);
	print_msg(YELLOW, "    5. Darkest secret:\t", _contact[DARKEST_SECRET]);
}
