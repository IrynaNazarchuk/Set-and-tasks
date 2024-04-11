#include "Set.h"
#include <iostream>
#include <string>

template<typename T>
bool canReachWithTwoTransfers(const Set<T>& cities, const Set<std::pair<T, T>>& flights, const T& start, const T& destination) {
   // Check if the starting and destination cities are multiple cities
    if (!cities.contains(start) || !cities.contains(destination))
        return false;

  // Create tuples for visited and current cities
    Set<T> visited;
    Set<T> currentLevel;
    Set<T> nextLevel;

   // Додаємо стартове місто до поточного рівня
    currentLevel.add(start);
    visited.add(start);

    int transfers = 0;  // number of transfers

// Start BFS
    while (currentLevel.getSize()) {
       // Bypass the current level
        for (size_t i = 0; i < currentLevel.getSize(); ++i) {
            const T& currentCity = currentLevel[i];
            if (currentCity == destination) // If the current city is the destination city, return true
                return true;

          // We add to the next level all the cities that can be reached by direct transfers or with one transfer
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

       // Go to the next level
        currentLevel = nextLevel;
        nextLevel.clear();

        // Increase the number of transfers
        ++transfers;

        // If more than 2 transfers are made, we exit the loop
        if (transfers > 2)
            break;
    }

    // If no path was found using direct crossings or with one stop, return false
    return false;
}


int main() {
    Set<std::string> cities = { "Kyiv", "Lviv", "Kharkiv", "Dnipro", "Odesa", "Ternopil", "Uzhgorod", "Lutsk", "Rivne", "Ivano-Frankivsk", "Zhytomyr", "Sumy", "Donetsk", "Luhansk", "Zaporizhzhia", "Simferopol", "Chernivtsi", "Khmelnytskyi", "Vinnytsia", "Cherkasy", "Poltava", "Chernihiv", "Kropyvnytskyi", "Mykolaiv", "Kherson" };
    Set<std::pair<std::string, std::string>> flights = { {"Kyiv", "Lviv"}, {"Kyiv", "Kharkiv"}, {"Lviv", "Dnipro"}, {"Lviv", "Kharkiv"}, {"Lviv", "Odessa"}, {"Dnipro", "Odessa"}, {"Kharkiv", "Donetsk"}, {"Odessa", "Kharkiv"}, {"Donetsk", "Luhansk"}, {"Donetsk", "Kharkiv"}, {"Luhansk", "Kharkiv"}, {"Luhansk", "Donetsk"}, {"Kharkiv", "Kyiv"}, {"Kharkiv", "Odesa"}, {"Kharkiv", "Dnipro"} };

    std::string startCity = "Kyiv";
    std::string destinationCity = "Dnipro";

    if (canReachWithTwoTransfers(cities, flights, startCity, destinationCity))
        std::cout << "It is possible to get from " << startCity << " to with two or fewer transplants." << destinationCity << " \n";
    else
        std::cout << "It is impossible to get from" << startCity << " to " << destinationCity << "with two or fewer transplants.\n";

    return 0;
}
