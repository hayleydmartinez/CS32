//
//  History.cpp
//  Proj1
//
//  Created by Hayley Martinez on 4/4/18.
//  Copyright © 2018 Hayley Martinez. All rights reserved.
//

#include <iostream>
#include "globals.h"
#include "History.h"
using namespace std;

History::History(int nRows, int nCols)
: m_rows(nRows), m_cols(nCols)
{
    // create an empty grid with the same size as City
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            m_grid[i][j] = '.';
        }
    }
}

bool History::record(int r, int c)
{
    // check to see whether the spot is in bounds
    if (! isInBounds(r, c))
        return false;
    
    else
    {
        // iterate if converts already at that spot
        char spot = m_grid[r - 1][c - 1];
        if (spot >= 'A' && spot <= 'Z')
        {
            m_grid[r - 1][c - 1] += 1;
        }
        
        // iterate if no converts at the spot yet
        else
        {
            m_grid[r - 1][c - 1] = 'A';
        }
        
        return true;
    }
}

void History::display() const
{
    clearScreen();
    
    // print m_grid to the screen
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            cout << m_grid[i][j];
        }
        cout << '\n';
    }
    
    cout << '\n';
}

bool History::isInBounds(int r, int c) const
{
    return (r >= 1  &&  r <= m_rows  &&  c >= 1  &&  c <= m_cols );
}
