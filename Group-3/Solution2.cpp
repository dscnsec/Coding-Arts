#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long

int main()
{
    fast;
    ll number_users, number_connections;
    cin>>number_users>>number_connections;
    unordered_map<string,vector<string>> userList;
    string follower,user,query_user;
    for(ll i=0; i<number_connections; i++)
    {
        cin>>follower>>user;
        userList[user].push_back(follower);
    }
    while(cin>>query_user)
    {
        cout<<userList[query_user].size()<<"\n";
        for(string name:userList[query_user])
            cout<<name<<" ";
        if(userList[query_user].size())
            cout<<"\n";
    }
    return 0;
}
// Time Complexity - O(n*q) in worst case, where 'q' is the number of queries
// Space COmplexity - O(n*n) in worst case.
