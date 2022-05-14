/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:57:17 by adelille          #+#    #+#             */
/*   Updated: 2022/05/14 16:56:19 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.hpp"

void	env::_try_word_green(const char word[WORD_LEN], bool *answer_status)
{
	size_t	i;

	i = 0;
	while (i < WORD_LEN)
	{
		if (word[i] == this->_word_to_guess[i])
		{
			this->_letter_status[this->_try][i] = STATUS_GREEN;
			answer_status[i] = true;
		}
		else
		{
			this->_letter_status[this->_try][i] = STATUS_BLACK;
			answer_status[i] = false;
		}
		this->_alphabet_status[word[i] - 'a']
			= this->_letter_status[this->_try][i];
		i++;
	}
}

void	env::_try_word_rest(const char word[WORD_LEN], bool answer_status[5])
{
	size_t	to_guess_index;
	size_t	input_index;

	to_guess_index = 0;
	while (to_guess_index < WORD_LEN)
	{
		input_index = 0;
		while (answer_status[to_guess_index] == false
				&& input_index < WORD_LEN)
		{
			if (this->_letter_status[this->_try][input_index] != STATUS_GREEN
					&& this->_letter_status[this->_try][input_index] != STATUS_YELLOW
					&& word[input_index] == this->_word_to_guess[to_guess_index])
			{
				this->_letter_status[this->_try][input_index] = STATUS_YELLOW;
				this->_alphabet_status[word[input_index] - 'a'] = STATUS_YELLOW;
				answer_status[to_guess_index] = true;
			}
			input_index++;
		}
		to_guess_index++;
	}
}

bool	env::_try_word(const char word[WORD_LEN])
{
	bool	answer_status[5] = { false };
	
	if (_guessable_words.find(word) != _guessable_words.end())
    {
		this->_try_word_green(word, answer_status);
		this->_try_word_rest(word, answer_status);
		
		if (strcmp(word, this->_word_to_guess) == 0)
		{
			this->_print_win();
			this->_try = 0;
			return (true);
		}
		
		this->_try++;
    }
	else
	{
		mvaddstr(0, 0, "not found");	// change and clear
		move(((this->_row - 3) - WORD_TRY) / 2 + this->_try,
			(this->_col - WORD_LEN) / 2);
		addstr(std::string(WORD_LEN, ' ').c_str());
		strcpy(this->_words_tried[this->_try], std::string(WORD_LEN, ' ').c_str());
	}

	return (false);
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
			this->_words_tried[this->_try][WORD_LEN] = '\0';
			
			mvaddstr(4, 0, this->_words_tried[this->_try]);	// debug

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
	
	if (this->_try == WORD_TRY)
		this->_print_lost();

	getch();
}