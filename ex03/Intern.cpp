#include "Intern.hpp"

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

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string forms[] = {
        "shrubbery creation",
        "robotomy request", 
        "presidential pardon"
    };
    
    AForm* (*formCreators[])(const std::string&) = {
        ShrubberyCreationForm::createForm,
        RobotomyRequestForm::createForm,
        PresidentialPardonForm::createForm
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (formName == forms[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }
    
    std::cout << "Intern couldn't create form: " << formName << " (form not found)" << std::endl;
    throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}
