#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;

//Flyod Warshall Algo to create all pair shortest path matrix
void minDistances(vector<vector<int>> &cm)
{
    int n = cm.size();
    int k, i, j;
    for(k=0; k<n; k++)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                cm[i][j] = min(cm[i][j], (cm[i][k] + cm[k][j]));
            }
        }
    }
}

//function to display optimal route
void route(vector<vector<int>> &cost, int n)
{
    vector<int> vis(n+1, 0);
    vis[0]=1;
    int rem=n, minCafe=0, minDist, cafe=0;
    cout<<0<<" "<<0<<"\n";
    while(rem--)
    {
        minDist=INF;
        for(int i=0; i<=n; i++)
        {
            if(vis[i]==0 && (cost[minCafe][i]<minDist))
            {
                minDist=cost[minCafe][i];
                cafe=i;
            }
        }minCafe=cafe;
        vis[minCafe]=1;
        cout<<minCafe<<" "<<minDist<<"\n";
    }
}

//main funtion
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>> cost(n+1,vector<int>(n+1,INF));
    for(int i=0; i<=n; i++)
    {
        cost[i][i]=0;
    }
    int edges = n*(n+1)/2;
    for(int i=0; i<edges; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        cost[u][v]=cost[v][u]=w;
    }
    //form the all pair shortest path matrix
    minDistances(cost);
    //display optimal route
    route(cost, n);
    return 0;
}
// Time Complexity -  O(V^3)+O(V^2) =  O(V^3)
// Space Complexity - O(V^2)
