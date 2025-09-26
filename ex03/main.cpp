#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Test 1: Intern creates Shrubbery Creation Form ===" << std::endl;
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("shrubbery creation", "home");
        
        Bureaucrat b1("John", 100);
        b1.signForm(*rrf);
        b1.executeForm(*rrf);
        
        delete rrf;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Intern creates Robotomy Request Form ===" << std::endl;
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        Bureaucrat b2("Jane", 30);
        b2.signForm(*rrf);
        b2.executeForm(*rrf);
        
        delete rrf;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Intern creates Presidential Pardon Form ===" << std::endl;
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("presidential pardon", "Arthur");
        
        Bureaucrat b3("Bob", 1);
        b3.signForm(*rrf);
        b3.executeForm(*rrf);
        
        delete rrf;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Intern tries to create unknown form ===" << std::endl;
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("unknown form", "target");
        
        delete rrf;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Intern creates form with case sensitivity ===" << std::endl;
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("SHRUBBERY CREATION", "garden");
        
        delete rrf;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}