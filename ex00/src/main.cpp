/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:48:04 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/09 17:17:15 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main( void )
{
	std::vector<int>		vect;
	std::list<int>			list;
	std::deque<int>			deque;

	vect.push_back(65);
	vect.push_back(25);
	vect.push_back(3);
	vect.push_back(-4);
	vect.push_back(-54);

	list.push_back(2);
	list.push_back(-2);
	list.push_back(0);
	list.push_back(89);
	list.push_back(3);

	deque.push_back(3);
	deque.push_back(3);
	deque.push_back(3);
	deque.push_back(8);
	deque.push_back(5);

	easyfind( vect, -2 ) ? std::cout << "Found" << std::endl : std::cout << "Not found" << std::endl;
	easyfind( list, -2 ) ? std::cout << "Found" << std::endl : std::cout << "Not found" << std::endl;
	easyfind( deque, -2 ) ? std::cout << "Found" << std::endl : std::cout << "Not found" << std::endl;

	return (0);
}
