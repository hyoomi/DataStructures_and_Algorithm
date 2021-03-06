#include <iostream>
#include <algorithm>

struct my_list_node{
    int data;
    my_list_node* next;
}

class my_list{
public:
    using node = my_list_node;
private:
    node* head;
public:
    void push_front(int val){
        auto new_node = new node {val, NULL};
        if(head != NULL)
            new_node->next = head;
        head = new_node;
    }
    void pop_front(){
        auto first = head;
        if(head){
            head = head->next;
            delete first;
        }
    }
}

struct my_list_iterator{
private:
    node* it;
public:
    my_list_iterator(node* i) : it(i) {}
    int& operator*() { return it->data; }
    node* get() { return it; }   

    my_list_iterator& operator++(){ //선행 증가
        it = it->next;
        return *this;
    }
    my_list_iterator operator++(int){ //후행 증가
        my_list_iterator result = *this;
        ++(*this);
        return result;
    }
    friend bool operator==(const my_list_iterator& left, const my_list_iterator& right){
        return left.it == right.it;
    }
    friend bool operator!=(const my_list_iterator& left, const my_list_iterator& right){
        return left.it != right.it;
    }
}