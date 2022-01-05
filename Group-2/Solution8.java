import java.util.*;
class LinkedList 
{
    class Node{  
        int data;  
        Node next;  
  
        public Node(int data) {  
            this.data = data;  
            this.next = null;  
        }  
    }  
  
    public static Node head = null;  
    public static Node tail = null;  
  
    public void addAtEnd(int data) {  
        //Create a new node  
        Node newNode = new Node(data);  
        if(head == null) {  
            head = newNode;  
            tail = newNode;  
        }  
        else {  
            tail.next = newNode;  
            tail = newNode;  
        }  
    }  
  
    public static void display() {  
        Node current = head;  
        if(head == null) {  
            System.out.println("List is empty");  
            return;  
        }  
        while(current != null) {  
            System.out.print(current.data + " ");  
            current = current.next;  
        }  
        System.out.println();  
    }  

    public static Node midNode(Node head){
        Node fast =  head, slow  =  head;
        while(fast.next!=null && fast.next.next!=null){
            fast =  fast.next.next;
            slow =  slow.next;
        }
        return slow;
    }
    
    public static Node reverse(Node head){
        Node curr =  head, prev=  null, next = null;
        while(curr!=null){
            next  =  curr.next;
            curr.next =  prev ;
            prev =  curr;
            curr  =  next;
        }
        return prev;
    }

    
    public static void reorderList(Node head) {
        
        Node midNode =  midNode(head);
        Node nextToMid =  midNode.next;
        midNode.next = null;
        Node p2 =  reverse(nextToMid);
        
        Node p1 =  head ,p1Next;    
        while(p1!=null && p2!=null){
            p1Next =  p1.next;                                    
			p1.next =  p2;
			           
            p1 =  p2;
            p2=p1Next;                        
        }                
    }            
  
    public static void main(String[] args) {  
  
        LinkedList sList = new LinkedList();  
  
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();

        for(int i=0;i<n;i++)
        {
            int x=in.nextInt();
            sList.addAtEnd(x);
        }

        Node root=head;
        display();//LL before changing
        reorderList(head);
        display();//LL after changing

    }  
}
//-----------Complexity Analysis--------------
//-----------Time Complexity-  O(N)-----------
//-----------Space Complexity - O(1)----------