//
//  Sequence.cpp
//  Proj2
//
//  Created by Hayley Martinez on 4/18/18.
//  Copyright © 2018 Hayley Martinez. All rights reserved.
//

#include "Sequence.h"
#include <iostream>

// Constructor for default node.
Sequence::Node::Node()
{
    m_next = this;
    m_prev = this;
}


// Constructor for specific node.
Sequence::Node::Node(ItemType data) : m_data(data)
{
    m_next = this;
    m_prev = this;
}


// Constructor for default sequence.
Sequence::Sequence() : head(new Node), m_size(0)
{
    head->m_next = head;
    head->m_prev = head;
}


// Copy constructor.
Sequence::Sequence(const Sequence& other) : m_size(other.m_size)
{
    head = new Node;
    Node* p = other.head->m_next;
    Node* r = head;
    
    for (; p != other.head; p = p->m_next)
    {
        Node* q = new Node(p->m_data);
        r->m_next = q;
        q->m_prev = r;
        q->m_next = head;
        head->m_prev = q;
        r = q;
    }
}


// Destructor for sequence.
Sequence::~Sequence()
{
    Node* p = head;
    for (Node* n = p->m_next; n != head; p = n, n = p->m_next)
        delete p;
    delete p;
}



// Assignment operator for sequence.
Sequence& Sequence::operator=(const Sequence& rhs)
{
    if (this != &rhs)
    {
        Sequence temp(rhs);
        swap(temp);
    }
    return *this;
}


// Dump function to see what sequence contains.
void Sequence::dump() const
{
    Node* p = head->m_next;
    
    std::cerr << "The list contains: ";
    
    for (int i = 0; i < size(); i++)
    {
        std::cerr << p->m_data << " ";
        p = p->m_next;
    }
    
    std::cerr << std::endl;
}


// Returns true if sequence is empty.
bool Sequence::empty() const
{
    return ( m_size == 0 );
}


// Return the number of items in the sequence.
int Sequence::size() const
{
    return m_size;
}


// Inserts a specific node at a specific position.
bool Sequence::insert(int pos, const ItemType& value)
{
    // Checks bounds.
    if ( pos < 0 || pos > size() )
    {
        return false;
    }
    
    uncheckedInsert(pos, value);
    return true;
}


// Inserts a specified node.
int Sequence::insert(const ItemType& value)
{
    // Make a pointer to the first item and store position.
    Node* p = head->m_next;
    int pos = 0;
    
    // Contiue searching if position is less than size and
    // the node data is less than value.
    for (; pos < size() && p->m_data < value; pos++)
    {
        p = p->m_next;
    }
    
    uncheckedInsert(pos, value);
    return pos;
}


// Erases node at specific position.
bool Sequence::erase(int pos)
{
    // Checks bounds.
    if (pos < 0 || pos >= size())
        return false;
    
    Node* p = head->m_next;
    
    // Iterate until at the position.
    for (int i = 0; i < pos; i++)
    {
        p = p->m_next;
    }
    
    // Erase node.
    Node* q = p;
    p->m_prev->m_next = p->m_next;
    p->m_next->m_prev = p->m_prev;
    delete q;
    
    // Decrement size.
    m_size--;
    
    return true;
}


// Removes all instances of a value from a sequence.
int Sequence::remove(const ItemType& value)
{
    // Create a counter.
    Node* p = head->m_next;
    int count = 0;
    
    // Iterate through entire sequence.
    int size = this->size();
    for (int i = 0; i < size;)
    {
        // Erase if it's the same value.
        if (p->m_data == value)
        {
            Node* q = p;
            p->m_prev->m_next = p->m_next;
            p->m_next->m_prev = p->m_prev;
            p = p->m_next;
            delete q;
            
            count++;
        }
        
        // Otherwise move on.
        else
        {
            p = p->m_next;
            i++;
        }
    }
    
    return count;
}


// Assigns value to the value at specific position.
bool Sequence::get(int pos, ItemType& value) const
{
    // Checks bounds.
    if (pos < 0 || pos >= size())
        return false;
    
    Node* p = head->m_next;
    
    // Iterate until at position.
    for (int i = 0; i < pos; i++)
    {
        p = p->m_next;
    }
    
    // Assign value to seq value.
    value = p->m_data;
    return true;
}


// Assigns the value at specific position to value.
bool Sequence::set(int pos, const ItemType& value)
{
    // Checks bounds.
    if (pos < 0 || pos >= size())
        return false;
    
    Node* p = head->m_next;
    
    // Iterate until at position.
    for (int i = 0; i < pos; i++)
    {
        p = p->m_next;
    }
    
    // Assign seq value to value.
    p->m_data = value;
    return true;
}


// Finds the first instance of value in a sequence.
int Sequence::find(const ItemType& value) const
{
    Node* p = head->m_next;
    
    // Iterate through until you find value.
    for (int i = 0; i < size(); i++)
    {
        if (p->m_data == value)
            return i;                   // Return first instance.
        
        p = p->m_next;
    }
    return -1;
}


// Swaps sequences.
void Sequence::swap(Sequence& other)
{
    // Swap heads.
    head->m_next->m_prev = other.head;
    other.head->m_next->m_prev = head;
    head->m_next = other.head->m_next;
    other.head->m_next = head->m_next;
    
    head->m_prev->m_next = other.head;
    other.head->m_prev->m_next = head;
    head->m_prev = other.head->m_prev;
    other.head->m_prev = head->m_prev;
    
    // Swap sizes.
    int tempSize = m_size;
    m_size = other.m_size;
    other.m_size = tempSize;
}


// Inserts.
void Sequence::uncheckedInsert(int pos, const ItemType& value)
{
    // Create a new Node.
    Node* ins = new Node(value);

    Node* curr = head;
    
    // Iterate until at position.
    for ( int i = 0; i < pos; i++ )
    {
        curr = curr->m_next;
    }
    
    // Relink nodes.
    ins->m_prev = curr;
    ins->m_next = curr->m_next;
    curr->m_next->m_prev = ins;
    curr->m_next = ins;
    
    // Increment size.
    m_size++;
}


// Finds earliest instance of a subsequence.
int subsequence(const Sequence& seq1, const Sequence& seq2)
{
    ItemType val1;
    ItemType val2;
    
    // Iterate until seq1 val equals seq2 val.
    for (int i = 0; i <= seq1.size() - seq2.size()
            && seq1.get(i, val1); i++)
    {
        if (seq2.get(0, val2) && val1 == val2)
        {
            bool exists = true;
            
            // Check if all following values equal seq2.
            for (int j = 1; j < seq2.size() && seq1.get(i + j, val1)
                    && seq2.get(j, val2); j++)
            {
                if (val1 != val2)
                {
                    exists = false;
                    break;
                }
            }
            
            // If so, return position.
            if (exists)
                return i;
        }
    }
    return -1;
}


// Interweaves two sequences together into result.
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result)
{
    // Guards against aliasing.
    if (&seq1 == &result)
        result = seq1;
    else if(&seq2 == &result)
        result = seq2;
    
    // Clear result.
    while (!result.empty())
    {
        result.erase(0);
    }
    
    // Create a new sequence.
    Sequence* ilseq = new Sequence;
    ItemType data;
    int c1 = 0;
    int c2 = 0;
    
    // Check which one is longer.
    if (seq1.size() >= seq2.size())
    {
        // Add them alternatingly to ilseq.
        while(c2 < seq2.size())
        {
            if (c1 == c2 && seq1.get(c1, data))
            {
                ilseq->insert(c1 + c2, data);
                c1++;
            }
            else
            {
                seq2.get(c2, data);
                ilseq->insert(c1 + c2, data);
                c2++;
            }
        }
        
        // Dump the rest of the longer into ilseq.
        while(c1 < seq1.size() && seq1.get(c1, data))
        {
            ilseq->insert(ilseq->size(), data);
            c1++;
        }
    }
    
    // Same idea here except opposite.
    else
    {
        while(c1 < seq1.size())
        {
            if (c1 == c2 && seq1.get(c1, data))
            {
                ilseq->insert(c1 + c2, data);
                c1++;
            }
            else
            {
                seq2.get(c2, data);
                ilseq->insert(c1 + c2, data);
                c2++;
            }
        }
        
        while(c2 < seq2.size() && seq2.get(c2, data))
        {
            ilseq->insert(ilseq->size(), data);
            c2++;
        }
    }
    
    // Set result equal to new sequence.
    result = *ilseq;
    
    delete ilseq;
}
