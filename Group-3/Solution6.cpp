/* 
   Let 'V' be the total number of cities in the map connected in the form of a graph and 
       'E' be the number of prerequisite connections (accepted as input starting from second line of input)
    
   Time Complexity: O(V+E) -> owing to the use of topological sort.
   Space Complexity: O(V+E) -> space requirement for storing the locations(V) and number of edges/prerequisite (E). 
                     O(V) -> auxiliary space to store indegree of each nodes
                     O(V) -> to store the nodes in the order they are finally visited
                     O(V) -> auxiliary space to store visited nodes while performing topological sort 
                     Therefore, the overall Space Complexity is O(V+E)
*/

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main()
{
    fast;
    int number_of_cities;
    cin>>number_of_cities;
    unordered_map<string,vector<string>> adjacencyList;
    string desired_city,prerequisite_city;
    unordered_map<string,int> indegree;
    while(cin>>desired_city>>prerequisite_city)
    {
        adjacencyList[prerequisite_city].push_back(desired_city);
        indegree[desired_city]++;
        if(indegree.find(prerequisite_city)==indegree.end())
        {
            indegree[prerequisite_city]=0;
        }
    }
    queue<string> visitingOrder;
    for(auto node:indegree)
    {
        if(node.second==0)
        {
            visitingOrder.push(node.first);
        }
    }
    if(visitingOrder.empty())
    {
        cout<<"0"<<endl;
    }
    else
    {
        vector<string> ansOrder;
        while(!visitingOrder.empty())
        {
            string node = visitingOrder.front();
            ansOrder.push_back(node);
            visitingOrder.pop();
            for(string location:adjacencyList[node])
            {
                indegree[location]--;
                if(indegree[location]==0)
                {
                    visitingOrder.push(location);
                }
            }
        }
        if(ansOrder.size()!=number_of_cities)
        {
            cout<<"0"<<endl;
        }
        else
        {
            for(string location:ansOrder)
            {
                cout<<location<<" ";
            }
        }
    }
    cout<<"\n";
    
    
    return 0;
}
