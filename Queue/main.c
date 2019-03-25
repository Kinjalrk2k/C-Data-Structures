#include <stdio.h>
#include <malloc.h>

/*  generic node structre for a singly linked List*/
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;   //  head of the list: initially NULL

/*  traverse throught the list  */
void traverse(){
    struct node *ptr = head;    //  a temporary node pointing to head

    if(ptr == NULL){    //  no nodes in the list
        printf("List Underflow! Unable to print!");
        return;
    }

    while(ptr->next != NULL){   //  iterating throughout the list(till NULL is reached)
        printf("%d->", ptr->data);  //  printing current node
        ptr = ptr->next;    //  shifting the temporary node to the next one
    }
    printf("%d->", ptr->data);  //  printing the last node
    printf("\b\b  \b\b");   //  just beautifying stuffs! :*
}

/*  insert at the end of the list   */
void enqueue(int data){
    if (head == NULL) {
        head = (struct node *)malloc(sizeof(struct node));
        if (head == NULL) {
            printf("Memory Underflow! Insertion failed!");
            return;
        }
        head->data = data;
        head->next = NULL;
        return;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    
    if (newNode == NULL) {
        printf("Memory Underflow! Insertion failed!");
        return;
    }
    else {
        struct node *ptr = head;
        while(ptr->next != NULL){   //  iterating till the last element
            ptr = ptr->next;    //  shifting the temporary node to the next one
        }
        newNode->data = data;
        newNode->next = NULL;   //  ending the list(as Insertion is being done at the end)
        ptr->next = newNode;    //  the previous last node is linked to the new node
    }
}

/*  delete from the beginning   */
void dequeue(){
    if (head == NULL) {
        printf("List underflow! Unable to delete!");
        return;
    }

    struct node *ptr = head;
    head = head->next;  //  shifting the head too the next one
    free(ptr);  //  freeing the temporary node(which was the last head)
}

/*  SAMPLE MAIN FUNCTION TO TEST THE FUNCTIONS  */
int main(int argc, char const *argv[])
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    
    dequeue();
    dequeue();    

    traverse();

    return 0;
}
