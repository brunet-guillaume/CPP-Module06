/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:20:01 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/27 19:06:45 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "style.h"
#include <iostream>

void	help_msg(std::string msg) {
	std::cout << GREEN << TITLE << " 💬 " << msg << " " << END_STYLE << std::endl;
}

void	warning_msg(std::string msg) {
	std::cout << " ⚠️  " << GREEN << BOLD << UNDERLINE << msg << END_STYLE << std::endl;
}

int	main() {
	help_msg("Testing base constructors");

	ScalarConverter::convert("-2147483646");
	ScalarConverter::convert("100352345345345326373423237723982389234223474345000000");
	ScalarConverter::convert("-2147483647");
	ScalarConverter::convert("-2147483648");
	ScalarConverter::convert("-2147483649");
	ScalarConverter::convert("superbe");
	ScalarConverter::convert("s");
	ScalarConverter::convert("\0");
	ScalarConverter::convert("5");
	ScalarConverter::convert("43");
	ScalarConverter::convert("s34");
	ScalarConverter::convert("234e");
	ScalarConverter::convert("\321");
	ScalarConverter::convert("\177");
	ScalarConverter::convert("\75");
	ScalarConverter::convert("0.0");
	ScalarConverter::convert("0.0f");
	ScalarConverter::convert("123.5434f");
	ScalarConverter::convert(".234f");
	ScalarConverter::convert("-23.234f");
	ScalarConverter::convert("+45.345f");
	std::cout << "sdfsdfsdf";
	ScalarConverter::convert("+45.3.45f");
	std::cout << "sdfsdfsdf";
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("-inff");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("0.0123");
	ScalarConverter::convert("4534534.2323");
	ScalarConverter::convert("+4534534.2323");
	ScalarConverter::convert("-23423234543453.234234423");
	ScalarConverter::convert("343.2323432.234");
	ScalarConverter::convert("23423234234.232324d");
	ScalarConverter::convert("324245O.3434");
	return (0);
}
