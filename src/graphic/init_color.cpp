/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:33:38 by adelille          #+#    #+#             */
/*   Updated: 2022/05/14 15:57:27 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "../../inc/graphic.hpp"
#include "../../inc/color_pair.hpp"

static int	r(const int val)
{
	return ((val * 1000) / 256);
}

static void	init_colors_s(void)
{
	init_color(C_WINDOW, r(0x31), r(0x28), r(0x21));
	init_color(C_BOARD, r(0x3a), r(0x3a), r(0x3c));

	init_color(C_GRAY, r(0x81), r(0x83), r(0x84));
	init_color(C_BLACK, r(0x21), r(0x21), r(0x21));
	init_color(C_YELLOW, r(0xb5), r(0x9f), r(0x3b));
	init_color(C_GREEN, r(0x53), r(0x8d), r(0x4e));

	init_color(C_LETTER, r(0xff), r(0xff), r(0xff));
}

static void	init_pairs(void)
{
	init_pair(CP_RED, COLOR_RED, C_WINDOW);
	init_pair(CP_BOARD, C_WINDOW, C_BOARD);
	init_pair(CP_WINDOW, COLOR_WHITE, C_WINDOW);

	init_pair(CP_GRAY, C_LETTER, C_GRAY);
	init_pair(CP_BLACK, C_LETTER, C_BLACK);
	init_pair(CP_YELLOW, C_LETTER, C_YELLOW);
	init_pair(CP_GREEN, C_LETTER, C_GREEN);
}

bool	graphic::init_colors(void)
{
	if (!has_colors())
		return (error("your terminal doesn't support colors", false));
	else if (!can_change_color())
		return (error("your terminal doesn't support color change", false));

	start_color();

	init_colors_s();
	init_pairs();

	bkgd(COLOR_PAIR(CP_BLACK));

	return (true);
}
