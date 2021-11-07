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
 struct node *addAfter(struct node *last, int data, int item)
{
    if (last == NULL)
       return NULL;
 
    struct node *temp, *p;
    p = last -> next;
    do
    {
        if (p ->data == item)
        {
            temp = malloc(sizeof(struct node));
            temp -> data = data;
            temp -> next = p -> next;
            p -> next = temp;
            
            if (p == last)
                last = temp;
 
            return last;
        }
        p = p -> next;
    } while (p != last -> next);
    return last;
}
void deleteNode(struct node *ref, int key)
{
    if (ref == NULL)
        return;
 
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
 
    if (curr->next == ref)
    {
        head = NULL;
        free(curr);
        return;
    }
 
    if (curr == ref)
    {
        prev = ref;
        while (prev->next != ref)
            prev = prev->next;
        ref = curr->next;
        prev->next = ref;
        free(curr);
    }
 
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

printf("\nPress 1 to add a node, 2 to delete any node, 3 to modify the contents of a node ");
int c;
scanf("%d",&c);

if (c==1)
{
    printf("\nEnter the data you want to add");
    int a;
    scanf ("%d",&a);
    printf("\nEnter the node index where you want to add");
    int c;
    scanf("%d", &c);
   addAfter(head, a,c);

}
else if (c==2)
{
    printf("\nEnter the node index you want to delete");
    int j;
    scanf("%d", j);
    deleteNode(head,j);
    printf("\n New List");
    display();

}
else if (c==3)
{
    node *current=head;
    printf("\nEnter the number you want to replace");
    int old, recent;
    scanf("%d", &old);
    printf("\nEnter the new number");
    scanf("%d", &recent);
    while(current!=NULL)
    {
        if(current->data==old)
        {
        current->data=recent;
        break;
        }

        current=current->next;
    }
}
   display();  
     
   return 0;  
}  
