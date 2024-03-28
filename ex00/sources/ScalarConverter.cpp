/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:12:10 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/28 10:12:00 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctype.h>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include "style.h"

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

static bool	isInt(std::string str) {
	size_t	i = 0;

	if (str[0] == '-' || str[0] == '+')
		i++;
	for (; i < str.length(); i++) {
		if (isdigit(str[i])) {
			continue ;
		} else {
			return (false);
		}
	}
	return (true);
}

static bool	isFloat(std::string str) {
	size_t	i = 0;
	bool	hasPoint = false;

	if (str[str.length() - 1] != 'f')
		return (false);
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '.')
		return (false);
	if (str == "+inff" || str == "-inff" || str == "nanf")
		return (true);
	for (; i < str.length() - 1; i++) {
		if (isdigit(str[i])) {
			continue ;
		} else if (str[i] == '.' && !hasPoint) {
			hasPoint = true;
			continue ;
		} else {
			return (false);
		}
	}
	return (true);
}

static bool	isDouble(std::string str) {
	size_t	i = 0;
	bool	hasPoint = false;

	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '.')
		return (false);
	if (str == "+inf" || str == "-inf" || str == "nan")
		return (true);
	for (; i < str.length(); i++) {
		if (isdigit(str[i])) {
			continue ;
		} else if (str[i] == '.' && !hasPoint) {
			hasPoint = true;
			continue ;
		} else {
			return (false);
		}
	}
	return (true);
}

static e_type	getType(std::string str) {
	if (str.length() == 0)
		return (CHAR);
	if (str.length() == 1) {
		if (isdigit(str[0]))
			return (INT);
		if (isascii(str[0]))
			return (CHAR);
		return (NONE);
	} else if (str.length() > 0) {
		if (isInt(str))
			return (INT);
		if (isFloat(str))
			return (FLOAT);
		if (isDouble(str))
			return (DOUBLE);
	}
	return (NONE);
}

std::string print_float(double nb) {
	std::ostringstream	strout;
	std::string			str;

	strout << std::fixed << nb;
	str = strout.str();
	str = str.erase(str.find_last_not_of('0') + 1);
	if (str[str.length() - 1] == '.')
		str += "0";
	return (str);
}

static void	convertChar(char c) {
	if (!isprint(c))
		std::cout << "  char: Non displayable" << std::endl;
	else
		std::cout << BOLD << "  char: " << END_STYLE << THIN << c << END_STYLE << std::endl;
	std::cout << BOLD << "   int: " << END_STYLE << THIN << static_cast<int>(c) << END_STYLE << std::endl;
	std::cout << BOLD << " float: " << END_STYLE << THIN << print_float(static_cast<float>(c)) << "f" << END_STYLE << std::endl;
	std::cout << BOLD << "double: " << END_STYLE << THIN << print_float(static_cast<double>(c)) << END_STYLE << std::endl;
}

static bool	intOverflow(std::string str) {	
	if (str[0] == '-') {
		if (str.length() > 11)
			return (true);
		else if (str.length() == 11 && str.compare("-2147483648") > 0)
			return (true);
	} else if (str[0] == '+') {
		if (str.length() > 11)
			return (true);
		else if (str.length() == 11 && str.compare("+2147483647") > 0)
			return (true);
	} else {
		if (str.length() > 10)
			return (true);
		else if (str.length() == 10 && str.compare("2147483647") > 0)
			return (true);
	}
	return (false);
}

static void	convertInt(std::string str) {
	bool	int_overflow = intOverflow(str);
	int		nb;

	if (!int_overflow)
		nb = std::atoi(str.c_str());
	if (!int_overflow) {
		if (isascii(nb)) {
			if (isprint(nb))
				std::cout << BOLD << "  char: " << END_STYLE << THIN << static_cast<char>(nb) << END_STYLE << std::endl;
			else
				std::cout << BOLD << "  char: " << END_STYLE << THIN << "Non displayable" << END_STYLE << std::endl;
		} else
			std::cout << BOLD << "  char: " << END_STYLE << THIN << "Impossible" << END_STYLE << std::endl;
		std::cout << BOLD << "   int: " << END_STYLE << THIN << nb << END_STYLE << std::endl;
		std::cout << BOLD << " float: " << END_STYLE << THIN << print_float(static_cast<float>(nb)) << "f" << END_STYLE << std::endl;
		std::cout << BOLD << "double: " << END_STYLE << THIN << print_float(static_cast<double>(nb)) << END_STYLE << std::endl;
	}
	else {
		std::cout << BOLD << "  char: " << END_STYLE << THIN << "Impossible" << END_STYLE << std::endl;
		std::cout << BOLD << "   int: " << END_STYLE << THIN << "Impossible" << END_STYLE << std::endl;
		std::cout << BOLD << " float: " << END_STYLE << THIN << "Impossible" << END_STYLE << std::endl;
		std::cout << BOLD << "double: " << END_STYLE << THIN << "Impossible" << END_STYLE << std::endl;
	}
}

static void	convertFloat(std::string str) {
	bool	int_overflow = false;
	float	nb;	
	
	nb = std::strtof(str.c_str(), NULL);
	if (static_cast<double>(nb) < static_cast<double>(INT_MIN) || nb > static_cast<double>(INT_MAX)
			|| str == "+inff" || str == "-inff" || str == "nanf")
		int_overflow = true;
	if (!int_overflow) {
		if (isascii(nb)) {
			if (isprint(nb))
				std::cout << BOLD << "  char: " << END_STYLE << THIN << static_cast<char>(nb) << END_STYLE << std::endl;
			else
				std::cout << BOLD << "  char: " << END_STYLE << THIN << "Non displayable" << END_STYLE << std::endl;
		} else
			std::cout << BOLD << "  char: " << END_STYLE << THIN << "Impossible" << END_STYLE << std::endl;
		std::cout << BOLD << "   int: " << END_STYLE << THIN << static_cast<int>(nb) << END_STYLE << std::endl;
		std::cout << BOLD << " float: " << END_STYLE << THIN << print_float(nb) << "f" << END_STYLE << std::endl;
		std::cout << BOLD << "double: " << END_STYLE << THIN << print_float(static_cast<double>(nb)) << END_STYLE << std::endl;
	}
	else {
		std::cout << BOLD << "  char: " << END_STYLE << THIN << "Impossible" << END_STYLE << std::endl;
		std::cout << BOLD << "   int: " << END_STYLE << THIN << "Impossible" << END_STYLE << std::endl;
		std::cout << BOLD << " float: " << END_STYLE << THIN << print_float(nb) << "f" << END_STYLE << std::endl;
		std::cout << BOLD << "double: " << END_STYLE << THIN << print_float(static_cast<double>(nb)) << END_STYLE << std::endl;	
	}
}

static void	convertDouble(std::string str) {
	bool	int_overflow = false;
	double	nb;

	nb = std::strtod(str.c_str(), NULL);
	if (nb < static_cast<double>(INT_MIN) || nb > static_cast<double>(INT_MAX)
			|| str == "+inf" || str == "-inf" || str == "nan")
		int_overflow = true;
	if (!int_overflow) {
		if (isascii(nb)) {
			if (isprint(nb))
				std::cout << BOLD << "  char: " << END_STYLE << THIN << static_cast<char>(nb) << END_STYLE << std::endl;
			else
				std::cout << BOLD << "  char: " << END_STYLE << THIN << "Non displayable" << END_STYLE << std::endl;
		} else
			std::cout << BOLD << "  char: " << END_STYLE << THIN << "Impossible" << END_STYLE << std::endl;
		std::cout << BOLD << "   int: " << END_STYLE << THIN << static_cast<int>(nb) << END_STYLE << std::endl;
		std::cout << BOLD << " float: " << END_STYLE << THIN << print_float(static_cast<float>(nb)) << "f" << END_STYLE << std::endl;
		std::cout << BOLD << "double: " << END_STYLE << THIN << print_float(nb) << END_STYLE << std::endl;
	}
	else {
		std::cout << BOLD << "  char: " << END_STYLE << THIN << "Impossible" << END_STYLE << std::endl;
		std::cout << BOLD << "   int: " << END_STYLE << THIN << "Impossible" << END_STYLE << std::endl;
		std::cout << BOLD << " float: " << END_STYLE << THIN << print_float(static_cast<float>(nb)) << "f" << END_STYLE << std::endl;
		std::cout << BOLD << "double: " << END_STYLE << THIN << print_float(nb) << END_STYLE << std::endl;
	}
}

void	ScalarConverter::convert(const std::string str) {
	std::cout << std::fixed;
	switch (getType(str)) {
		case CHAR:
			convertChar(str[0]);
			break;
		case INT:
			convertInt(str);
			break;
		case FLOAT:
			convertFloat(str);
			break;
		case DOUBLE:
			convertDouble(str);
			break;
		default:
			std::cout << BOLD << "  char: " << END_STYLE << THIN << "Impossible" << END_STYLE << std::endl;
			std::cout << BOLD << "   int: " << END_STYLE << THIN << "Impossible" << END_STYLE << std::endl;
			std::cout << BOLD << " float: " << END_STYLE << THIN << "Impossible" << END_STYLE << std::endl;
			std::cout << BOLD << "double: " << END_STYLE << THIN << "Impossible" << END_STYLE << std::endl;
			break;
	}
}
