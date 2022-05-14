/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_word.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:58:22 by adelille          #+#    #+#             */
/*   Updated: 2022/05/14 18:57:48 by adelille         ###   ########.fr       */
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
			this->_alphabet_status[word[i] - 'a'] = STATUS_GREEN;
			answer_status[i] = true;
		}
		else
			answer_status[i] = false;

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
				if (this->_alphabet_status[word[input_index] - 'a'] != STATUS_GREEN)
					this->_alphabet_status[word[input_index] - 'a'] = STATUS_YELLOW;
				answer_status[to_guess_index] = true;
			}
			else if (this->_alphabet_status[word[input_index] - 'a'] == STATUS_GRAY)
				this->_alphabet_status[word[input_index] - 'a'] = STATUS_BLACK;
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
			
		this->_try++;

		if (strcmp(word, this->_word_to_guess) == 0)
		{
			this->_print_win();
			this->_print_words();
			this->_try = 0;
			return (true);
		}
    }
	else
	{
		attrset(A_BOLD | A_ITALIC);
		std::string	not_found_msg("\"" + std::string(word) + "\" isn't in word list");
		mvprintw((this->_row - 1) / 2 - 7,
			(this->_col - not_found_msg.size()) / 2,
			not_found_msg.c_str());
		attrset(A_NORMAL);

		move(((this->_row - 3) - WORD_TRY) / 2 + this->_try,
			(this->_col - WORD_LEN) / 2);
		addstr(std::string(WORD_LEN, ' ').c_str());
		strcpy(this->_words_tried[this->_try], std::string(WORD_LEN, ' ').c_str());
	}

	return (false);
}