/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 21:56:21 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/02 18:10:48 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute): name(name), is_signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if(gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if(gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();

}
Form::Form(const Form &other): name(other.name), is_signed(other.is_signed), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{

}
Form &Form::operator=(const Form &other)
{
	if(this != &other)
		this->is_signed = other.is_signed;
	return *this;
}

Form::~Form()
{
	
}
const std::string Form::getName() const
{
	return name;
}
int Form::getGradeToSign() const
{
	return gradeToSign;
}
int Form::getGradeToExecute() const
{
	return gradeToExecute;
}
bool Form::get_is_signed() const
{
	return is_signed;
}
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}
std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << ", sign status is " << form.get_is_signed() << ", grade required to sign is " << form.getGradeToSign() << ", grade required to execute is " << form.getGradeToExecute() << std::endl;
	return out;
}
