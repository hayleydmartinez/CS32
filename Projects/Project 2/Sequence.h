//
//  Sequence.h
//  Proj2
//
//  Created by Hayley Martinez on 4/18/18.
//  Copyright © 2018 Hayley Martinez. All rights reserved.
//

#ifndef Sequence_h
#define Sequence_h

#include <string>

using ItemType = std::string;

class Sequence
{
public:
    // Constructors
    Sequence();
    Sequence(const Sequence& other);
    
    // Destructor
    ~Sequence();
    
    // Assignment operator
    Sequence& operator=(const Sequence& rhs);
    
    //Public functions
    void dump() const;
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
    // Declare Node
    struct Node
    {
        // Constructors
        Node();
        Node(ItemType data);
        
        // Member variables
        ItemType m_data;
        Node* m_prev;
        Node* m_next;
    };
    
    // Member variables
    Node* head;
    int   m_size;
    
    // Private function
    void uncheckedInsert(int pos, const ItemType& value);
};

// Non-member functions
int subsequence(const Sequence& seq1, const Sequence& seq2);
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);

#endif /* Sequence_h */
