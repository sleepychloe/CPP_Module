/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:15:22 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/20 02:16:51 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
			: AForm("RobotomyRequestForm", 72, 45), _target("")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
			: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& robotomyrequestform)
			: AForm(robotomyrequestform)
{
	*this = robotomyrequestform;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& robotomyrequestform)
{
	if (this == &robotomyrequestform)
		return (*this);
	AForm::operator=(robotomyrequestform);
	this->_target = robotomyrequestform.get_target();
	return (*this);	
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string	RobotomyRequestForm::get_target(void) const
{
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	check_executable(executor);
	std::cout << "<noise drill sound>" << std::endl;

	int	random;
	/* initialize random seed: */
	srand(time(NULL));
 	/* generate 0 or 1 randomly: probability 50%*/
 	random = rand() % 2;
	
	if (random == 0)
	{
		std::cout << CYAN << get_target()
			<< " has been successfully robotomized" << BLACK << std::endl;
	}
	else
	{
		std::cout << RED << "robotomy failed on "
			<< get_target() << BLACK << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& ostream, const RobotomyRequestForm& robotomyrequestform)
{
	ostream << "form " << robotomyrequestform.get_name() << " has information of" << std::endl
		<< "\tsigned: " << robotomyrequestform.get_signed_str() << std::endl
		<< "\tgrade required to sign it: " << robotomyrequestform.get_grade_sign() << std::endl
		<< "\tgrade required to execute it: " << robotomyrequestform.get_grade_execute() << std::endl;
	return (ostream);
}
