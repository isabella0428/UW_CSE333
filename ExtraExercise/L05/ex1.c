#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Implement a program that builds a list of lists */

typedef struct node{
    void* value;
    struct node* next;
}Node,*Nodeptr;

Nodeptr addToLinkedList(void* value, Node* next){
    Nodeptr n = (Nodeptr)malloc(sizeof(Nodeptr) + sizeof(value));
    n->next = next;
    n->value = value;
    return n;
}

/* Add a function that returns the number of elements in a list */
int sizeOfLinkedList(Nodeptr head){
    Nodeptr temp = head;
    int size = 0;
    while(head){
        head = head->next;
        ++size;
    }
    return size;
}

/* design and implement a “Pop” function */
Nodeptr Pop(Nodeptr p){
    Nodeptr newHead = p->next;
    free(p);
    return newHead;
}

void cleanUp(Nodeptr p)
{
    Nodeptr temp, temp1, prev_temp, prev_temp1;
    while (temp)
    {
        printf("1");
        temp1 = temp->value;
        while (temp1)
        {
            prev_temp1 = temp1;
            temp1 = temp1->next;
            free(prev_temp1);
        }
        prev_temp = temp;
        temp = temp->next;
        printf("%d", temp == NULL);
        free(prev_temp);
    }
}

void printValue(Nodeptr head4)
{
    Nodeptr temp, temp1;
    temp = head4;
    while (temp)
    {
        temp1 = temp->value;
        while (temp1)
        {
            printf("Node val: %s\n", temp1->value);
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
}

int main(int argc, char **argv){
    Nodeptr head1, head2, head3, head4;

    head1 = addToLinkedList("None", NULL);
    head1 = addToLinkedList("one", head1);
    head1 = addToLinkedList("two", head1);

    head2 = addToLinkedList("None1", NULL);
    head2 = addToLinkedList("one1", head2);
    head2 = addToLinkedList("two1", head2);

    head3 = addToLinkedList("None2", NULL);
    head3 = addToLinkedList("one2", head3);
    head3 = addToLinkedList("two2", head3);

    head4 = addToLinkedList(head1, NULL);
    head4 = addToLinkedList(head2, head4);
    head4 = addToLinkedList(head3, head4);

    printValue(head4);
    printf("Size of head4 is : %d\n", sizeOfLinkedList(head4));

    printf("After pop: \n");
    head4 = Pop(head4);
    printValue(head4);
    printf("Size of head4 is : %d\n", sizeOfLinkedList(head4));
    cleanUp(head4);
}
