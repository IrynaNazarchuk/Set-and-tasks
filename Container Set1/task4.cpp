#include <iostream>
#include "Set.h" 

void SieveOfEratosthenes(int n) {
    Set<int> primes(n + 1); // ��������� ������� ��� ���������� ������� �����
    for (int i = 2; i <= n; ++i) {
        primes.add(i); // ������ �� ����� �� 2 �� n
    }

    for (int p = 2; p <= n; p++) {
        if (primes.contains(p)) {
            // ��������� �� ����� ����� �� "�� �����"
            for (int i = p * 2; i <= n; i += p) {
                primes.remove(i);
            }
        }
    }

    // �������� ����� �����
    std::cout << "Prime numbers less than or equal to " << n << ":\n";
    for (size_t i = 0; i < primes.getSize(); ++i) {
        std::cout << primes[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n = 100; // ������ ����� n
    SieveOfEratosthenes(n);
    return 0;
}
