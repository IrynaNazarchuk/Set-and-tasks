#include <iostream>
#include <string>
#include "Set.h" 

int main() {
    // Створюємо множини для кожної категорії символів
    Set<char> digits = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    Set<char> arithmeticOperators = { '+', '-', '*', '/' };
    Set<char> brackets = { '(', ')' };

    // Заданий рядок з арифметичним виразом
    std::string expression = "(3 + 4) * (5 - 2)";

    // Лічильники для кількості цифр, операцій та дужок
    int digitCount = 0;
    int operatorCount = 0;
    int bracketCount = 0;

    // Проходимося по кожному символу у рядку
    for (char c : expression) {
        // Перевіряємо, до якої категорії належить символ
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
    std::cout << "Кількість цифр: " << digitCount << std::endl;
    std::cout << "Кількість арифметичних операцій: " << operatorCount << std::endl;
    std::cout << "Кількість дужок: " << bracketCount << std::endl;

    // Перевіряємо, чи відповідає кількість дужок
    if (bracketCount % 2 == 0) {
        std::cout << "Кількість дужок у виразі відповідає." << std::endl;
    }
    else {
        std::cout << "Кількість дужок у виразі не відповідає." << std::endl;
    }

    return 0;
}

