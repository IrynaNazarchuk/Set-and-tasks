#include <iostream>
#include "Set.h" 

void SieveOfEratosthenes(int n) {
    Set<int> primes(n + 1); // Створюємо множину для збереження простих чисел
    for (int i = 2; i <= n; ++i) {
        primes.add(i); // Додаємо всі числа від 2 до n
    }

    for (int p = 2; p <= n; p++) {
        if (primes.contains(p)) {
            // Позначаємо всі кратні числа як "не прості"
            for (int i = p * 2; i <= n; i += p) {
                primes.remove(i);
            }
        }
    }

    // Виводимо прості числа
    std::cout << "Prime numbers less than or equal to " << n << ":\n";
    for (size_t i = 0; i < primes.getSize(); ++i) {
        std::cout << primes[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n = 100; // Задане число n
    SieveOfEratosthenes(n);
    return 0;
}
