#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

// intern class - like a person who create forms for bureaucrats
// can make different types of forms by name
class Intern
{
public:
    // constructors and destructor
    Intern();                                    // default constructor
    Intern(const Intern& other);                 // copy constructor
    Intern& operator=(const Intern& other);      // assignment operator
    ~Intern();                                   // destructor

    // main function - create form by name and target
    AForm* makeForm(const std::string& formName, const std::string& target);

    // exception for when form name is not found
    class FormNotFoundException : public std::exception
    {
    public:
        virtual const char* what() const throw();  // return error message
    };
};

#endif
