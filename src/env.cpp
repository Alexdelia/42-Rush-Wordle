/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:55:19 by adelille          #+#    #+#             */
/*   Updated: 2022/05/12 23:01:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/env.hpp"

env::env()
{
	if (graphic::init())
		return ;	// different handle
}

env::~env()
{}

void		env::set_row(const int row)
{ this->_row = row; }
void		env::set_row(const int col)
{ this->_col = col; }

const int	env::get_row(void) const
{ return (this->_row); }
const int	env::get_col(void) const
{ return (this->_col); }