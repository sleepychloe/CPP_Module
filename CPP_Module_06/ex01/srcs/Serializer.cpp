/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:14:52 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/21 06:52:45 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& serializer)
{
	*this = serializer;
}

Serializer& Serializer::operator=(const Serializer& serializer)
{
	if (this == &serializer)
		return (*this);
	return (*this);
}

Serializer::~Serializer()
{
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t	res;

	res = reinterpret_cast<uintptr_t>(ptr);
	return (res);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	Data*	res;

	res = reinterpret_cast<Data *>(raw);
	return (res);
}
