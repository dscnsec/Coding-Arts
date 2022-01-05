#include<bits/stdc++.h>
using namespace std;
#define ll int

struct LinkedList{
    int nodeValue;
    LinkedList *next;
    LinkedList(int value)
    {
        nodeValue = value;
        next = NULL;
    }
};

LinkedList* buildList()
{
    ll number_of_nodes,nodeValue;
    cin>>number_of_nodes;
    cin>>nodeValue;
    LinkedList *head=new LinkedList(nodeValue);
    LinkedList *iterator=head;
    for(ll count=1;count<number_of_nodes;count++)
    {
        cin>>nodeValue;
        iterator->next=new LinkedList(nodeValue);
        iterator = iterator->next;
    }
    return head;
}

void createNewOrder(LinkedList* head)
{
    LinkedList *iterator=head,*middle=head,*previous=NULL;
    while (iterator->next && iterator->next->next) 
    {
        iterator = iterator->next->next;
        middle = middle->next;
    }
    if (iterator->next) middle = middle->next;
        
    while (middle) 
    {
        iterator = middle->next;
        middle->next = previous;
        previous = middle;
        middle = iterator;
    }
    middle = previous;
        
    while (head && middle) {
    iterator = head->next;
        previous = middle->next;
        head->next = middle;
        middle->next = iterator;
        head = iterator;
        middle = previous;
    }
    if (head && head->next) head->next->next = NULL;
}

void printList(LinkedList* head)
{
    LinkedList *iterator=head;
    while(iterator)
    {
        cout<<iterator->nodeValue<<" ";
        iterator=iterator->next;
    }
}

int main()
{
    LinkedList *head=buildList();
    createNewOrder(head);
    printList(head);
    return 0;
}

/*
Time Complexity - O(N) + O(N/2) + O(N) = O(N)
Space Complexity - O(1)
*/
