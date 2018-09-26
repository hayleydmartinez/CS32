//
//  newSequence.h
//  Hw1
//
//  Created by Hayley Martinez on 4/13/18.
//  Copyright © 2018 Hayley Martinez. All rights reserved.
//

#ifndef newSequence_h
#define newSequence_h

#include <iostream>

using ItemType = unsigned long;
const int DEFAULT_MAX_ITEMS = 200;

class Sequence
{
public:
    // Constructors & Destructor
    Sequence();
    Sequence(int size);
    Sequence(const Sequence& other );
    ~Sequence();
    
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
    ItemType * m_array;
    int        m_size;
    int        m_max;
};

#endif /* newSequence_h */
