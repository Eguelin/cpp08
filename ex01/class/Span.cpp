/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:17:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/10 18:03:25 by eguelin          ###   ########lyon.fr   */
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
		int					shortestSpan = std::numeric_limits<int>::max();

		std::sort(tmpVector.begin(), tmpVector.end());

		for (unsigned int i = 0; i < tmpVector.size() - 1; i++)
		{
			int	tmp = tmpVector[i + 1] - tmpVector[i];

			if (tmp < shortestSpan)
				shortestSpan = tmp;
		}

		return (shortestSpan);
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
