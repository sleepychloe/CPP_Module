/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:15:14 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/20 03:23:54 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
			: AForm("PresidentialPardonForm", 25, 5), _target("")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
			:AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& presidentialpardonform)
			:AForm(presidentialpardonform)
{
	*this = presidentialpardonform;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& presidentialpardonform)
{
	if (this == &presidentialpardonform)
		return (*this);
	AForm::operator=(presidentialpardonform);
	this->_target = presidentialpardonform.get_target();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string	PresidentialPardonForm::get_target(void) const
{
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	check_executable(executor);
	std::cout << CYAN << get_target()
		<< " has been pardoned by Zaphod Beeblebrox" << BLACK << std::endl;
}

std::ostream&	operator<<(std::ostream& ostream, const PresidentialPardonForm& presidentialpardonform)
{
	ostream << "form " << presidentialpardonform.get_name() << " has information of" << std::endl
		<< "\tsigned: " << presidentialpardonform.get_signed_str() << std::endl
		<< "\tgrade required to sign it: " << presidentialpardonform.get_grade_sign() << std::endl
		<< "\tgrade required to execute it: " << presidentialpardonform.get_grade_execute() << std::endl;
	return (ostream);
}
