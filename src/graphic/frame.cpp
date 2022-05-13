/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:42:04 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 18:04:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/graphic.hpp"

void	graphic::frame_resize(const int row, const int col)
{
	mvprintw(0, 0, "⌜");
	mvprintw(0, col - 1, "⌝");
	mvprintw(row - 1, 0, "⌞");
	mvprintw(row - 1, col - 1, "⌟");
}