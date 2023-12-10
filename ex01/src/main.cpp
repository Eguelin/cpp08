/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:48:04 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/10 18:01:07 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <sys/time.h>

int main( void )
{
	{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(-17);
		sp.addNumber(-18);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span	sp = Span(1000000);
		int		ranges[1000000];
		timeval	currentTime;

		for (int i = 0; i < 1000000; i++)
		{
			gettimeofday(&currentTime, NULL);
			std::srand(static_cast<unsigned int>(currentTime.tv_usec));

			if (std::rand() % 2)
			{
				gettimeofday(&currentTime, NULL);
				std::srand(static_cast<unsigned int>(currentTime.tv_usec));
				ranges[i] = std::rand();
			}
			else
			{
				gettimeofday(&currentTime, NULL);
				std::srand(static_cast<unsigned int>(currentTime.tv_usec));
				ranges[i] = -std::rand();
			}
		}

		sp.addNumber(ranges, 1000000);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		try
		{
			Span	sp;

			sp.addNumber(6);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			Span	sp(5);

			sp.shortestSpan();
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			Span	sp(5);

			sp.addNumber(6);
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
		{
		try
		{
			Span	sp(5);

			sp.addNumber(6);
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return (0);
}
