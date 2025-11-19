/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:16:54 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/19 10:36:38 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	//extra test
	const int size = 100000;
	std::vector<int> NbrVec;
	for (int i = 0; i < size; i++)
		NbrVec.push_back(i);
	Span spanVec(size);
	std::cout << "\n=== CANT COUNT SPAN EXCEPTION ===" << std::endl;
	try
	{
		spanVec.shortestSpan();
		spanVec.longestSpan();
	}
	catch (const std::exception& e) 
	{
		std::cout << "Exception Test Passed: " << e.what() << std::endl;
	}

	std::cout << "\n=== ADDNUMBER FROM VECTORS ===" << std::endl;
	spanVec.addNumber(NbrVec.begin(), NbrVec.end());
	std::cout << "Shortest span: " << spanVec.shortestSpan() << std::endl;
	std::cout << "Longest span: " << spanVec.longestSpan() << std::endl;

	std::cout << "\n=== MAX NUMBER TO FILL EXCEPTION===" << std::endl;
	try
	{
		spanVec.addNumber(6);
	}
	catch (const std::exception& e) 
	{
		std::cout << "Exception Test Passed: " << e.what() << std::endl;
	}
	return 0;
}
