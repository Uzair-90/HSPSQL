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
    struct node *head = NULL; 
    int n = 0;

    for (;;) {
        printf("Enter a series of numbers and (0) to exit: ");
        scanf("%d", &n);
        if (n == 0) {
            return head; 
        }

        head = add_to_list(head, n);
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
    if(current == NULL){
        return head;
    }
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
    int n = 0;
    printf("Enter a number to delete from the linked list: ");
    scanf("%d",&n);
    delete_node(head,n);
    display(head);
    struct node *temp;
    printf("Enter a number to search: ");
    scanf("%d",&n);
    temp = search_list(head,n);
    if(!temp){
        printf("Number not found!\n");
    }else{
        printf("Number found.");
    }
    return 0;
}
