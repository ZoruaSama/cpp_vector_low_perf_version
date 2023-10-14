// Date: 2023.10.14
// Author: Zorua

#pragma once
#include<stdexcept>
#include<iostream>

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
    void pop_back();
    void clear();
    T& at(unsigned int pos);
    T& operator[](unsigned int pos);
    void reverse();

    friend std::ostream& operator<<(std::ostream& cout, Vector<T>& v){
        cout<<"[";
        for (unsigned i = 0; i < v.size(); ++i){
            cout << v[i];
            if (i != v.size() - 1) cout << ", ";
        }
        cout<<"]";
        return cout;
    };

    class Iterator{
        public:
            Iterator(T* pointer) : m_pointer(pointer){ };
            bool operator==(const Iterator& other){
                return m_pointer == other.m_pointer;
            }
            
            bool operator!=(const Iterator& other){
                return m_pointer != other.m_pointer;
            }

            T& operator*(){
                return *m_pointer;
            }

            Iterator& operator++(){
                m_pointer++;
                return *this;
            }

            Iterator operator++(int){
                Iterator it = *this;
                m_pointer++;
                return it;
            }

            T* operator->(){
                return m_pointer;
            }
            

        private:
            T* m_pointer;
    };

    Iterator begin();
    Iterator end();

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
    for (unsigned int i = 0; i < m_size; ++i){
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
void Vector<T>::pop_back(){
    m_size--;
}

template<typename T>
void Vector<T>::clear(){
    m_size = 0;
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

template<typename T>
void Vector<T>::reverse(){
    unsigned mid = m_size / 2;
    for(unsigned int i = 0; i < mid; ++i){
        T temp = m_data[i];
        m_data[i] = m_data[m_size - 1 - i];
        m_data[m_size - 1 - i] = temp;
    }
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::begin(){
    return Vector<T>::Iterator(m_data);
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::end(){
    return Vector<T>::Iterator(m_data + m_size);
}


}
}