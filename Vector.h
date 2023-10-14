#pragma once
#include<stdexcept>

namespace zorua{
namespace stl{

template <typename T>
class Vector{
public:
    Vector();
    ~Vector();
    int size() const;
    int capacity() const;
    bool empty() const;
    void reserve(unsigned int new_cap);
    void push_back(const T& value);
    T& at(unsigned int pos);
    T& operator[](unsigned int pos);

private:
    T* m_data;
    unsigned int m_size;
    unsigned int m_capacity;
};

template<typename T>
Vector<T>::Vector() : m_data(nullptr), m_size(0), m_capacity(0){

}

template<typename T>
Vector<T>::~Vector(){
    if (m_data != nullptr){
        delete [] m_data;
        m_data = nullptr;
    }
    m_size = 0;
    m_capacity = 0;
}

template<typename T>
int Vector<T>::size() const{
    return m_size;
}

template<typename T>
int Vector<T>::capacity() const{
    return m_capacity;
}

template<typename T>
bool Vector<T>::empty() const{
    return m_size == 0;
}

template<typename T>
void Vector<T>::reserve(unsigned int new_cap){
    if (new_cap <= m_capacity) return ;
    T* data = nullptr;
    data = new T[new_cap];
    for (int i = 0; i < m_size; ++i){
        data[i] = m_data[i];
    }
    if (m_data != nullptr){
        delete [] m_data;
    }
    m_data = data;
    m_capacity = new_cap;
}

template<typename T>
void Vector<T>::push_back(const T& value){
    if (m_size >= m_capacity){
        reserve(m_capacity == 0 ? 1 : (m_capacity * 2));
    }
    m_data[m_size] = value;
    m_size++;
}

template<typename T>
T& Vector<T>::at(unsigned int pos){
    if (pos < 0 || pos >= m_size){
        throw std::logic_error("out of range!");
    }
    return m_data[pos];
}

template<typename T>
T& Vector<T>::operator[](unsigned int pos){
    return at(pos);
}

}
}