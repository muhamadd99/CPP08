/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:55:20 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/18 13:12:24 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T &container, int nbr)
{
	typename T::iterator it = std::find(container.begin(), container.end(), nbr);
	if (it == container.end())
		throw std::runtime_error("Value not found");
	return it;
}