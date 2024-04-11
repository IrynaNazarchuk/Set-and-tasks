#pragma once
#include <iostream>
#include <initializer_list>

template<typename T>
class Set {
private:
    T* elements;         // A pointer to an array of set elements
    size_t capacity;     // The current capacity of the set (the number of elements that the array can hold)
    size_t size;         // Current set size (number of elements added)

    void resize();       // Method to resize an array of elements

public:
    Set(size_t initialCapacity = 10);   // A constructor with a default parameter to create a set with an initial capacity
    Set(std::initializer_list<T> initList);  // A constructor that accepts an initialization list to create a set with the specified elements
    Set(const Set& other);  // Copy constructor
    ~Set();                 // Destructor

    Set& operator=(const Set& other);        // Assignment operator

    void add(const T& element);              // Adding an element to the set
    void add(const Set& other);              // Adding all elements from another set
    bool contains(const T& element) const;   // Checking whether an element is contained in a set
    void remove(const T& element);           // Remove an element from the set
    void clear();                            // Clear the set (remove all elements)
    size_t getSize() const;                  // Get the current size of the set
    Set unionWith(const Set& other) const;   // Combination of sets
    Set intersectionWith(const Set& other) const;   // Intersection of sets
    Set differenceWith(const Set& other) const;     // Difference of sets

    template<typename U>
    bool operator==(const Set<U>& rhs) const;         // Overloaded comparison operator

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Set<U>& set);    // Overloaded output operator

    T& operator[](size_t index);                // Overloaded set element access operator
    const T& operator[](size_t index) const;    // Overloaded constant operator to access the element of the set
};

