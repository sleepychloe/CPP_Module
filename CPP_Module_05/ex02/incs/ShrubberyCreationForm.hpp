/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:43:46 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/20 01:41:46 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRY_CREATION_FORM_HPP
# define SHRUBERRY_CREATION_FORM_HPP

#include <fstream>
#include "./Bureaucrat.hpp"
#include "./AForm.hpp"

class	Bureaucrat;

class	ShruberryCreationForm: public AForm
{
public:
	ShruberryCreationForm();
	ShruberryCreationForm(std::string target);
	ShruberryCreationForm(const ShruberryCreationForm &shruberrycreationform);
	ShruberryCreationForm& operator=(const ShruberryCreationForm &shruberrycreationform);
	~ShruberryCreationForm();

	std::string		get_target(void) const;
	virtual void		execute(Bureaucrat const& executor) const;

private:
	std::string		_target;
};

std::ostream&	operator<<(std::ostream& ostream, const ShruberryCreationForm& shruberrycreationform);

#endif
