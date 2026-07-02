/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 21:56:25 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/02 18:09:38 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int gradeToSign;
		const int gradeToExecute;
	public:
		Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		const std::string getName() const;
		bool get_is_signed() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

};
std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
