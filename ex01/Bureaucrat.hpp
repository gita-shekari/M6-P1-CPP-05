/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 21:59:22 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/01 21:59:25 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
	   const std::string name;
	   int grade;
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		const std::string getName() const;
		int getGrade() const;
		void setGrade(int g);
		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};

};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
