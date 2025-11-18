/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:29:53 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/18 13:16:10 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() //: std::stack<T>() //bts
{}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) //c(other.c) //bts
{}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
	if (this != &other)
		std::stack<T>::operator=(other); //c = other.c //bts
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack()
{}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return(this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end ()
{
	return(this->c.end());
}

#endif