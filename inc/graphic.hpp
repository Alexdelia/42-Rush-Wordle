/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:55:30 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 19:01:12 by adelille         ###   ########.fr       */
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

class graphic
{
	public:
		static bool	init(void);
		static bool	init_colors(void);

		static void	frame_resize(const int row, const int col);
		static void	pmw(const std::string &str, const int row, const int col);
		static void board(const int row, const int col);
		static void	keyboard(const int status[26], const int row, const int col);

		static bool	valid_size(const int row, const int col);

    private:
		graphic();
		~graphic();	
        graphic(const graphic &src);
        graphic &operator=(const graphic &src);

};

#endif
