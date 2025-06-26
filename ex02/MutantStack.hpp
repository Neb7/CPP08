/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:40:01 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/13 16:37:34 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

/**
 * @brief	A stack that allows iteration over its elements.
 */
template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack();
		MutantStack(const MutantStack &origin);
		MutantStack	&operator=(const MutantStack &other);
		~MutantStack();

		iterator begin();
		iterator end();
};

#endif
