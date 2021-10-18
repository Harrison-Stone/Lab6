#pragma once
#include <algorithm>
#include <ostream>
#include <string>

template <typename T>
class ArrayList
{
public:
    // Construct an empty list
    explicit ArrayList(unsigned int size = 0, unsigned int addlCapacity = 16);

    // Copy constructor
    ArrayList(const ArrayList<T>& original);

    // Move constructor
    ArrayList(ArrayList<T>&& original);

    // Destructor
    ~ArrayList();

    // Copy assignment operator
    ArrayList<T>& operator= (const ArrayList<T>& original);

    // Move assignment operator
    ArrayList<T>& operator= (ArrayList<T>&& original);

    // Gets size of the list.
    unsigned int getSize() const;

    // Gets a single element of the list.
    // Throws an exception if index >= size.
    const T& operator[] (unsigned int index) const;

    // Gets a single, mutable element of the list.
    // Throws an exception if index >= size.
    T& operator[] (unsigned int index);

    // Adds an element to the end of the list.
    // Increases size of the list by one.
    void add(T value);

    // Removes an element from the end of the list.
    // Decreases size of the list by one.
    // Throws an exception if the list is empty.
    void remove();

private:
    // Pointer to the array
    T* arr;

    // Capacity of the array (amount of currently allocated space)
    unsigned int capacity;

    // Size of the list (number of entries currently being used)
    unsigned int size{ 0 };
};

template <typename T>
std::ostream& operator << (std::ostream& out, const ArrayList<T>& list)
{
    out << '[';

    if (list.getSize() > 0)
    {
        out << list[0];

        for (unsigned int i{ 1 }; i < list.getSize(); i++)
        {
            out << ", " << list[i];
        }
    }

    out << ']';

    return out;
}

template <typename T>
ArrayList<T>::ArrayList(unsigned int size, unsigned int addlCapacity)
    : size { size }, capacity { size + addlCapacity }, arr { new T[size + addlCapacity] }
{
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    delete[] arr;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& original)
    : ArrayList{ 0, original.capacity }
{
    // Copy each element from the original list to 
    // the new list.
    for (unsigned int i { 0 }; i < original.size; i++)
    {
        this->add(original.arr[i]);
    }
}

template <typename T>
ArrayList<T>::ArrayList(ArrayList<T>&& original)
    : size { original.size },
      capacity { original.capacity },
      arr { original.arr } // Steal the array from original.

{
    // Make the original empty.
    original.arr = nullptr;
    original.size = 0;
    original.capacity = 0;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator= (const ArrayList<T>& original)
{
    if (&original != this)
    {
        // Delete the previous array.
        delete[] arr;

        // Set the capacity to be considerably larger 
        // than the initial number of elements.
        capacity = original.capacity;

        // Allocate a new array with the new capacity.
        arr = new T[capacity];

        // Reset the size to zero.
        size = 0;

        // Copy each element from the original list to 
        // the new list.
        for (unsigned int i{ 0 }; i < original.size; i++)
        {
            this->add(original.arr[i]);
        }
    }

    // Return a reference to allow chain assignments.
    return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator= (ArrayList<T>&& original)
{
    // Steal from original and give original our old data to destroy.
    std::swap(this->arr, original.arr);
    std::swap(this->capacity, original.capacity);
    std::swap(this->size, original.size);
    return *this;

    // Return a reference to allow chain assignments.
    return *this;
}

template <typename T>
unsigned int ArrayList<T>::getSize() const
{
    return size;
}

template <typename T>
const T& ArrayList<T>::operator[] (unsigned int index) const
{
    if (index >= size)
    {
        throw std::out_of_range(
            "Index: " + std::to_string(index) +
            ", Size: " + std::to_string(size));
    }
    else
    {
        return arr[index];
    }
}

template <typename T>
T& ArrayList<T>::operator[] (unsigned int index)
{
    if (index >= size)
    {
        throw std::out_of_range(
            "Index: " + std::to_string(index) +
            ", Size: " + std::to_string(size));
    }
    else
    {
        return arr[index];
    }
}

template <typename T>
void ArrayList<T>::add(T value)
{
    // TODO: Implement this function.
}

template <typename T>
void ArrayList<T>::remove()
{
    // TODO: Implement this function.
}
