/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:48:04 by eguelin           #+#    #+#             */
/*   Updated: 2024/02/14 13:38:59 by eguelin          ###   ########lyon.fr   */
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

	std::cout << "find -2 in vector [65, 25, 3, -4, -54]:" << std::endl;
	easyfind( vect, -2 ) == vect.end() ? std::cout << "Value not found in vector" << std::endl : std::cout << "Value found in vector" << std::endl;
	std::cout << std::endl;

	list.push_back(2);
	list.push_back(-2);
	list.push_back(0);
	list.push_back(89);
	list.push_back(3);

	std::cout << "find -2 in list [2, -2, 0, 89, 3]:" << std::endl;
	easyfind( list, -2 ) == list.end() ? std::cout << "Value not found in list" << std::endl : std::cout << "Value found in list" << std::endl;
	std::cout << std::endl;

	deque.push_back(3);
	deque.push_back(3);
	deque.push_back(3);
	deque.push_back(8);
	deque.push_back(5);

	std::cout << "find 3 in deque [3, 3, 3, 8, 5]:" << std::endl;
	easyfind( deque, 3 ) == deque.end() ? std::cout << "Value not found in deque" << std::endl : std::cout << "Value found in deque" << std::endl;

	return (0);
}
