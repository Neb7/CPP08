/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:25:32 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/13 16:37:08 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.tpp"

int main()
{
    MutantStack<int> mstack;

    std::cout << "Push 5, 17" << std::endl;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    std::cout << "Pop" << std::endl;
    mstack.pop();

    std::cout << "Size: " << mstack.size() << std::endl;

    std::cout << "Push 3, 5, 737, 0" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Iterate through stack:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "Copy constructor test" << std::endl;
    MutantStack<int> mstack2(mstack);
    for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "Assignment operator test" << std::endl;
    MutantStack<int> mstack3;
    mstack3 = mstack;
    for (MutantStack<int>::iterator it = mstack3.begin(); it != mstack3.end(); ++it)
        std::cout << *it << std::endl;

    return (0);
}
