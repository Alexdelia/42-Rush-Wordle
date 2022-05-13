/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:33:38 by adelille          #+#    #+#             */
/*   Updated: 2022/05/14 00:46:44 by adelille         ###   ########.fr       */
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
	//init_color(C_BOARD, r(0x84), r(0x79), r(0x6b));
	init_color(C_BOARD, r(0x93), r(0x95), r(0x98));

	//init_color(C_GRAY, r(0xed), r(0xf4), r(0xee));
	init_color(C_GRAY, r(0xed), r(0xf4), r(0xee));
	//init_color(C_BLACK, r(0x40), r(0x41), r(0x40));
	init_color(C_BLACK, r(0x21), r(0x21), r(0x21));
	//init_color(C_YELLOW, r(0xcc), r(0xd8), r(0x51));
	init_color(C_YELLOW, r(0xc9), r(0xb4), r(0x58));
	//init_color(C_GREEN, r(0x0e), r(0xd6), r(0x44));
	init_color(C_GREEN, r(0x6a), r(0xaa), r(0x64));
}

static void	init_pairs(void)
{
	init_pair(CP_RED, COLOR_RED, C_WINDOW);
	init_pair(CP_BOARD, C_WINDOW, C_BOARD);
	init_pair(CP_WINDOW, COLOR_WHITE, C_WINDOW);

	init_pair(CP_GRAY, COLOR_WHITE, C_GRAY);
	init_pair(CP_BLACK, COLOR_WHITE, C_BLACK);
	init_pair(CP_YELLOW, COLOR_WHITE, C_YELLOW);
	init_pair(CP_GREEN, COLOR_WHITE, C_GREEN);
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
