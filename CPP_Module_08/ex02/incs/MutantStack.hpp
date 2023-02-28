/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 06:52:08 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/28 08:02:58 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <vector>
#include <stack>

/* stack: LIFO(Last In First Out)
template<class T, Class C = deque<T> >
class std::stack {
    protected:
        C c;

    public:
        typedef typename C::value_type value_type;
        typedef typename C::size_type size_type;
        typedef C container_type;

        explicit stack(const C& a = C()) : c(a){} // Inherit the constructor

        bool empty() const { return c.empty(); }
        size_type size() const { return c.size(); }
        value_type& top() const { return c.back(); }
        const value_type& top() const { return c.back(); }
        void push(const value_type& n) { c.push_back(n); }
        void pop() { c.pop_back(); }
};
*/

template <typename T>
class	MutantStack: public std::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack& mutantstack)
	{
		*this = mutantstack;
	}
	MutantStack& operator=(const MutantStack& mutantstack)
	{
		if (this == &mutantstack)
			return (*this);
		std::stack<T>::operator=(mutantstack);
		return (*this);
	}
	~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator	iterator;
	iterator	begin()
	{
		return (std::stack<T>::c.begin());
	}
	iterator	end()
	{
		return (std::stack<T>::c.end());
	}

};

#endif
