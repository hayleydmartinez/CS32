//
//  newSequence.cpp
//  Hw1
//
//  Created by Hayley Martinez on 4/13/18.
//  Copyright © 2018 Hayley Martinez. All rights reserved.
//

#include "newSequence.h"


Sequence::Sequence()
: m_array(new ItemType[DEFAULT_MAX_ITEMS]), m_size(0), m_max(DEFAULT_MAX_ITEMS)
{ }


Sequence::Sequence(int size)
: m_array(new ItemType[size]), m_size(0), m_max(size)
{ }


Sequence::Sequence(const Sequence& other)
{
    m_array = new ItemType[other.m_size];
    
    for ( int i = 0; i < m_size; i++ )
    {
        m_array[i] = other.m_array[i];
    }
    
    m_size  = other.m_size;
    m_max   = other.m_max;
}


Sequence::~Sequence()
{
    delete [] m_array;
}


Sequence Sequence::operator=(const Sequence& rhs)
{
    // Check to see if you are reassigning the same thing.
    if (this != &rhs)
    {
        // Make a copy of rhs.
        Sequence temp(rhs);
        
        // Delete initial array.
        delete [] m_array;
        
        // Swap.
        m_size  = temp.m_size;
        m_max   = temp.m_max;
        m_array = new ItemType[temp.m_max];
        for (int i = 0; i < m_size; i++)
        {
            m_array[i] = temp.m_array[i];
        }
    }
    return *this;
}


bool Sequence::empty() const
{
    // Return true if the sequence is empty
    // otherwise return false.
    return ( m_size == 0 );
}


int Sequence::size() const
{
    // Return the number of items in the sequence.
    return m_size;
}


bool Sequence::insert(int pos, const ItemType& value)
{
    
    if ( pos >= 0 && pos <= m_size && m_size < m_max )
    {
        // The original item at position pos and those that follow it
        // end up at positions one higher than they were at before.
        for ( int i = m_size; i > pos; i-- )
        {
            m_array[i + 1] = m_array[i];
            m_array[i] = m_array[i - 1];
        }
        
        // Insert value into the sequence so that it becomes the item
        // at position pos.
        m_array[pos] = value;
        
        // Update size of Sequence.
        m_size++;
        
        // Return true if 0 <= pos <= size() and the value could be
        // inserted.
        return true;
    }
    
    else
    {
        // Otherwise, leave the sequence unchanged and return false.
        return false;
    }
    
}


int Sequence::insert(const ItemType& value)
{
    
    bool larger_found = false;
    int p = 0;
    
    // Let p be the smallest integer such that value <= the item at
    // position p in the sequence.
    if ( !this->empty() )
    {
        while ( p <= m_size && !larger_found )
        {
            if ( value <= m_array[p] )
            {
                larger_found = true;
            }
            
            p++;
        }
    }
    else
    {
        larger_found = true;
    }
    
    // Insert value into the sequence, etc.
    if ( larger_found && this->insert(p, value) )
    {
        // Return p if the value was actually inserted.
        return p;
    }
    
    else
    {
        // Return -1 if the value was not inserted.
        return -1;
    }
    
}


bool Sequence::erase(int pos)
{
    
    if ( 0 <= pos && pos < m_size )
    {
        // Update size of Sequence.
        m_size--;
        
        // Remove the item at position pos from the sequence...
        for ( int i = pos; i < m_size; i++ )
        {
            m_array[pos] = m_array[pos + 1];
        }
        
        // ...and return true.
        return true;
    }
    
    else
    {
        // Otherwise, leave the sequence unchanged and return false.
        return false;
    }
    
}


int Sequence::remove(const ItemType& value)
{
    int num_removed = 0;
    
    for ( int i = 0; i < m_size; i++ )
    {
        // Erase all items from the sequence that == value.
        if ( m_array[i] == value )
        {
            this->erase(i);
            num_removed += 1;
        }
    }
    
    // Return the number of items removed.
    return num_removed;
}


bool Sequence::get(int pos, ItemType& value) const
{
    
    if ( 0 <= pos && pos <= m_size )
    {
        // Copy into value the item at position pos in the
        // sequence...
        value = m_array[pos];
        
        // ...and return true.
        return true;
    }
    
    else
    {
        // Otherwise, leave value unchanged and return false.
        return false;
    }
    
}


bool Sequence::set(int pos, const ItemType& value)
{
    
    if ( 0 <= pos && pos < m_size )
    {
        // Replace the item at position pos in the sequence
        // with value...
        m_array[pos] = value;
        
        // ...and return true.
        return true;
    }
    
    else
    {
        //Otherwise, leave the sequence unchanged and return false.
        return false;
    }
    
}


int Sequence::find(const ItemType& value) const
{
    
    bool found = false;
    int p = 0;
    
    // Let p be the smallest integer such that value == the item at
    // position p in the sequence.
    while ( p < m_size && !found )
    {
        if ( value == m_array[p] )
        {
            found = true;
            break;
        }
        
        p++;
    }
    
    // If no such item exists, let p be -1.
    if ( !found )
    {
        p = -1;
    }
    
    return p;
}


void Sequence::swap(Sequence& other)
{
    // Exchange the contents of this sequence with the other one.
    
    // Create a temp Sequence copy of other.
    int temp_max  = other.m_max;
    int temp_size = other.m_size;
    ItemType* temp_cont = other.m_array;
    
    // Equal other to this.
    other.m_max   = this->m_max;
    other.m_size  = this->m_size;
    other.m_array = this->m_array;
    
    // Equal this to other.
    this->m_max   = temp_max;
    this->m_size  = temp_size;
    this->m_array = temp_cont;
}

