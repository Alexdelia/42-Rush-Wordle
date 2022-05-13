/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:55:19 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 14:53:24 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.hpp"

env::env()
{}

env::~env()
{}

bool	env::init(void)
{
	if (graphic::init())
		return (false);

	if (!this->_choose_word()
		|| !this->_fill_guessable_words())
		return (false);

	setlocale(LC_ALL, "");
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);

	if (!this->resize())
		return (false);

	return (true);
}
