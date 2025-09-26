#include "Bureaucrat.hpp"

// default constructor - make bureaucrat with unknown name and worst grade
Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150)
{
}

// constructor with name and grade - check if grade is valid
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)        // grade 1 is best, cannot be better
        throw GradeTooHighException();
    if (grade > 150)      // grade 150 is worst, cannot be worse
        throw GradeTooLowException();
}

// copy constructor - make new bureaucrat same as other
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

// assignment operator - copy grade from other bureaucrat
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)   // make sure not copying to self
    {
        _grade = other._grade;  // only grade can change, name is const
    }
    return *this;
}

// destructor - clean up when bureaucrat is destroyed
Bureaucrat::~Bureaucrat()
{
}

// getter for name - return the name
const std::string& Bureaucrat::getName() const
{
    return _name;
}

// getter for grade - return the grade
int Bureaucrat::getGrade() const
{
    return _grade;
}

// make grade better (lower number is better)
void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)      // already at best grade
        throw GradeTooHighException();
    _grade--;             // make grade better
}

// make grade worse (higher number is worse)
void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)    // already at worst grade
        throw GradeTooLowException();
    _grade++;             // make grade worse
}

// exception message for grade too high
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

// exception message for grade too low
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

// operator to print bureaucrat - show name and grade
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}
