// Time complexity: O(V^3)
// V is the number of cafeterias.

// Space complexity: O(V^2)

import java.util.*;
class ProblemStatement3 {

    void floydWarshall(int graph[][],int V)
    {
        int dist[][] = new int[V][V];
        int i, j, k;
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                dist[i][j] = graph[i][j];
        for (k = 0; k < V; k++)
        {
            for (i = 0; i < V; i++)
            {
                for (j = 0; j < V; j++)
                {

                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        printSolution(dist,V);
    }
    void printSolution(int dist[][],int V)
    {
        int ar[]=new int[V];
        int a=0;
        int c=0;
        //System.out.println("The following matrix shows the shortest "+
        //"distances between every pair of cafeterias");
        int indexar[]=new int[V];
        int index=0;
        //finding the minimum distance of unvisited cafeteria
        for (int i=0; i<V; i=index)
        {
            int min=10000;

            for (int j=0; j<V; ++j)
            {
                if(min>dist[i][j]&&dist[i][j]!=0&&j!=0)
                {
                    min=dist[i][j];
                    index=j;

                }

                // System.out.print(dist[i][j]+"   ");
            }
            dist[i][index]=0;
            dist[index][i]=0;
            ar[a]=min;
            indexar[a]=index;
            a++;
            if(a==V-1)
                break;
        }
	        /*printing the information about which cafeteria she is going to visit next
	        and how much minimum distance she gas to travel*/
        System.out.println((0)+" "+0);
        for(int l=0;l<V-1;l++)
        {
            System.out.println((indexar[l])+" "+ar[l]);

        }
    }

    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        //System.out.println("Enter the number of cafeterias");
        int n=sc.nextInt();
        int A[][]=new int[n+1][n+1];
        int k,l;
        //Enter the distances
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                A[i][j]=0;

            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                k=sc.nextInt();
                l=sc.nextInt();
                A[i][j]=sc.nextInt();
                A[j][i]=A[i][j];

            }
        }

       ProblemStatement3 z=new ProblemStatement3();
        z.floydWarshall(A,n+1);


    }
}
