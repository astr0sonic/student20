#include "bracket.h"
#include "bits/stdc++.h"
using namespace std;

bool checkBrackets(const std::string& s) {
    string b="{[<(",c="}]>)";
    stack<char>now;
    for(auto i:s)
    {
        int key=-1;
        for(int j=0;j<4;j++)
        {
            if(i==b[j])
            {
                key=j;
            }
        }
        if(key!=-1)
        {
            now.push(i);
            continue;
        }
        for(int j=0;j<4;j++)
        {
            if(i==c[j])
            {
                key=j;
            }
        }
        if(key!=-1)
        {
            if(now.empty())
            {
                now.push(i);
                break;
            }
            bool did=0;
            for(int j=0;j<4;j++)
            {
                if(now.top()==b[j]&&j==key)
                {
                    now.pop();
                    did=1;
                    break;
                }
            }
            if(!did)
            {
                cout<<"0\n";
                return 0;
            }
            continue;
        }
    }
    if(!now.empty())
    {
        cout<<"0\n";
    }
    else
    {
        cout<<"1\n";
    }
    return true;
}
