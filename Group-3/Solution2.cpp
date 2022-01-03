#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long

int main()
{
    fast;
    ll n, m;
    cin>>n>>m;
    unordered_map<string,vector<string>> mp;
    string a,b,s;
    for(ll i=0; i<m; i++)
    {
        cin>>a>>b;
        mp[b].push_back(a);
    }
    while(cin>>s)
    {
        cout<<mp[s].size()<<"\n";
        for(string name:mp[s])
            cout<<name<<" ";
        if(mp[s].size())
            cout<<"\n";
    }
    return 0;
}
// Time Complexity - O(n) in worst case.
// Space COmplexity - O(n*n) in worst case.
