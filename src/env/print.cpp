/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:01:21 by adelille          #+#    #+#             */
/*   Updated: 2022/05/15 10:57:19 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.hpp"

void env::_print_words(void) const
{
	size_t t;
	size_t i;

	t = 0;
	while (t < this->_try)
	{
		move(((this->_row - 3) - WORD_TRY) / 2 + t, (this->_col - WORD_LEN) / 2);
		i = 0;
		while (i < WORD_LEN)
		{
			attrset(A_BOLD | COLOR_PAIR(this->_letter_status[t][i]));
			addch(this->_words_tried[t][i] - 32);
			i++;
		}
		t++;
	}

	attrset(A_NORMAL);
}

void env::_print_win(void) const
{
	attrset(A_BOLD | A_ITALIC);

	std::stringstream win_msg;
	win_msg << "found \"" << this->_word_to_guess;
	if (this->_try > 1)
		win_msg << "\" in " << (char)(this->_try + '0') << " tries!";
	else
		win_msg << "\" on first try!";

	mvprintw((this->_row - 1) / 2 + 4,
			(this->_col - win_msg.str().size()) / 2,
			win_msg.str().c_str());

	attrset(A_NORMAL);
}

void env::_print_lost(void) const
{
	attrset(A_BOLD | A_ITALIC);

	std::string	lost_msg("the word was: "
		+ std::string(this->_word_to_guess));

	mvprintw((this->_row - 1) / 2 + 4,
			(this->_col - lost_msg.size()) / 2,
			lost_msg.c_str());

	attrset(A_NORMAL);
}