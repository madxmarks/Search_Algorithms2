#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <list>
#include <stack>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

class HashySlashy
{
public :
    vector<vector<string> > Hashy;
    //  unsigned int W = 997;
    //  unsigned int W = 10009;
    unsigned int W =  50671;

    HashySlashy()
    {
        Hashy.resize(W);
    }


    int Hashing(string s)
    {
        unsigned int S = 128;
        unsigned  int h =0;
        for (int k=0; k<s.length(); k++)
        {
            h=((h*S)%W+s[k])%W;
        }
        return h;
    }


    int searchy (string s, int i)
    {
        if(!Hashy[i].empty())
        {
            for(int j = 0; j<Hashy[i].size(); j++)
            {
                if(Hashy[i][j] == s)
                    return 1;
            }
        }
        return 0;
    }

    int searching (string s)
    {
        int i = Hashing(s);
        i = (searchy(s,i));
        return i;
    }


    void pushy(string s)
    {
        int i = Hashing(s);
        if(!searchy(s,i))
            Hashy[i].push_back(s);
    }




};







#endif // DFS_H
