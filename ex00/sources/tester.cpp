/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:20:01 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/28 10:09:44 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <stdlib.h>
#include "style.h"
#include <climits>

void	test(std::string str) {
	std::cout << GREEN << TITLE << " 💬 " << str << " " << END_STYLE << std::endl;
	system(str.c_str());
	std::cout << std::endl;
}

int	main() {
	test("./convert q");
	test("./convert w");
	test("./convert e");
	test("./convert r");
	test("./convert t");
	test("./convert y");
	test("./convert Q");
	test("./convert W");
	test("./convert E");
	test("./convert R");
	test("./convert T");
	test("./convert Y");
	test("./convert [");
	test("./convert $");
	test("./convert !");

	std::cout << std::endl << std::endl << std::endl;
	test("./convert -5");
	test("./convert -2");
	test("./convert 0");
	test("./convert 2");
	test("./convert +5");
	test("./convert 35");
	test("./convert 45");
	test("./convert +55");
	test("./convert -2147483649");
	test("./convert -2147483648");
	test("./convert 2147483647");
	test("./convert 2147483648");
	test("./convert +2147483647");
	test("./convert +2147483648");
	test("./convert -9223372036854775809");
	test("./convert -9223372036854775808");
	test("./convert 9223372036854775807");
	test("./convert 9223372036854775808");
	test("./convert +9223372036854775807");
	test("./convert +9223372036854775808");
	test("./convert -9223372036854775808374634875638475638745683746578346534");
	test("./convert 9223372036854775808374634875638475638745683746578346534");
	test("./convert +9223372036854775808374634875638475638745683746578346534");

	std::cout << std::endl << std::endl << std::endl;
	test("./convert -5.0f");
	test("./convert -2.0f");
	test("./convert 0.0f");
	test("./convert 2.0f");
	test("./convert +5.0f");
	test("./convert 35.0f");
	test("./convert 45.0f");
	test("./convert +55.0f");
	test("./convert -2147483777.0f");
	test("./convert -2147483776.0f");
	test("./convert -2147483649.0f");
	test("./convert -2147483648.0f");
	test("./convert 2147483583.0f");
	test("./convert 2147483584.0f");
	test("./convert 2147483647.0f");
	test("./convert 2147483648.0f");
	test("./convert +2147483583.0f");
	test("./convert +2147483584.0f");
	test("./convert +2147483647.0f");
	test("./convert +2147483648.0f");
	test("./convert -9223372036854775809.0f");
	test("./convert -9223372036854775808.0f");
	test("./convert 9223372036854775807.0f");
	test("./convert 9223372036854775808.0f");
	test("./convert +9223372036854775807.0f");
	test("./convert +9223372036854775808.0f");
	test("./convert -9223372036854775808374634875638475638745683746578346534.0f");
	test("./convert 9223372036854775808374634875638475638745683746578346534.0f");
	test("./convert +9223372036854775808374634875638475638745683746578346534.0f");

	std::cout << std::endl << std::endl << std::endl;
	test("./convert -5.123413345f");
	test("./convert -2.345f");
	test("./convert 0.000000345f");
	test("./convert 2.0334756347868374634875f");
	test("./convert +5.0000345f");
	test("./convert 35.034534f");
	test("./convert 45.01f");
	test("./convert +55.00006f");
	test("./convert +52345873465.006f");

	std::cout << std::endl << std::endl << std::endl;
	test("./convert -5.0");
	test("./convert -2.0");
	test("./convert 0.0");
	test("./convert 2.0");
	test("./convert +5.0");
	test("./convert 35.0");
	test("./convert 45.0");
	test("./convert +55.0");
	test("./convert -2147483777.0");
	test("./convert -2147483776.0");
	test("./convert -2147483649.0");
	test("./convert -2147483648.0");
	test("./convert 2147483583.0");
	test("./convert 2147483584.0");
	test("./convert 2147483647.0");
	test("./convert 2147483648.0");
	test("./convert +2147483583.0");
	test("./convert +2147483584.0");
	test("./convert +2147483647.0");
	test("./convert +2147483648.0");
	test("./convert -9223372036854775809.0");
	test("./convert -9223372036854775808.0");
	test("./convert 9223372036854775807.0");
	test("./convert 9223372036854775808.0");
	test("./convert +9223372036854775807.0");
	test("./convert +9223372036854775808.0");
	test("./convert -9223372036854775808374634875638475638745683746578346534.0");
	test("./convert 9223372036854775808374634875638475638745683746578346534.0");
	test("./convert +9223372036854775808374634875638475638745683746578346534.0");
	test("./convert -9923437454658734657837458973489573948759384759837459873489573498347658734658734658763478563478568734658736458763487563874658723437458973495345345234757346587346578327345762348576348756384756834938475983745897348957394875938475983745987348957349834765873465873465876347856347856873465873645876348756387465873645876348756347865577434234234234234234234223372036854775808374634875638475638745683746578346534.0");
	test("./convert 9923437454658734657837458973489573948759384759837459873489573498347658734658734658763478563478568734658736458763487563874658723437458973495345345234757346587346578327345762348576348756384756834938475983745897348957394875938475983745987348957349834765873465873465876347856347856873465873645876348756387465873645876348756347865577434234234234234234234223372036854775808374634875638475638745683746578346534.0");
	test("./convert +9923437454658734657837458973489573948759384759837459873489573498347658734658734658763478563478568734658736458763487563874658723437458973495345345234757346587346578327345762348576348756384756834938475983745897348957394875938475983745987348957349834765873465873465876347856347856873465873645876348756387465873645876348756347865577434234234234234234234223372036854775808374634875638475638745683746578346534.0");

	std::cout << std::endl << std::endl << std::endl;
	test("./convert -5.123413345");
	test("./convert -2.345");
	test("./convert 0.000000345");
	test("./convert 2.0334756347868374634875");
	test("./convert +5.0000345");
	test("./convert 35.034534");
	test("./convert 45.01");
	test("./convert +55.00006");
	test("./convert +52345873465.006");

	std::cout << std::endl << std::endl << std::endl;
	test("./convert -inff");
	test("./convert -inf");
	test("./convert +inff");
	test("./convert +inf");
	test("./convert nanf");
	test("./convert nan");
	return (0);
}
