// Time Complexity = O(No. of Queries * No. of Users) = O(Q*N)
// Space Complexity = O((No. of Users + No. of Connections)*(Size of string))


#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    unordered_map<string,unordered_map<string,int>> karanMap;
    int n,m;
    cin>>n>>m;

    while(m--)
    {
        string a,b;
        cin>>a>>b;

        karanMap[b][a] = 1;
    }

    int a;
    cin >> a;
    string str1, str2;
    while(a--)
    {
        cin >> str1 >> str2;
        int followers = 0;
        for(auto p: karanMap[str2]){
            if(karanMap[p.first][str1]==0 && str1!=p.first){
                cout << p.first << " ";
                followers++;
            }
        }
        if(followers == 0){
            cout << 0;
        }
        cout << "\n";
    
    }

    return 0;
}
