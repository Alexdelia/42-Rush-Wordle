/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:57:17 by adelille          #+#    #+#             */
/*   Updated: 2022/05/15 15:37:40 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.hpp"

void	env::play(void)
{
	size_t	i;

	graphic::frame(this->_row, this->_col);

	i = 0;
	while (this->_try < WORD_TRY)
	{
		this->_print_words();
		graphic::keyboard_cpp(this->_row, this->_col, this->_alphabet_status);

		//mvaddstr(1, 1, this->_word_to_guess);	// debug

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
			graphic::frame(this->_row, this->_col);
		}
		else if (key == KEY_ENTER || key == 10)
		{
			this->_words_tried[this->_try][i] = '\0';
			
			clear();
			graphic::frame(this->_row, this->_col);
			if (this->_try_word(this->_words_tried[this->_try]))
				break ;
			i = 0;
		}
		else if ((key == KEY_BACKSPACE || key == 127) && i > 0)
		{
			i--;
			move(((this->_row - 3) - WORD_TRY) / 2 + this->_try,
				(this->_col - WORD_LEN) / 2 + i);
			addch(' ');
		}
		else if (key >= 'a' && key <= 'z' && i < WORD_LEN)
		{
			attrset(A_BOLD);
			this->_words_tried[this->_try][i] = key;
			addch(key - 32);
			i++;
			attrset(A_NORMAL);
		}
	}

	this->_print_words();
	graphic::keyboard_cpp(this->_row, this->_col, this->_alphabet_status);
	
	if (this->_try == WORD_TRY)
		this->_print_lost();

	getch();
}