#include "Set.h"
#include <iostream>
#include <string>

template<typename T>
bool canReachWithTwoTransfers(const Set<T>& cities, const Set<std::pair<T, T>>& flights, const T& start, const T& destination) {
    // Перевірка чи стартове та призначення міста є в множинах міст
    if (!cities.contains(start) || !cities.contains(destination))
        return false;

    // Створюємо множини для відвіданих та поточних міст
    Set<T> visited;
    Set<T> currentLevel;
    Set<T> nextLevel;

    // Додаємо стартове місто до поточного рівня
    currentLevel.add(start);
    visited.add(start);

    int transfers = 0; // кількість пересадок

    // Початок BFS
    while (currentLevel.getSize()) {
        // Обхід поточного рівня
        for (size_t i = 0; i < currentLevel.getSize(); ++i) {
            const T& currentCity = currentLevel[i];
            if (currentCity == destination) // Якщо поточне місто - місто призначення, повертаємо true
                return true;

            // Додаємо до наступного рівня всі міста, до яких можна потрапити за допомогою прямих переїздів або з однією пересадкою
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

        // Переходимо до наступного рівня
        currentLevel = nextLevel;
        nextLevel.clear();

        // Збільшуємо кількість пересадок
        ++transfers;

        // Якщо зроблено більше ніж 2 пересадки, виходимо з циклу
        if (transfers > 2)
            break;
    }

    // Якщо не було знайдено шляху за допомогою прямих переїздів або з однією пересадкою, повертаємо false
    return false;
}


int main() {
    Set<std::string> cities = { "Київ", "Львів", "Харків", "Дніпро", "Одеса", "Тернопіль", "Ужгород", "Луцьк", "Рівне", "Івано-Франківськ", "Житомир", "Суми", "Донецьк", "Луганськ", "Запоріжжя", "Сімферополь", "Чернівці", "Хмельницький", "Вінниця", "Черкаси", "Полтава", "Чернігів", "Кропивницький", "Миколаїв", "Херсон" };
    Set<std::pair<std::string, std::string>> flights = { {"Київ", "Львів"}, {"Київ", "Харків"}, {"Львів", "Дніпро"}, {"Львів", "Харків"}, {"Львів", "Одеса"}, {"Дніпро", "Одеса"}, {"Харків", "Донецьк"}, {"Одеса", "Харків"}, {"Донецьк", "Луганськ"}, {"Донецьк", "Харків"}, {"Луганськ", "Харків"}, {"Луганськ", "Донецьк"}, {"Харків", "Київ"}, {"Харків", "Одеса"}, {"Харків", "Дніпро"} };

    std::string startCity = "Київ";
    std::string destinationCity = "Дніпро";

    if (canReachWithTwoTransfers(cities, flights, startCity, destinationCity))
        std::cout << "Можливо потрапити з " << startCity << " до " << destinationCity << " з двома або менше пересадками.\n";
    else
        std::cout << "Неможливо потрапити з " << startCity << " до " << destinationCity << " з двома або менше пересадками.\n";

    return 0;
}
