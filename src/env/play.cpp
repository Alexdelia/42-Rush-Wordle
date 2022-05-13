/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:57:17 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 18:30:47 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.hpp"

void	env::_try_word(void)
{

}

void	env::play(void)
{
	while (this->_try < WORD_TRY)
	{
		graphic::board(this->_row, this->_col);
		key = getch();

		// get key
		// if different than exit or resize
		if (key::is_exit(key))
			return ;
			this->_try_word();
			this->_try++;
		// else
		//	do action
		//	// if resize, clear before redraw
	}
}