/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 00:55:31 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/18 05:08:58 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name(""), _grade(0)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
	}
	catch(std::exception& exception)
	{
		std::cout << RED << exception.what() << BLACK << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
{
	*this = bureaucrat;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	if (this == &bureaucrat)
		return (*this);
	this->_grade = bureaucrat.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Error: Grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Error: Grade is too low");
}

const std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::set_grade(int grade)
{
	_grade = grade;
}

void	Bureaucrat::increment_grade(void)
{
	try
	{
		if (_grade - 1 < 1)
			throw GradeTooHighException();
	}
	catch (const std::exception& exception)
	{
		std::cout << RED << exception.what() << BLACK << std::endl;
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
	catch (const std::exception& exception)
	{
		std::cout << RED << exception.what() << BLACK << std::endl;
	}
	_grade++;
}

std::ostream&	operator<<(std::ostream& ostream, const Bureaucrat& bureaucrat)
{
	ostream << bureaucrat.getName()
		<< ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (ostream);
}
