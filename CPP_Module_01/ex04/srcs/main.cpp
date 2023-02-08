/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:40:04 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/06 15:13:22 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/replace.h"

int	main(int argc, char **argv)
{
	/* error check: argument error */
	if (argc != 4)
	{
		std::cout << "Error: arument error" << std::endl
			<< "(command: ./replace [filename] [s1] [s2])" << std::endl;
		return (1);
	}

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	/* declare filestream object to read from file and to write to file */
	std::ifstream	f_read;
	std::ofstream	f_write;

	/* open */
	f_read.open(filename.c_str(), std::ios::in);
	
	/* error check: file open */
	if (f_read.fail())
	{
		std::cout << "Error: file open error" << std::endl
			<< "Please put exist file name" << std::endl;
		return (1);
	}
	if (f_write.fail())
	{
		std::cout << "Error: file open error" << std::endl
			<< "Something is wrong with making " << filename << ".replace" << std::endl;
		f_read.close();
		return (1);
	}

	f_write.open((filename + ".replace").c_str(), std::ios::out | std::ios::trunc);

	std::string	line;
	int		i = 0;
	while (std::getline(f_read, line))
	{
		/* replace each line */
		line = replace_line(line, s1, s2);
		f_write << line;
		if (!(f_read.eof()))
			f_write << std::endl;
		i++;
	}

	/* close */
	f_read.close();
	f_write.close();

	return (0);
}