/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:15:03 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/13 16:38:06 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MutantStack.hpp"

/**
 * @brief	Default constructor for MutantStack class.
 */
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{}

/**
 * @brief	Copy constructor for MutantStack class.
 * 
 * @param 	origin The MutantStack object to copy from.
 */
template <typename T>
MutantStack<T>::MutantStack(const MutantStack &origin) : std::stack<T>(origin)
{}

/**
 * @brief	Assignment operator for MutantStack class.
 * 
 * @param 	other The MutantStack object to assign from.
 * @return	Reference to the current MutantStack object.
 */
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
	if (this != &other)
	{
		std::stack<T>::operator=(other);
	}
	return (*this);
}

/**
 * @brief	Destructor for MutantStack class.
 */
template <typename T>
MutantStack<T>::~MutantStack()
{}

/**
 * @brief	Returns an iterator to the beginning of the stack.
 * 
 * @return	An iterator to the first element of the stack.
 */
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

/**
 * @brief	Returns an iterator to the end of the stack.
 * 
 * @return	An iterator to the element following the last element of the stack.
 */
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}
