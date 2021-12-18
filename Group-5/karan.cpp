#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    unordered_map<string,vector<string>> karanMap;
    int n,m;
    cin>>n>>m;

    while(m--)
    {
        string a,b;
        cin>>a>>b;

        karanMap[b].push_back(a);
    }

    string str;
    while(cin>>str)
    {
        cout<<karanMap[str].size()<<endl;
        for(auto i:karanMap[str])
        {
            cout<<i<<" ";
        }
    
    }

    return 0;
}