#pragma once
#include <iostream>
#include <initializer_list>

template<typename T>
class Set {
private:
    T* elements;
    size_t capacity;
    size_t size;

    void resize();

public:
    Set(size_t initialCapacity = 10);
    Set(std::initializer_list<T> initList);
    Set(const Set& other);
    ~Set();

    Set& operator=(const Set& other);

    void add(const T& element);
    void add(const Set& other);
    bool contains(const T& element) const;
    void remove(const T& element);
    void clear();
    size_t getSize() const;
    Set unionWith(const Set& other) const;
    Set intersectionWith(const Set& other) const;
    Set differenceWith(const Set& other) const;

    template<typename U>
    bool operator==(const Set<U>& rhs) const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Set<U>& set);

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
};

