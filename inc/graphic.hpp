/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:55:30 by adelille          #+#    #+#             */
/*   Updated: 2022/05/14 17:05:48 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_HPP
# define GRAPHIC_HPP

# include "env.hpp"

# include <ncurses.h>
# include <string>

# define KEYBOARD_ROW_0	"QWERTYUIOP"
# define KEYBOARD_ROW_1	"ASDFGHJKL"
# define KEYBOARD_ROW_2	"ZXCVBNM"

# ifndef WORD_LEN
#  define WORD_LEN   5
#  define WORD_TRY   6
# endif

class graphic
{
	public:
		static bool	init_colors(void);

		static void	frame_resize(const int row, const int col);
		static void	pmw(const std::string &str, const int row, const int col);
		static void frame(const int row, const int col);
		static void	keyboard(const int row, const int col,
			const int alphabet_status[26]);
		static void	keyboard_cpp(const int row, const int col,
			const int alphabet_status[26]);	// tmp

		static bool	valid_size(const int row, const int col);

    private:
		graphic();
		~graphic();	
        graphic(const graphic &src);
        graphic &operator=(const graphic &src);

};

#endif
