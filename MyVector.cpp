#include "MyVector.h"

template<typename T>
MyVector<T>::MyVector(int size) : length(size), current_pos(0)
{
    if (data != nullptr) {
        delete[] data;
        data = nullptr;
    }
    data = new T[length];
    memset(data, 0, length * sizeof(T));
}

template<typename T>
MyVector<T>::~MyVector()
{
    if (data != nullptr) {
        delete[] data;
        data = nullptr;
    }
}

template<typename T>
T& MyVector<T>::at(int index) const
{
    assert(index > 0 && index < current_pos);
    return data[index];
}

template<typename T>
T& MyVector<T>::front() const
{
    assert(current_pos > 0);
    return data[0];
}

template<typename T>
T& MyVector<T>::back() const
{
    assert(current_pos > 0);
    return data[current_pos - 1];
}

template<typename T>
T& MyVector<T>::operator[](int index)
{
    assert(index > 0 || index < current_pos);
    return data[index];
}

template<typename T>
bool MyVector<T>::empty() const
{
    return current_pos == 0 ? true : false;
}

template<typename T>
int MyVector<T>::size() const
{
    return current_pos;
}

template<typename T>
int MyVector<T>::capacity() const
{
    return length;
}

template<typename T>
void MyVector<T>::clear()
{
    current_pos = 0;
}

template<typename T>
void MyVector<T>::insert(int index, const T& d)
{
    assert(index > 0 || index < current_pos);
    if (current_pos == length) {
        // 扩容，每次扩容 10 个数据大小的空间
        T* temp = new T[length + 10];
        memset(temp, 0, (length + 10) * sizeof(T));
        memcpy(temp, data, length * sizeof(T));
        length += 10;
        delete[] data;
        data = nullptr;
        data = temp;
    }

    // 插入数据
    memcpy(data + index + 1, data + index, (length - index) * sizeof(T));
    data[index] = d;

    // 当前数组指针 +1
    current_pos++;

}

template<typename T>
void MyVector<T>::remove(int index)
{
    assert(index > 0 || index < current_pos);

    memcpy(data + index, data + index + 1, (current_pos - index) * sizeof(T));
    current_pos--;
}

template<typename T>
void MyVector<T>::push_back(const T& d)
{
    // 检查当前数组大小是否可用
    if (current_pos == length) {
        // 扩容，每次扩容 10 个数据大小的空间
        T* temp = new T[length + 10];
        memset(temp, 0, (length + 10) * sizeof(T));
        memcpy(temp, data, length * sizeof(T));
        length += 10;
        delete[] data;
        data = nullptr;
        data = temp;
    }

    // 插入数据
    data[current_pos] = d;

    // 当前数组指针 +1
    current_pos++;

}

template<typename T>
void MyVector<T>::pop_back()
{
    assert(current_pos > 0);
    current_pos--;
}