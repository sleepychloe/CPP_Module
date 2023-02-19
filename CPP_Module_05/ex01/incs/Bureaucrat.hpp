/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:02:52 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/19 03:15:52 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "./Form.hpp"

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"

class	Form;

class	Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& bureaucrat);
	Bureaucrat& operator=(const Bureaucrat& bureaucrat);
	~Bureaucrat();

	class	GradeTooHighException: public std::exception
	{
	public:
		virtual const char*	what(void) const throw();

	};
	
	class	GradeTooLowException: public std::exception
	{
	public:
		virtual const char*	what(void) const throw();
	};

	std::string		getName(void) const;
	int			getGrade(void) const;

	void			increment_grade(void);
	void			decrement_grade(void);

	void			signForm(Form& form) const;

private:
	const std::string	_name;
	int			_grade;
};

std::ostream&	operator<<(std::ostream &ostream, const Bureaucrat& bureaucrat);

#endif
