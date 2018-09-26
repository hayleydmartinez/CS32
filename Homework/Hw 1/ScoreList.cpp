//
//  ScoreList.cpp
//  Hw1
//
//  Created by Hayley Martinez on 4/13/18.
//  Copyright © 2018 Hayley Martinez. All rights reserved.
//

#include "ScoreList.h"

ScoreList::ScoreList() : m_scores()
{ }

bool ScoreList::add(unsigned long score)
{
    // If the score is valid (a value from 0 to 100) and the score list
    // has room for it, add it to the score list and return true.
    // Otherwise, leave the score list unchanged and return false.
    return ( score <= 100 &&
             m_scores.insert(m_scores.size(), score) );
}

bool ScoreList::remove(unsigned long score)
{
    // Remove ONE instance of the specified score from the score list.
    // Return true if a score was removed; otherwise false.
    int pos = m_scores.find(score);
    
    return ( !m_scores.empty() && m_scores.erase(pos) );
}

int ScoreList::size() const
{
    // Return the number of scores in the list.
    return m_scores.size();
}

unsigned long ScoreList::minimum() const
{
    
    // Return the lowest score in the score list.
    unsigned long cur;
    unsigned long min;
    int pos = 0;
    
    if ( !m_scores.empty() )
    {
        // Initialize min.
        m_scores.get(pos, min);
        
        // Update cur.
        while ( m_scores.get(pos, cur) && pos < m_scores.size() )
        {
            // If the current item is smaller than the smallest
            // item so far, the current item becomes the new min.
            if ( cur < min )
            {
                min = cur;
            }
            
            pos++;
        }
        
        return min;
    }
    
    // If the list is empty, return NO_SCORE.
    else
    {
        return NO_SCORE;
    }
    
}


unsigned long ScoreList::maximum() const
{
    // Return the highest score in the score list.
    unsigned long cur;
    unsigned long max;
    int pos = 0;
    
    if ( !m_scores.empty() )
    {
        // Initialize max.
        m_scores.get(pos, max);
        
        // Update cur.
        while ( m_scores.get(pos, cur) && pos < m_scores.size() )
        {
            // If the current item is bigger than the biggest
            // item so far, the current item becomes the new max.
            if ( cur > max )
            {
                max = cur;
            }
            
            pos++;
        }
        
        return max;
    }
    
    // If the list is empty, return NO_SCORE.
    else
    {
        return NO_SCORE;
    }
}
