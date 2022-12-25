/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 07:43:09 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/25 08:30:16 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

#include <iostream>
#include <string>

void		argument_err_exit(void);
void		print_msg(std::string color, std::string msg);
void		print_msg(std::string color, std::string msg, int n);
void		print_msg(std::string color, std::string msg1, int n, std::string msg2);
void		print_msg(std::string color, std::string msg, std::string s);
void		print_msg(std::string color, std::string msg1, std::string s, std::string msg2);
void		show_prompt(char c);

#endif
