#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  

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
void display()
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
      
int main()  
{  
    int i, num;
    while(1)
    {
    printf("Enter your data value except 0\n");
    scanf("%d",&num);
    if (num==0)
    break;
    else if(num!=0)
    add(num);
    }

   display();  
   node *revc=dup(head);
   display();
     
   return 0;  
}  