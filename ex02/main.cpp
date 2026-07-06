/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:04:59 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/06 22:37:35 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b("manager" , 1);
	Bureaucrat b1("offic employee" , 140);
	Bureaucrat b2("amatour" , 150);
	Bureaucrat b3("boss", 44);

	std::cout << "\n===== Form creation test=====\n";
	try
	{
		ShrubberyCreationForm f("home");
		b.signForm(f);
		b.executeForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		ShrubberyCreationForm f1("inssurance");
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
		b2.signForm(f2);
		b2.executeForm(f2);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n===== Robotomy test=====\n";
	try
	{
		RobotomyRequestForm fr("home");
		b.signForm(fr);
		b.executeForm(fr);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		RobotomyRequestForm fr1("insurance");
		b1.signForm(fr1);
		b1.executeForm(fr1);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		RobotomyRequestForm fr2("insurance");
		b3.signForm(fr2);
		b3.executeForm(fr2);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n===== Presidential pardon test=====\n";
	try
	{
		PresidentialPardonForm fp("insurance");
		b.signForm(fp);
		b.executeForm(fp);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		PresidentialPardonForm fp1("insurance");
		b3.signForm(fp1);
		b3.executeForm(fp1);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
