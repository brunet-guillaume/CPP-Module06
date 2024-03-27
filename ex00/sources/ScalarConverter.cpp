/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:12:10 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/27 19:05:02 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctype.h>
#include <cstdlib>
#include <climits>

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
	if (str.compare("+inff") == 0 || str.compare("-inff") == 0 || str.compare("nanf"))
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
	if (str.compare("+inf") == 0 || str.compare("-inf") == 0 || str.compare("nan"))
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

std::string print_float(float nb) {
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
		std::cout << "  char: " << c << std::endl;
	std::cout << "   int: " << static_cast<int>(c) << std::endl;
	std::cout << " float: " << print_float(static_cast<float>(c)) << "f" << std::endl;
	std::cout << "double: " << print_float(static_cast<double>(c)) << std::endl;
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
		else if (str.length() == 11 && str.compare("+2147483648") > 0)
			return (true);
	} else {
		if (str.length() > 10)
			return (true);
		else if (str.length() == 10 && str.compare("2147483648") > 0)
			return (true);
	}
	return (false);
}

static void	convertInt(std::string str) {
	bool	int_overflow = intOverflow(str);
	int		nb;
	double	nb_d;

	if (!int_overflow)
		nb = std::atoi(str.c_str());
	else
		nb_d = std::atof(str.c_str());
	if (!int_overflow) {
		if (isascii(nb)) {
			if (isprint(nb))
				std::cout << "  char: " << static_cast<char>(nb) << std::endl;
			else
				std::cout << "  char: Non displayable" << std::endl;
		} else
			std::cout << "  char: Impossible" << std::endl;
		std::cout << "   int: " << nb << std::endl;
		std::cout << " float: " << print_float(static_cast<float>(nb)) << "f" << std::endl;
		std::cout << "double: " << print_float(static_cast<double>(nb)) << std::endl;
	}
	else {
		std::cout << "  char: Impossible" << std::endl;
		std::cout << "   int: Impossible" << std::endl;
		if (nb_d == 0) {
			std::cout << " float: Impossible" << std::endl;
			std::cout << "double: Impossible" << std::endl;	
		} else {
			std::cout << " float: " << print_float(static_cast<float>(nb_d)) << "f" << std::endl;
			std::cout << "double: " << print_float(nb_d) << std::endl;	
		}
	}
}

static void	convertFloat(std::string str) {
	bool	int_overflow = false;
	float	nb;

	nb = std::atof(str.c_str());
	if (nb < static_cast<float>(INT_MIN) || nb > static_cast<float>(INT_MAX))
		int_overflow = true;
	if (!int_overflow) {
		if (isascii(nb)) {
			if (isprint(nb))
				std::cout << "  char: " << static_cast<char>(nb) << std::endl;
			else
				std::cout << "  char: Non displayable" << std::endl;
		} else
			std::cout << "  char: Impossible" << std::endl;
		std::cout << "   int: " << static_cast<int>(nb) << std::endl;
		std::cout << " float: " << print_float(nb) << "f" << std::endl;
		std::cout << "double: " << print_float(static_cast<double>(nb)) << std::endl;
	}
	else {
		std::cout << "  char: Impossible" << std::endl;
		std::cout << "   int: Impossible" << std::endl;
		std::cout << " float: " << print_float(nb) << "f" << std::endl;
		std::cout << "double: " << print_float(static_cast<double>(nb)) << std::endl;	
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
			std::cout << "DOUBLE";
			break;
		default:
			std::cout << "NONE";
			break;
	}
	std::cout << " <== \"" << str << "\"" << std::endl;
}

