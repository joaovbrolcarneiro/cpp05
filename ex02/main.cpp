#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Test 1: Shrubbery Creation Form ===" << std::endl;
    try
    {
        Bureaucrat b1("John", 100);
        ShrubberyCreationForm f1("home");
        
        std::cout << "Before signing: " << f1 << std::endl;
        b1.signForm(f1);
        std::cout << "After signing: " << f1 << std::endl;
        
        std::cout << "Executing form: ";
        b1.executeForm(f1);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Robotomy Request Form ===" << std::endl;
    try
    {
        Bureaucrat b2("Jane", 30);
        RobotomyRequestForm f2("Bender");
        
        std::cout << "Before signing: " << f2 << std::endl;
        b2.signForm(f2);
        std::cout << "After signing: " << f2 << std::endl;
        
        std::cout << "Executing form: ";
        b2.executeForm(f2);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Presidential Pardon Form ===" << std::endl;
    try
    {
        Bureaucrat b3("Bob", 1);
        PresidentialPardonForm f3("Arthur");
        
        std::cout << "Before signing: " << f3 << std::endl;
        b3.signForm(f3);
        std::cout << "After signing: " << f3 << std::endl;
        
        std::cout << "Executing form: ";
        b3.executeForm(f3);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Form not signed ===" << std::endl;
    try
    {
        Bureaucrat b4("Alice", 1);
        ShrubberyCreationForm f4("garden");
        
        std::cout << "Trying to execute unsigned form: ";
        b4.executeForm(f4);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Grade too low to execute ===" << std::endl;
    try
    {
        Bureaucrat b5("Charlie", 150);
        Bureaucrat b6("David", 1);
        RobotomyRequestForm f5("Marvin");
        
        b6.signForm(f5);
        std::cout << "Trying to execute with low grade: ";
        b5.executeForm(f5);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
