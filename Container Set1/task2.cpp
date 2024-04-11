#include "Set.h"
#include <iostream>

// Function to calculate the number of different digits in a number
int digits(int n) {
    Set<int> digitSet; // Create an instance of the Set class to store different numbers

  // We go through each digit of the number n
    while (n > 0) {
        int digit = n % 10; // Get the last digit of the number
        digitSet.add(digit); // Add a number to the set
        n /= 10; // Delete the last digit of the number
    }

  // Return the number of elements in the set (the number of different digits)
    return digitSet.getSize();
}

int main() {
    std::cout << "digits(2024) = " << digits(2024) << std::endl; // Expected value: 3
    std::cout << "digits(5) = " << digits(5) << std::endl; // Expected value: 1
    std::cout << "digits(10110111) = " << digits(10110111) << std::endl; // Expected value: 2

    return 0;
}

