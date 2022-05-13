/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:03:04 by adelille          #+#    #+#             */
/*   Updated: 2022/05/14 00:48:08 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/graphic.hpp"

void	env::_print_words(void) const
{
	size_t	t;
	size_t	i;

	t = 0;
	while (t < this->_try)
	{
		move(((this->_row - 3) - WORD_TRY) / 2 + t, (this->_col - WORD_LEN) / 2);
		i = 0;
		while (i < WORD_LEN)
		{
			attrset(COLOR_PAIR(this->_letter_status[t][i]));
			addch(this->_words_tried[t][i] - 32);
			i++;
		}
		t++;
	}

	attrset(A_NORMAL);
}

void	graphic::keyboard(const int row, const int col, const int alphabet_status[26])
{
	// need to handle color
	mvaddstr(row - 1, (col - (strlen(KEYBOARD_ROW_2))) / 2, KEYBOARD_ROW_2);
	mvaddstr(row - 2, (col - (strlen(KEYBOARD_ROW_1))) / 2, KEYBOARD_ROW_1);
	mvaddstr(row - 3, (col - (strlen(KEYBOARD_ROW_0))) / 2, KEYBOARD_ROW_0);
	(void)alphabet_status;
}

void	graphic::frame(const int row, const int col)
{
	// top left =
	//	(row - (WORD_LEN + 2)) / 2			// might add + 1 after + 2
	//	((col - 3) - (WORD_TRY + 2)) / 2	// same

	attrset(COLOR_PAIR(CP_BOARD));

	move(((row - 3) - (WORD_TRY + 2)) / 2,
		(col - (WORD_LEN + 2)) / 2);
	hline(' ', WORD_LEN + 2);
	vline(' ', WORD_TRY + 2);
	move(((row - 3) - (WORD_TRY + 2)) / 2 + (WORD_TRY + 2) - 1,
		(col - (WORD_LEN + 2)) / 2);
	hline(' ', WORD_LEN + 2);
	move(((row - 3) - (WORD_TRY + 2)) / 2,
		(col - (WORD_LEN + 2)) / 2 + (WORD_LEN + 2) - 1);
	vline(' ', WORD_TRY + 2);

	attrset(A_NORMAL);
}