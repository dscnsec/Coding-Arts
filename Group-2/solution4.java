import java.util.*;

public class solution4 {
    static int Count;
 
    // A Binary Tree Node
    static class Node {
        Node left, right;
        int key;
 
        // Constructor
        Node(int key) {
            this.key = key;
            left = null;
            right = null;
        }
    }


    static Node findLCA(Node root, int n1, int n2) {
        if (root == null)
            return null;
 
        if (root.key == n1 || root.key == n2)
            return root;
 
        Node left_lca = findLCA(root.left, n1, n2);
        Node right_lca = findLCA(root.right, n1, n2);

        if (left_lca != null && right_lca != null)
            return root;
 

        return (left_lca != null) ? left_lca : right_lca;
    }

    static boolean CountTurn(Node root, int key, boolean turn) {
        if (root == null)
            return false;

        if (root.key == key)
            return true;

        if (turn == true) {
            if (CountTurn(root.left, key, turn))
                return true;
            if (CountTurn(root.right, key, !turn)) {
                Count += 1;
                return true;
            }
        } else 
        {
            if (CountTurn(root.right, key, turn))
                return true;
            if (CountTurn(root.left, key, !turn)) {
                Count += 1;
                return true;
            }
        }
        return false;
    }
    static int NumberOfTurn(Node root, int first, int second) {
        Node LCA = findLCA(root, first, second);

        if (LCA == null)
            return -1;
        Count = 0;

        if (LCA.key != first && LCA.key != second) {
 
            if (CountTurn(LCA.right, second, false)
                    || CountTurn(LCA.left, second, true))
                ;

            if (CountTurn(LCA.left, first, true)
                    || CountTurn(LCA.right, first, false))
                ;
            return Count + 1;
        }

        if (LCA.key == first) {
 

            CountTurn(LCA.right, second, false);
            CountTurn(LCA.left, second, true);
            return Count;
        }
        else 
        {
 
            CountTurn(LCA.right, first, false);
            CountTurn(LCA.left, first, true);
            return Count;
        }
    }
    static Node root;

    static void insert(int []arr,int index)
    {
        Queue<Node> q = new LinkedList<Node>();
        root=new Node(arr[0]);
        q.add(root);
        int p=1;
        while(q.size()!=0 && p<index)
        {
            int a=arr[p];
            Node temp=q.peek();
            q.remove();
            if(a==-1)
            {
                temp.left=null;
            }
            else
            {
                Node temp1=new Node(a);
                temp.left=temp1;
                q.add(temp1);
            }
            p++;
            if(p>=index)
            {
                break;
            }
            int b=arr[p];
            if(b==-1)
            {
                temp.right=null;    
            }
            else
            {
                Node temp2=new Node(b);
                temp.right=temp2;
                q.add(temp2);
            }
            p++;
        }
        
    }

    // static void inorder(Node node)
    // {
    //     if (node == null)
    //         return;
 
    //     inorder(node.left);
 
    //     System.out.print(node.key + " ");
 
    //     inorder(node.right);
    // }
    public static void main(String[] args) 
    {
        Scanner in=new Scanner(System.in);
        String str=in.nextLine();
        
        int d1=in.nextInt();
        int d2=in.nextInt();
        
        int arr[]=new int[1000];
        int p=0;
        String s="";
        for(int i=0;i<str.length();i++)
        {
            char ch=str.charAt(i);
            if(ch==' ')
            {
                if(s.equals("N"))
                {
                    arr[p++]=-1;
                }
                else if(s!="N")
                {
                    int t=Integer.parseInt(s);
                    arr[p++]=t;  
                }
                s="";
            }
            else
            {
                s+=ch;
            }
        }
        insert(arr,p);
        int turn = 0;
        if ((turn = NumberOfTurn(root, d1, d2)) != 0)
            System.out.println(turn);
        else
            System.out.println("-1");
    }
    
}

/*--------Complexity Analysis------
Time Complexity - O(N)
Space Complexity - O(N) where N is the number of Nodes in a tree------*/