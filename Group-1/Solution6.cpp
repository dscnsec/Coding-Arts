
/*
**Time complexity-
O(V+E)- topological Sorting is used. Here,
- V= Total number of cities.
- E= Number of prior connections.
**Space complexity-
O(V+E)-Space used to store the nodes of the graph in stack
V and E as mentioned above
**Approach-
1.Build a graph for a given connections.
2.Sort the graph using Topological Sorting Technique.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll int
//Finding the cycle if any.
bool Cycle_detection(unordered_map<string,vector<string>> &adjacencyList,unordered_map<string,bool> &Loc_visited,unordered_map<string,bool> & Visited_recent,string Location_current)
{
    if(!Loc_visited[Location_current])
    {
        Visited_recent[Location_current] = 1;
        Loc_visited[Location_current] = 1;
        for(auto location : adjacencyList[Location_current])
        {
            if(Visited_recent[location] == 1)
            	return true;
            if(Loc_visited[location]==0)
                if(Cycle_detection(adjacencyList,Loc_visited,Visited_recent,location))
			return true;
        }
    }
    Visited_recent[Location_current] = 0;
    return false;
}
//Sorting the graph using topological Sorting Technique.
void topologicalSorting(unordered_map<string,vector<string>> &adjacencyList, unordered_map<string,bool> &Loc_visited,vector<string> &order_of_visiting,string Location_current)
{
    Loc_visited[Location_current] = 1;
    for(auto location :adjacencyList[Location_current])
    {
        if(!Loc_visited[location])
            topologicalSorting(adjacencyList,Loc_visited,order_of_visiting,location);
    }
   order_of_visiting.push_back(Location_current);
}

int main() {
    ll city_num;
    cin>>city_num;
    string city_prereq,city_des;
    unordered_map<string,vector<string>> adjacencyList;
    while(cin>>city_des)
    {
        cin>>city_prereq;
        adjacencyList[city_prereq].push_back(city_des);
        adjacencyList[city_des];
    }
    unordered_map<string,bool> Loc_visited,Visited_recent;
    for(auto element:adjacencyList)
    {
        string location = element.first;
        if(!Loc_visited[location] && Cycle_detection(adjacencyList,Loc_visited,Visited_recent,location))
        {
            cout<<"0";
            	return 0;
        }
    }
    Loc_visited.clear();
    vector<string>order_of_visiting;
    for(auto element : adjacencyList)
    {
        string location = element.first;
        if(!Loc_visited[location])
            topologicalSorting(adjacencyList,Loc_visited,order_of_visiting,location);
    }
    //reversing the data which is pushed
    reverse(order_of_visiting.begin(),order_of_visiting.end());
    for(auto location:order_of_visiting)
        cout<<location<<" ";
    return 0;
}
