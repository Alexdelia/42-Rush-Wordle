/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_word.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:58:22 by adelille          #+#    #+#             */
/*   Updated: 2022/05/14 16:58:46 by adelille         ###   ########.fr       */
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