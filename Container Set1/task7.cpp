#include "Set.h"
#include <iostream>
#include <string>

template<typename T>
bool canReachWithTwoTransfers(const Set<T>& cities, const Set<std::pair<T, T>>& flights, const T& start, const T& destination) {
    // �������� �� �������� �� ����������� ���� � � �������� ���
    if (!cities.contains(start) || !cities.contains(destination))
        return false;

    // ��������� ������� ��� �������� �� �������� ���
    Set<T> visited;
    Set<T> currentLevel;
    Set<T> nextLevel;

    // ������ �������� ���� �� ��������� ����
    currentLevel.add(start);
    visited.add(start);

    int transfers = 0; // ������� ���������

    // ������� BFS
    while (currentLevel.getSize()) {
        // ����� ��������� ����
        for (size_t i = 0; i < currentLevel.getSize(); ++i) {
            const T& currentCity = currentLevel[i];
            if (currentCity == destination) // ���� ������� ���� - ���� �����������, ��������� true
                return true;

            // ������ �� ���������� ���� �� ����, �� ���� ����� ��������� �� ��������� ������ ������� ��� � ���� ����������
            for (size_t j = 0; j < flights.getSize(); ++j) {
                if (flights[j].first == currentCity && !visited.contains(flights[j].second)) {
                    nextLevel.add(flights[j].second);
                    visited.add(flights[j].second);
                }
                else if (flights[j].second == currentCity && !visited.contains(flights[j].first)) {
                    nextLevel.add(flights[j].first);
                    visited.add(flights[j].first);
                }
            }
        }

        // ���������� �� ���������� ����
        currentLevel = nextLevel;
        nextLevel.clear();

        // �������� ������� ���������
        ++transfers;

        // ���� �������� ����� �� 2 ���������, �������� � �����
        if (transfers > 2)
            break;
    }

    // ���� �� ���� �������� ����� �� ��������� ������ ������� ��� � ���� ����������, ��������� false
    return false;
}


int main() {
    Set<std::string> cities = { "���", "����", "�����", "�����", "�����", "��������", "�������", "�����", "г���", "�����-���������", "�������", "����", "�������", "��������", "��������", "ѳ���������", "�������", "������������", "³�����", "�������", "�������", "������", "�������������", "�������", "������" };
    Set<std::pair<std::string, std::string>> flights = { {"���", "����"}, {"���", "�����"}, {"����", "�����"}, {"����", "�����"}, {"����", "�����"}, {"�����", "�����"}, {"�����", "�������"}, {"�����", "�����"}, {"�������", "��������"}, {"�������", "�����"}, {"��������", "�����"}, {"��������", "�������"}, {"�����", "���"}, {"�����", "�����"}, {"�����", "�����"} };

    std::string startCity = "���";
    std::string destinationCity = "�����";

    if (canReachWithTwoTransfers(cities, flights, startCity, destinationCity))
        std::cout << "������� ��������� � " << startCity << " �� " << destinationCity << " � ����� ��� ����� �����������.\n";
    else
        std::cout << "��������� ��������� � " << startCity << " �� " << destinationCity << " � ����� ��� ����� �����������.\n";

    return 0;
}
