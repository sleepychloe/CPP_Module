/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 07:20:36 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/21 08:25:28 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

class	Base
{
public:
	virtual ~Base();
};

Base*	generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
