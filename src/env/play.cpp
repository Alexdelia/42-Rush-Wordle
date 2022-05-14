/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:57:17 by adelille          #+#    #+#             */
/*   Updated: 2022/05/14 12:43:48 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.hpp"

void	env::_try_word_green(const char word[WORD_LEN],
	bool *answer_status)
{
	for (int i = 0; i < WORD_LEN; i++)
	{
		if (word[i] == this->_word_to_guess[i])
		{
			this->_letter_status[this->_try][i] = STATUS_GREEN;
			answer_status[i] = true;
		}
		else
			this->_letter_status[this->_try][i] = STATUS_GRAY;
	}
}

void	env::_try_word_rest(const char word[WORD_LEN],
	bool answer_status[5])
{
	for (int i = 0; i < WORD_LEN; i++)
	{
		for (int x = 0; answer_status[i] == false && x < WORD_LEN; x++)
		{
			if (this->_letter_status[this->_try][x] != STATUS_GREEN
					&& this->_letter_status[this->_try][x] != STATUS_YELLOW
					&& word[i] == this->_word_to_guess[x])
			{
				this->_letter_status[this->_try][x] = STATUS_YELLOW;
				answer_status[i] = true;
			}
		}
	}
}

void	env::_try_word(const char word[WORD_LEN])
{
	bool	answer_status[5] = { false };
	// test if word is valid to find	
	if (_guessable_words.find(word) != _guessable_words.end())
    {
		this->_try_word_green(word, answer_status);
		this->_try_word_rest(word, answer_status);
		this->_try++;
    }
	else
	{
		mvaddstr(0, 0, "not found");	// change and clear
		move(((this->_row - 3) - WORD_TRY) / 2 + this->_try,
			(this->_col - WORD_LEN) / 2);
		addstr(std::string(WORD_LEN, ' ').c_str());
	}

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

		mvaddstr(1, 0, this->_word_to_guess);

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
			mvaddstr(4, 0, this->_words_tried[this->_try]);
			this->_try_word(this->_words_tried[this->_try]);
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
			this->_words_tried[this->_try][i] = key;
			addch(key - 32);
			i++;
		}
	}
}