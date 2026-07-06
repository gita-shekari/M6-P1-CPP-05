/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 15:51:41 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/06 21:00:45 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool is_signed;
		const int gradeToSign;
		const int gradeToExecute;
	public:
		AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		const std::string getName() const;
		bool get_is_signed() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat const &bureaucrat);
		void execute(Bureaucrat const &executor) const;
		virtual void executeAction() const = 0;
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
		class FormIsNotSigned : public std::exception
		{
			public :
				const char* what() const throw();
		};
		class GradeOfExecutorIsTooLow : public std::exception
		{
			public :
				const char* what() const throw();
		};

};
std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
