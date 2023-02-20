/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:15:53 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/20 00:23:57 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
# define A_FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "./Bureaucrat.hpp"

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"
# define YELLOW			"\x1b[33m"

class	Bureaucrat;

class	AForm
{
public:
	AForm();
	AForm(std::string name, const int grade_sign, const int grade_execute);
	AForm(const AForm& aform);
	AForm& operator=(const AForm& aform);
	virtual ~AForm();

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

	class	IsAlreadySignedException: public std::exception
	{
	public:
		virtual const char*	what(void) const throw();
	};

	class	IsNotSignedException: public std::exception
	{
	public:
		virtual const char*	what(void) const throw();
	};

	const std::string	get_name(void) const;
	bool			get_signed(void) const;
	int			get_grade_sign(void) const;
	int			get_grade_execute(void) const;

	std::string		get_signed_str(void) const;
	void			check_executable(const Bureaucrat& Bureaucrat) const;

	void			beSigned(const Bureaucrat& bureaucrat);
	virtual void		execute(Bureaucrat const& executor) const = 0;

private:
	const std::string	_name;
	bool			_signed;
	const int		_grade_sign;
	const int		_grade_execute;

	std::string		_signed_str;

};

std::ostream&	operator<<(std::ostream& ostream, const AForm& aform);

#endif
