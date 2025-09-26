#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

// form class - like a paper that need to be signed
// has name, signed status, and grades needed to sign and execute
class Form
{
private:
    const std::string _name;        // name of the form
    bool _signed;                   // is form signed or not
    const int _gradeToSign;         // grade needed to sign form
    const int _gradeToExecute;      // grade needed to execute form

public:
    // constructors and destructor
    Form();                                    // default constructor
    Form(const std::string& name, int gradeToSign, int gradeToExecute); // constructor with all info
    Form(const Form& other);                   // copy constructor
    Form& operator=(const Form& other);        // assignment operator
    ~Form();                                    // destructor

    // getter functions
    const std::string& getName() const;         // get form name
    bool isSigned() const;                      // check if form is signed
    int getGradeToSign() const;                 // get grade needed to sign
    int getGradeToExecute() const;              // get grade needed to execute

    // function to sign form
    void beSigned(const Bureaucrat& bureaucrat); // try to sign form with bureaucrat

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

// operator to print form info
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
