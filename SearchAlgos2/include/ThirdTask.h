#ifndef THIRDTASK_H
#define THIRDTASK_H
#define NUMC 256

#include <iostream>
#include <string>

using namespace std;
/// prefix trie
class trie
{
    struct node
    {
        node *ch[NUMC];
        bool val;
        node()
        {
            val=false;
            for (int i=0; i<NUMC; i++) ch[i]=nullptr;
        }
    }
    root;
public:
    void inse(const string &str);
    bool finde(const string &str);

};


void trie::inse(const string &str)
{
    node * ptr = &root;
    int i=0;
    while(i<str.length())
    {
        if(!(ptr->ch)[str[i]])
            ptr->ch[str[i]]=new node;
        ptr=ptr->ch[str[i]];
        i=i+1;
    }
    ptr->val=true;
}

bool trie::finde(const string &str)
{
    node * ptr= &root;
    int i=0;
    while(i<str.length())
    {
        if(!ptr->ch[str[i]])
            return false;
        ptr=ptr->ch[str[i]];
        i=i+1;
    }
    return ptr->val;

}




#endif // THIRDTASK_H
