#include "Set.h"
#include <iostream>
#include <string>

using namespace std;
int main() {
    // ��������� ��������� ����� Set ��� ����.
    Set<string> names = { "Olexa", "Yuliia", "Kateryna", "Vitalii", "Artemii", "Markiian", "Vladyslav", "Oleg", "Kseniia", "Olha", "Sofia", "Andrii", "Ivan", "Yurii", "Taras", "Kostiantyn", "Halyna", "Vasyl", "Solomiia", "Mykola", "Iryna" };

    // ��������� ��������� ����� Set ��� ������.
    Set<string> guests = { "Olexa",  "Olha", "Sofia" };

    // ��������� ������ ����� ��� ���������.
    Set<pair<string, string>> visits;

    // ������ ����������.
    for (int i = 0; i < names.getSize(); ++i) {
        for (int j = 0; j < guests.getSize(); ++j) {
            const string& name = names[i];
            const string& guest = guests[j];
            if (name != guest) { // ��������� ���������� ������ ����.
                // �������� ������� ���� ���� ��� ���������.
                bool exists = false;
                for (int k = 0; k < visits.getSize(); ++k) {
                    if (visits[k].first == name && visits[k].second == guest) {
                        exists = true;
                        break;
                    }
                }
                if (!exists) {
                    visits.add({ name, guest });
                }
            }
        }
    }

    // �������� 1: ��� � ���������� ��� (����) �������� ������ � ����.
    Set<string> leastVisitors;
    size_t minVisits = guests.getSize(); // ���������� �������� ������� ��������� ������������ ��������.
    for (int i = 0; i < names.getSize(); ++i) {
        size_t numVisits = 0;
        const string& name = names[i];
        for (int j = 0; j < visits.getSize(); ++j) {
            if (visits[j].first == name) {
                numVisits++;
            }
        }
        if (numVisits < minVisits) {
            minVisits = numVisits;
            leastVisitors.clear();
            leastVisitors.add(name);
        }
        else if (numVisits == minVisits) {
            leastVisitors.add(name);
        }
    }
    cout << "1. �������� ������ � ����: ";
    for (int i = 0; i < leastVisitors.getSize(); ++i) {
        cout << leastVisitors[i] << " ";
    }
    cout << endl;

    // �������� 2: ��� ������ ��� �����.
    Set<string> allVisited;
    for (int i = 0; i < names.getSize(); ++i) {
        const string& name = names[i];
        bool visitedAll = true;
        for (int j = 0; j < guests.getSize(); ++j) {
            const string& guest = guests[j];
            if (name != guest && !visits.contains({ name, guest })) {
                visitedAll = false;
                break;
            }
        }
        if (visitedAll) {
            allVisited.add(name);
        }
    }
    cout << "2. ³����� ��� �����: ";
    for (int i = 0; i < allVisited.getSize(); ++i) {
        cout << allVisited[i] << " ";
    }
    cout << endl;

    // �������� 3: �� � ����� ���������� ��� "���� ���� ����� �����".
    // �����, ���, �� ������ � ������ ���� � ������ � � � ���� �����.
    bool tightCircleOfThree = false;
    for (int i = 0; i < names.getSize(); ++i) {
        const string& name1 = names[i];
        for (int j = 0; j < names.getSize(); ++j) {
            if (i == j) continue;
            const string& name2 = names[j];
            for (int k = 0; k < names.getSize(); ++k) {
                if (i == k || j == k) continue;
                const string& name3 = names[k];
                if (visits.contains({ name1, name2 }) && visits.contains({ name1, name3 }) &&
                    visits.contains({ name2, name1 }) && visits.contains({ name2, name3 }) &&
                    visits.contains({ name3, name1 }) && visits.contains({ name3, name2 })) {
                    cout << "3. � ���� ���� ����� �����: " << name1 << ", " << name2 << ", " << name3 << endl;
                    tightCircleOfThree = true;
                }
            }
        }
    }
    if (!tightCircleOfThree) {
        cout << "3. ҳ���� ��� �� ��������." << endl;
    }

    // �������� 4: ��������� ������� ���������.
    cout << "4. ������� ���������:" << endl;
    for (int i = 0; i < visits.getSize(); ++i) {
        cout << visits[i].first << " ������(��) " << visits[i].second << endl;
    }

    return 0;
}
