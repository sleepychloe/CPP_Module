/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:04:26 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/19 04:46:54 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "./Bureaucrat.hpp"

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"

class	Bureaucrat;

class	Form
{
public:
	Form();
	Form(std::string name, const int grade_sign, const int grade_execute);
	Form(const Form& form);
	Form& operator=(const Form& form);
	~Form();

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

	class	IsAlreadySigned: public std::exception
	{
	public:
		virtual const char*	what(void) const throw();
	};


	const std::string	get_name(void) const;
	bool			get_signed(void) const;
	int			get_grade_sign(void) const;
	int			get_grade_execute(void) const;

	std::string		get_signed_str(void) const;

	void			beSigned(const Bureaucrat& bureaucrat);

private:
	const std::string	_name;
	bool			_signed;
	const int		_grade_sign;
	const int		_grade_execute;

	std::string		_signed_str;

};

std::ostream&	operator<<(std::ostream &ostream, const Form& form);

#endif
