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
}