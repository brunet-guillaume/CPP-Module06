/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:20:01 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/28 11:42:20 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "style.h"
#include <iostream>
#include "Serializer.hpp"

void	help_msg(std::string msg) {
	std::cout << GREEN << TITLE << " 💬 " << msg << " " << END_STYLE << std::endl;
}

int	main(void)
{
    Data		test;
    uintptr_t	serialized;
    Data		*deserialized;

	help_msg("Initializing struct Data test with :");
	test.str = "a custom string";
	std::cout << BOLD << &test << END_STYLE << std::endl;
	std::cout << BOLD << " str: " << END_STYLE << THIN << test.str << END_STYLE << std::endl;
	test.nb = 123;
	std::cout << BOLD << "  nb: " << END_STYLE << THIN << test.nb << END_STYLE << std::endl;
	test.d_nb = 123.321;
	std::cout << BOLD << "d_nb: " << END_STYLE << THIN << test.d_nb << END_STYLE << std::endl;

	std::cout << std::endl;
	serialized = Serializer::serialize(&test);
	help_msg("Serialized struct Data test is :");
	std::cout << BOLD << serialized << END_STYLE << std::endl;
	std::cout << THIN << std::hex << serialized << std::dec << " (in hexadecimal)" << END_STYLE << std::endl;

	std::cout << std::endl;
	deserialized = Serializer::deserialize(serialized);
	help_msg("Deserialized serialized struct Data test is :");
	std::cout << BOLD << deserialized << END_STYLE << std::endl;
	std::cout << BOLD << " str: " << END_STYLE << THIN << deserialized->str << END_STYLE << std::endl;
	test.nb = 123;
	std::cout << BOLD << "  nb: " << END_STYLE << THIN << deserialized->nb << END_STYLE << std::endl;
	test.d_nb = 123.321;
	std::cout << BOLD << "d_nb: " << END_STYLE << THIN << deserialized->d_nb << END_STYLE << std::endl;


    return (0);
}
