/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:54:29 by yhwang            #+#    #+#             */
/*   Updated: 2023/03/29 02:21:49 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <queue>
#include <deque>
#include <iterator>
#include <stdexcept>

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

class	RPN
{
public:
	RPN(char *input);
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

	IterableQueue<std::string>	get_input(void) const;
	IterableQueue<int>		get_temp(void) const;

private:
	RPN();
	int				check_int(std::string str);
	int				check_operator(std::string str);
	void				parse(char *input);
	int				do_operation(void);
	int				rpn_calculate(void);

	IterableQueue<std::string>	_input;
	IterableQueue<int>		_temp;
};

#endif
