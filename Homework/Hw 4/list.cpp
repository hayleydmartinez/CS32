void listAll(string path, const File* f)  // two-parameter overload
{
    if (f == nullptr) { return; }
    
    path += "/" + f->name();
    cout << path << endl;
    
    if (f->files() != nullptr)
    {
        vector<File*>::const_iterator it = f->files()->begin();
        while (it != f->files()->end())
        {
            listAll(path, *it);
            it++;
        }
    }
}

