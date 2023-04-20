/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:01:48 by yhwang            #+#    #+#             */
/*   Updated: 2023/04/20 22:49:07 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <vector>
#include <list>

# define BLACK			"\x1b[0m"
# define RED			"\x1b[31m"
# define CYAN			"\x1b[36m"
# define YELLOW			"\x1b[33m"

class	PmergeMe
{
public:
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe& pmergeme);
	PmergeMe& operator=(const PmergeMe& pmergeme);
	~PmergeMe();

	std::vector<int>	get_vector_container(void) const;
	std::list<int>		get_list_container(void) const;
	
	void			print_vector_container(void);
	void			print_list_container(void);

	void			sort_vector(void);
	void			merge_sort_vector(void);
	void			insert_sort_vector(int left, int right);

private:
	PmergeMe();
	int			check_int(char *str);
	void			parse(int argc, char **argv);

	void			combine_vector(int left, int mid, int right);
	void			divide_vector(int left, int right);

	std::vector<int>	_vector_container;
	std::list<int>		_list_container;
};

#endif
