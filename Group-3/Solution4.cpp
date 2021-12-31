/* 
Time Complexity - for N nodes
    O(N) for finding LCA 
    O(N) for finding Number of Turns
Total Time Complexity - O(N) , where N is number of Nodes in a tree.
Total Space Complexity - O(1), considering recursion stack takes O(1) space and ignoring the space for storing the tree (i.e. O(N), where N is nodes in tree). 
*/


#include<bits/stdc++.h>
using namespace std;
#define ll int

// structure of a node in a tree
struct TreeNode{
    ll nodeValue;
    TreeNode* leftNode;
    TreeNode* rightNode;
    TreeNode(ll value){
        nodeValue=value;
        leftNode=rightNode=NULL;
    }
};

// function to create newNode and return its pointer
TreeNode* newNode(ll value){
    return new TreeNode(value);}

// function to build a tree from given input
TreeNode* buildTree(string inputString){
    if(inputString.size()==0 || inputString[0]=='N')
        return NULL;
    stringstream stream(inputString);
    vector<string> nodeList;
    string streamReader;
    while(stream>>streamReader)
        nodeList.push_back(streamReader);
    TreeNode *rootNode=newNode(stoi(nodeList[0]));
    queue<TreeNode*> my_queue;
    my_queue.push(rootNode);
    for(ll i=1;i<nodeList.size();i++)
    {
        TreeNode *curNode=my_queue.front();
        if(nodeList[i]!="N")
        {
            curNode->leftNode=newNode(stoi(nodeList[i]));
            my_queue.push(curNode->leftNode);
        }
        i++;
        if((i<nodeList.size()) && (nodeList[i]!="N"))
        {
            curNode->rightNode=newNode(stoi(nodeList[i]));
            my_queue.push(curNode->rightNode);
        }
        my_queue.pop();
    }
    return rootNode;
}

// function to find least common ancestor of given source and  destination
TreeNode* findLeastCommonAncestor(TreeNode* rootNode,ll source,ll destination)
{
    if(rootNode == NULL)
        return rootNode;
    if(rootNode->nodeValue == source || rootNode->nodeValue == destination)
        return rootNode;
    TreeNode* leftAncestor=findLeastCommonAncestor(rootNode->leftNode,source,destination);
    TreeNode* rightAncestor=findLeastCommonAncestor(rootNode->rightNode,source,destination);
    if(leftAncestor != NULL && rightAncestor != NULL)
        return rootNode;
    if(leftAncestor != NULL)
        return leftAncestor;
    return rightAncestor;
}

// function to check for value and find no.of turns  
int calcNumberOfTurns(TreeNode *rootNode,string typeOfChild,ll valueToFind)
{
    if(rootNode == NULL)
        return -1;
    if(rootNode->nodeValue == valueToFind)
        return 0;   
    ll findInLeftSubTree = calcNumberOfTurns(rootNode->leftNode , "left" , valueToFind);
    if(findInLeftSubTree != -1)
    {
        if(typeOfChild == "left")
            return findInLeftSubTree;
        else 
            return 1+findInLeftSubTree;
    }
    ll findInRightSubTree = calcNumberOfTurns(rootNode->rightNode , "right" , valueToFind);
    if(findInRightSubTree != -1)
    {
        if(typeOfChild == "right")
            return findInRightSubTree;
        else 
            return 1+findInRightSubTree;
    }
    return -1;
}

int main(){
    string nodesString;
    getline(cin,nodesString);
    ll source,destination;
    cin>>source>>destination;
    TreeNode *rootNode = buildTree(nodesString);
    TreeNode *leastCommonAncestor = findLeastCommonAncestor(rootNode,source,destination);
//     if either source or destination is equal to LCA value, search for other one else search for both.
    if(leastCommonAncestor->nodeValue == source || leastCommonAncestor->nodeValue == destination)
    {
        if(leastCommonAncestor->nodeValue == destination)
            swap(source,destination);
        ll calcTurnsLeftSubTree = calcNumberOfTurns( leastCommonAncestor->leftNode, "left", destination);
        ll calcTurnsRightSubTree = calcNumberOfTurns( leastCommonAncestor->rightNode, "right", destination);
        if(calcTurnsLeftSubTree > 0)
            cout<<calcTurnsLeftSubTree;
        else if(calcTurnsRightSubTree > 0)
            cout<<calcTurnsRightSubTree;
        else
            cout<<-1;   
    }
    else
    {        
        ll sourceInLeftSubTree = calcNumberOfTurns( leastCommonAncestor->leftNode, "left", source);
        ll destinationInRightSubTree = calcNumberOfTurns( leastCommonAncestor->rightNode, "right", destination);
        if(sourceInLeftSubTree != -1)
        {
            cout<<(1 + sourceInLeftSubTree + destinationInRightSubTree);
        }
        else
        {
            ll sourceInRightSubTree = calcNumberOfTurns( leastCommonAncestor->rightNode, "right", source);
            ll destinationInLeftSubTree = calcNumberOfTurns( leastCommonAncestor->leftNode, "left", destination);
            cout<<(1 + sourceInRightSubTree + destinationInLeftSubTree);
        }
    }   
    return 0;
}
