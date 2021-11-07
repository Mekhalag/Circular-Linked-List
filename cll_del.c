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
void deleteNode(struct node *ref, int key)
{
    if (ref == NULL)
        return;
 
    // Find the required node
    struct node *curr = head, *prev;
    while (curr->data != key)
    {
        if (curr->next == head)
        {
            printf("\nGiven node is not found"
                   " in the list!!!");
            break;
        }
 
        prev = curr;
        curr = curr->next;
    }
 
    // Check if node is only node
    if (curr->next == ref)
    {
        head = NULL;
        free(curr);
        return;
    }
 
    // If more than one node, check if
    // it is first node
    if (curr == ref)
    {
        prev = ref;
        while (prev->next != ref)
            prev = prev->next;
        ref = curr->next;
        prev->next = ref;
        free(curr);
    }
 
    // check if node is last node
    else if (curr->next == head && curr == ref)
    {
        prev->next = ref;
        free(curr);
    }
    else
    {
        prev->next = curr->next;
        free(curr);
    }
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
    printf("Enter your the data you want to delete\n");
    scanf("%d", &i);
   deleteNode(head, i);
   display();  
     
   return 0;  
}  