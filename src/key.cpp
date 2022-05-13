/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:45:59 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 21:45:00 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/key.hpp"

bool	key::is_exit(const int key)
{
	return (key == 'q'
		|| key == KEY_DC
		|| key == KEY_END
		|| key == KEY_EXIT
		|| key == KEY_ESCAPE
		|| key == KEY_CC
		|| key == KEY_CD);
}