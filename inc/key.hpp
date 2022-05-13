/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:47:42 by adelille          #+#    #+#             */
/*   Updated: 2022/05/13 12:48:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HPP
# define KEY_HPP


class key
{
	public:
		static bool	is_exit(const int key);

    private:
		key();
		~key();	
        key(const key &src);
        key &operator=(const key &src);

};

#endif