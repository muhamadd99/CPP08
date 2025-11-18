/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:16:38 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/18 16:39:25 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main()
{
	std::cout << "=== MUTANTSTACK ===" << std::endl;
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Stack top: " << mstack.top() << std::endl;
	
	mstack.pop(); //remove top element
	
	std::cout << "After removing top: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	std::cout << "Stack content: \n" << mstack.size() << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	
	std::cout << "\n=== LIST === " << std::endl;
	std::list<int>	mlist;

	mlist.push_back(5);
	mlist.push_back(17);

	std::cout << "Stack top: " << mlist.back() << std::endl;
	
	mlist.pop_back(); //remove top element
	
	std::cout << "After removing top: " << mlist.size() << std::endl;
	
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);
	
	std::list<int>::iterator it2 = mlist.begin();
	std::list<int>::iterator ite2 = mlist.end();
	
	++it2;
	--it2;
	std::cout << "Stack content: \n" << mstack.size() << std::endl;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::list<int> s2(mlist);

    std::cout << "\n=== COMPARISON: MUTANTSTACK vs LIST vs VECTOR ===" << std::endl;
    
    MutantStack<int> mstack2;
    std::list<int> mlist2;
    std::vector<int> mvector;
    
    // Same operations on all three
    int values[] = {5, 17, 3, 5, 737, 0};
    for (int i = 0; i < 6; i++) {
        mstack2.push(values[i]);
        mlist2.push_back(values[i]);
        mvector.push_back(values[i]);
    }
    
    std::cout << "MutantStack: ";
    for (MutantStack<int>::iterator it3 = mstack2.begin(); it3 != mstack2.end(); ++it3)
        std::cout << *it3 << " ";
    
    std::cout << "\nstd::list:    ";
    for (std::list<int>::iterator it4 = mlist2.begin(); it4 != mlist2.end(); ++it4)
        std::cout << *it4 << " ";
        
    std::cout << "\nstd::vector:  ";
    for (std::vector<int>::iterator it5 = mvector.begin(); it5 != mvector.end(); ++it5)
        std::cout << *it5 << " ";
    std::cout << std::endl;
	
	return 0;
}

// int main()
// {
// MutantStack<int>	mstack;
// mstack.push(5);
// mstack.push(17);
// std::cout << mstack.top() << std::endl;
// 
// mstack.pop(); //remove top element
// 
// std::cout << mstack.size() << std::endl;
// 
// mstack.push(3);
// mstack.push(5);
// mstack.push(737);
// //[...]
// mstack.push(0);
// 
// MutantStack<int>::iterator it = mstack.begin();
// MutantStack<int>::iterator ite = mstack.end();
// 
// ++it;
// --it;
// while (it != ite)
// {
	// std::cout << *it << std::endl;
	// ++it;
// }
// std::stack<int> s(mstack);
// return 0;
// }