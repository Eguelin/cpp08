/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:48:04 by eguelin           #+#    #+#             */
/*   Updated: 2024/02/13 17:39:16 by eguelin          ###   ########lyon.fr   */
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
		std::cout << "Added 6" << std::endl;
		sp.addNumber(3);
		std::cout << "Added 3" << std::endl;
		sp.addNumber(-17);
		std::cout << "Added -17" << std::endl;
		sp.addNumber(-18);
		std::cout << "Added -18" << std::endl;
		sp.addNumber(11);
		std::cout << "Added 11" << std::endl;


		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		Span				sp = Span(100);
		std::vector<int>	ranges(100);
		timeval				currentTime;

		for (int i = 0; i < 100; i++)
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

		sp.addNumber(ranges.begin(), ranges.end());
		std::cout << "Added 100 random numbers" << std::endl;

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		try
		{
			Span	sp;

			sp.addNumber(6);
		}
		catch(const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Span	sp(5);

			sp.addNumber(6);
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Span	sp(5);

			sp.addNumber(6);
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}
