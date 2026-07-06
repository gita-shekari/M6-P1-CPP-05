/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 23:04:29 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/07 00:27:34 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm* createShrubbery(const std::string& target);
		AForm* createRobotomy(const std::string& target);
		AForm* createPardon(const std::string& target);
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();
		AForm *makeForm(const std::string name, std::string target);
		class UnknownFormException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif

