/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:03:17 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/19 04:54:54 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name(""), _grade(1)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	try
	{
		if (grade < 1)
			throw (GradeTooHighException());
		else if (grade > 150)
			throw (GradeTooLowException());
	}
	catch(std::exception& e)
	{
		std::cerr << RED << e.what() << BLACK << std::endl;
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
{
	*this = bureaucrat;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	if (this == &bureaucrat)
		return (*this);
	/* cannot copy name because _name is constant string */
	this->_grade = bureaucrat.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::increment_grade(void)
{
	try
	{
		if (_grade - 1 < 1)
			throw GradeTooHighException();
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << BLACK << std::endl;
	}
	_grade--;
}

void	Bureaucrat::decrement_grade(void)
{
	try
	{
		if (_grade + 1 > 150)
			throw GradeTooLowException();
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << BLACK << std::endl;
	}
	_grade++;
}

void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		if (form.get_signed() == true)
			std::cout << getName() << " signed " << form.get_name() << std::endl;
		else
		{
			std::cout << getName() << " couldn't sign " << form.get_name()
			<< " because ";
			form.beSigned(*this);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << BLACK << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& ostream, const Bureaucrat& bureaucrat)
{
	ostream << bureaucrat.getName()
		<< ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (ostream);
}
