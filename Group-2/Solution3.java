import java.util.*;
import java.lang.*;
import java.io.*;


public class AllPairShortestPath
{

/*To find the distance betweem every consecutive vertex sequentially we can use the floyd warshall algorithm*/
	void floydWarshall(int graph[][],int V,int dist[][])
	{

		int i, j, k;
		for (i = 0; i < V+1; i++)//copying graph weights into distance
		{
		    for (j = 0; j < V+1; j++)
		    {
		        dist[i][j] = graph[i][j];
		    }
		}
		for (k = 0; k < V+1; k++)
		{
			for (i = 0; i < V+1; i++)
			{

				for (j = 0; j < V+1; j++)
				{
					if (dist[i][k] + dist[k][j] < dist[i][j])
					{
					    dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
	}

	void printSolution(int dist[][],int V)
	{
	    System.out.println(0+" "+0);//distance from home to home
		for (int i=0; i<V; ++i)//distance from home to the last cafe sequentially
		{
			System.out.println((i+1)+" "+dist[i][i+1]);
		}
	}

	public static void main (String[] args)
	{
	    Scanner in=new Scanner(System.in);
	    int V,E;
	    V=in.nextInt();
	    E=(V*(V+1))/2;//number of edges
	    int dist[][] = new int[V+1][V+1];//matrix to store the minimum distances for every vertex
		int graph[][] = new int[V+1][V+1];//adjacency matrix to store the graph with weights
		for(int i=0;i<V+1;i++)//self loops will have a distance 0
		{
		    graph[i][i]=0;
		}
		while(E!=0)//reading all the distances i.e weights of the graph
		{
		    int c1,c2,d;
		    c1=in.nextInt();
		    c2=in.nextInt();
		    graph[c1][c2]=in.nextInt();
            graph[c2][c1]=graph[c1][c2];
		    E--;
		}
		
		AllPairShortestPath obj = new AllPairShortestPath();//object of class as the functions are non static

		obj.floydWarshall(graph,V,dist);//for finding the minimum path length
		obj.printSolution(dist,V);//for printing
	}
}
