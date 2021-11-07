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
            printf("%d\n", current->data);  
            current = current->next;  
        }while(current != head);  
        printf("\n");  
    }  
}  
      
int main()  
{  
    int i, num;
    while(1)
    {
    printf("Enter your data value except 0\n");
    scanf("%d",&num);
    if(num!=0)
    add(num);
    else if (num==0)
    break;
    }
   node *copy=dup(head);
   printf("Copy\n");
   display(copy);
   return 0;  
}  