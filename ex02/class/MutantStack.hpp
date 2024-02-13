/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:00:46 by eguelin           #+#    #+#             */
/*   Updated: 2024/02/13 17:26:32 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <iterator>

template < typename T >
class MutantStack: public std::stack<T>
{
	public:

/* ************************************************************************** */
/*                                 Constructor                                */
/* ************************************************************************** */

		MutantStack( void ) {};
		MutantStack( const MutantStack &src )
		{
			*this = src;
		};

/* ************************************************************************** */
/*                                 Destructor                                 */
/* ************************************************************************** */

		~MutantStack( void ) {};

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

		MutantStack	&operator=( const MutantStack &src )
		{
			if (this != &src)
				this->c = src.c;

			return (*this);
		};

/* ************************************************************************** */
/*                          Public members functions                          */
/* ************************************************************************** */

		typedef typename std::stack<T>::container_type::iterator	iterator;

		iterator	begin( void ) {return (this->c.begin());};
		iterator	end( void ) {return (this->c.end());};

		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

		const_iterator	cbegin( void ) const {return (this->c.begin());};
		const_iterator	cend( void ) const {return (this->c.end());};

		typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;

		reverse_iterator	rbegin( void ) {return (this->c.rbegin());};
		reverse_iterator	rend( void ) {return (this->c.rend());};

		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		const_reverse_iterator	crbegin( void ) const {return (this->c.rbegin());};
		const_reverse_iterator	crend( void ) const {return (this->c.rend());};
};

#endif
