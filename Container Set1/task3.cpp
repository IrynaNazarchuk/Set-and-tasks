#include <iostream>
#include <string>
#include "Set.h"

int main() {
    std::string str = "abracadabra";

    // First occurrence of each letter
    Set<char> firstOccurrences;
    for (char c : str) {
        firstOccurrences.add(c);
    }
    std::cout << "The first occurrence of each letter: ";
    for (size_t i = 0; i < firstOccurrences.getSize(); ++i) {
        std::cout << firstOccurrences[i] << " ";
    }
    std::cout << std::endl;

   // Letters that occur at least twice
    Set<char> multipleOccurrences;
    Set<char> uniqueChars;
    for (char c : str) {
        if (uniqueChars.contains(c)) {
            multipleOccurrences.add(c);
        }
        else {
            uniqueChars.add(c);
        }
    }
    std::cout << "Letters that occur at least twice: ";
    for (size_t i = 0; i < multipleOccurrences.getSize(); ++i) {
        std::cout << multipleOccurrences[i] << " ";
    }
    std::cout << std::endl;

    // Letters that occur only once
    Set<char> singleOccurrences = uniqueChars.differenceWith(multipleOccurrences);
    std::cout << "Letters that occur only once: ";
    for (size_t i = 0; i < singleOccurrences.getSize(); ++i) {
        std::cout << singleOccurrences[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

