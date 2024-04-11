#include "Set.h"
#include <iostream>
#include <string>

using namespace std;
int main() {
    // Створюємо екземпляр класу Set для імен.
    Set<string> names = { "Olexa", "Yuliia", "Kateryna", "Vitalii", "Artemii", "Markiian", "Vladyslav", "Oleg", "Kseniia", "Olha", "Sofia", "Andrii", "Ivan", "Yurii", "Taras", "Kostiantyn", "Halyna", "Vasyl", "Solomiia", "Mykola", "Iryna" };

    // Створюємо екземпляр класу Set для гостей.
    Set<string> guests = { "Olexa",  "Olha", "Sofia" };

    // Створюємо пустий масив для відвідувань.
    Set<pair<string, string>> visits;

    // Додамо відвідування.
    for (int i = 0; i < names.getSize(); ++i) {
        for (int j = 0; j < guests.getSize(); ++j) {
            const string& name = names[i];
            const string& guest = guests[j];
            if (name != guest) { // Виключаємо відвідування самого себе.
                // Генеруємо унікальні пари імен для відвідувань.
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

    // Завдання 1: Хто з перелічених осіб (імен) найменше ходить в гості.
    Set<string> leastVisitors;
    size_t minVisits = guests.getSize(); // Ініціалізуємо мінімальну кількість відвідувань максимальною можливою.
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
    cout << "1. Найменше ходять в гості: ";
    for (int i = 0; i < leastVisitors.getSize(); ++i) {
        cout << leastVisitors[i] << " ";
    }
    cout << endl;

    // Завдання 2: Хто відвідав усіх друзів.
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
    cout << "2. Відвідав усіх друзів: ";
    for (int i = 0; i < allVisited.getSize(); ++i) {
        cout << allVisited[i] << " ";
    }
    cout << endl;

    // Завдання 3: Чи є серед перелічених осіб "тісне коло трьох друзів".
    // Тобто, такі, які бували в гостях один в одного і ні в кого більше.
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
                    cout << "3. Є тісне коло трьох друзів: " << name1 << ", " << name2 << ", " << name3 << endl;
                    tightCircleOfThree = true;
                }
            }
        }
    }
    if (!tightCircleOfThree) {
        cout << "3. Тісних кол не знайдено." << endl;
    }

    // Завдання 4: Побудуйте таблицю відвідувань.
    cout << "4. Таблиця відвідувань:" << endl;
    for (int i = 0; i < visits.getSize(); ++i) {
        cout << visits[i].first << " відвідав(ла) " << visits[i].second << endl;
    }

    return 0;
}
