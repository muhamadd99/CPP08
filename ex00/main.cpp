/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:57:33 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/16 19:00:34 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int	main()
{
	try 
	{
		std::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 10);
		
		std::cout << "=== CORRECT TEST ===" << std::endl;
		std::vector<int>::iterator it = easyfind(vec, 60);
		std::cout << "the value: " << *it << std::endl;
		//std::cout << it << std::endl; //give an error. not memory address
		std::cout << "the position: " << std::distance(vec.begin(), it) << std::endl;
		
		std::cout << "\n=== EXCEPTION TEST ===" << std::endl;
		std::vector<int>::iterator it2 = easyfind(vec, 66);
		std::cout << *it2 << "exception not triggered" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;	
	}
}