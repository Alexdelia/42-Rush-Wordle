/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:55:19 by adelille          #+#    #+#             */
/*   Updated: 2022/05/14 12:45:01 by adelille         ###   ########.fr       */
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
	
	return (true);
}
