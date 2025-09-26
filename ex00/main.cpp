#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Test 1: Valid bureaucrat creation ===" << std::endl;
    try
    {
        Bureaucrat b1("John", 50);
        std::cout << b1 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Grade too high ===" << std::endl;
    try
    {
        Bureaucrat b2("Jane", 0);
        std::cout << b2 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Grade too low ===" << std::endl;
    try
    {
        Bureaucrat b3("Bob", 151);
        std::cout << b3 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Increment grade ===" << std::endl;
    try
    {
        Bureaucrat b4("Alice", 3);
        std::cout << "Before increment: " << b4 << std::endl;
        b4.incrementGrade();
        std::cout << "After increment: " << b4 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Decrement grade ===" << std::endl;
    try
    {
        Bureaucrat b5("Charlie", 149);
        std::cout << "Before decrement: " << b5 << std::endl;
        b5.decrementGrade();
        std::cout << "After decrement: " << b5 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Increment grade 1 (should fail) ===" << std::endl;
    try
    {
        Bureaucrat b6("David", 1);
        std::cout << "Before increment: " << b6 << std::endl;
        b6.incrementGrade();
        std::cout << "After increment: " << b6 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: Decrement grade 150 (should fail) ===" << std::endl;
    try
    {
        Bureaucrat b7("Eve", 150);
        std::cout << "Before decrement: " << b7 << std::endl;
        b7.decrementGrade();
        std::cout << "After decrement: " << b7 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
