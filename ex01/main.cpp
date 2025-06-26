/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:06:18 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/23 15:02:23 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	try
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		// Uncommenting the next line will throw an exception
		sp.addNumber(12);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Span	 sp2(1);

		sp2.addNumber(42);

		// Uncommenting the next line will throw an exception
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	std::cout << std::endl;
	
	try
	{
		Span	 sp3(10000);
		// Fill the Span with 10000 "random" numbers
		for (unsigned int i = 0; i < 10000; ++i)
		{
			sp3.addNumber(rand());
		}
		std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << std::endl;

	try
	{
		std::vector<int>	numbers;
		for (int i = 0; i < 10; ++i)
		{
			numbers.push_back(rand());
		}
		
		Span				sp4(10), sp5(9);

		std::cout << "First" << std::endl;
		sp4.addNumbers(numbers.begin(), numbers.end());
		std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp4.longestSpan() << std::endl;
		std::cout << "Second" << std::endl;
		sp5.addNumbers(numbers.begin(), numbers.end());
		std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp5.longestSpan() << std::endl;
		std::cout << "All Good!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	return (0);
}
