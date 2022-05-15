/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:52:00 by adelille          #+#    #+#             */
/*   Updated: 2022/05/15 19:52:02 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.hpp"

bool	env::_choose_word(void)
{
	std::set<std::string>	list;

	if (this->_parse_file(this->_possible_words_file, &list, 500))
		return (false);

	std::set<std::string>::iterator	i = list.begin();

	srand(time(NULL));
	std::advance(i, rand() % list.size());
	strcpy(this->_word_to_guess, (*i).c_str());

	std::cout << "\033[3m" << "word to guess has been choosen"
		<< "\033[0m" << std::endl << std::endl;

	return (true); 
}

bool	env::_fill_guessable_words(void)
{
	return (this->_parse_file(this->_allowed_words_file,
		&this->_guessable_words, 2000));
}

bool	env::_parse_file(const std::string &file,
	std::set<std::string> *list, const unsigned int point)
{
	std::string		buffer;
	std::ifstream	ifs(file.c_str(), std::ifstream::in);

	std::cout << "\033[1;38;2;169;250;169m" << "parsing " 
		<< "\033[0m" << "\033[1m" << file << " ";

	while(ifs.peek()!=EOF)
	{
		getline(ifs, buffer);
		if (!env::_is_valid_word(buffer))
		{
			std::cerr << std::endl << s_error()
				<< "\"" << file
				<< "\" has an incompatible word: \"" << buffer << "\""
				<< std::endl << "\033[3m" << "\t(only " << WORD_LEN << " lowercase letters accepted)"
				<< "\033[0m" << std::endl;
			return (false);
		}
		(*list).insert(buffer);
	}
	ifs.close();

	std::cout << std::endl << "found " << "\033[38;2;255;250;169m"
		<< (*list).size() << "\033[0m" << "\033[1m" << " words" << "\033[0m"
		<< std::endl << std::endl;
	return (true);
}

// test words in both files
bool	env::_is_valid_word(const std::string &word)
{
	if (word.size() != WORD_LEN)
		return (false);
    return (word.find_first_not_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos);
}