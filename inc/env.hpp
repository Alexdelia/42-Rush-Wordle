/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:55:30 by adelille          #+#    #+#             */
/*   Updated: 2022/05/12 22:26:11 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_HPP
# define ENV_HPP

# include <ncurses.h>
# include <set>
# include <cstdlib>

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

		bool	resize(void);
		
		void	set_row(const int row);
		void	set_col(const int col);

		const int	get_row(void) const;
		const int	get_col(void) const;

    private:
        env(const env &src);
        env &operator=(const env &src);

		char						_word_to_guess[WORD_LEN];
		std::set<char[WORD_LEN]>	_guessable_words;

		int							_row;
		int							_col;

        char						_words_tried[WORD_TRY][WORD_LEN];
		int							_letter_status[WORD_TRY][WORD_LEN];
        unsigned int				_try;

};

#endif
