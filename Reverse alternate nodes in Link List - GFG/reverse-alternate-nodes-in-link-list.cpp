//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
      void rearrange(struct Node *head)
    {
        //1 node is not req to rearrange
        if(head->next==NULL) return;
        
        Node *p=head,*prev=NULL,*altHead=NULL,*copy;
        int cnt=1;
        
        for(;p!=NULL;)
        {
            //Keep odd positioned node as it is
            //temporarily del even positioned node and store in a new ll(altHead) 
            //for reversing the even positioned nodes inserted in altHead ,
            //insert at beg each time as then it gets automatically reversed
            if(cnt%2==0)
            {
                prev->next=p->next;
                copy=p->next;//to avoid lose of add of next ll
                p->next=altHead;
                altHead=p;
                
                p=copy;//imp
            }
            else
            {
                //not req to move prev when even positioned nodes are deleted bz 
                //after del p goes to next ll but prev remains just behind p
                prev=p;
                p=p->next;//imp
            }
             
            cnt++;
        }
        //append reversed eveb positioned node at end of head
        prev->next=altHead;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends