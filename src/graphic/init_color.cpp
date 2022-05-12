/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:33:38 by adelille          #+#    #+#             */
/*   Updated: 2022/05/12 22:40:37 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "../../inc/color_pair.hpp"

static int	r(const int val)
{
	return ((val * 1000) / 256);
}

static void	init_colors(void)
{
	init_color(C_LOW_GREEN, r(0x34), r(0x8c), r(0x46));
	init_color(C_WINDOW, r(0x31), r(0x28), r(0x21));
	init_color(C_BOARD, r(0x84), r(0x79), r(0x6b));
}

static void	init_pairs(void)
{
	init_pair(CP_RED, COLOR_RED, C_WINDOW);
	init_pair(CP_GREEN, COLOR_GREEN, C_WINDOW);
	init_pair(CP_MENU, COLOR_MAGENTA, C_WINDOW);
	init_pair(CP_PLAY, COLOR_GREEN, C_WINDOW);
	init_pair(CP_BOARD, C_WINDOW, C_BOARD);
//	init_pair(CP_SCORE, COLOR_B_2048, C_WINDOW);
//	init_pair(CP_EXIT, COLOR_B_64, C_WINDOW);
	init_pair(CP_WINDOW, COLOR_WHITE, C_WINDOW);
}

bool	graphic::init_colors(void)
{
	if (!has_colors())
		return (error("your terminal doesn't support colors", false));
	else if (!can_change_color())
		return (error("your terminal doesn't support color change", false));

	start_color();

	init_colors();
	init_pairs();

	bkgd(COLOR_PAIR(CP_WINDOW));

	return (true);
}
