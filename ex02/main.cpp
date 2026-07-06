/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:04:59 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/06 21:20:42 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::cout << "\n===== Form creation test=====\n";
	try
	{
		ShrubberyCreationForm f("home");
		Bureaucrat b("manager" , 1);
		b.signForm(f);
		b.executeForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		ShrubberyCreationForm f1("insurance");
		Bureaucrat b1("offic employee" , 140);
		b1.signForm(f1);
		b1.executeForm(f1);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		ShrubberyCreationForm f2("insurance");
		Bureaucrat b2("amatour" , 150);
		b2.signForm(f2);
		b2.executeForm(f2);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n===== Form creation test=====\n";
	return 0;
}
