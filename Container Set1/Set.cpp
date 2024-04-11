#include "Set.h"

// Constructor of the Set class with the default parameter initialCapacity
template<typename T>
Set<T>::Set(size_t initialCapacity) : capacity(initialCapacity), size(0) {
    elements = new T[capacity];
}

// Constructor of the Set class with an initialization list
template<typename T>
Set<T>::Set(std::initializer_list<T> initList) : Set(initList.size()) {
    for (const auto& element : initList) {
        add(element);
    }
}

// Copy constructor of the Set class
template<typename T>
Set<T>::Set(const Set& other) : Set(other.capacity) {
    size = other.size;
    for (size_t i = 0; i < size; ++i) {
        elements[i] = other.elements[i];
    }
}

// Destructor of the Set class
template<typename T>
Set<T>::~Set() {
    delete[] elements;
}

// Assignment operator of the Set class
template<typename T>
Set<T>& Set<T>::operator=(const Set& other) {
    if (this != &other) {
        delete[] elements;
        capacity = other.capacity;
        size = other.size;
        elements = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

// Adding an element to the set
template<typename T>
void Set<T>::add(const T& element) {
    if (!contains(element)) {
        if (size == capacity) {
            resize();
        }
        elements[size++] = element;
    }
}

// Adding all elements from another set
template<typename T>
void Set<T>::add(const Set& other) {
    for (size_t i = 0; i < other.size; ++i) {
        add(other.elements[i]);
    }
}

// Checking whether an element is contained in a set
template<typename T>
bool Set<T>::contains(const T& element) const {
    for (size_t i = 0; i < size; ++i) {
        if (elements[i] == element) {
            return true;
        }
    }
    return false;
}

// Remove an element from the set
template<typename T>
void Set<T>::remove(const T& element) {
    for (size_t i = 0; i < size; ++i) {
        if (elements[i] == element) {
            for (size_t j = i; j < size - 1; ++j) {
                elements[j] = elements[j + 1];
            }
            size--;
            return;
        }
    }
}

// Clear the set (remove all elements)
template<typename T>
void Set<T>::clear() {
    size = 0;
}

// Get the size of the set
template<typename T>
size_t Set<T>::getSize() const {
    return size;
}

// Combination of sets
template<typename T>
Set<T> Set<T>::unionWith(const Set& other) const {
    Set result(*this);
    result.add(other);
    return result;
}

// Intersection of sets
template<typename T>
Set<T> Set<T>::intersectionWith(const Set& other) const {
    Set result;
    for (size_t i = 0; i < size; ++i) {
        if (other.contains(elements[i])) {
            result.add(elements[i]);
        }
    }
    return result;
}

// Difference of sets
template<typename T>
Set<T> Set<T>::differenceWith(const Set& other) const {
    Set result(*this);
    for (size_t i = 0; i < other.size; ++i) {
        result.remove(other.elements[i]);
    }
    return result;
}

// Overloaded comparison operator ==
template<typename T>
template<typename U>
bool Set<T>::operator==(const Set<U>& rhs) const {
    if (getSize() != rhs.getSize())
        return false;

    for (size_t i = 0; i < getSize(); ++i) {
        if (!rhs.contains(elements[i]))
            return false;
    }
    return true;
}

// Overloaded output operator <<
template<typename T>
std::ostream& operator<<(std::ostream& os, const Set<T>& set) {
    os << "{ ";
    for (size_t i = 0; i < set.size; ++i) {
        os << set.elements[i] << " ";
    }
    os << "}";
    return os;
}

// Increase the size of the element array
template<typename T>
void Set<T>::resize() {
    capacity *= 2;
    T* newElements = new T[capacity];
    for (size_t i = 0; i < size; ++i) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
}

// Overloaded element access operator
template<typename T>
T& Set<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

// Overloaded constant element access operator
template<typename T>
const T& Set<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}
