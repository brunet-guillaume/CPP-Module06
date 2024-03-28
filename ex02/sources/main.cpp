/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:20:01 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/28 13:46:44 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "style.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void	help_msg(std::string msg) {
	std::cout << GREEN << TITLE << " 💬 " << msg << " " << END_STYLE << std::endl;
}

Base	*generate(void) {
	int	rand = std::rand() % 3;

	if (rand == 0)
		return (new A);
	else if (rand == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &p) {
	Base test;
	try {
		test = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {}
	try {
		test = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception &e) {}
	try {
		test = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception &e) {}
}

int	main(void)
{
	Base	*tmp;

	std::srand(time(NULL) * getpid() * getpid());

	help_msg("Identifying (with pointer) 10 classes (A, B or C) generated randomly");
	for (int i = 0; i < 10; i++) {
		tmp = generate();
		identify(tmp);
		delete tmp;
	}

	std::cout << std::endl;
	help_msg("Identifying (with reference) 10 classes (A, B or C) generated randomly");
	for (int i = 0; i < 10; i++) {
		tmp = generate();
		identify(*tmp);
		delete tmp;
	}

	std::cout << std::endl;
	help_msg("Identifying (with pointer) classes generated manually");
	tmp = new A;
	std::cout << BOLD << "A: " << CYAN;
	identify(tmp);
	std::cout << END_STYLE;
	delete tmp;
	tmp = new B;
	std::cout << BOLD << "B: " << CYAN;
	identify(tmp);
	std::cout << END_STYLE;
	delete tmp;
	tmp = new C;
	std::cout << BOLD << "C: " << CYAN;
	identify(tmp);
	std::cout << END_STYLE;
	delete tmp;

	std::cout << std::endl;
	help_msg("Identifying (with reference) classes generated manually");
	tmp = new A;
	std::cout << BOLD << "A: " << CYAN;
	identify(*tmp);
	std::cout << END_STYLE;
	delete tmp;
	tmp = new B;
	std::cout << BOLD << "B: " << CYAN;
	identify(*tmp);
	std::cout << END_STYLE;
	delete tmp;
	tmp = new C;
	std::cout << BOLD << "C: " << CYAN;
	identify(*tmp);
	std::cout << END_STYLE;
	delete tmp;
	return (0);
}
