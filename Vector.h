#pragma once

namespace zorua{
namespace stl{

template <typename T>
class Vector{
public:
    Vector();
    ~Vector();
    

private:
    T* m_data;
    int m_size;
    int m_capacity;
};

template<typename T>
Vector<T>::Vector() : m_data(nullptr), m_size(0), m_capacity(0){

}

template<typename T>
Vector<T>::~Vector(){
    if (m_data != nullptr){
        delete[] m_data;
        m_data = nullptr;
    }
    m_size = 0;
    m_capacity = 0;
}

}
}