/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:12:10 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/27 12:19:26 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter(){};
ScalarConverter::ScalarConverter(const ScalarConverter &cpy) {(void)cpy;};
ScalarConverter::~ScalarConverter(){};

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {(void)rhs; return (*this);}

void	ScalarConverter::convert(const std::string str) {
	std::cout << "Hello, World!\n" << str << std::endl;
}
