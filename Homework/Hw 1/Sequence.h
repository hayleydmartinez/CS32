//
//  Sequence.h
//  Hw1
//
//  Created by Hayley Martinez on 4/12/18.
//  Copyright © 2018 Hayley Martinez. All rights reserved.
//

#ifndef Sequence_h
#define Sequence_h
#include <iostream>

using ItemType = unsigned long;
const int DEFAULT_MAX_ITEMS = 200;

class Sequence
{
public:
    // Constructor
    Sequence();
    
    // Member Functions
    bool empty() const;
    int size() const;
    bool insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
    
private:
    ItemType m_array[DEFAULT_MAX_ITEMS];
    int      m_size;
};

#endif /* Sequence_h */
