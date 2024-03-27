/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:12:10 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/27 13:29:07 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <ctype.h>

ScalarConverter::ScalarConverter(){};
ScalarConverter::ScalarConverter(const ScalarConverter &cpy) {(void)cpy;};
ScalarConverter::~ScalarConverter(){};

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {(void)rhs; return (*this);}

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
};

static bool	isFloat(std::string str) {
	int		i = 0;
	bool	hasPoint = false;
	bool	hasSign = false;

	if (str[str.length() - 1] != 'f')
		return (false);
	if (str[0] == '-' || str[0] == '+') {
		i++;
		hasSign = true;
	}
	for (; i < str.length() - 1; i++) {
		if (isdigit(str[i]) || (str[i] == '.' && i !=))
	}
	return (false);
}

static e_type	getType(std::string str) {
	if (str.length == 1) {
		if (isdigit(str[0]))
			return (INT);
		if (isascii(str[0]))
			return (CHAR);
		return (NONE);
	} else if (str.length > 0) {
		
	}
	return (NONE);
}

void	ScalarConverter::convert(const std::string str) {
	getType(str);
	std::cout << "Hello, World!\n" << str << std::endl;
}

