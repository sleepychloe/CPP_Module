/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:02:01 by yhwang            #+#    #+#             */
/*   Updated: 2023/04/22 13:53:22 by yhwang           ###   ########.fr       */
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
		double		time_vector, time_list;

		PmergeMe	p(argc, argv);

		std::cout << YELLOW << "Before:\t" << BLACK;
		p.print_vector_container();
		
		gettimeofday(&tv, NULL);
		begin = (double)(tv.tv_sec) * 1000000 + (double)(tv.tv_usec);
		p.sort_vector();
		gettimeofday(&tv, NULL);
		end = (double)(tv.tv_sec) * 1000000 + (double)(tv.tv_usec);
		
		time_vector = end - begin;

		gettimeofday(&tv, NULL);
		begin = (double)(tv.tv_sec) * 1000000 + (double)(tv.tv_usec);
		//std::list<int>	sort;
		//p.get_list_container().merge(sort);
		p.sort_list();
		gettimeofday(&tv, NULL);
		end = (double)(tv.tv_sec) * 1000000 + (double)(tv.tv_usec);
		
		time_list = end - begin;

		unsigned long	value_check = 0;
		std::vector<int>		sorted_v = p.get_vector_container();
		std::list<int>			sorted_l = p.get_list_container();
		std::list<int>::iterator	it_l = sorted_l.begin();
		for (std::vector<int>::iterator it_v = sorted_v.begin();
			it_v != sorted_v.end(); it_v++)
		{
			if (*it_v == *it_l)
				value_check++;
			it_l++;
		}

		if (value_check != sorted_v.size())
		{
			std::cout << RED << "Error: failed to sort" << BLACK << std::endl;
			std::cout << CYAN;
			p.print_vector_container();
			std::cout << BLACK;
			std::cout << YELLOW;
			p.print_list_container();
			std::cout << BLACK;
			return (1);
		}

		std::cout << YELLOW << "After:\t" << CYAN;
		p.print_vector_container();
		std::cout << BLACK;

		std::cout << "Time to process a range of "
			<< YELLOW << p.get_vector_container().size() << BLACK
			<< " elements with " << YELLOW << "std::vector : " << BLACK
			<< YELLOW << time_vector << " us" << BLACK << std::endl;
		std::cout << "Time to process a range of "
			<< YELLOW << p.get_list_container().size() << BLACK
			<< " elements with " << YELLOW << "std::list   : " << BLACK
			<< YELLOW << time_list << " us" << BLACK << std::endl;
	}
	catch (std::string err_msg)
	{
		std::cout << RED << "Error: " << err_msg << BLACK << std::endl;
	}
	
	return (0);
}