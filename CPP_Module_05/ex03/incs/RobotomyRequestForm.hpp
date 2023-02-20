/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:13:37 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/20 02:14:20 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include <ctime>
#include <cstdlib>
#include "./Bureaucrat.hpp"
#include "./AForm.hpp"

class	Bureaucrat;

class	RobotomyRequestForm: public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& robotomyrequestform);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& robotomyrequestform);
	~RobotomyRequestForm();

	std::string		get_target(void) const;
	virtual void		execute(Bureaucrat const & executor) const;

private:
	std::string		_target;
};

std::ostream&	operator<<(std::ostream& ostream, const RobotomyRequestForm& robotomyrequestform);

#endif
