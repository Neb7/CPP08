/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:24:43 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/17 17:43:59 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <iterator>
# include <stdexcept>

/**
 * @brief	Searches for a value in a container and returns an iterator to it.
 * 
 * @param	container The container to search in (e.g., vector, list, ...).
 * @param	value The value to search for.
 */
template <typename T>
typename T::iterator	easyfind(T &container, int value)
{
	typename T::iterator	it;

	it = find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		throw std::out_of_range("Value not found in the container");
	}
	return (it);
}

#endif
