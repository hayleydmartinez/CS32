// Dictionary.cpp

#include "Dictionary.h"
#include <string>
#include <vector>
#include <list>
#include <cctype>
#include <algorithm>
#include <functional>
#include <utility>  // for swap

using namespace std;

void removeNonLetters(string& s);
void generateNextPermutation(string& permutation);

// This class does the real work of the implementation.

// make buckets! modeled after the in-class example
// of our student id numbers

class Bucket
{
public:
    Bucket(string key) : m_key(key) {}
    string getKey() const { return m_key; }
    void addAnagram(string anagram) { m_anagrams.push_back(anagram); }
    vector<string> getAnagrams() const { return m_anagrams; }
    
private:
    string m_key;
    vector<string> m_anagrams;
};

class DictionaryImpl
{
public:
    DictionaryImpl() {}
    ~DictionaryImpl();
    void insert(string word);
    void lookup(string letters, void callback(string)) const;
private:
    list<Bucket*> m_words[50000];
};

DictionaryImpl::~DictionaryImpl()
{
    for (int i = 0; i < 50000; i++)
    {
        list<Bucket*>::iterator j = m_words[i].begin();
        
        while (j != m_words[i].end())
        {
            if ((*j) != nullptr)
                delete (*j);
            j++;
        }
    }
}

void DictionaryImpl::insert(string word)
{
    removeNonLetters(word);
    if ( ! word.empty())
    {
        // make a key
        string key = word;
        sort(key.begin(), key.end());
        hash<string> hash;
        int hashkey = hash(key) % 50000;
        
        // add the key to the map or add word to bucket
        if (m_words[hashkey].size() == 0)
        {
            Bucket* newAnagram = new Bucket(key);
            newAnagram->addAnagram(word);
            m_words[hashkey].push_back(newAnagram);
        }
        else
        {
            list<Bucket*>::iterator i = m_words[hashkey].begin();
            
            while (i != m_words[hashkey].end())
            {
                if ((*i)->getKey() == key)
                {
                    (*i)->addAnagram(word);
                    return;
                }
                i++;
            }
            
            Bucket* newAnagram = new Bucket(key);
            newAnagram->addAnagram(word);
            m_words[hashkey].push_back(newAnagram);
        }
    }
}

void DictionaryImpl::lookup(string letters, void callback(string)) const
{
    if (callback == nullptr)
        return;
    
    removeNonLetters(letters);
    if (letters.empty())
        return;
    
    string key = letters;
    sort(key.begin(), key.end());
    hash<string> hash;
    int hashkey = hash(key) % 50000;
    
    
    if (m_words[hashkey].size() != 0)
    {
        list<Bucket*>::const_iterator i = m_words[hashkey].begin();
        
        while (i != m_words[hashkey].end())
        {
            if ((*i)->getKey() == key)
            {
                vector<string> anagrams = (*i)->getAnagrams();
                
                for (int j = 0; j < anagrams.size(); j++)
                    callback(anagrams[j]);
            }
            i++;
        }
    }
}

void removeNonLetters(string& s)
{
    string::iterator to = s.begin();
    for (string::const_iterator from = s.begin(); from != s.end(); from++)
    {
        if (isalpha(*from))
        {
            *to = tolower(*from);
            to++;
        }
    }
    s.erase(to, s.end());  // chop everything off from "to" to end.
}

// Each successive call to this function generates the next permutation of the
// characters in the parameter.  For example,
//    string s = "eel";
//    generateNextPermutation(s);  // now s == "ele"
//    generateNextPermutation(s);  // now s == "lee"
//    generateNextPermutation(s);  // now s == "eel"
// You don't have to understand this function's implementation.
void generateNextPermutation(string& permutation)
{
    string::iterator last = permutation.end() - 1;
    string::iterator p;
    
    for (p = last; p != permutation.begin()  &&  *p <= *(p-1); p--)
        ;
    if (p != permutation.begin())
    {
        string::iterator q;
        for (q = p+1; q <= last  &&  *q > *(p-1); q++)
            ;
        swap(*(p-1), *(q-1));
    }
    for ( ; p < last; p++, last--)
        swap(*p, *last);
}

//******************** Dictionary functions ********************************

// These functions simply delegate to DictionaryImpl's functions.
// You probably don't want to change any of this code

Dictionary::Dictionary()
{
    m_impl = new DictionaryImpl;
}

Dictionary::~Dictionary()
{
    delete m_impl;
}

void Dictionary::insert(string word)
{
    m_impl->insert(word);
}

void Dictionary::lookup(string letters, void callback(string)) const
{
    m_impl->lookup(letters,callback);
}

