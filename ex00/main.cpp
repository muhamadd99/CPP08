/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:57:33 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/18 18:37:16 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <iterator>//distance

int	main()
{
	std::cout << "===== VECTOR =====" << std::endl;
	try 
	{
		std::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 10);
		
		std::cout << "--- Correct Test ---" << std::endl;
		std::vector<int>::iterator it = easyfind(vec, 60);
		std::cout << "the value: " << *it << std::endl;
		//std::cout << it << std::endl; //give an error. not memory address
		std::cout << "the position: " << std::distance(vec.begin(), it) << std::endl;
		
		std::cout << "\n--- Exception Test ---" << std::endl;
		std::vector<int>::iterator it2 = easyfind(vec, 66);
		std::cout << *it2 << "exception not triggered" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;	
	}

	std::cout << "\n===== LIST =====\n" << std::endl;
	try 
	{
		std::list<int> list;
		for (int i = 0; i < 10; i++)
			list.push_back(i * 10);
		
		std::cout << "--- Correct Test ---" << std::endl;
		std::list<int>::iterator it_list = easyfind(list, 60);
		std::cout << "the value: " << *it_list << std::endl;
		std::cout << "the position: " << std::distance(list.begin(), it_list) << std::endl;
		
		std::cout << "\n--- Exception Test ---" << std::endl;
		std::list<int>::iterator it_list2 = easyfind(list, 66);
		std::cout << *it_list2 << "exception not triggered" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;	
	}

	std::cout << "\n===== DEQUE =====\n" << std::endl;
	try 
	{
		std::deque<int> deque;
		for (int i = 0; i < 10; i++)
			deque.push_back(i * 10);
		
		std::cout << "--- Correct Test ---" << std::endl;
		std::deque<int>::iterator it_deque = easyfind(deque, 60);
		std::cout << "the value: " << *it_deque << std::endl;
		std::cout << "the position: " << std::distance(deque.begin(), it_deque) << std::endl;
		
		std::cout << "\n--- Exception Test ---" << std::endl;
		std::deque<int>::iterator it_deque2 = easyfind(deque, 66);
		std::cout << *it_deque2 << "exception not triggered" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;	
	}
}