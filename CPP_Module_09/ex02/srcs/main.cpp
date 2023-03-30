/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:02:01 by yhwang            #+#    #+#             */
/*   Updated: 2023/03/30 04:49:56 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << RED << "Error: Argument error" << BLACK << std::endl;
		return (1);
	}

	try
	{
		PmergeMe	p(argc, argv);
		p.print_vector_container();
		p.print_list_container();
		p.merge_sort_vector();
		std::cout << std::endl;
		p.print_vector_container();
	}
	catch (std::string err_msg)
	{
		std::cout << RED << "Error: " << err_msg << BLACK << std::endl;
	}
	
	return (0);
}