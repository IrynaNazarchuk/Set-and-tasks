#include <iostream>
#include <string>
#include "Set.h" 

int main() {
    // Create tuples for each character category
    Set<char> digits = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    Set<char> arithmeticOperators = { '+', '-', '*', '/' };
    Set<char> brackets = { '(', ')' };

    // Given string with an arithmetic expression
    std::string expression = "(3 + 4) * (5 - 2)";

    // Counters for the number of digits, operations, and parentheses
    int digitCount = 0;
    int operatorCount = 0;
    int bracketCount = 0;

    // Go through each character in the line
    for (char c : expression) {
       // We check to which category the symbol belongs
        if (digits.contains(c)) {
            digitCount++;
        }
        else if (arithmeticOperators.contains(c)) {
            operatorCount++;
        }
        else if (brackets.contains(c)) {
            bracketCount++;
        }
    }

     // Виводимо результати
    std::cout << "Number of digits:: " << digitCount << std::endl;
    std::cout << "Number of arithmetic operations: " << operatorCount << std::endl;
    std::cout << "Number of brackets: " << bracketCount << std::endl;

    // Check if the number of brackets matches
    if (bracketCount % 2 == 0) {
        std::cout << "The number of parentheses in the expression corresponds." << std::endl;
    }
    else {
        std::cout << "The number of parentheses in the expression does not match." << std::endl;
    }

    return 0;
}

