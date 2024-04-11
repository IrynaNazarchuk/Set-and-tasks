#include <iostream>
#include <string>
#include "Set.h"

int main() {
    std::string str = "abracadabra";

    // Перше входження кожної літери
    Set<char> firstOccurrences;
    for (char c : str) {
        firstOccurrences.add(c);
    }
    std::cout << "Перше входження кожної літери: ";
    for (size_t i = 0; i < firstOccurrences.getSize(); ++i) {
        std::cout << firstOccurrences[i] << " ";
    }
    std::cout << std::endl;

    // Літери, які зустрічаються не менше двох разів
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
    std::cout << "Літери, які зустрічаються не менше двох разів: ";
    for (size_t i = 0; i < multipleOccurrences.getSize(); ++i) {
        std::cout << multipleOccurrences[i] << " ";
    }
    std::cout << std::endl;

    // Літери, які зустрічаються тільки один раз
    Set<char> singleOccurrences = uniqueChars.differenceWith(multipleOccurrences);
    std::cout << "Літери, які зустрічаються тільки один раз: ";
    for (size_t i = 0; i < singleOccurrences.getSize(); ++i) {
        std::cout << singleOccurrences[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

