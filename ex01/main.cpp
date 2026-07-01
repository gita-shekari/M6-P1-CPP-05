/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:04:59 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/01 21:53:26 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Gita", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "b1: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b2("Gita", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "b2: " << e.what()<< std::endl;
	}

	try
	{
		Bureaucrat b3("Gita", 1);
		std::cout << b3;
		b3.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "b3: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b4("Sara", 150);
		std::cout << b4;
		b4.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "b4: " << e.what() << std::endl;
	}

	return 0;
}
