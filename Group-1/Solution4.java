
/* 
Time Complexity for Riya to find her friend's buildings are as follows-
* O(N) in finding Lowest common Ancestors.
* O(N) in finding Number of Turns she has to take
* In worst case we iterate through the tree by a constant factor.
Total Time Complexity - O(N)
- where N=number of Nodes in a tree.
Total Space Complexity - O(1). 
Approach-
1. Build a tree
2. Find  Lowest common Ancestors.
3. Find the number of turns Riya takes from LCA to n and m.If she travels straight than turns will be -1 
*/

import java.util.*;//including util package for taking Scanner input
class Node
{
	 int data;
	 Node left;
	 Node right;
	public Node()
	{
		data=0;
		left=right=null;
	}
	public Node(int x)
	{
		data = x;
		left = right = null;
	}
}
public class helpingRiya
{
	public static char pprev = 'N';
	public static boolean turnLeft = false;
	public static boolean turnRight = false;
	public static int ccount = 0;
	// New node creation
	static Node newNode(int val)
	{
		return (new Node(val));
	}
    //Building a tree for Riya
    static Node buildTree(String str)
	{
		if (str.length() == 0 || str.charAt(0) == 'N')
		{
			return null;
		}
		ArrayList<String> ip = new ArrayList<String>();
		//Extracting the nodes from the input line and adding it to ArrayList
		for(String s : str.split(" "))
		{
		       ip.add(s);
		}
		Node root = newNode(Integer.parseInt(ip.get(0)));
		LinkedList<Node> q = new LinkedList<Node>();
		q.offer(root);
		int i = 1;
		while (!q.isEmpty() && i < ip.size())
		{
			Node currNode = q.peek();
			q.poll();
			String currVal = ip.get(i);
			if (!currVal.equals("N"))
			{
				currNode.left = newNode(Integer.parseInt(currVal));
				q.offer(currNode.left);
			}
			i++;
			if (i >= ip.size())
			{
				break;
			}
			currVal = ip.get(i);
			if (!currVal.equals("N"))
			{
				currNode.right = newNode(Integer.parseInt(currVal));
				q.offer(currNode.right);
			}
			i++;
		}//while loop ends
		return root;
	}//buildTree function ends
	// returns Lowest Common Ancestor of the two nodes
	public static Node findLCA(Node curr, long n, long m)
	{
		if (curr == null)
		{
			return null;
		}
		if (curr.data == n || curr.data == m)
		{
			return curr;
		}
		Node leftLCA = findLCA(curr.left, n, m);
		Node rightLCA = findLCA(curr.right, n, m);
		if (leftLCA != null && rightLCA != null)
		{
			return curr;
		}
		return (leftLCA) != null?leftLCA:rightLCA;

	}//findLCA function ends
	//Return count of nodes in path from one of the nodes to LCA
	public static boolean pathExists(Node curr, long n)
	{
		if (curr == null)
		{
			return false;
		}
		if (curr.data == n)
		{
			return true;
		}
		if (curr.left != null && pathExists(curr.left, n))
		{
			if (pprev == 'N')
			{
				pprev = 'L';
			}
			else if (pprev == 'R')
			{
				ccount++;
				pprev = 'L';
			}
			turnLeft = true;
			return true;
		}
		if (curr.right != null && pathExists(curr.right, n))
		{
			if (pprev == 'N')
			{
				pprev = 'R';
			}
			else if (pprev == 'L')
			{
				ccount++;
				pprev = 'R';
			}
			turnRight = true;
			return true;
		}
		return false;
	}//pathExists function ends
	//main function starts
	public static void main(String[] args)
	{
		String str;
		long n;
		long m;
		Scanner sc=new Scanner(System.in);
		str =sc.nextLine();
		n =sc.nextLong();
		m =sc.nextLong();
		Node root = buildTree(str);
		Node lca =findLCA(root, n, m);
		int turns = 1;
		ccount = 0;
		boolean pathN = pathExists(lca, n);
		turns += ccount;
		pprev = 'N';
		ccount = 0;
		boolean pathM = pathExists(lca, m);
		turns = turns + ccount;
		if (turnLeft && turnRight)
		{
			if (pathN && pathM)
			{
				/*Printing number of turns Riya has to take to reach one
				friend's house to the other*/
				System.out.print(turns);
				System.out.print("\n");
			}
			else
			{
				System.out.println(-1);
			}
		}
		else
		{
			//If Riya doesn't move left or right than -1 is printed
			System.out.println(-1);
		}
	}//main method ends
}//class ends
