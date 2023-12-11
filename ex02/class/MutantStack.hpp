/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:00:46 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/11 13:50:15 by eguelin          ###   ########lyon.fr   */
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
};

#endif
