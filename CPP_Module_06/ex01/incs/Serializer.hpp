/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:14:55 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/21 06:43:10 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <inttypes.h>

typedef	struct s_data
{
	unsigned int	u1;
	unsigned int	u2;
	unsigned int	u3;
}	Data;

class	Serializer
{
public:
	Serializer();
	Serializer(const Serializer& serializer);
	Serializer& operator=(const Serializer& serializer);
	~Serializer();

	uintptr_t	serialize(Data* ptr);
	Data*		deserialize(uintptr_t raw);

};

#endif
