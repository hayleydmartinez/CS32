//
//  History.h
//  Proj1
//
//  Created by Hayley Martinez on 4/4/18.
//  Copyright © 2018 Hayley Martinez. All rights reserved.
//

#ifndef History_h
#define History_h

#include "globals.h"

class History
{
public:
    // Constructor
    History(int nRows, int nCols);
    
    // Mutators
    bool record(int r, int c);
    void display() const;
    
private:
    char m_grid[MAXROWS][MAXCOLS];
    int  m_rows;
    int  m_cols;
    
    // Helper functions
    bool isInBounds(int r, int c) const;
};

#endif /* History_h */
