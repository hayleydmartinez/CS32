
void removeBad(list<Movie*>& li)
{
    list<Movie*>::const_iterator p = li.begin();
    
    while (p != li.end())
    {
        if (*p != nullptr && (*p)->rating() < 50)
        {
            Movie* q = *p;
            li.erase(p++);
            delete q;
        }
        else if (*p == nullptr)
        {
            li.erase(p++);
        }
        else
        {
            p++;
        }
    }
}
