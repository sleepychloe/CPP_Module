/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:15:36 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/20 21:43:21 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Intern.hpp"

Intern::Intern(): _form(""), _target("")
{
}

Intern::Intern(std::string form, std::string target): _form(form), _target(target)
{
}

Intern::Intern(const Intern& intern)
{
	*this = intern;
}

Intern& Intern::operator=(const Intern& intern)
{
	if (this == &intern)
		return (*this);
	this->_form = intern.get_form();
	this->_target = intern.get_target();
	return (*this);
}

Intern::~Intern()
{
}

const char*	Intern::NoTargetNameException::what(void) const throw()
{
	return ("there is no target name");
}

const char*	Intern::NotMatchFormNameException::what(void) const throw()
{
	return ("can't find proper form with this form name");
}

std::string	Intern::get_form(void) const
{
	return (_form);
}

std::string	Intern::get_target(void) const
{
	return (_target);
}

int	Intern::get_form_flag(std::string form)
{
	std::string	form_name[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (form == form_name[i])
			return (i);
	}
	return (-1);
}

AForm*	Intern::makeForm(std::string form, std::string target)
{
	AForm		*form_ptr = NULL;
	int		flag = get_form_flag(form);

	try
	{
		if (target == "")
			throw (NoTargetNameException());
		switch(flag)
		{
			case 0:
				form_ptr = new ShruberryCreationForm(target);
				break ;

			case 1:
				form_ptr = new RobotomyRequestForm(target);
				break ;

			case 2:
				form_ptr = new PresidentialPardonForm(target);
				break ;

			default:
				form_ptr = NULL;
				throw (NotMatchFormNameException());
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Intern couldn't create a form because"
			<< e.what() << BLACK << std::endl;
	}
	return (form_ptr);
}
