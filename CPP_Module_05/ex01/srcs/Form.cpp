/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:04:33 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/19 04:54:40 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Form.hpp"

Form::Form(): _name(""), _signed(false), _grade_sign(1), _grade_execute(1), _signed_str("N")
{
}

Form::Form(std::string name, const int grade_sign, const int grade_execute)
			: _name(name), _grade_sign(grade_sign), _grade_execute(grade_execute), _signed_str("N")
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

Form::Form(const Form& form): _grade_sign(1), _grade_execute(1)
{
	*this = form;
}

Form& Form::operator=(const Form& form)
{
	if (this == &form)
		return (*this);
	this->_signed = form.get_signed();
	return (*this);
}

Form::~Form()
{
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

const char*	Form::IsAlreadySigned::what(void) const throw()
{
	return ("This form is already signed");
}

const std::string	Form::get_name(void) const
{
	return (_name);
}

bool	Form::get_signed(void) const
{
	return (_signed);
}

int	Form::get_grade_sign(void) const
{
	return (_grade_sign);
}

int	Form::get_grade_execute(void) const
{
	return (_grade_execute);
}

std::string	Form::get_signed_str(void) const
{
	return (_signed_str);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (get_grade_sign() < bureaucrat.getGrade())
		throw (GradeTooLowException());
	_signed = true;
	_signed_str = "Y";
}

std::ostream&	operator<<(std::ostream& ostream, const Form& form)
{
	ostream << "form " << form.get_name() << " has information of" << std::endl
		<< "\tsigned: " << form.get_signed_str() << std::endl
		<< "\tgrade required to sign it: " << form.get_grade_sign() << std::endl
		<< "\tgrade required to execute it: " << form.get_grade_execute() << std::endl;
	return (ostream);
}
