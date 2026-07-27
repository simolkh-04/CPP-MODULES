#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array {
private:
    T*              _array;
    unsigned int    _size;

public:
    Array() : _array(NULL), _size(0) {}
    Array(unsigned int n) : _size(n) {
        if (n == 0)
            _array = NULL;
        else
            _array = new T[n]();
    }

    Array(Array const & src) : _array(NULL), _size(0) {
        *this = src;
    }

    ~Array() {
        if (_array)
            delete[] _array;
    }

    Array & operator=(Array const & rhs) {
        if (this != &rhs) {
            if (_array)
                delete[] _array;
            
            _size = rhs._size;
            if (_size == 0)
                _array = NULL;
            else {
                _array = new T[_size]();
                for (unsigned int i = 0; i < _size; i++) {
                    _array[i] = rhs._array[i];
                }
            }
        }
        return *this;
    }

    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Index out of bounds!";
        }
    };

    T & operator[](unsigned int index) {
        if (index >= _size || !_array)
            throw OutOfBoundsException();
        return _array[index];
    }

    T const & operator[](unsigned int index) const {
        if (index >= _size || !_array)
            throw OutOfBoundsException();
        return _array[index];
    }
    
    unsigned int size() const {
        return _size;
    }
};

#endif