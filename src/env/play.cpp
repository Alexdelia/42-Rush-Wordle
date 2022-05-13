/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:57:17 by adelille          #+#    #+#             */
/*   Updated: 2022/05/14 01:14:38 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.hpp"

void	env::_try_word(const char word[WORD_LEN])
{
	// test if word is valid to find
	// find word in set

	// inc if found
	if (word[0] != '4')
		this->_try++;
	// else	// show message
}

void	env::play(void)
{
	size_t	i;

	i = 0;
	while (this->_try < WORD_TRY)
	{
		graphic::frame(this->_row, this->_col);
		this->_print_words();
		graphic::keyboard(this->_row, this->_col, this->_alphabet_status);

		// move to right elem
		move(((this->_row - 3) - WORD_TRY) / 2 + this->_try,
			(this->_col - WORD_LEN) / 2 + i);

		key = getch();
		//std::cout << key << std::endl;

		if (key::is_exit(key))
			return ;
		else if (key == KEY_RESIZE)
		{
			resize();
			clear();
		}
		else if (key == KEY_ENTER || key == 10)
		{
			this->_try_word(this->_words_tried[this->_try]);
			i = 0;
		}
		else if ((key == KEY_BACKSPACE || key == 127) && i > 0)
		{
			i--;
			//this->_words_tried[this->_try][i] = '\0';
			move(((this->_row - 3) - WORD_TRY) / 2 + this->_try,
				(this->_col - WORD_LEN) / 2 + i);
			addch(' ');
		}
		else if (key >= 'a' && key <= 'z' && i < WORD_LEN)
		{
			this->_words_tried[this->_try][i] = key;
			addch(key - 32);
			i++;
		}
	}
}