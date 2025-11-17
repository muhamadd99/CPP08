/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:34:54 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/17 22:21:18 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span {
private:
	unsigned int		_maxSize;
	std::vector<int>	_vec;

public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();
	void	addNumber(int nbr);
	void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int		shortestSpan() const;
	int		longestSpan() const;
	class FullVecException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class NoSpanException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif