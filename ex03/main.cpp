/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:04:59 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/07 00:34:18 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "\n===== INTERN TEST =====\n";

	Intern intern;
	Bureaucrat boss("Boss", 1);

	try
	{
		std::cout << "\n--- Creating Shrubbery Form ---\n";

		AForm* shrubbery = intern.makeForm("shrubbery creation","home");
		boss.signForm(*shrubbery);
		boss.executeForm(*shrubbery);
		delete shrubbery;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n--- Creating Robotomy Form ---\n";
		AForm* robotomy = intern.makeForm("robotomy request","Bender");
		boss.signForm(*robotomy);
		boss.executeForm(*robotomy);
		delete robotomy;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n--- Creating Presidential Form ---\n";
		AForm* pardon = intern.makeForm("presidential pardon","Arthur Dent");
		boss.signForm(*pardon);
		boss.executeForm(*pardon);
		delete pardon;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n--- Testing Unknown Form ---\n";
		AForm* unknown = intern.makeForm("coffee request","office");
		delete unknown;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Intern error: " << e.what() << std::endl;
	}
	return 0;
}
