/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:02:01 by yhwang            #+#    #+#             */
/*   Updated: 2023/04/20 23:30:41 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <sys/time.h>
#include "../incs/PmergeMe.hpp"
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << RED << "Error: Argument error" << BLACK << std::endl;
		return (1);
	}

	try
	{
		struct timeval	tv;
		double		begin, end;
		double		time_vector;

		PmergeMe	p(argc, argv);	
		p.print_vector_container();
		
		gettimeofday(&tv, NULL);
		begin = (double)(tv.tv_sec) * 1000000 + (double)(tv.tv_usec);
		p.sort_vector();
		gettimeofday(&tv, NULL);
		end = (double)(tv.tv_sec) * 1000000 + (double)(tv.tv_usec);
		
		time_vector = end - begin;
		std::cout << std::endl;
		p.print_vector_container();
	
		std::cout << time_vector << " us" << std::endl;
	}
	catch (std::string err_msg)
	{
		std::cout << RED << "Error: " << err_msg << BLACK << std::endl;
	}
	
	return (0);
}