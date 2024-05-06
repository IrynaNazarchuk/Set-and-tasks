#include "Set.h"
#include <iostream>
#include <string>

//Halyna Danylchyk'
using namespace std;
int main() {
 // Create an instance of the Set class for names.
    Set<string> names = { "Olexa", "Yuliia", "Kateryna", "Vitalii", "Artemii", "Markiian", "Vladyslav", "Oleg", "Kseniia", "Olha", "Sofia", "Andrii", "Ivan", "Yurii", "Taras", "Kostiantyn", "Halyna", "Vasyl", "Solomiia", "Mykola", "Iryna" };

// Create an instance of the Set class for guests.
    Set<string> guests = { "Olexa",  "Olha", "Sofia" };

   // Create an empty array for visits.
    Set<pair<string, string>> visits;


// Add a visit.
    for (int i = 0; i < names.getSize(); ++i) {
        for (int j = 0; j < guests.getSize(); ++j) {
            const string& name = names[i];
            const string& guest = guests[j];
            if (name != guest) { // We exclude visiting itself.
                // Generate unique pairs of names for visits.
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

    // Task 1: Which of the listed persons (names) visits the least
    Set<string> leastVisitors;
    size_t minVisits = guests.getSize(); // Initialize the minimum number of visits to the maximum possible.
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
    cout << "1. They visit the least: ";
    for (int i = 0; i < leastVisitors.getSize(); ++i) {
        cout << leastVisitors[i] << " ";
    }
    cout << endl;

    // Task 2: Who visited all friends.
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
    cout << "2.Visited all friends: ";
    for (int i = 0; i < allVisited.getSize(); ++i) {
        cout << allVisited[i] << " ";
    }
    cout << endl;

   // Task 3: Is there a "close circle of three friends" among the listed persons.
    // That is, those who visited each other and no one else.
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
                    cout << "3. There is a close circle of three friends: " << name1 << ", " << name2 << ", " << name3 << endl;
                    tightCircleOfThree = true;
                }
            }
        }
    }
    if (!tightCircleOfThree) {
        cout << "3.No tight circles found." << endl;
    }

    // Task 4: Build the visits table.
    cout << "4. Table of visits:" << endl;
    for (int i = 0; i < visits.getSize(); ++i) {
        cout << visits[i].first << " visited " << visits[i].second << endl;
    }

    return 0;
}
