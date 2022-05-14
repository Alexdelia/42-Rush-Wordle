/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:55:19 by adelille          #+#    #+#             */
/*   Updated: 2022/05/14 11:33:00 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.hpp"

env::env(): key(0), _try(0)
{

}

env::~env()
{}

bool	env::init(void)
{
	if (!this->_choose_word()
		|| !this->_fill_guessable_words())
		return (false);

	setlocale(LC_ALL, "");
	initscr();
	raw();
	noecho();
	//keypad(stdscr, TRUE);

	if (!graphic::init())
		return (endwin(), false);

	if (!this->resize())
		return (endwin(), false);
	
	strcpy(this->_words_tried[0], "hello");
	this->_try++;
	this->_letter_status[0][0] = CP_GREEN;
	this->_letter_status[0][1] = CP_YELLOW;
	this->_letter_status[0][2] = CP_BLACK;
	this->_letter_status[0][3] = CP_BLACK;
	this->_letter_status[0][4] = CP_GREEN;

	return (true);
}
