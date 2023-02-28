/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 06:52:13 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/28 08:02:15 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "../incs/MutantStack.hpp"

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

int	main(int argc, char **argv)
{
	(void)argv;
	/* error check: argument */
	if (argc != 1)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}

	{
		std::cout << CYAN << "[ test 1 ]" << BLACK << std::endl;
	
		MutantStack<int>	mstack;
		mstack.push(5);
		std::cout << YELLOW << "5 is added" << BLACK << std::endl;
		mstack.push(17);
		std::cout << YELLOW << "17 is added" << BLACK << std::endl;

		std::cout << "top: ";
		std::cout << mstack.top() << std::endl; //result: 17

		mstack.pop(); //remove the 5(top)
		std::cout << RED << "top removed" << BLACK << std::endl;

		std::cout << "size is: ";
		std::cout << mstack.size() << std::endl;

		std::cout << "top: ";
		std::cout << mstack.top() << std::endl; //result: 5
		std::cout << std::endl;


		mstack.push(3);
		std::cout << YELLOW << "3 is added" << BLACK << std::endl;
		mstack.push(5);
		std::cout << YELLOW << "5 is added" << BLACK << std::endl;
		mstack.push(737);
		std::cout << YELLOW << "737 is added" << BLACK << std::endl;
		mstack.push(0);
		std::cout << YELLOW << "0 is added" << BLACK << std::endl;
		std::cout << std::endl;

		MutantStack<int>::iterator	it = mstack.begin();
		MutantStack<int>::iterator	ite = mstack.end();
		++it;
		--it;
		std::cout << CYAN << "stack: ";
		while (it != ite)
		{
			std::cout << *it << ' ';
			++it;
		}
		std::cout << BLACK << std::endl;
		
		std::stack<int>	s(mstack);
		MutantStack<int>::iterator	it_ = mstack.begin();
		MutantStack<int>::iterator	ite_ = mstack.end();
		std::cout << CYAN << "stack: ";
		while (it_ != ite_)
		{
			std::cout << *it_ << ' ';
			++it_;
		}
		std::cout << BLACK << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << CYAN << "[ test 2 ]" << BLACK << std::endl;
	
		std::list<int>	list;
		list.push_back(5);
		std::cout << YELLOW << "5 is added" << BLACK << std::endl;
		list.push_back(17);
		std::cout << YELLOW << "17 is added" << BLACK << std::endl;

		std::cout << "back: ";
		std::cout << list.back() << std::endl; //result: 17

		list.pop_back(); //remove the 5(top)
		std::cout << RED << "back removed" << BLACK << std::endl;

		std::cout << "size is: ";
		std::cout << list.size() << std::endl;

		std::cout << "back: ";
		std::cout << list.back() << std::endl; //result: 5
		std::cout << std::endl;


		list.push_back(3);
		std::cout << YELLOW << "3 is added" << BLACK << std::endl;
		list.push_back(5);
		std::cout << YELLOW << "5 is added" << BLACK << std::endl;
		list.push_back(737);
		std::cout << YELLOW << "737 is added" << BLACK << std::endl;
		list.push_back(0);
		std::cout << YELLOW << "0 is added" << BLACK << std::endl;
		std::cout << std::endl;

		std::list<int>::iterator	it = list.begin();
		std::list<int>::iterator	ite = list.end();
		++it;
		--it;
		std::cout << CYAN << "stack: ";
		while (it != ite)
		{
			std::cout << *it << ' ';
			++it;
		}
		std::cout << BLACK << std::endl;
	}

	return (0);
}
