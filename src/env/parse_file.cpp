/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:52:00 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 23:39:47 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.hpp"

bool	env::_choose_word(void)
{
	size_t					count;
	std::set<std::string>	list;

	count = this->_parse_file(this->_possible_words_file, &list, 500);
	if (!count)
		return (false);

	std::set<std::string>::iterator	i = list.begin();

	srand(time(NULL));
	std::advance(i, rand() % count);
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

size_t	env::_parse_file(const std::string &file,
	std::set<std::string> *list, const unsigned int point)
{
	size_t			count;
	std::string		buffer;
	std::ifstream	ifs(file.c_str(), std::ifstream::in);

	std::cout << "\033[1;38;2;169;250;169m" << "parsing " 
		<< "\033[0m" << "\033[1m" << file << " ";

	count = 0;
	while(ifs.peek()!=EOF)
	{
		getline(ifs, buffer);
		if (!env::_is_valid_word(buffer))
		{
			std::cerr << std::endl << s_error()
				<< "\"" << file
				<< "\" has an incompatible word: \"" << buffer << "\""
				<< std::endl << "\033[3m" << "\t(only lowercase letters accepted)"	// size of 5
				<< "\033[0m" << std::endl;
			return (false);
		}
		(*list).insert(buffer);
		count++;
		if (count % point == 0)
			std::cout << '.';
	}
	ifs.close();

	std::cout << std::endl << "found " << "\033[38;2;255;250;169m"
		<< count << "\033[0m" << "\033[1m" << " words" << "\033[0m"
		<< std::endl << std::endl;
	
	return (count);
}


// test words in both files
bool	env::_is_valid_word(const std::string &word)
{
	if (word.size() != WORD_LEN)
		return (false);
    return (word.find_first_not_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos);
}