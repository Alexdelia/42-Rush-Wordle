/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:24:59 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 13:30:12 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>

void	error(const std::string &str)
{
	std::cerr << "\033[31;1m" << "Error:" << "\033[0m"
		<< "\033[31m" << str << "\033[0m" << std::endl;
}

int		error(const std::string &str, const int ret)
{
	error(str);
	return (ret);
}

std::string	s_error(void)
{
	std::stringstream	o;

	o << "\033[31;1m" << "Error:" << "\033[0m" << "\033[31m";

	return (o.str());
}