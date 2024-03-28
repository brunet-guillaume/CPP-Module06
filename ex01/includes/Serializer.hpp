/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:07:12 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/28 11:20:16 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <stdint.h>

typedef struct s_Data {
	std::string	str;
	int			nb;
	double		d_nb;
} Data;

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer &cpy);
		
		~Serializer();

		Serializer &operator=(const Serializer &rhs);

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif
