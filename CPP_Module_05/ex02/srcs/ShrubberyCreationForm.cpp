/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:43:42 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/20 01:54:14 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ShrubberyCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm()
			: AForm("ShruberryCreationForm", 145, 137), _target("")
{
}

ShruberryCreationForm::ShruberryCreationForm(std::string target)
			: AForm("ShruberryCreationForm", 145, 137), _target(target)
{
}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm& shruberrycreationform)
			: AForm(shruberrycreationform)
{
	*this = shruberrycreationform;
}

ShruberryCreationForm& ShruberryCreationForm::operator=(const ShruberryCreationForm& shruberrycreationform)
{
	if (this == &shruberrycreationform)
		return (*this);
	AForm::operator=(shruberrycreationform);
	this->_target = shruberrycreationform.get_target();
	return (*this);
}

ShruberryCreationForm::~ShruberryCreationForm()
{
}

std::string	ShruberryCreationForm::get_target(void) const
{
	return (_target);
}

void	ShruberryCreationForm::execute(Bureaucrat const& executor) const
{
	check_executable(executor);

	std::string	file_name = get_target() + "_shrubbery";
	std::ofstream	f_write;

	f_write.open(file_name.c_str(), std::ios::out);
	if (f_write.fail())
	{
		std::cout << "Error: file open error" << std::endl
			<< "Something is wrong with making " << file_name << std::endl;
		return ;
	}
	std::cout << CYAN << "Drawing a ascii tree... " << BLACK;

	f_write << "          &&& &&  & &&" << std::endl;
	f_write << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
	f_write << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	f_write << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
	f_write << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	f_write << "&&   && & &| &| /& & % ()& /&&" << std::endl;
	f_write << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	f_write << "     &&     \\|||" << std::endl;
	f_write << "             |||" << std::endl;
	f_write << "             |||" << std::endl;
	f_write << "             |||" << std::endl;
	f_write << "       , -=-~  .-^- _" << std::endl;

	std::cout << CYAN
		<< get_target() << "_shrubbery has been created!" << BLACK << std::endl;
	f_write.close();
}

std::ostream&	operator<<(std::ostream& ostream, const ShruberryCreationForm& shruberrycreationform)
{
	ostream << "form " << shruberrycreationform.get_name() << " has information of" << std::endl
		<< "\tsigned: " << shruberrycreationform.get_signed_str() << std::endl
		<< "\tgrade required to sign it: " << shruberrycreationform.get_grade_sign() << std::endl
		<< "\tgrade required to execute it: " << shruberrycreationform.get_grade_execute() << std::endl;
	return (ostream);
}
