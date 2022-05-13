/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:18:35 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 12:16:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.hpp"
#include "../../inc/graphic.hpp"
#include "../../inc/color_pair.hpp"

bool	env::resize(void)
{
	attrset(A_BOLD | COLOR_PAIR(CP_RED));

	getmaxyx(stdscr, this->_row, this->_col);
	while (!graphic::valid_size(this->_row, this->_col))
	{
		clear();
		graphic::frame_resize(this->_row, this->_col);
		graphic::pmw("too small", this->_row, this->_col);
		refresh();

		this->key = 0;
		while (this->key != KEY_RESIZE)
		{
			this->key = getch();
			if (key::is_exit(this->key))
				return (false);
		}

		getmaxyx(stdscr, this->_row, this->_col);
	}

	attrset(A_NORMAL);

	return (true);
}