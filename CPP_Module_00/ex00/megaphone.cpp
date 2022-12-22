/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 03:16:54 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/22 03:39:19 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl; 
	else
	{
		argv++;
		while (*argv)
		{
			while (**argv)
			{
				if (97 <= **argv && **argv <= 122)
					**argv =  **argv - 32;
				std::cout << **argv;
				(*argv)++;
			}
			argv++;
		}
		std::cout << std::endl;
	}
	return (0);
}
