#include <iostream>
#include <string>
#include <fstream>
#include "structs.h"

using namespace std;

void push_back(node *new_node, blacklist *list_ptr){
    new_node = make_copy(new_node);
    if (list_ptr->first == nullptr){
        list_ptr->first = new_node;
    }
    else{
        node * current = list_ptr->first;
        while (current->next != nullptr){
            current = current->next;
        }
        current->next = new_node;
    }

    new_node->next = nullptr;
    list_ptr->size++;
}

void push_front(node *new_node, blacklist *list_ptr){
    new_node = make_copy(new_node);
    new_node->next = list_ptr->first;
    list_ptr->first = new_node;
    list_ptr->size++;
}

void push_after_front(node *new_node, blacklist *list_ptr){
    if (!empty(list_ptr)){
        new_node = make_copy(new_node);
        new_node->next = list_ptr->first->next;
        list_ptr->first->next = new_node;
        list_ptr->size++;
    }
}

void insert_after_each(node *new_node,node * to_search, blacklist *list_ptr){
    node * current = list_ptr->first;
        while (current->next != nullptr){
            if (current->text == to_search->text){
                new_node = make_copy(new_node);
                new_node->next=current->next;
                current->next = new_node;
                list_ptr->size++;
            }
            current = current->next;
        }
}

void print_in_file(blacklist * list_ptr){
    string path;
    cout << "Enter file path: ";
    cin >> path;
    ofstream fout;
    fout.exceptions(ofstream::badbit | ofstream::failbit);
    try{
    fout.open(path, ios::app);
    node * current = list_ptr->first;
    for (int i=0;current != nullptr || i<list_ptr->size; i++){
        fout<<"["<<i<<"]" <<current->text << endl;
        current = current->next;
    }
    fout <<"Size: "<< list_ptr->size << endl;

    fout.close();
    }
    catch (const std::exception & ex){
        cout << ex.what() << endl;
        if (wanna_try()){
            print_in_file(list_ptr);
        }
    }

}

void print_all(blacklist * list_ptr){
    node * current = list_ptr->first;
    for (int i = 0; i <= 20; i++){
        cout << "=";
    }
    cout <<endl;
    for (int i=0;current != nullptr || i<list_ptr->size; i++){
        cout <<"["<<i<<"]" <<current->text << endl;
        current = current->next;
    }
    cout <<"Size: "<< list_ptr->size <<endl;
        for (int i = 0; i <= 20; i++){
        cout << "=";
    }
    cout <<endl;
}

node * make_copy(node * input){
    node * ghost = new node;
    ghost->text = input->text;
    return ghost;
}

void pop_front(blacklist * list_ptr){
    node * temp = list_ptr->first;
    list_ptr->first = list_ptr->first->next;
    list_ptr->size--;
    delete temp;
}

void clear(blacklist * list_ptr){
    while (list_ptr->first != nullptr){
        pop_front(list_ptr);
    }
}

bool wanna_try(){
    char answ;
    cout << "Try again? <y/n> \n";
    cin >> answ;
    switch (answ){
    case 'y':
        return true;
    case 'n':
        return false;
    default:
        return true;
}
}

bool empty(blacklist * list_ptr){
    if(list_ptr->first == nullptr){
        return true;
    }
    else{
        return false;
    }
}






