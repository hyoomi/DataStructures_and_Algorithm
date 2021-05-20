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

    friend my_array<T> operator+(const my_array<T>& arr1, my_array<T>& arr2){
        my_array<T> sum(arr1.size() + arr2.size());
        std::copy(arr1.begin(), arr1.end(), sum.begin());
        std::copy(arr2.begin(), arr2.end(), sum.begin() + arr1.size());
        return sum;                        
    }

};

struct person{
    std::string name;
    int gender; //male:0,  female:1
};

std::ostream& operator<<(std::ostream& os, const person& p){
    if(p.gender == 1)
        return (os << "[" << p.name << ", male]");
    else if(p.gender == 2)
        return (os << "[" << p.name << ", female]");
    else
        return (os <<"[" << p.name << ", none]");
}

int main(){
    int numPerson;
    std::cout << "사람 수를 입력하시오: ";
    std::cin >> numPerson;

    my_array<person> p1(numPerson);
    for(int i = 0; i < numPerson; i++){
        std::string name;
        int gender;
        std::cout << i + 1 << "번째 사람 이름과 성별(0:male, 1:female)을 입력하시오: ";
        std::cin >> name >> gender;
        p1[i] = person{name, gender};
    }

    return 0;
}