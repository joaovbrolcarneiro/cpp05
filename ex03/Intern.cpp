#include "Intern.hpp"

// default constructor - make intern (no special setup needed)
Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

// main function - create form by name and target
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    // array of form names that intern can create
    std::string forms[] = {
        "shrubbery creation",
        "robotomy request", 
        "presidential pardon"
    };
    
    // array of functions that create each form type
    AForm* (*formCreators[])(const std::string&) = {
        ShrubberyCreationForm::createForm,
        RobotomyRequestForm::createForm,
        PresidentialPardonForm::createForm
    };
    
    // check if form name matches any known form
    for (int i = 0; i < 3; i++)
    {
        if (formName == forms[i])  // if form name matches
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);  // create the form with target
        }
    }
    
    // if form name not found, print error and throw exception
    std::cout << "Intern couldn't create form: " << formName << " (form not found)" << std::endl;
    throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}
