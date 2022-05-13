/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:03:04 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 22:52:20 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/graphic.hpp"

static void	draw_words_frame(const int row, const int col)
{
	// top left =
	//	(row - (WORD_LEN + 2)) / 2			// might add + 1 after + 2
	//	((col - 3) - (WORD_TRY + 2)) / 2	// same

	// change board color

	move(((row - 3) - (WORD_TRY + 2)) / 2,
		(col - (WORD_LEN + 2)) / 2);
	hline('H', WORD_LEN + 2);
	vline('V', WORD_TRY + 2);
	move(((row - 3) - (WORD_TRY + 2)) / 2 + (WORD_TRY + 2) - 1,
		(col - (WORD_LEN + 2)) / 2);
	hline('B', WORD_LEN + 2);
	move(((row - 3) - (WORD_TRY + 2)) / 2,
		(col - (WORD_LEN + 2)) / 2 + (WORD_LEN + 2));
	vline('R', WORD_TRY + 2);

	// reset color
}

static void	draw_words(const int row, const int col,
	const char &words[WORD_TRY][WORD_LEN], const size_t tries)
{
	size_t	t;
	size_t	i;

	t = 0;
	while (t < tries)
	{
		move(((row - 3) - WORD_TRY) / 2 + t, (col - WORD_LEN) / 2);
		i = 0;
		while (i < WORD_LEN)
		{
			// set color (need letter status)
			addch(words[t][i] - 32);
			i++;
		}
		t++;
	}
}

void	graphic::keyboard(const int row, const int col, const int alphabet_status[26])
{
	// need to handle color
	mvaddstr(row - 1, (col - (strlen(KEYBOARD_ROW_2))) / 2, KEYBOARD_ROW_2);
	mvaddstr(row - 2, (col - (strlen(KEYBOARD_ROW_1))) / 2, KEYBOARD_ROW_1);
	mvaddstr(row - 3, (col - (strlen(KEYBOARD_ROW_0))) / 2, KEYBOARD_ROW_0);
}

void	graphic::board(const int row, const int col,
	const char &words[WORD_TRY][WORD_LEN], const size_t tries)
{
	draw_words_frame(row, col);
	draw_words(row, col, tried_words, tries);
}