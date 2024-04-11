#include <iostream>
#include <string>
#include "Set.h"

int main() {
    std::string str = "abracadabra";

    // ����� ��������� ����� �����
    Set<char> firstOccurrences;
    for (char c : str) {
        firstOccurrences.add(c);
    }
    std::cout << "����� ��������� ����� �����: ";
    for (size_t i = 0; i < firstOccurrences.getSize(); ++i) {
        std::cout << firstOccurrences[i] << " ";
    }
    std::cout << std::endl;

    // ˳����, �� ������������ �� ����� ���� ����
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
    std::cout << "˳����, �� ������������ �� ����� ���� ����: ";
    for (size_t i = 0; i < multipleOccurrences.getSize(); ++i) {
        std::cout << multipleOccurrences[i] << " ";
    }
    std::cout << std::endl;

    // ˳����, �� ������������ ����� ���� ���
    Set<char> singleOccurrences = uniqueChars.differenceWith(multipleOccurrences);
    std::cout << "˳����, �� ������������ ����� ���� ���: ";
    for (size_t i = 0; i < singleOccurrences.getSize(); ++i) {
        std::cout << singleOccurrences[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

