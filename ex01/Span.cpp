/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:48:51 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/23 14:56:20 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/**
 * @brief	Default constructor for Span class.
 */
Span::Span() : _size(0), _numbers()
{}

/**
 * @brief	Constructor that initializes the Span with a given size.
 * 
 * @param 	n The size of the span.
 */
Span::Span(unsigned int n) : _size(n), _numbers()
{}

/**
 * @brief	Copy constructor for Span class.
 * 
 * @param 	origin The Span object to copy from.
 */
Span::Span(const Span &origin)
{
	*this = origin;
}

/**
 * @brief	Assignment operator for Span class.
 * 
 * @param 	other The Span object to assign from.
 * @return	Reference to the current Span object.
 */
Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_size = other._size;
		this->_numbers = other._numbers;
	}
	return (*this);
}

/**
 * @brief	Destructor for Span class.
 */
Span::~Span()
{}

/**
 * @brief	Adds a number to the span.
 * 
 * @param 	number The number to add.
 * @throws	FullSpanException if the span is already full.
 */
void	Span::addNumber(int number)
{
	if (this->_numbers.size() >= this->_size)
	{
		throw (FullSpanException());
	}
	this->_numbers.push_back(number);
}

/**
 * @brief	Adds a range of numbers to the span.
 * 
 * @param 	begin Iterator to the beginning of the range.
 * @param 	end Iterator to the end of the range.
 * @throws	FullSpanException if adding the numbers exceeds the span's size.
 */
void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_numbers.size() + std::distance(begin, end) > this->_size)
	{
		throw (FullSpanException());
	}
	this->_numbers.insert(this->_numbers.end(), begin, end);
}


/**
 * @brief	Calculates the shortest span between any two numbers in the Span.
 * 
 * @return	The shortest span.
 * @throws	NoSpanException if there are not enough numbers to calculate a span.
 */
unsigned int	Span::shortestSpan() const
{
	unsigned int span, shortest = UINT_MAX;

	if (this->_numbers.size() < 2)
	{
		throw (NoSpanException());
	}
	
	std::vector<int> sortedNumbers = this->_numbers;
	sort(sortedNumbers.begin(), sortedNumbers.end());

	for (size_t i = 1; i < sortedNumbers.size(); ++i)
	{
		span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < shortest)
		{
			shortest = span;
		}
	}
	return (shortest);
}

/**
 * @brief	Calculates the longest span between any two numbers in the Span.
 * 
 * @return	The longest span.
 * @throws	NoSpanException if there are not enough numbers to calculate a span.
 */
unsigned int	Span::longestSpan() const
{
	int	min;
	int	max;

	if (this->_numbers.size() < 2)
	{
		throw (NoSpanException());
	}
	min = *min_element(this->_numbers.begin(), this->_numbers.end());
	max = *max_element(this->_numbers.begin(), this->_numbers.end());
	return (static_cast<unsigned int>(max - min));
}

/**
 * @brief	Exception thrown when trying to add a number to a full Span.
 */
const char	*Span::FullSpanException::what() const throw()
{
	return ("Span is full, cannot add more numbers.");
}

/**
 * @brief	Exception thrown when there are not enough numbers to calculate a span.
 */
const char	*Span::NoSpanException::what() const throw()
{
	return ("Not enough numbers to calculate a span.");
}
