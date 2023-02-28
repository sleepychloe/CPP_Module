/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 07:50:54 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/28 06:46:57 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include "../incs/Span.hpp"

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

	srand(time(NULL));
	int	random;
	{
		std::cout << CYAN << "[ test 1 ]" << BLACK << std::endl;
		
		Span	s = Span(5);
		int	i;
		try
		{
			for (i = 0; i < 6; i++)
			{
				random = rand() % 100;
				if (random % 3 == 1)
					random *= -1;
				s.addNumber(random);
				std::cout << i + 1 << ": added" << std::endl;
			}
		}
		catch (std::exception& e)
		{
			std::cerr << i + 1 << ": " << RED
				<< e.what() << BLACK << std::endl;
		}
		std::cout << std::endl;
		std::cout << YELLOW << "Span: ";
		s.print();
		std::cout << BLACK;

		try
		{
			std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}

		try
		{
			std::cout << "longest span:  " << s.longestSpan() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << CYAN << "[ test 2 ]" << BLACK << std::endl;
		
		Span	s = Span(0);
		int	i;
		try
		{
			for (i = 0; i < 6; i++)
			{
				random = rand() % 100;
				if (random % 3 == 1)
					random *= -1;
				s.addNumber(random);
				std::cout << i + 1 << ": added" << std::endl;
			}
		}
		catch (std::exception& e)
		{
			std::cerr << i + 1 << ": " << RED
				<< e.what() << BLACK << std::endl;
		}
		std::cout << std::endl;
		std::cout << YELLOW << "Span: ";
		s.print();
		std::cout << BLACK;

		try
		{
			std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}

		try
		{
			std::cout << "longest span:  " << s.longestSpan() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}
	}

	std::cout << std::endl;
	
	{
		std::cout << CYAN << "[ test 3 ]" << BLACK << std::endl;
		
		Span	s = Span(1);
		int	i;
		try
		{
			for (i = 0; i < 6; i++)
			{
				random = rand() % 100;
				if (random % 3 == 1)
					random *= -1;
				s.addNumber(random);
				std::cout << i + 1 << ": added" << std::endl;
			}
		}
		catch (std::exception& e)
		{
			std::cerr << i + 1 << ": " << RED
				<< e.what() << BLACK << std::endl;
		}
		std::cout << std::endl;
		std::cout << YELLOW << "Span: ";
		s.print();
		std::cout << BLACK;

		try
		{
			std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}

		try
		{
			std::cout << "longest span:  " << s.longestSpan() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << CYAN << "[ test 4 ]" << BLACK << std::endl;
		
		Span	s = Span(20000);
		int	i;
		try
		{
			for (i = 0; i < 20000; i++)
			{
				random = rand();
				if (random % 3 == 1)
					random *= -1;
				s.addNumber(random);
				//std::cout << i + 1 << ": added" << std::endl;
			}
		}
		catch (std::exception& e)
		{
			std::cerr << i + 1 << ": " << RED
				<< e.what() << BLACK << std::endl;
		}
		//std::cout << std::endl;
		std::cout << YELLOW << "Span: ";
		s.print();
		std::cout << BLACK;

		try
		{
			std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}

		try
		{
			std::cout << "longest span:  " << s.longestSpan() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << CYAN << "[ test 5 ]" << BLACK << std::endl;
		
		Span	s = Span(10000);
		std::vector<int>	v(10000, 42);
		int	i;
		try
		{
			s.fill(v.begin(), v.end());
		}
		catch (std::exception& e)
		{
			std::cerr << i + 1 << ": " << RED
				<< e.what() << BLACK << std::endl;
		}
		//std::cout << std::endl;
		std::cout << YELLOW << "Span: ";
		s.print();
		std::cout << BLACK;

		try
		{
			std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}

		try
		{
			std::cout << "longest span:  " << s.longestSpan() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
		}
	}
	return (0);
}
