/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 23:04:33 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/07 00:31:07 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}
AForm* Intern::createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string name, std::string target)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm* (Intern::*creators[3])(const std::string&) =
	{
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPardon
	};
	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*creators[i])(target);
		}
	}

	throw UnknownFormException();
}
const char* Intern::UnknownFormException::what() const throw()
{
	return "Unknown Form!";
}
