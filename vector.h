/**

@file vector.h
@brief This file contains the implementation of the myVector class, a custom vector implementation.
*/
#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <initializer_list>
#include <cstdlib> 
#include <limits>
#include <vector>
/**
 * @brief Templated vector class implementation.
 *
 * Full vector implementation, except for operator invalidation.
 */
template <class T, class... Args>
class myVector
{
private:
    T* arr; /**< Pointer to the underlying array. */
    int size; /**< Current size of the vector. */
    int capacity; /**< Current capacity of the vector. */

public:
    int myVecCount = 0;
    /**
     * @brief Default constructor.
     */
    myVector() : arr(new T[1]), size(0), capacity(1) {};

    /**
     * @brief Constructor with size parameter.
     * @param size The initial size of the vector.
     */
    myVector(int size) : arr(new T[size]), size(size), capacity(size) {};

    /**
     * @brief Constructor with initializer list.
     * @param init The initializer list containing initial elements.
     */
    template <typename U>
    myVector(std::initializer_list<U> init) : size(init.size()), capacity(init.size())
    {
        arr = new T[capacity];
        int i = 0;
        for (auto it = init.begin(); it != init.end(); ++it) 
        {
            arr[i++] = *it;
        }
    }

    /**
     * @brief Constructor with iterators.
     * @param first Iterator pointing to the first element.
     * @param last Iterator pointing to one past the last element.
     */
    template<typename InputIt>
    myVector(InputIt first, InputIt last) : myVector(std::distance(first, last))
    {
        std::copy(first, last, arr);
    }

    /**
     * @brief Copy constructor.
     * @param other The vector to be copied.
     */
    myVector(const myVector<T>& other) : myVector(other.size)
    {
        std::copy(other.arr, other.arr + other.size, arr);
    }

    /**
     * @brief Destructor that deallocates the underlying array.
     */
    
    ~myVector()
    {
        delete[] arr; 
    }   

    /**
     * @brief Clears the vector.
     * 
     */
    void clear()
    {
        size = 0;
        capacity = 1;
        delete[] arr;
        arr = new T[1];
    }

    /**
     * @brief Prints the vector size, capacity and elements.
     * 
     */
    void print()
    {
        std::cout << "Size: " << size << std::endl;
        std::cout << "Capacity: " << capacity << std::endl;
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n" << std::endl;
    }

    /**
     * @brief resizes vector to newSize, fills new elements with default value
     * @param newSize The new size of the vector.
     */
    void resize(int newSize)
    {
        if (newSize < 0)
        {
            throw std::out_of_range("New size cannot be negative");
        }
        if(newSize > capacity)
        {
            reserve(newSize);
        }
        if(newSize > size)
        {
            for (int i = size; i < newSize; i++)
            {
                arr[i] = T();
            }
        }
        size = newSize;
    }

    /**
     * @brief pushes data to the back of the vector
     * 
     * @param data The data to be pushed to the back of the vector.
     */
    void push_back(T data)
    {
        (size == capacity) ? reserve(2 * capacity) : void();
        arr[size] = data;
        size++;
    }

    /**
     * @brief checks if vector is empty
     * 
     * @return true if vector is empty
     * @return false if vector is not empty
     */
    bool empty()
    {
        return size == 0; 
    }

    /**
     * @brief removes last element from vector
     * 
     */
    void pop_back() // removes last element
    {
        if(size > 0)
        {
            size--;
        }
    }

    /**
     * @brief reserves memory for vector
     * 
     * @param newCapacity The new capacity of the vector.
     */
    void reserve(int newCapacity)
    {
        myVecCount++;
        T* temp = new T[newCapacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }   
        delete[] arr;
        arr = temp;
        capacity = newCapacity; 
       
    }

    /**
     * @brief shrinks capacity to size, to save memory
     * 
     */
    void shrink_to_fit()
    {
        if(size < capacity)
        {
            T* temp = new T[size];
            for (int i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            capacity = size;
        }
    }

    /**
     * @brief inserts element at position
     * 
     * @param position The position to insert the element at.
     * @param data The data to be inserted.
     */
    void insert(T* position, const T& val)
    {
        // std::cout << "Inserting value " << val << " at position " << (position - arr) << std::endl;
        if (position < arr || position > arr + size) 
        {
            throw std::out_of_range("Position out of range");
        }
        if (size == capacity) 
        {
            T* old_arr = arr; // save pointer to old array
            reserve(2 * capacity);
            position = arr + (position - old_arr); // adjust position relative to new array
        }
        for (T* i = arr + size; i > position; i--) 
        {
            *i = *(i - 1);
        }
        *position = val;
        size++;
    }
    
    /**
     * @brief constructs element at the end of vector, forwards arguments to constructor
     * 
     * @tparam TArgs 
     * @param args 
     */
    template <typename... TArgs>
    void emplace_back(TArgs&&... args)
    {
        if (size == capacity) 
        {
            reserve(2 * capacity);
        }
        new (arr + size) T(std::forward<TArgs>(args)...);
        size++;
    }

    /**
     * @brief erases element at position
     * 
     * @param position The position of the element to be erased.
     */
    void erase(T* position)
    {
        if (position < arr || position >= arr + size) 
        {
            throw std::out_of_range("Position out of range");
        }
        for (T* i = position; i < arr + size - 1; i++) 
        {
            *i = *(i + 1);
        }
        size--;
    }

    /**
     * @brief swaps contents of two vectors
     * 
     * @param other 
     */
    void swap(myVector<T>& other)
    {
        std::swap(this->arr, other.arr);
        std::swap(this->size, other.size);
        std::swap(this->capacity, other.capacity);
    }
    
    /**
     * @brief  returns element at index, throws out_of_range exception if index is out of range
     * 
     * @param index 
     * @return T& 
     */
    T& at(int index)
    {
        if(index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    /**
     * @brief returns element at index, checks if index is out of range
     * 
     * @param index 
     * @return T& 
     */
    T& operator[](int index)
    {
        if(index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    /** 
     * @brief returns element in front of vector
     * 
     * @return T&
     */
    T& front()
    {
        if (size == 0) 
        {
            throw std::out_of_range("Vector is empty");
        }
        return arr[0];
    }

    /**
     * @brief returns element at the back of vector
     * 
     * @return T& 
     */
    T& back()
    {
        if (size == 0) 
        {
            throw std::out_of_range("Vector is empty");
        }
        return arr[size - 1];
    }

    /**
     * @brief returns pointer to array
     * 
     * @return T* 
     */
    T* data()
    {
        return arr;
    }
    

    /**
     * @brief returns pointer to first element
     * 
     * @return T* 
     */
    T* begin()
    {
        return arr;
    }

    /**
     * @brief returns pointer to one past last element
     * 
     * @return T* 
     */
    T* end()
    {
        return arr + size;
    }

    /**
     * @brief returns pointer to last element minus one
     * 
     * @return T* 
     */
    T* rbegin()
    {
        return arr + size - 1;
    }

    /**
     * @brief returns pointer to first element minus one
     * 
     * @return T* 
     */
    T* rend()
    {
        return arr - 1;
    }

    /**
     * @brief Gets the Size of object
     * 
     * @return int 
     */
    int getSize()
    {
        return size;
    }

    /**
     * @brief Gets the Capacity of object
     * 
     * @return int 
     */
    int getCapacity()
    {
        return capacity;
    }
    size_t max_size()
    {
        return std::numeric_limits<size_t>::max();
    }
    




};

#endif