#include <string>
#include <algorithm>
#include <iostream>

template <typename T>
class my_array{
    T* data;
    size_t n;
public:
    my_array(int n){
        this->n = n;
        data = new T[n];
    }
    my_array(const my_array<T>& copy){
        n = copy.n;
        data = new T[n];
        for(int i = 0; i < n; i++)
            data[i] = copy.data[i]; //data[i] = copy[i];
    }
    T& operator[](int index){
        return data[index];
    }
    T& at(int index){
        if(index < n)
            return data[index];
        throw "index out of range";
    }
    size_t size() const{
        return n;
    }
    ~my_array(){
        delete[] data;
    }

    T* begin(){ return data; }
    const T* begin() const { return data; }
    T* end() { return data + n; }
    const T* end() const { return data + n; }

}