/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:44:29 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/20 03:22:50 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTAL_PARDON_FORM_HPP
# define PRESIDENTAL_PARDON_FORM_HPP

#include "./Bureaucrat.hpp"
#include "./AForm.hpp"

class	Bureaucrat;

class	PresidentialPardonForm: public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& presidentialpardonform);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& presidentialpardonform);
	~PresidentialPardonForm();

	std::string		get_target(void) const;
	virtual void		execute(Bureaucrat const & executor) const;

private:
	std::string		_target;
};

std::ostream&	operator<<(std::ostream& ostream, const PresidentialPardonForm& presidentialpardonform);

#endif
