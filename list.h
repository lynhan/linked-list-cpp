//
//  list.h
//  list
//
//  Created by lynhan on 7/4/16.
//  Copyright © 2016 lynhan. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>
#include <iostream>


template<typename T>
class list {
    struct node {
        node* prev;
        node* next;
        T val;
    };
    node* head = nullptr;
    node* tail = nullptr;
    
public:
    class iterator {
        node* current;
        
    public:
        T operator*() {
            return current->val;
        }
        node* operator->() {
            return current;
        }
        node* getCurrent() {
            return current;
        }
        bool operator==(const iterator & other) {
            return current == other.current;
        }
        bool operator!=(const iterator & other) {
            return current != other.current;
        }
        void operator++() {
            current = current->next;
        }
        void operator--() {
            current = current->prev;
        }
        operator bool() const {
            return current != nullptr;
        }
        void setNext(iterator nextIt) {
            current -> next = nextIt.current;
        }
        void setPrev(iterator prevIt) {
            current -> prev = prevIt.current;
        }
        void deleteNode() {
            delete current;
        }
        iterator(node* n) {
            current = n;
        }
        iterator(iterator const &other) {
            current = other.current;
        }
    };
    
    iterator begin() {
        return iterator(head);
    }
    
    iterator end() {
        return iterator(nullptr);
    }
    
    bool empty() {
        return head == nullptr;
    }
    
    void link(node* one, node* two) {
        one -> next = two;
        two -> prev = one;
    }
    
    /*
     return iterator pointing to element following last deleted element.
     */
    iterator erase(iterator it) {
        if (!it) return it;
        
        if (it.getCurrent() == head && head == tail) { // size == 1
            head = tail = nullptr;
        } else if (it.getCurrent() == head) {
            it -> next -> prev = it -> prev;
            head = head -> next;
        } else if (it.getCurrent() == tail) {
            it -> prev -> next = it -> next;
            tail = tail -> prev;
        } else {  // middle of list with size > 2
            link(it -> prev, it ->next);
        }
        iterator after(it);
        ++after;
        it.deleteNode();
        return after;
    }
    
    /*
     erase [first,last)
     */
    iterator erase(iterator first, iterator last) {
        while (first != last) {
            first = erase(first);
        }
        return last;
    }
    
    /*
     return iterator that points to the first of the newly inserted elements.
     */
    iterator insert(iterator it, T val) {
        node* newNode = new node{nullptr, nullptr, val};
        
        if (empty()) {
            head = tail = newNode;
        }
        // start of list OR list with size 1
        else if (it == begin() || begin() == end()) {
            link(newNode, head);
            head = newNode;
        }
        else if (it == end()) {
            link(tail, newNode);
            tail = tail -> next;
        }
        else {  // middle of list with size > 2
            link(it -> prev, newNode);
            link(newNode, it.getCurrent());
        }
        return iterator(newNode);
    }
    
    void push_back(T val) {
        insert(end(), val);
    }
    
    void pop_back() {
        if (head != tail) {
            tail = tail->prev;
            tail -> next = nullptr;
        } else {
            head = tail = nullptr;
        }
    }
    
    void printMe() {
        if (empty()) {
            std::cout << "empty list!" << std::endl;
            return;
        }
        iterator current(begin());
        while (current != end()) {
            std::cout << *current << " ";
            ++current;
        }
        std::cout << std::endl;
    }
    
    ~list() {
        while (!empty()) {
            erase(begin());
        }
    }
};


#endif /* list_h */
