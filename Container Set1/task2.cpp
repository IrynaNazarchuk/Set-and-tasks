#include "Set.h"
#include <iostream>

// Функція для обчислення кількості різних цифр у числі
int digits(int n) {
    Set<int> digitSet; // Створюємо екземпляр класу Set для зберігання різних цифр

    // Проходимося по кожній цифрі числа n
    while (n > 0) {
        int digit = n % 10; // Отримуємо останню цифру числа
        digitSet.add(digit); // Додаємо цифру до множини
        n /= 10; // Видаляємо останню цифру числа
    }

    // Повертаємо кількість елементів у множині (кількість різних цифр)
    return digitSet.getSize();
}

int main() {
    std::cout << "digits(2024) = " << digits(2024) << std::endl; // Очікуване значення: 3
    std::cout << "digits(5) = " << digits(5) << std::endl; // Очікуване значення: 1
    std::cout << "digits(10110111) = " << digits(10110111) << std::endl; // Очікуване значення: 2

    return 0;
}

