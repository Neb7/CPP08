/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:40:57 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/26 14:59:44 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>

# define UINT_MAX 4294967295

/**
 * @brief 	A class that represents a span of integers.
 * 			It allows adding numbers and calculating the shortest and longest spans.
 */
class Span
{
	private:
		unsigned int        _size;
		std::vector<int>    _numbers;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span			&operator=(const Span &other);
		~Span();

		void			addNumber(int number);
		void			addNumbers(std::vector<int>::iterator begin,
									std::vector<int>::iterator end);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		class FullSpanException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

#endif
