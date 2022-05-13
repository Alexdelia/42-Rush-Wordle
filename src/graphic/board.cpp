/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:03:04 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 18:29:18 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/graphic.hpp"

static void	draw_words_frame(const int row, const int col)
{
	// top left =
	//	(row - (WORD_LEN + 2)) / 2			// might add + 1 after + 2
	//	((col - 3) - (WORD_TRY + 2)) / 2	// same

	// change board color

	move((row - (WORD_LEN + 2)) / 2, ((col - 3) - (WORD_TRY + 2)) / 2);
	hline('H', WORD_LEN + 2);
	vline('V', WORD_TRY + 2);
	move((row - (WORD_LEN + 2)) / 2 + (WORD_LEN + 2),
		((col - 3) - (WORD_TRY + 2)) / 2);
	hline('B', WORD_LEN + 2);
	move((row - (WORD_LEN + 2)) / 2,
		((col - 3) - (WORD_TRY + 2)) / 2 + (WORD_TRY + 2));
	vline('R', WORD_TRY + 2);

	// reset color
}

void	graphic::board(const int row, const int col)
{
	draw_words_frame(row, col);
	// draw words in it
	// draw keyboard
}