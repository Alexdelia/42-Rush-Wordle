/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:53:02 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 14:53:19 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.hpp"

bool	env::set_files(const std::string &possible, const std::string &allowed)
{
	{
		struct stat	buffer;
		if (stat(possible.c_str(), &buffer) == -1)
		{
			std::cerr << s_error() << possible << " does not exist"
				<< "\033[0m" << std::endl;
			return (false);
		}
		else
			this->_possible_words_file = possible;
	}
	{
		struct stat	buffer;
		if (stat(allowed.c_str(), &buffer) == -1)
		{
			std::cerr << s_error() << allowed << " does not exist"
				<< "\033[0m" << std::endl;
			return (false);
		}
		else
			this->_allowed_words_file = allowed;
	}

	return (true);
}

void	env::set_row(const int row)
{ this->_row = row; }
void	env::set_col(const int col)
{ this->_col = col; }

int		env::get_row(void) const
{ return (this->_row); }
int		env::get_col(void) const
{ return (this->_col); }