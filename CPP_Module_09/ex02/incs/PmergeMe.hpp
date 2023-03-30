/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:01:48 by yhwang            #+#    #+#             */
/*   Updated: 2023/03/30 04:55:51 by yhwang           ###   ########.fr       */
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

	void			merge_sort_vector(void);//

private:
	PmergeMe();
	int			check_int(char *str);
	void			parse(int argc, char **argv);

	void			merge_vector(int left, int right);
	void			split_vector(int left, int right);
	//void			merge_sort_vector(void);
	void			insert_sort_vector(void);
	void			merge_insert_sort_vector(void);

	void			merge_sort_list(void);
	void			insert_sort_list(void);
	void			merge_insert_sort_list(void);

	std::vector<int>	_vector_container;
	std::list<int>		_list_container;
};

#endif
