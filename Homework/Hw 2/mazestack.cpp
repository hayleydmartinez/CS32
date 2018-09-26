//
//  mazestack.cpp
//  Hw2
//
//  Created by Hayley Martinez on 4/27/18.
//  Copyright © 2018 Hayley Martinez. All rights reserved.
//

#include <stack>
#include <iostream>
using namespace std;

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

bool isValid(char pos)
{
    return pos != '!' && pos != 'X';
}

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    stack<Coord> cstack;
    Coord pos(sr, sc);
    cstack.push(pos);
    maze[sr][sc] = '!';
    
    while (!cstack.empty())
    {
        pos = cstack.top();
        cstack.pop();
        int r = pos.r();
        int c = pos.c();
        
        if (r == er && c == ec)
            return true;
        
        if (r != 0 && isValid(maze[r-1][c]))
        {
            Coord npos(r-1, c);
            cstack.push(npos);
            maze[r-1][c] = '!';
        }
        if (c != 0 && isValid(maze[r][c-1]))
        {
            Coord npos(r, c-1);
            cstack.push(npos);
            maze[1][c-1] = '!';
        }
        if (r != 9 && isValid(maze[r+1][c]))
        {
            Coord npos(r+1, c);
            cstack.push(npos);
            maze[r+1][c] = '!';
        }
        if (c != 9 && isValid(maze[r][c+1]))
        {
            Coord npos(r, c+1);
            cstack.push(npos);
            maze[r][c+1] = '!';
        }
    }
    
    return false;
}

int main()
{
    char maze[10][10] = {
        { 'X','X','X','X','X','X','X','X','X','X' },
        { 'X','.','.','.','.','.','.','.','.','X' },
        { 'X','X','X','X','X','.','X','.','X','X' },
        { 'X','.','.','.','X','.','X','.','.','X' },
        { 'X','.','X','.','.','.','X','.','.','X' },
        { 'X','.','X','X','X','.','X','X','X','X' },
        { 'X','X','X','.','.','.','.','X','.','X' },
        { 'X','.','X','X','.','X','X','X','.','X' },
        { 'X','.','.','.','.','X','.','.','.','X' },
        { 'X','X','X','X','X','X','X','X','X','X' }
    };
    
    if (pathExists(maze, 6,5, 1,8))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}

