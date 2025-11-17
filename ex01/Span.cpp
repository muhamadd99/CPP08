/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:42:32 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/17 22:40:19 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) :  _maxSize(N) //vec automatically empty
{}

Span::Span(const Span& other) : _maxSize(other._maxSize), _vec(other._vec)
{}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_vec = other._vec; //the vector handle its own medical
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

void	Span::addNumber(int nbr)