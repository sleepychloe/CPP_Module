/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:52:34 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/25 07:47:27 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# define FIRST_NAME		0
# define LAST_NAME		1
# define NICKNAME		2
# define PHONE_NUMBER		3
# define DARKEST_SECRET		4

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

#include <iostream>
#include <string>
#include "./utils.hpp"

class Contact
{
public:
	Contact();
	void		add(void);
	std::string	get_value(int i);
	void		search(void);
	~Contact();

private:
	std::string	_contact[5];

	void		add_element(std::string *contact, int i);
	void		check_valid_input(std::string *contact, int i, std::string str);
	void		show_input(void);
};

#endif
