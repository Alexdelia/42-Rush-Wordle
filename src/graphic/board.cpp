/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:03:04 by adelille          #+#    #+#             */
/*   Updated: 2022/05/14 16:04:07 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/graphic.hpp"

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