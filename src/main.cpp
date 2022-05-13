/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:31:11 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 15:25:17 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/env.hpp"

int main(int ac, char **av)
{
	env	e;

	if (ac == 3 && !e.set_files(av[1], av[2]))
		return (1);
	else if (ac != 3 && !e.set_files(POSSIBLE_WORDS_FILE, ALLOWED_WORDS_FILE))
		return (1);

	if (!e.init())
		return (1);

	endwin();

	std::cout << "\033[1;38;2;255;183;197m" << "thanks for playing 😊"
		<< "\033[0m" << std::endl;

    return (0);
}