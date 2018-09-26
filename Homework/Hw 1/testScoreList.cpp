//
//  testScoreList.cpp
//  Hw1
//
//  Created by Hayley Martinez on 4/13/18.
//  Copyright © 2018 Hayley Martinez. All rights reserved.
//


#include "ScoreList.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    ScoreList s;
    assert( s.size() == 0 );
    assert( s.minimum() == NO_SCORE );
    assert( s.maximum() == NO_SCORE );
    assert( s.add(0) );
    assert( s.minimum() == 0 );
    assert( s.maximum() == 0 );
    assert( s.add(30) );
    assert( s.add(99) );
    assert( s.add(100) );
    assert( !s.add(101) );
    assert( !s.add(-1) );
    assert( s.minimum() == 0 );
    assert( s.maximum() == 100 );
    assert( s.size() == 4 );
    assert( s.remove(100) );
    assert( s.size() == 3 );
    assert( !s.remove(31) );
    assert( !s.remove(101) );
    
    
    cout << "Passed all tests" << endl;
}

