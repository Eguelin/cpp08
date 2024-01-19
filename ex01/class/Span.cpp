/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:17:44 by eguelin           #+#    #+#             */
/*   Updated: 2024/01/19 15:09:28 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Span::Span( void ): _storage(0), _size_max(0)
{
}

Span::Span( const Span &src )
{
	*this = src;
}

Span::Span( unsigned int N ): _storage(0), _size_max(N)
{
}

Span::~Span( void )
{
}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

Span	&Span::operator=( const Span &src )
{
	if (this != &src)
	{
		this->_storage = src._storage;
		this->_size_max = src._size_max;
	}

	return (*this);
}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

	void	Span::addNumber( int value )
	{
		if (this->_size_max == this->_storage.size())
			throw (storageIsFull());

		this->_storage.push_back(value);
	}

	void	Span::addNumber( int *tab, unsigned int size )
	{
		if (this->_size_max < this->_storage.size() + size)
			throw (storageIsFull());

		this->_storage.insert(this->_storage.end(), tab, tab + size);
	}

	unsigned int	Span::shortestSpan( void )
	{
		if (this->_storage.empty())
			throw (noValueToCompare());

		if (this->_storage.size() == 1)
			return (0);

		std::vector<int>	tmpVector = this->_storage;

		std::sort(tmpVector.begin(), tmpVector.end());

		std::adjacent_difference(tmpVector.begin(), tmpVector.end(), tmpVector.begin());

		return (*std::min_element(tmpVector.begin() + 1, tmpVector.end()));
	}

	unsigned int	Span::longestSpan( void )
	{
		if (this->_storage.empty())
			throw (noValueToCompare());

		std::vector<int>	tmpVector = this->_storage;

		std::sort(tmpVector.begin(), tmpVector.end());

		return (tmpVector[tmpVector.size() - 1] - tmpVector[0]);
	}

/* ************************************************************************** */
/*                                 Exception                                  */
/* ************************************************************************** */

const char	*Span::storageIsFull::what( void ) const throw()
{
	return ("Storage is full");
}

const char	*Span::noValueToCompare::what( void ) const throw()
{
	return ("No value to compare");
}
