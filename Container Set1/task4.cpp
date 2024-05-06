#include <iostream>
#include "Set.h" 

//Halyna Danylchyk
void SieveOfEratosthenes(int n) {
    Set<int> primes(n + 1);  // Create a set to store prime numbers
    for (int i = 2; i <= n; ++i) {
        primes.add(i); // Add all numbers from 2 to n
    }

    for (int p = 2; p <= n; p++) {
        if (primes.contains(p)) {
           // Mark all multiples as "not prime"
            for (int i = p * 2; i <= n; i += p) {
                primes.remove(i);
            }
        }
    }

   // Output prime numbers
    std::cout << "Prime numbers less than or equal to " << n << ":\n";
    for (size_t i = 0; i < primes.getSize(); ++i) {
        std::cout << primes[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n = 100; // Given number n
    SieveOfEratosthenes(n);
    return 0;
}
