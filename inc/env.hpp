/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:55:30 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 15:08:57 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_HPP
# define ENV_HPP

# include <ncurses.h>
# include <iostream>
# include <fstream>
# include <string.h>
# include <string>
# include <vector>
# include <set>
# include <cstdlib>
# include <sys/stat.h>

# include "graphic.hpp"
# include "key.hpp"
# include "utils.hpp"

# define POSSIBLE_WORDS_FILE	"./words/possible_words.txt"
# define ALLOWED_WORDS_FILE		"./words/allowed_words.txt"

# define WORD_LEN   5
# define WORD_TRY   6

# define STATUS_GRAY	0
# define STATUS_RED		1
# define STATUS_YELLOW	2
# define STATUS_GREEN	3

class env
{
	public:
		env();
		~env();

		int		key;

		bool	init(void);
		bool	resize(void);
	
		bool	set_files(const std::string &possible, const std::string &allowed);
		void	set_row(const int row);
		void	set_col(const int col);

		int		get_row(void) const;
		int		get_col(void) const;

    private:
        env(const env &src);
        env &operator=(const env &src);

		std::string					_possible_words_file;
		std::string					_allowed_words_file;

		char						_word_to_guess[WORD_LEN];
		std::set<std::string>		_guessable_words;

		int							_row;
		int							_col;

        char						_words_tried[WORD_TRY][WORD_LEN];
		int							_letter_status[WORD_TRY][WORD_LEN];
        unsigned int				_try;
		
		bool	_choose_word(void);
		bool	_fill_guessable_words(void);
		bool	_is_valid_word(const std::string &word);
		size_t	_parse_file(const std::string &file,
					std::set<std::string> *list,
					const unsigned int point);
		

};

#endif
