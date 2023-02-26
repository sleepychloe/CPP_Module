/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 03:36:47 by yhwang            #+#    #+#             */
/*   Updated: 2023/02/26 05:53:21 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template <typename T>
class	Array
{
public:
	Array(): _array(NULL), _size(0) {};
	Array(unsigned int n): _array(new T[n]), _size(n) {};
	Array(const Array& array): _array(NULL), _size(0)
	{
		*this = array;
	};
	Array& operator=(const Array& array)
	{
		if (this == &array)
			return (*this);
		if (_array != NULL)
			delete[] _array;
		this->_size = array.size();
		if (_size == 0)
			return (*this);
		_array = new T[_size];
		for (unsigned int i = 0; i < _size ; i++)
			_array[i] = array._array[i];
		return (*this);
	};
	~Array()
	{
		if (_array != NULL)
			delete[] _array;
	};

	class	OutOfBoundsException: public std::exception
	{
	public:
		virtual const char*	what(void) const throw()
		{
			return ("Index is out of bounds");
		};
	};

	T&	operator[](unsigned int n)
	{
		if (n < 0)
			throw (OutOfBoundsException());
		if (n >= _size)
			throw (OutOfBoundsException());
		return (_array[n]);
	}

	unsigned int	size(void) const
	{
		return (_size);
	}

private:
	T*		_array;
	unsigned int	_size;

};

#endif
