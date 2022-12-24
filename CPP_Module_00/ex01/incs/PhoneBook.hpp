/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:00:13 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/24 06:52:24 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX_CONTACT		8

#include <iostream>
#include <string>
#include <iomanip>
#include "./Contact.hpp"

class PhoneBook
{
	public:

	PhoneBook();
	void		add(void);
	void		search(void);
	~PhoneBook();

	private:

	int		_num_contact;
	Contact		_Contact[MAX_CONTACT];
	void		show_phonebook_list(void);
};

#endif
