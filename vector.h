#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <initializer_list>
#include <cstdlib> 
#include <limits>
#include <vector>

template <class T, class... Args>
class manoVector //Full vector implementation, except for operator invalidation
{
private:
    T* arr;
    int size;
    int capacity;
public:

    manoVector() : arr(new T[1]), size(0), capacity(1) {}; // default constructor
    manoVector(int size) : arr(new T[size]), size(size), capacity(size) {}; // constructor with size
    template <typename U>
    manoVector(std::initializer_list<U> init) : size(init.size()), capacity(init.size()) // constructor with initializer list
    {
        arr = new T[capacity];
        int i = 0;
        for (auto it = init.begin(); it != init.end(); ++it) 
        {
            arr[i++] = *it;
        }
    }
    template<typename InputIt>
    manoVector(InputIt first, InputIt last) : manoVector(std::distance(first, last)) // constructor with iterators
    {
        std::copy(first, last, arr);
    }

    
    manoVector(const manoVector<T>& other) : manoVector(other.size) // copy constructor
    {
        std::copy(other.arr, other.arr + other.size, arr);
    }
    ~manoVector()
    {
        // for (int i = 0; i < size; i++) 
        // {
        //     for(int i = 0; i < size; i++)
        //     {
        //         delete arr[i];
        //     }
        // }
        delete[] arr; 
    }   

    // member functions
    void clear() // clears vector, sets size to 0, capacity to 1, deletes array and creates new array with capacity 1
    {
        size = 0;
        capacity = 1;
        delete[] arr;
        arr = new T[1];
    }
    void print() // prints vector size, capacity and elements
    {
        std::cout << "Size: " << size << std::endl;
        std::cout << "Capacity: " << capacity << std::endl;
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n" << std::endl;
    }
    void resize(int newSize) // resizes vector to newSize, fills new elements with default value
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
    void push_back(T data)
    {
        (size == capacity) ? reserve(2 * capacity) : void();
        arr[size] = data;
        size++;
    }
    bool empty() // checks if vector is empty
    {
        return size == 0; 
    }
    void pop_back() // removes last element
    {
        if(size > 0)
        {
            size--;
        }
    }
    void reserve(int newCapacity) // reserves newCapacity for vector
    {
        T* temp = new T[newCapacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }   
        delete[] arr;
        arr = temp;
        capacity = newCapacity; 
       
    }
    void shrink_to_fit() // reduces capacity to size
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
    void insert(T* position, const T& val) // inserts val before position
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
    
    template <typename... TArgs>
    void emplace_back(TArgs&&... args) // constructs element at the end of vector
    {
        if (size == capacity) 
        {
            reserve(2 * capacity);
        }
        new (arr + size) T(std::forward<TArgs>(args)...);
        size++;
    }

    void erase(T* position) // removes element at position
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
    void swap(manoVector<T>& other) // swaps contents of two vectors
    {
        std::swap(this->arr, other.arr);
        std::swap(this->size, other.size);
        std::swap(this->capacity, other.capacity);
    }
    //element access
    T& at(int index) // returns element at index, throws out_of_range exception if index is out of range
    {
        if(index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }
    T& operator[](int index) // overloads [] operator, returns element at index
    {
        return arr[index];
    }
    T& front() // returns first element
    {
        if (size == 0) 
        {
            throw std::out_of_range("Vector is empty");
        }
        return arr[0];
    }
    T& back() // returns last element
    {
        if (size == 0) 
        {
            throw std::out_of_range("Vector is empty");
        }
        return arr[size - 1];
    }
    T* data() // returns pointer to array
    {
        return arr;
    }
    //iterators
    T* begin() // returns pointer to first element
    {
        return arr;
    }
    T* end() // returns pointer to one past last element
    {
        return arr + size;
    }
    T* rbegin()
    {
        return arr + size - 1;
    }
    T* rend()
    {
        return arr - 1;
    }

    // getters
    int getSize()
    {
        return size;
    }
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