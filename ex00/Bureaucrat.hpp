#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

// bureaucrat class - like a person who work in office
// has name and grade (1 is best, 150 is worst)
class Bureaucrat
{
private:
    const std::string _name;  // name of bureaucrat (cannot change)
    int _grade;               // grade from 1 to 150

public:
    // constructors and destructor
    Bureaucrat();                                    // default constructor
    Bureaucrat(const std::string& name, int grade); // constructor with name and grade
    Bureaucrat(const Bureaucrat& other);             // copy constructor
    Bureaucrat& operator=(const Bureaucrat& other); // assignment operator
    ~Bureaucrat();                                   // destructor

    // getter functions
    const std::string& getName() const;  // get the name
    int getGrade() const;                // get the grade

    // functions to change grade
    void incrementGrade();  // make grade better (lower number)
    void decrementGrade();  // make grade worse (higher number)

    // exception classes for when grade is wrong
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();  // return error message
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw();  // return error message
    };
};

// operator to print bureaucrat info
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
