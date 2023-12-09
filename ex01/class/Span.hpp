/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:17:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/09 19:45:59 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <limits>

class Span
{
	public:

		Span( void );
		Span( const Span &src );
		Span( unsigned int N );
		~Span( void );

		Span	&operator=( const Span &src );

		void	addNumber( int value );
		int		shortestSpan( void );
		int		longestSpan( void );

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
		unsigned int		_size_max;
};

#endif
