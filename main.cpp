//
//  main.cpp
//  list
//
//  Created by lynhan on 7/4/16.
//  Copyright © 2016 lynhan. All rights reserved.
//

#include <iostream>
#include "list.h"
using namespace std;

class bowl {
    string noodle = "soba";
    int toppings = 0;
    
public:
    bowl(string&& _noodle,
         int&& _toppings) :
    noodle(_noodle),
    toppings(_toppings) {}
    
    bowl(bowl&& other) :
    noodle(other.noodle),
    toppings(other.toppings) {}
};

template<typename ...AllParams>
void print(AllParams... allParams);

template<>
void print() {
    std::cout << endl;
}

template<typename First, typename ...Rest>
void print(First first, Rest... rest) {
    std::cout << first;
    print(rest...);
}

int main(int argc, const char * argv[]) {
    int a(1);
    int b(2);
    list<int> nums;
    
    nums.push_back(a);
    nums.push_back(b);
    nums.insert(nums.end(), 3);
    nums.insert(nums.end(), 4);
    nums.printMe();
    
    nums.erase(nums.begin());
    nums.printMe();
    
    nums.pop_back();
    nums.printMe();
    
    nums.erase(nums.begin(), nums.end());
    nums.printMe();
    
    list<bowl> bowls;
    string w("wheat");
    int t(10);
    bowls.emplace_back(std::move(w), std::move(t));
    return 0;
}
