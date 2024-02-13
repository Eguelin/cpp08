/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:17:44 by eguelin           #+#    #+#             */
/*   Updated: 2024/02/13 17:40:09 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <numeric>

class Span
{
	public:

		Span( void );
		Span( const Span &src );
		Span( const size_t N );
		~Span( void );

		Span	&operator=( const Span &src );

		void			addNumber( int value );
		void			addNumber( std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end );
		unsigned int	shortestSpan( void );
		unsigned int	longestSpan( void );


		class storageIsFull: public std::exception
		{
			public:
			virtual const char	*what( void ) const throw();
		};

		class noValueToCompare: public std::exception
		{
			public:
			virtual const char	*what( void ) const throw();
		};

	private:

		std::vector<int>	_storage;
		size_t				_size;
};

#endif
