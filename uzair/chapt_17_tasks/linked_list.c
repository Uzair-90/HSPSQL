#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *add_to_list(struct node *list, int val) {
    struct node *current = malloc(sizeof(struct node));
    if (!current) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    current->data = val;
    current->next = list;
    return current;
}

struct node *read_numbers() {
    struct node *head = NULL; // Initialize head to NULL
    int n = 0;

    for (;;) {
        printf("Enter a series of numbers and (0) to exit: ");
        scanf("%d", &n);
        if (n == 0) {
            return head; // Return the head of the linked list
        }

        head = add_to_list(head, n); // Update the head with the new node
    }
}

void display(struct node *first) {
    struct node *p;

    for (p = first; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }

    printf("\n");
}

struct node *search_list(struct node *head, int val){
    while(head!=NULL && head->data != val)
        head = head->next;
    return head;
}

struct node *delete_node(struct node *head,int val){
    struct node *current,*previous;
    
    for(current = head, previous = NULL; current!=NULL && current->data!=val;previous = current, current = current->next)
    ;
    
    
    //this shows that node is not found
    if(current == NULL){
        return head;
    }
    
    //this means that the node is the first node
    if(previous == NULL){
        head = head->next;
    } else{
        previous->next = current->next;
    }
    
    free(current);
    return head;
    
}

int main() {
    struct node *head = read_numbers();
    display(head);
    delete_node(head,11);
    display(head);
    return 0;
}

