/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:16:34 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/20 01:44:56 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/AForm.hpp"

AForm::AForm(): _name(""), _signed(false), _grade_sign(1), _grade_execute(1), _signed_str("N")
{
}

AForm::AForm(std::string name, const int grade_sign, const int grade_execute)
			: _name(name), _signed(false), _grade_sign(grade_sign), _grade_execute(grade_execute), _signed_str("N")
{
	try
	{
		if (grade_sign < 1 || grade_execute < 1)
			throw (GradeTooHighException());
		else if (grade_sign > 150 || grade_execute > 150)
			throw (GradeTooLowException());
	}
	catch(std::exception& e)
	{
		std::cerr << RED << e.what() << BLACK << std::endl;
	}
}

AForm::AForm(const AForm& aform): _grade_sign(1), _grade_execute(1)
{
	*this = aform;
}

AForm& AForm::operator=(const AForm& aform)
{
	if (this == &aform)
		return (*this);
	this->_signed = aform.get_signed();
	return (*this);
}

AForm::~AForm()
{
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("grade is too high");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("grade is too low");
}

const char*	AForm::IsAlreadySignedException::what(void) const throw()
{
	return ("this form is already signed");
}

const char*	AForm::IsNotSignedException::what(void) const throw()
{
	return ("this form is not signed");
}

const std::string	AForm::get_name(void) const
{
	return (_name);
}

bool	AForm::get_signed(void) const
{
	return (_signed);
}

int	AForm::get_grade_sign(void) const
{
	return (_grade_sign);
}

int	AForm::get_grade_execute(void) const
{
	return (_grade_execute);
}

std::string	AForm::get_signed_str(void) const
{
	return (_signed_str);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (get_grade_sign() < bureaucrat.getGrade())
		throw (GradeTooLowException());
	if (get_signed() == true)
		throw (IsAlreadySignedException());
	_signed = true;
	_signed_str = "Y";
}

void	AForm::check_executable(const Bureaucrat& bureaucrat) const
{
	if (get_grade_sign() < bureaucrat.getGrade())
		throw (GradeTooLowException());
	if (get_grade_execute() < bureaucrat.getGrade())
		throw (GradeTooLowException());
	if (get_signed() == false)
		throw (IsNotSignedException());
}

std::ostream&	operator<<(std::ostream& ostream, const AForm& aform)
{
	ostream << "form " << aform.get_name() << " has information of" << std::endl
		<< "\tsigned: " << aform.get_signed_str() << std::endl
		<< "\tgrade required to sign it: " << aform.get_grade_sign() << std::endl
		<< "\tgrade required to execute it: " << aform.get_grade_execute() << std::endl;
	return (ostream);
}
