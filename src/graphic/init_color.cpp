/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:33:38 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 20:32:56 by adelille         ###   ########.fr       */
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
	init_color(C_BOARD, r(0x84), r(0x79), r(0x6b));
}

static void	init_pairs(void)
{
	init_pair(CP_RED, COLOR_RED, C_WINDOW);
	init_pair(CP_BOARD, C_WINDOW, C_BOARD);
	init_pair(CP_WINDOW, COLOR_WHITE, C_WINDOW);
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

	bkgd(COLOR_PAIR(CP_WINDOW));

	return (true);
}
