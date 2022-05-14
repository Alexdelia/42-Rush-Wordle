/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:03:04 by adelille          #+#    #+#             */
/*   Updated: 2022/05/14 16:54:43 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/graphic.hpp"

void	graphic::keyboard(const int row, const int col, const int alphabet_status[26])
{
	char	keyboard_row_0[] = KEYBOARD_ROW_0;
	char	keyboard_row_1[] = KEYBOARD_ROW_1;
	char	keyboard_row_2[] = KEYBOARD_ROW_2;
	size_t	i;

	move(row - 1, (col - (strlen(KEYBOARD_ROW_2))) / 2);
	i = 0;
	while (keyboard_row_2[i])
	{
		attrset(COLOR_PAIR(alphabet_status[keyboard_row_2[i] - 'a']));
		addch(keyboard_row_2[i]);
		i++;
	}
	move(row - 2, (col - (strlen(KEYBOARD_ROW_1))) / 2);
	i = 0;
	while (keyboard_row_1[i])
	{
		attrset(COLOR_PAIR(alphabet_status[keyboard_row_1[i] - 'a']));
		addch(keyboard_row_1[i]);
		i++;
	}
	move(row - 3, (col - (strlen(KEYBOARD_ROW_0))) / 2);
	i = 0;
	while (keyboard_row_0[i])
	{
		attrset(COLOR_PAIR(alphabet_status[keyboard_row_0[i] - 'a']));
		addch(keyboard_row_0[i]);
		i++;
	}

	// need to handle color
	// mvaddstr(row - 1, (col - (strlen(KEYBOARD_ROW_2))) / 2, KEYBOARD_ROW_2);
	// mvaddstr(row - 2, (col - (strlen(KEYBOARD_ROW_1))) / 2, KEYBOARD_ROW_1);
	// mvaddstr(row - 3, (col - (strlen(KEYBOARD_ROW_0))) / 2, KEYBOARD_ROW_0);
	// (void)alphabet_status;
}

void	graphic::frame(const int row, const int col)
{
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