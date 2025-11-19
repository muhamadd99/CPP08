/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:42:32 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/18 18:58:09 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstddef>
#include <algorithm>
#include <stdexcept>
#include <numeric> //adjacent_difference

Span::Span(unsigned int N) :  _maxSize(N) //vec automatically empty
{}

Span::Span(const Span& other) : _maxSize(other._maxSize), _vec(other._vec)
{}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_vec = other._vec; //the vector handle its own memory
	}
	return (*this);
}

Span::~Span() //vec automatically delete
{}

void	Span::addNumber(int nbr)
{
	if (_vec.size() >= _maxSize)
		throw FullVecException();
	_vec.push_back(nbr);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (end < begin)
        throw std::invalid_argument("Invalid iterator range");
	//cannot use distance of end begin, it will give error
	size_t sizeToAdd = static_cast<size_t>(std::distance(begin, end));
	size_t sizeVacant = _maxSize - _vec.size();
	
	if (sizeVacant < sizeToAdd)
		throw Span::FullVecException();
	_vec.insert(_vec.end(), begin, end);
}

int	Span::shortestSpan() const
{
	if (_vec.size() < 2)
		throw NoSpanException();
	std::vector<int> sorted = _vec;
	std::sort(sorted.begin(), sorted.end());

	std::vector<int> difference(_vec.size());
	std::adjacent_difference(sorted.begin(), sorted.end(), difference.begin());
	int	minSpan = *std::min_element(difference.begin() + 1, difference.end());
	return minSpan;
}

//1 method. sort and deduct first & last
//1 method. find min/max substract
int	Span::longestSpan() const
{
	if (_vec.size() < 2)
		throw NoSpanException();
	int min = *std::min_element(_vec.begin(), _vec.end());
	int max = *std::max_element(_vec.begin(), _vec.end());
	int maxSpan = max - min;
	return (maxSpan);
}

const char* Span::FullVecException::what() const throw()
{
	return ("Full vector limit reached");
}

const char* Span::NoSpanException::what() const throw()
{
	return ("Not enough number to find span");
}

// int	Span::shortestSpan() const
// {
// 	if (_vec.size() < 2)
// 		throw NoSpanException();
// 	std::vector<int> sorted = _vec;
// 	std::sort(sorted.begin(), sorted.end());
//
// 	int minSpan = sorted[1] - sorted[0];
// 	for (size_t i = 2; i < sorted.size(); i++)
// 	{
// 		int span = sorted[i] - sorted[i - 1];
// 		if (minSpan > span)
// 			minSpan = span;
// 	}
// 	return minSpan;
// }