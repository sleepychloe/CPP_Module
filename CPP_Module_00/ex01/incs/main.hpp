/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:05:57 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/25 07:43:55 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

#include <iostream>
#include <string>
#include "./PhoneBook.hpp"
#include "./Contact.hpp"
#include "./utils.hpp"

void		argument_err_exit(void);
int		main(int argc, char **argv);

#endif
