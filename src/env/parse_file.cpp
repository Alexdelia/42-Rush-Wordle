/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:52:00 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 14:57:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.hpp"

bool	env::_choose_word(void)
{
	size_t					count;
	std::set<std::string>	list;

	count = this->_parse_file(this->_possible_words_file, &list);
	if (!count)
		return (false);

	std::set<std::string>::iterator	i = list.begin();

	srand(time(NULL));
	std::advance(i, rand() % count);
	strcpy(this->_word_to_guess, (*i).c_str());

	std::cout << "word to guess has been choosen" << std::endl;

	return (true); 
}

bool	env::_fill_guessable_words(void)
{
	return (this->_parse_file(this->_allowed_words_file,
		&this->_guessable_words));
}

size_t	env::_parse_file(const std::string &file,
	std::set<std::string> *list)
{
	size_t			count;
	std::string		buffer;
	std::ifstream	ifs(file.c_str(), std::ifstream::in);

	std::cout << "\033[1m" << "parsing " << file << " ";

	count = 0;
	while(ifs.peek()!=EOF)
	{
		getline(ifs, buffer);
		if (env::_is_valid_word(buffer))
		{
			std::cerr << std::endl << s_error()
				<< "\"" << file
				<< "\" have an incompatible word: \"" << buffer << "\""
				<< std::endl << "\033[3m" << "\t(only lowercase letters accepted)"
				<< "\033[0m" << std::endl;
			return (false);
		}
		(*list).insert(buffer);
		count++;
		if (count % 2000 == 0)
			std::cout << '.';
	}
	ifs.close();

	std::cout << std::endl << "found " << count << " words" << std::endl;
	
	return (count);
}

bool	env::_is_valid_word(const std::string &word)
{
	if (word.size() != WORD_LEN)
		return (false);
    return (word.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != std::string::npos);
}