/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:13:33 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/20 03:25:18 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "./AForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

class	Intern
{
public:
	Intern();
	Intern(std::string form, std::string target);
	Intern(const Intern& intern);
	Intern& operator=(const Intern& intern);
	~Intern();

	class	NoTargetNameException: public std::exception
	{
	public:
		virtual const char*	what(void) const throw();
	};

	class	NotMatchFormNameException: public std::exception
	{
	public:
		virtual const char*	what(void) const throw();
	};

	std::string	get_form(void) const;
	std::string	get_target(void) const;

	int		get_form_flag(std::string form);

	AForm*		makeForm(std::string form, std::string target);

private:
	std::string	_form;
	std::string	_target;
};

#endif
