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
        ~Bureaucrat();
        std::string const getName() const;
        int getGrade();
        
        
};
#endif