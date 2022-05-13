/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmw.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:12:05 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 12:14:37 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/graphic.hpp"

void	graphic::pmw(const std::string &str, const int row, const int col)
{
	mvprintw((row - 1) / 2, (col - str.size()) / 2, str.c_str());
}