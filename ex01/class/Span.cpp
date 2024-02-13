/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:17:44 by eguelin           #+#    #+#             */
/*   Updated: 2024/02/13 17:40:22 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Span::Span( void ): _storage(0), _size(0)
{
}

Span::Span( const Span &src )
{
	*this = src;
}

Span::Span( const size_t N ): _storage(0), _size(N)
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
		this->_size = src._size;
	}

	return (*this);
}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

	void	Span::addNumber( const int value )
	{
		if (this->_size == this->_storage.size())
			throw (storageIsFull());

		this->_storage.push_back(value);

		this->_size++;
	}

	void	Span::addNumber( std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end )
	{
		if (this->_size < this->_storage.size() + std::distance(begin, end))
			throw (storageIsFull());

		this->_storage.insert(this->_storage.end(), begin, end);

		this->_size += std::distance(begin, end);
	}

	unsigned int	Span::shortestSpan( void )
	{
		if (this->_storage.empty() || this->_storage.size() == 1)
			throw (noValueToCompare());

		std::vector<int>	tmpVector(this->_storage.begin(), this->_storage.end());

		std::sort(tmpVector.begin(), tmpVector.end());

		std::adjacent_difference(tmpVector.begin(), tmpVector.end(), tmpVector.begin());

		return (*std::min_element(tmpVector.begin() + 1, tmpVector.end()));
	}

	unsigned int	Span::longestSpan( void )
	{
		if (this->_storage.empty() || this->_storage.size() == 1)
			throw (noValueToCompare());

		return (*std::max_element(this->_storage.begin(), this->_storage.end()) - *std::min_element(this->_storage.begin(), this->_storage.end()));
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
