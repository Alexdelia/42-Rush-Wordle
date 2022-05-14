/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_words.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:01:21 by adelille          #+#    #+#             */
/*   Updated: 2022/05/14 16:03:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.hpp"

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