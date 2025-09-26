#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Test 1: Valid form creation ===" << std::endl;
    try
    {
        Form f1("Tax Form", 50, 30);
        std::cout << f1 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Form with invalid grades ===" << std::endl;
    try
    {
        Form f2("Invalid Form", 0, 30);
        std::cout << f2 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Bureaucrat signing form successfully ===" << std::endl;
    try
    {
        Bureaucrat b1("John", 30);
        Form f3("Contract", 50, 30);
        std::cout << "Before signing: " << f3 << std::endl;
        b1.signForm(f3);
        std::cout << "After signing: " << f3 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Bureaucrat with grade too low to sign ===" << std::endl;
    try
    {
        Bureaucrat b2("Jane", 100);
        Form f4("Important Document", 50, 30);
        std::cout << "Before signing: " << f4 << std::endl;
        b2.signForm(f4);
        std::cout << "After signing: " << f4 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Form already signed ===" << std::endl;
    try
    {
        Bureaucrat b3("Bob", 30);
        Bureaucrat b4("Alice", 40);
        Form f5("Report", 50, 30);
        
        std::cout << "Before first signing: " << f5 << std::endl;
        b3.signForm(f5);
        std::cout << "After first signing: " << f5 << std::endl;
        
        std::cout << "Trying to sign again: ";
        b4.signForm(f5);
        std::cout << "After second signing: " << f5 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
