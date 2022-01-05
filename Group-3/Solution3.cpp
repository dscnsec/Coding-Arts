#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;

//Flyod Warshall Algo to create all pair shortest path matrix
void minDistances(vector<vector<int>> &cost_matrix)
{
    int size = cost_matrix.size();
    // i,j,k are the three control variables to three respective loops
    int k, i, j;
    for(k=0; k<size; k++)
    {
        for(i=0; i<size; i++)
        {
            for(j=0; j<size; j++)
            {
                cost_matrix[i][j] = min(cost_matrix[i][j], (cost_matrix[i][k] + cost_matrix[k][j]));
            }
        }
    }
}

//function to display optimal route
void route(vector<vector<int>> &cost_matrix, int size)
{
    vector<int> visited(size+1, 0);
    visited[0]=1;
    int limit=size, nearest_cafe=0, minimum_distance, cafe=0;
    cout<<0<<" "<<0<<"\n";
    while(limit--)
    {
        minimum_distance=INF;
        for(int i=0; i<=size; i++)
        {
            if(visited[i]==0 && (cost_matrix[nearest_cafe][i]<minimum_distance))
            {
                minimum_distance=cost_matrix[nearest_cafe][i];
                cafe=i;
            }
        }
        nearest_cafe=cafe;
        visited[nearest_cafe]=1;
        cout<<nearest_cafe<<" "<<minimum_distance<<"\n";
    }
}

//main funtion
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size;
    cin>>size;
    vector<vector<int>> cost_matrix(size+1,vector<int>(size+1,INF));
    for(int i=0; i<=size; i++)
    {
        cost_matrix[i][i]=0;
    }
    int edges = size*(size+1)/2;
    for(int i=0; i<edges; i++)
    {
        int start, end, cost;
        cin>>start>>end>>cost;
        cost_matrix[start][end]=cost_matrix[end][start]=cost;
    }
    //form the all pair shortest path matrix
    minDistances(cost_matrix);
    //display optimal route
    route(cost_matrix, size);
    return 0;
}
// Time Complexity -  O(V^3)+O(V^2) =  O(V^3)
// Space Complexity - O(V^2)
