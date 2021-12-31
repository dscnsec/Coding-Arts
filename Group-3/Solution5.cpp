/* Time complexity - 
    O(no_of_new_connections * no_of_users) = O(X*N) to answer the queries.
Total time Complexity = O(X*N) 
Here N-no_of_users X number_of_new_connections_input
Space Complexity - O(N^2)  (space required to store users and their folllowers). Here N is No.of Users. */

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll int

int main()
{
    fast;
    ll number_of_users, number_of_connections;
    cin >> number_of_users >> number_of_connections;
    unordered_map<string,unordered_map<string,bool>> followersList;
    string userA, userB, userC, userD;
    for(ll i=0; i<number_of_connections; i++)
    {
        cin >> userA >> userB;
        followersList[userB][userA] = 1;
    }
    ll number_of_new_connections;
    cin>>number_of_new_connections;
    for(ll i=0;i<number_of_new_connections;i++)
    {
        cin >> userC >> userD;
        bool noFollowers=true;
        for(auto [follower, isFollowing ] : followersList[userD])
        {
            if(followersList[follower][userC] == 0 && follower!=userC)
            {
                cout<< follower <<" ";
                noFollowers=false;
            }
        }
        if(noFollowers)
            cout<<"0";
        cout<<"\n";
    }
    return 0;
}