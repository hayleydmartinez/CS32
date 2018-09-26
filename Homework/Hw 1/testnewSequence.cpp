//
//  testnewSequence.cpp
//  Hw1
//
//  Created by Hayley Martinez on 4/14/18.
//  Copyright © 2018 Hayley Martinez. All rights reserved.
//

#include "newSequence.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    Sequence s;
    assert(s.empty());
    assert(s.find(42) == -1);
    assert(s.insert(42) == 0);
    assert(s.size() == 1  &&  s.find(42) == 0);
    assert(s.insert(1, 19));
    assert(s.size() == 2);
    assert(s.insert(18) == 1);
    assert(s.size() == 3);
    assert(!s.empty());
    assert(s.erase(0));
    assert(s.size() == 2);
    assert(s.find(18) == 0);
    assert(s.insert(0, 3));
    assert(s.insert(0, 34));
    assert(s.insert(0, 6));
    assert(s.remove(34) == 1);
    assert(s.size() == 4);
    assert(s.find(3) == 1);
    
    Sequence s1(10);
    Sequence sc(s);
    
    assert(sc.size() == 4);
    assert(s1.size() == 0);
    assert(s1.insert(3) == 0);
    assert(s1.insert(0,4));
    assert(s1.insert(0,5));
    s1.swap(sc);
    
    assert(s1.size() == 4);
    assert(sc.size() == 3);
    
    
    cout << "Passed all tests" << endl;
}

