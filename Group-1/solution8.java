
/*
Time Complexity = O(n)
Space Complexity = O(1), no extra space is required
 */

import java.util.*;
public class SinglyLinkedList {
    //Represent a node of the singly linked list
    static class Node
    {
        int data;
        Node next;
        public Node(int data) {
            this.data = data;
            this.next = null; }
    }
    //Represent the head and tail of the singly linked list
    public Node head = null;
    public Node tail = null;
    //addNode() will add a new node to the list
    public void addNode(int data) {
        //Create a new node
        Node newNode = new Node(data);

        //Checks if the list is empty
        if(head == null) {
            //If list is empty, both head and tail will point to new node
            head = newNode;
            tail = newNode;
        }
        else {
            //newNode will be added after tail such that tail's next will point to newNode
            tail.next = newNode;
            //newNode will become new tail of the list
            tail = newNode;
        }
    }

    //display() will display all the nodes present in the list
    public void display(int n) {
        int count=0;
        //Node current will point to head
        Node current = head;

        if(head == null) {
            System.out.println("List is empty");
            return;
        }

        while(current != null) {
            count++;
            //printing the first and last song from the playlist
            if(count==1||count==n) {
                System.out.print(current.data + " ");
            }
            //Prints each node by incrementing pointer
            // System.out.print(current.data + " ");
            current = current.next;
        }

        count=0;
    }
    public void removelast() {

        if(head==null)
            return;
        if(head.next==null)
        {
            return;
        }
        Node sec=head;

        while(sec.next.next!=null)
        {

            sec=sec.next;
        }
        sec.next=null;


    }
    public void removefirst()
    {
        if(this.head!=null)
        {
            Node temp=this.head;
            this.head=this.head.next;
            temp=null;
        }

    }
    public static void main(String[] args) {

        SinglyLinkedList sList = new SinglyLinkedList();
        Scanner sc=new Scanner(System.in);
        int number_of_songs=sc.nextInt();
        int data;
        //Add nodes to the list
        for(int i=0;i<number_of_songs;i++)
        {
            data=sc.nextInt();
            sList.addNode(data);

        }
        int a=0;
        int iteration;
        if(number_of_songs%2==0)
            iteration=number_of_songs/2;
        else
            iteration=number_of_songs/2+1;
        //displays in the order as asked
        for(int i=0;i<iteration;i++)
        {
            sList.display(number_of_songs-a);
            a+=2;
            sList.removefirst();
            sList.removelast();

        }
    }
}
