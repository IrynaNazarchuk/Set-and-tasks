#include <iostream>
#include <string>
#include "Set.h" 

int main() {
    // ��������� ������� ��� ����� ������� �������
    Set<char> digits = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    Set<char> arithmeticOperators = { '+', '-', '*', '/' };
    Set<char> brackets = { '(', ')' };

    // ������� ����� � ������������ �������
    std::string expression = "(3 + 4) * (5 - 2)";

    // ˳�������� ��� ������� ����, �������� �� �����
    int digitCount = 0;
    int operatorCount = 0;
    int bracketCount = 0;

    // ����������� �� ������� ������� � �����
    for (char c : expression) {
        // ����������, �� ��� ������� �������� ������
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

    // �������� ����������
    std::cout << "ʳ������ ����: " << digitCount << std::endl;
    std::cout << "ʳ������ ������������ ��������: " << operatorCount << std::endl;
    std::cout << "ʳ������ �����: " << bracketCount << std::endl;

    // ����������, �� ������� ������� �����
    if (bracketCount % 2 == 0) {
        std::cout << "ʳ������ ����� � ����� �������." << std::endl;
    }
    else {
        std::cout << "ʳ������ ����� � ����� �� �������." << std::endl;
    }

    return 0;
}

