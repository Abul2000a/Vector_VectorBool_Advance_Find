#include <iostream>

template <typename T>
class Vector{
public:
    class Iterator{
    public:
        Iterator(const Vector<T> *vector, int index);
        const T &operator*() const;
        Iterator &operator++();
        bool operator!=(const Iterator &rhs) const;

    private:
        const Vector<T> *m_Vector;
        int m_Index = -1;
    };

public:
    Vector() = default;
    explicit Vector(int capacity);
    ~Vector();

    void pushBack(const T &value);

    size_t size() const;
    const T &operator[](int index) const;

    Iterator begin() const;
    Iterator end() const;

private:
    T *m_Data = nullptr;
    int m_Size = 0;
    int m_Capacity = 0;
};


template<>
class Vector<bool>{
public:
    class Reference{
        public:
        Reference(Vector<bool>* vc = nullptr,size_t index = 0){
            vec = vc;
            ind = index;
        }
        operator bool(){
            return vec->m_Data[ind];
        };
        Reference &operator =(const bool value){
            vec->m_Data[ind] = value;
            return *this;
        }


        Reference &operator =(const Reference &obj){
            this->vec->m_Data = obj.vec->m_Data;
            return *this;
        }


        bool  operator[](size_t pos){
            return vec->m_Data[pos];
        }


        void flip(){
            if(vec->m_Data[ind]==true){
                 vec->m_Data[ind] = false;
            }
            else
                vec->m_Data[ind] = true;
        }


        private:
        Vector<bool> *vec;
        int ind;
    };


    Vector() = default;


    explicit Vector(int capacity){
    m_Capacity = capacity;
    m_Data = new bool[capacity];
    }


    ~Vector(){
    delete m_Data;
    m_Size = 0;
    m_Capacity = 0;
    }


    void pushBack(bool value){
        if (m_Size == m_Capacity){
            if (m_Capacity == 0)
                m_Capacity = 1;

            m_Capacity *= 2;

        bool * newVec = new bool[m_Capacity];

        for (int i = 0; i < m_Size; ++i){
            newVec[i] = m_Data[i];
        }

            delete m_Data;
            m_Data = newVec;
    }

    m_Data[m_Size] = value;
    ++m_Size;
    }


    size_t size() const{
        return m_Size;
    }


    Reference operator[](size_t index) {
        return Reference(this,index);
    }


    void flip(){
        for(size_t i = 0; i < size();++i){
           if(m_Data[i]==true){
                m_Data[i] = false;
        }
            else
                m_Data[i] = true;
        }
    }

    private:
    friend class Reference;
    bool *m_Data = nullptr;
    int m_Size = 0;
    int m_Capacity = 0;
};


template <typename T>
Vector<T>::Vector(int capacity){
    m_Capacity = capacity;
    m_Data = new T[capacity];
}


template <typename T>
Vector<T>::~Vector(){
    delete m_Data;
    m_Size = 0;
    m_Capacity = 0;
}


template <typename T>
void Vector<T>::pushBack(const T &value){
    if (m_Size == m_Capacity){
        if (m_Capacity == 0)
            m_Capacity = 1;

        m_Capacity *= 2;

        T * newVec = new T[m_Capacity];

        for (int i = 0; i < m_Size; ++i){
            newVec[i] = m_Data[i];
        }

            delete m_Data;
            m_Data = newVec;
    }

    m_Data[m_Size] = value;
    ++m_Size;
}


template <typename T>
size_t Vector<T>::size() const{
    return m_Size;
}


template <typename T>
const T &Vector<T>::operator[](int index) const{
    if (index >= m_Size){
        throw std::out_of_range("Invalid Index");
    }

    return m_Data[index];
}


template <typename T>
typename Vector<T>::Iterator Vector<T>::begin() const{
    return Vector<T>::Iterator{ this, 0 };
}


template <typename T>
typename Vector<T>::Iterator Vector<T>::end() const{
    return Vector<T>::Iterator{ this, m_Size };
}


template <typename T>
Vector<T>::Iterator::Iterator(const Vector<T> *vector, int index)
    : m_Vector(vector)
    , m_Index(index){}


template <typename T>
const T &Vector<T>::Iterator::operator*() const{
    return m_Vector->operator[](m_Index);
}


template <typename T>
typename Vector<T>::Iterator &Vector<T>::Iterator::operator++(){
    ++m_Index;
    return *this;
}


template <typename T>
bool Vector<T>::Iterator::operator!=(const Vector<T>::Iterator &rhs) const{
    return m_Index != rhs.m_Index;
}


int main(){
    Vector <int> vec;
    vec.pushBack(15);
    vec.pushBack(10);
    for(auto it: vec){
        std::cout << it << " ";
    }
    Vector<int>::Iterator it = vec.begin();
    std::cout << *it;
    Vector<bool> vec1;
    vec1.pushBack(1);
    vec1.pushBack(0);
    vec1.pushBack(1);
    vec1.flip();
    for(size_t i = 0 ; i < vec1.size();++i){
        std::cout << vec1[i] << " ";
    }
    vec1[2].flip();
    std::cout << vec1[2];
}