#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node *head = NULL;  
node *tail = NULL;  
   
void add(int data)
{  
    node *newNode = malloc(sizeof(struct node));  
    newNode->data = data;   
    if(head == NULL)
    {  
        head = newNode;  
        tail = newNode;  
        newNode->next = head;  
    }
    else 
    {    
        tail->next = newNode;  
        tail = newNode;  
        tail->next = head;  
    }  
}  
void reverse()
{
 node *current=head, *prev=NULL,*next;
 
 if (head==NULL)
 return;
   do
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }  while(current!=head);
    
head->next=prev;
head=prev;
}
node *dup(node *curr)
{
node *temp=curr, *start=curr;
if(curr!=NULL)
{
do
{
temp->data=curr->data;
temp->next=curr->next;
}while(temp!=curr);
}
return temp;
}

void display(node *head)
{  
    node *current = head;  
    if(head == NULL){  
        printf("List is empty");  
    }  
    else
    {  
         do {    
            printf("%d\t", current->data);  
            current = current->next;  
        }while(current != head);  
        printf("\n");  
    }  
}  
int main()  
{  
    int i, num;
    for(i=0;i<7;i++)
    {
    printf("Enter your data value\n");
    scanf("%d",&num);
    add(num);
    }
   printf("The actual List is\t");
   display(head);
   reverse();
   node *revc=dup(head);
   printf("The reversed replica list is\t");
   display(revc);  
     
   return 0;  
}  

/* Major changes needed:
1. Creating a link between the first and the last node.
2. In every loop when the last node is created, a link is established between the last node and the first.
3. The same is taken care of while reversing.

Advantages and Disdavantages of Circular Linked List:
Since a circular linked list is a singular linked list just having the last and the first ned linked, its advantages and disadvantages are similar to that of SLL.

Advantages:

1. In a CLL, if we are at one particular node, then we can go to any node by traversing between the nodes. 
2. It saves time when we have to go to the first node from the last node. It can be done in single step because of the link and there is no need to traverse the in between nodes.

Disadvantages:

1.if we are at a node, except the first and the last nodes, we cannot go to the previous node without completing a loop
2. It is not easy to reverse the linked list.
3. If proper care is not taken, then there can be infinite loop.

*/