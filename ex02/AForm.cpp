/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 15:51:30 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/03 16:17:01 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute): name(name), is_signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if(gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if(gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();

}
AForm::AForm(const AForm &other): name(other.name), is_signed(other.is_signed), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{

}
AForm &AForm::operator=(const AForm &other)
{
	if(this != &other)
		this->is_signed = other.is_signed;
	return *this;
}

AForm::~AForm()
{

}
const std::string AForm::getName() const
{
	return name;
}
int AForm::getGradeToSign() const
{
	return gradeToSign;
}
int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}
bool AForm::get_is_signed() const
{
	return is_signed;
}
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	is_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}
std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << AForm.getName() << ", sign status is " << AForm.get_is_signed() << ", grade required to sign is " << AForm.getGradeToSign() << ", grade required to execute is " << AForm.getGradeToExecute() << std::endl;
	return out;
}

