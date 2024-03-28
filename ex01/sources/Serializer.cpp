/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:12:10 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/28 11:18:18 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "style.h"

Serializer::Serializer(){};
Serializer::Serializer(const Serializer &cpy) {(void)cpy;};
Serializer::~Serializer(){};

Serializer &Serializer::operator=(const Serializer &rhs) {(void)rhs; return (*this);}

uintptr_t	Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}
