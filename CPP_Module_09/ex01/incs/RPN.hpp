/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:54:29 by yhwang            #+#    #+#             */
/*   Updated: 2023/03/30 01:59:37 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iterator>
#include <stdexcept>

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

class	RPN
{
public:
	RPN(std::string input);
	RPN(const RPN& rpn);
	RPN& operator=(const RPN& rpn);
	~RPN();

	template <typename T>
	class IterableQueue : public std::queue<T>
	{
	public:
		IterableQueue() {}
		IterableQueue(const IterableQueue& iterablequeue): std::queue<T>(iterablequeue)
		{
			*this = iterablequeue;
		}
		IterableQueue& operator=(const IterableQueue& iterablequeue)
		{
			if (this == &iterablequeue)
				return (*this);
			std::queue<T>::operator=(iterablequeue);
			return (*this);
		}
		~IterableQueue() {};

		typedef typename std::queue<T>::container_type::iterator	iterator;
		typedef typename std::queue<T>::container_type::const_iterator	const_iterator;

		iterator	begin()
		{
			return (std::queue<T>::c.begin());
		}
		iterator	end()
		{
			return (std::queue<T>::c.end());
		}
		const iterator	begin() const
		{
			return (std::queue<T>::c.begin());
		}
		const iterator	end() const
		{
			return (std::queue<T>::c.end());
		}
	};

	class	EmptyInputException: public std::exception
	{
	public:
		virtual const char*	what(void) const throw();
	};

	class	InvalidInputException: public std::exception
	{
	public:
		virtual const char*	what(void) const throw();
	};

	class	InvalidCharacterException: public std::exception
	{
	public:
		virtual const char*	what(void) const throw();
	};

	IterableQueue<std::string>	get_input(void) const;
	IterableQueue<long>		get_temp(void) const;

private:
	RPN();

	int				check_int(std::string str);
	int				check_operator(std::string str);
	double				do_operation(void);
	int				rpn_calculate(void);
	void				parse(std::string input);

	IterableQueue<std::string>	_input;
	IterableQueue<long>		_temp;
};

#endif
