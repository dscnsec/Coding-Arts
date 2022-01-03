import java.util.*;

class Graph {
	
	private final int V;//for the number of vertices
	private final List<List<Integer>> adj;//adjacency list for the edges

	public Graph(int V)
	{
		this.V = V;
		adj = new ArrayList<>(V);
		
		for (int i = 0; i < V; i++)
			adj.add(new LinkedList<>());
	}

    private void addEdge(int source, int dest) 
    {
		adj.get(source).add(dest);
	}
    //-------------checking if the graph is cyclis or not-----------------//
	private boolean isCyclicUtil(int i, boolean[] visited,
									boolean[] recStack)
	{
		if (recStack[i])
			return true;

		if (visited[i])
			return false;
			
		visited[i] = true;

		recStack[i] = true;
		List<Integer> children = adj.get(i);
		
		for (Integer c: children)
			if (isCyclicUtil(c, visited, recStack))
				return true;
				
		recStack[i] = false;

		return false;
	}
	private boolean isCyclic()
	{
		
		boolean[] visited = new boolean[V];
		boolean[] recStack = new boolean[V];
		for (int i = 0; i < V; i++)
			if (isCyclicUtil(i, visited, recStack))
				return true;

		return false;
	}

    //----------------------------topological sort algorithm---------------------------------//
    void topologicalSortUtil(int v, boolean visited[],
                             Stack<Integer> stack)
    {
        // Mark the current node as visited.
        visited[v] = true;
        Integer i;
        // Recur for all the vertices adjacent
        // to thisvertex
        Iterator<Integer> it = adj.get(v).iterator();
        while (it.hasNext()) {
            i = it.next();
            if (!visited[i])
                topologicalSortUtil(i, visited, stack);//recursive funtion for topological sort
        }
 
        // Push current vertex to stack
        // which stores result
        stack.push(new Integer(v));
    }
    void topologicalSort(String arr[])
    {
        Stack<Integer> stack = new Stack<Integer>();
 
        // Mark all the vertices as not visited
        boolean visited[] = new boolean[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
 
        // Call the recursive helper
        // function to store
        // Topological Sort starting
        // from all vertices one by one
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                topologicalSortUtil(i, visited, stack);
 
        // Print contents of stack
        while (stack.empty() == false)
        {
            String str=arr[stack.pop()];
            System.out.print(str+" ");
        }
    }

	public static void main(String[] args)
	{
        Scanner in=new Scanner(System.in);
        int vertices=in.nextInt();
		Graph graph = new Graph(vertices);
        HashMap<String, Integer> map = new HashMap<>();
        int p=1;
        while(in.hasNext())
        {
            String s2=in.next();
            String s1=in.next();
            int r=-1,s=-1;
            if(!map.containsKey(s1))
            {
                map.put(s1,p);
                r=p;
                p++;
            }
            else
            {
                r=map.get(s1);
            }

            if(!map.containsKey(s2))
            {
                map.put(s2,p);
                s=p;
                p++;
            }
            else
            {
                s=map.get(s2);
            }
            graph.addEdge(r-1,s-1);
        }
        String arr[]=new String[vertices];

        for (Map.Entry<String, Integer> entry : map.entrySet()) 
        {
            int k=entry.getValue();
            String str=entry.getKey();
            arr[k-1]=str;
        }
		if(graph.isCyclic())
			System.out.println("0");
		else
			graph.topologicalSort(arr);
	}
}

/* --------Complexity Analysis---------
Time Complexity - O(V+E)
Space Complexity - O(V) for hashmap containing the vertices
                   O(V) for stack used in topological sorting
                   O(V) for visited array in cyclic and topological sorting functions
                   O(V+E) for adjacency list for storing the edges
                   
                   O(V+E) total space complexity----------*/
