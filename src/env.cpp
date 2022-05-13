/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:55:19 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 14:28:47 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/env.hpp"

env::env()
{

}

env::~env()
{}

bool	env::init(void)
{
	if (graphic::init())
		return (false);

	if (!this->_choose_word()
		|| !this->_fill_guessable_words())
		return (false);

	setlocale(LC_ALL, "");
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);

	if (!this->resize())
		return (false);

	return (true);
}

bool	env::_choose_word(void)
{
	size_t						count;
	std::string					buffer;
	std::vector<std::string>	list;
	std::ifstream				ifs(this->_possible_words_file.c_str(), std::ifstream::in);

	std::cout << "\033[1m" << "parsing " << this->_possible_words_file << " ";

	count = 0;
	while(ifs.peek()!=EOF)
	{
		getline(ifs, buffer);
		if (env::_is_valid_word(buffer))
		{
			std::cerr << std::endl << s_error()
				<< "\"" << this->_possible_words_file
				<< "\" have an incompatible word: \"" << buffer << "\""
				<< std::endl << "\033[3m" << "\t(only lowercase letters accepted)"
				<< "\033[0m" << std::endl;
			return (false);
		}
		list.push_back(buffer);
		count++;
		if (count % 500 == 0)
			std::cout << '.';
	}
	ifs.close();

	std::cout << std::endl << "found " << count << " words" << std::endl;

	std::vector<std::string>::iterator	i = list.begin();

	srand(time(NULL));
	i += rand() % count;
	strcpy(this->_word_to_guess, (*i).c_str());

	std::cout << "word to guess has been choosen" << std::endl;

	return (true); 
}

bool	env::_fill_guessable_words(void)
{
	return (true);
}

bool	env::_is_valid_word(const std::string &word)
{
	if (word.size() != WORD_LEN)
		return (false);
    return (word.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != std::string::npos);
}

bool	env::set_files(const std::string &possible, const std::string &allowed)
{
	{
		struct stat	buffer;
		if (stat(possible.c_str(), &buffer) == -1)
		{
			std::cerr << s_error() << possible << " does not exist"
				<< "\033[0m" << std::endl;
			return (false);
		}
		else
			this->_possible_words_file = possible;
	}
	{
		struct stat	buffer;
		if (stat(allowed.c_str(), &buffer) == -1)
		{
			std::cerr << s_error() << allowed << " does not exist"
				<< "\033[0m" << std::endl;
			return (false);
		}
		else
			this->_allowed_words_file = allowed;
	}

	return (true);
}

void	env::set_row(const int row)
{ this->_row = row; }
void	env::set_col(const int col)
{ this->_col = col; }

int		env::get_row(void) const
{ return (this->_row); }
int		env::get_col(void) const
{ return (this->_col); }