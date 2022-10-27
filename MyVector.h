#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

template<typename T>
class MyVector
{
public:
    MyVector(int size = 10);
    ~MyVector();

    // ·ÃÎÊ
    T& at(int index) const;
    T& front() const;
    T& back() const;
    T& operator[](int index);

    // ÈÝÁ¿
    bool empty() const;
    int size() const;
    int capacity() const;

    // ÐÞ¸Ä
    void clear();
    void insert(int index, const T& d);
    void remove(int index);
    void push_back(const T& d);
    void pop_back();

private:
    T* data;
    int length;
    int current_pos;
};

#endif // !MYVECTOR_H