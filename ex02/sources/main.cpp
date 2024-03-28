/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:20:01 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/28 12:05:38 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "style.h"
#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include <unistd.h>

void	help_msg(std::string msg) {
	std::cout << GREEN << TITLE << " 💬 " << msg << " " << END_STYLE << std::endl;
}

Base	*generate(void) {
	return (NULL);
}

void	identify(Base *p) {
	(void)p;
}

void	identify(Base &p) {
	(void)p;
}

int	main(void)
{
	std::srand(time(NULL));

	std::cout << std::rand() << std::endl;
	std::cout << std::rand() << std::endl;
	std::cout << std::rand() << std::endl;
	std::cout << std::rand() << std::endl;
	std::cout << std::rand() << std::endl;
	std::cout << std::rand() << std::endl;
	std::cout << getpid() << std::endl;

	return (0);
}
