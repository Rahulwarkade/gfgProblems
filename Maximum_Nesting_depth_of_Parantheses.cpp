#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s)
{
    int mxdepth = INT_MIN;

    int depth = 0;
    for(int i=0; i<s.length(); i++)
    {
        if(s.at(i)=='(')
            depth++;
        else if(s.at(i)==')')
            depth--;

        mxdepth = max(mxdepth,depth);
    }

    return mxdepth;
}
int main()
{

 string str;

 getline(cin,str);

 cout<<maxDepth(str)<<endl;
}