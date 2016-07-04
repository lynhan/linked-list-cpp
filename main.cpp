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

int main(int argc, const char * argv[]) {
    int a(1);
    int b(2);
    list<int> L;
    
    L.push_back(a);
    L.push_back(b);
    L.insert(L.end(), 3);
    L.insert(L.end(), 4);
    L.printMe();
    
    L.erase(L.begin());
    L.printMe();
    
    L.pop_back();
    L.printMe();
    
    L.erase(L.begin(), L.end());
    L.printMe();

    cout << "done" << endl;
    return 0;
}
