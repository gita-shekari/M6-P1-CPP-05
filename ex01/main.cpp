/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:04:59 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/02 17:07:46 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "===== Form grade too high =====\n";
	try
	{
		Form f("Tax Form", 0, 50);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n===== Form grade too low =====\n";
	try
	{
		Form f("Tax Form", 50, 151);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n===== Valid form =====\n";
	try
	{
		Form f("Leave Request", 50, 25);
		std::cout << f << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n===== Successful signing =====\n";
	try
	{
		Bureaucrat boss("Boss", 1);
		Form f("Contract", 50, 25);

		std::cout << f << '\n';
		boss.signForm(f);
		std::cout << f << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n===== Failed signing =====\n";
	try
	{
		Bureaucrat intern("Intern", 100);
		Form f("Secret Document", 50, 25);

		std::cout << f << '\n';
		intern.signForm(f);
		std::cout << f << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
