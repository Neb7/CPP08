/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:33:54 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/17 17:40:24 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	std::vector<int>	vec;
	std::list<int>		lst;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);
	try
	{
		std::vector<int>::iterator	itVec = easyfind(vec, 3);
		std::cout << "Found in vector: " << *itVec << std::endl;

		std::list<int>::iterator	itLst = easyfind(lst, 20);
		std::cout << "Found in list: " << *itLst << std::endl;

		// This will throw an exception
		easyfind(vec, 6);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::list<int> l;
    
	for (int i = 1; i <= 3; ++i)
    {
		l.push_back(i);
	}
	
    std::cout << "Test list: ";
    try
	{
        std::cout << *easyfind(l, 2) << " found" << std::endl;
        std::cout << *easyfind(l, 4) << " found" << std::endl; // Not found
    } 
	catch (const std::exception &e)
	{
        std::cout << "Error : " << e.what() << std::endl;
    }
	
	return (0);
}
