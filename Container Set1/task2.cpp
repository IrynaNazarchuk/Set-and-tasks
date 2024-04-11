#include "Set.h"
#include <iostream>

// ������� ��� ���������� ������� ����� ���� � ����
int digits(int n) {
    Set<int> digitSet; // ��������� ��������� ����� Set ��� ��������� ����� ����

    // ����������� �� ����� ���� ����� n
    while (n > 0) {
        int digit = n % 10; // �������� ������� ����� �����
        digitSet.add(digit); // ������ ����� �� �������
        n /= 10; // ��������� ������� ����� �����
    }

    // ��������� ������� �������� � ������ (������� ����� ����)
    return digitSet.getSize();
}

int main() {
    std::cout << "digits(2024) = " << digits(2024) << std::endl; // ��������� ��������: 3
    std::cout << "digits(5) = " << digits(5) << std::endl; // ��������� ��������: 1
    std::cout << "digits(10110111) = " << digits(10110111) << std::endl; // ��������� ��������: 2

    return 0;
}

