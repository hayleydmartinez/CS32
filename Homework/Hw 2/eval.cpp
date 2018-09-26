//
//  eval.cpp
//  Hw2
//
//  Created by Hayley Martinez on 4/27/18.
//  Copyright © 2018 Hayley Martinez. All rights reserved.
//

#include <string>
#include <stack>
#include <iostream>
#include <cassert>
using namespace std;

bool convert(char b);
char convert(bool b);
int precedence(char op);

int evaluate(string infix, string& postfix, bool& result)
{
    // Empty string catcher
    if (infix.size() == 0)
        return 1;
    
    // Initialize variables
    postfix = "";               // postfix
    stack<char> ops;            // operand / operator stack
    int ptc = 0;                // parenthese count
    char pc = infix[0];         // previous character
    
    // Infix to postfix
    for (int i = 0; i < infix.size(); i++)
    {
        char ch = infix[i];
        
        switch(ch)
        {
            case ' ':
                // continue if a space
                break;
            case 'T':
            case 'F':
                // cannot follow another T or F
                if (i != 0 && infix.size() != 1 && isalpha(pc))
                    return 1;
                postfix += ch;
                pc = ch;        // update previous character
                break;
             case '!':
             case '(':
                // cannot follow ) or a operand, be only char, or be last
                if ((infix.size() != 1 && (pc == ')' || isalpha(pc)))
                    || i == infix.size() - 1 || infix.size() == 1)
                    return 1;
                ops.push(ch);
                if (ch == '(')
                    ptc++;      // update parenthese count
                pc = ch;        // update previous character
                break;
            case ')':
                // cannot be first, follow an operator or (, or be only char
                if (i == 0 || (infix.size() != 1 && (pc == '!' || pc == '|'
                    || pc == '&' || pc == '(')) || infix.size() == 1 || ptc == 0)
                    return 1;
                while(ops.top() != '(')
                {
                    postfix += ops.top();
                    ops.pop();
                }
                ops.pop();
                ptc--;          // update parenthese count
                pc = ch;        // update previous character
                break;
            case '|':
            case '&':
                // cannot be first, last, follow an operator, or be only char
                if (i == 0 || i == infix.size() - 1 || (infix.size() != 1 &&
                   (pc == '!' || pc == '(' || pc == '&' || pc == '|')) ||
                    infix.size() == 1)
                    return 1;
                // check precedence
                while(!ops.empty() && ops.top() != '(' &&
                      precedence(ch) <= precedence(ops.top()))
                {
                    postfix += ops.top();
                    ops.pop();
                }
                ops.push(ch);
                pc = ch;
                break;
            default:
                return 1;
                break;
        }
    }
    
    // Parenthese check
    if (ptc != 0)
    {
        return 1;
    }
    
    // Add rest of operators to postfix
    while (!ops.empty())
    {
        postfix += ops.top();
        ops.pop();
    }
    
    // Evaluate postfix
    for (int i = 0; i < postfix.size(); i++)
    {
        char ch = postfix[i];
        
        if (ch == 'T' || ch == 'F')
        {
            ops.push(ch);
        }
        else if (ch == '!')
        {
            ops.top() = convert(!convert(ops.top()));
        }
        else
        {
            bool op2 = convert(ops.top());
            ops.pop();
            bool op1 = convert(ops.top());
            ops.pop();
            if (ch == '|')
            {
                ops.push(convert(op1 || op2));
            }
            else if (ch == '&')
            {
                ops.push(convert(op1 && op2));
            }
        }
    }
    
    result = convert(ops.top());
    
    return 0;
}

bool convert(char b)
{
    return b == 'T';
}
                     
char convert(bool b)
{
    if (b)
        return 'T';
    else
        return 'F';
}
                     
int precedence(char op)
{
    switch(op)
    {
        case '!':
            return 3;
        case '&':
            return 2;
        case '|':
            return 1;
        default:
            return 0;
    }
}
                     
int main()
{
    string pf;
    bool answer;
    assert(evaluate("T| F", pf, answer) == 0  &&  pf == "TF|"  &&  answer);
    assert(evaluate("T|", pf, answer) == 1);
    assert(evaluate("|", pf, answer) == 1);
    assert(evaluate("1", pf, answer) == 1);
    assert(evaluate("T&", pf, answer) == 1);
    assert(evaluate("!T", pf, answer) == 0 && pf == "T!" && !answer);
    assert(evaluate("!", pf, answer) == 1);
    assert(evaluate("&", pf, answer) == 1);
    assert(evaluate(")T", pf, answer) == 1);
    assert(evaluate("T(", pf, answer) == 1);
    assert(evaluate("T()", pf, answer) == 1);
    assert(evaluate("()!F", pf, answer) == 1);
    assert(evaluate("F&T(!F)", pf, answer) == 1);
    assert(evaluate("F&&T", pf, answer) == 1);
    assert(evaluate("F!&T", pf, answer) == 1);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("(T) & F | T)", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("T|F", pf, answer) == 0 && pf == "TF|" && answer);
    assert(evaluate("()", pf, answer) == 1);
    assert(evaluate("T(F|T)", pf, answer) == 1);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("(T&(F|F)", pf, answer) == 1);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("F  |  !F & (T&F) ", pf, answer) == 0
           &&  pf == "FF!TF&&|"  &&  !answer);
    assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
    assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
    assert(evaluate("T | (F)", pf, answer) == 0  &&  pf == "TF|"  &&  answer);
    assert(evaluate("T | ((F & T) | T) & !F", pf, answer) == 0
           &&  pf == "TFT&T|F!&|"  &&  answer);
    
    cout << "Passed all tests" << endl;
}
