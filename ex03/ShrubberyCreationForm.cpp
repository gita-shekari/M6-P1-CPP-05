/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 15:59:14 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/06 21:02:20 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{

}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{

}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{

}
void ShrubberyCreationForm::executeAction() const
{
	std::string fileName = target+"_shrubbery";
	std::ofstream myFile(fileName.c_str());
	if (!myFile.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		return;
	}
	myFile << "   /\\\n";
	myFile << "  /**\\\\\n";
	myFile << " /****\\\\\n";
	myFile << "/******\\\\\n";
	myFile << "   ||\n";
	myFile << "   ||\n";
	myFile.close();
}

