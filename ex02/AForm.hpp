#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

// abstract form class - base class for all forms
// cannot be used directly, must be inherited
class AForm
{
private:
    const std::string _name;        // name of the form
    bool _signed;                   // is form signed or not
    const int _gradeToSign;         // grade needed to sign form
    const int _gradeToExecute;      // grade needed to execute form

public:
    // constructors and destructor
    AForm();                                    // default constructor
    AForm(const std::string& name, int gradeToSign, int gradeToExecute); // constructor with all info
    AForm(const AForm& other);                   // copy constructor
    AForm& operator=(const AForm& other);        // assignment operator
    virtual ~AForm();                             // virtual destructor (important for inheritance)

    // getter functions
    const std::string& getName() const;         // get form name
    bool isSigned() const;                      // check if form is signed
    int getGradeToSign() const;                 // get grade needed to sign
    int getGradeToExecute() const;              // get grade needed to execute

    // functions for form operations
    void beSigned(const Bureaucrat& bureaucrat); // try to sign form with bureaucrat
    void execute(const Bureaucrat& executor) const; // try to execute form with bureaucrat
    virtual void executeAction() const = 0;        // pure virtual function - must be implemented by child classes

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
