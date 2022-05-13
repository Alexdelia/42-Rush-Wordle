/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:57:17 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 22:23:17 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.hpp"

void	env::_try_word(const char word[WORD_LEN])
{
	// test if word is valid to find
	// find word in set

	// inc if found
	this->_try++;
	// else	// show message
}

void	env::play(void)
{
	while (this->_try < WORD_TRY)
	{
		graphic::board(this->_row, this->_col,
			this->_words_tried, this->_try);
		graphic::keyboard(this->_row, this->_col, this->_alphabet_status);

		key = getch();

		if (key::is_exit(key))
			return ;
		else if (key == KEY_RESIZE)
		{
			resize();
			clear();
		}
		else if (key == KEY_ENTER)
			this->_try_word(this->_words_tried[this->_try]);
		//else if (key == KEY_BACKSPACE)
			// delete letter
		//else if (key >= 'a' && key <= 'z')
			// add letter
	}
}