/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_size.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:38:14 by adelille          #+#    #+#             */
/*   Updated: 2022/05/14 00:22:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/graphic.hpp"
#include "../../inc/env.hpp"

bool	graphic::valid_size(const int row, const int col)
{
	return (row >= 13 && col >= 12);
}