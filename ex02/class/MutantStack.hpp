/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:00:46 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/10 20:03:04 by eguelin          ###   ########lyon.fr   */
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
			{
				this->_begin = src._begin;
				this->_end = src._end;
			}

			return (*this);
		}

/* ************************************************************************** */
/*                               Iterator class                               */
/* ************************************************************************** */

		class	iterator: public std::iterator<std::bidirectional_iterator_tag, T>
		{
			public:

				iterator( void ) {};
				iterator( const iterator &src ) {static_cast<void>(src);};
				~iterator( void ) {};

				iterator	&operator=( const iterator &src ) {static_cast<void>(src);};

				iterator	&operator++( void ) {};
				iterator	&operator--( void ) {};
				iterator	operator++( int ) {};
				iterator	operator--( int ) {};

				bool		operator==( const iterator &src ) {static_cast<void>(src);};
				bool		operator!=( const iterator &src ) {static_cast<void>(src);};

				T			&operator*( void ) {};
				T			*operator->( void ) {};

			private:

				T			*_ptr;
				iterator	*_next;
		};

/* ************************************************************************** */
/*                          Public members functions                          */
/* ************************************************************************** */

		void	push( const T &value ) {static_cast<void>(value);};
		void	pop( void ) {};
		T		top( void ) const {};

		MutantStack::iterator	&begin( void ) const {return (this->_begin);};
		MutantStack::iterator	&end( void ) const {return (this->_end);};

	private:

/* ************************************************************************** */
/*                             Private attributes                             */
/* ************************************************************************** */

		MutantStack::iterator	_begin;
		MutantStack::iterator	_end;
};

#endif
