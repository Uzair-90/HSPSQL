#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define bucketSize 3

struct Node {
    bool isLeaf;
    struct Node** ptr;
    int* key;
    int size;
};

struct Node* createNode() {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->key = (int*)malloc(bucketSize * sizeof(int));
    new_node->ptr = (struct Node**)malloc((bucketSize + 1) * sizeof(struct Node*));
    new_node->size = 0;
    return new_node;
}

struct Btree {
    struct Node* root;
};

struct Btree* createBtree() {
    struct Btree* btree = (struct Btree*)malloc(sizeof(struct Btree));
    btree->root = NULL;
    return btree;
}

struct Queue {
    struct Node* data;
    struct Queue* next;
};

void enqueue(struct Queue** queue, struct Node* data) {
    struct Queue* newNode = (struct Queue*)malloc(sizeof(struct Queue));
    newNode->data = data;
    newNode->next = NULL;

    if (*queue == NULL) {
        *queue = newNode;
    } else {
        struct Queue* temp = *queue;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

struct Node* dequeue(struct Queue** queue) {
    if (*queue == NULL)
        return NULL;

    struct Node* data = (*queue)->data;
    struct Queue* temp = *queue;
    *queue = (*queue)->next;
    free(temp);

    return data;
}


void insert(struct Btree* btree, int x);
void shiftLevel(int x, struct Node* current, struct Node* child, struct Btree* btree);
int search(struct Btree* btree, int x);
void display(struct Node* current);
struct Node* findParent(struct Node* current, struct Node* child);
struct Node* getRoot(struct Btree* btree);
int queueSize(struct Queue* queue);




int main() {
    struct Btree* btree = createBtree();
    printf("The size of bucket is %d!\n", bucketSize);

    char ch;
    int val;

    while (1) {
        printf("Enter operation to perform: i for insert, p for display, S to stop: ");
        ch = getchar(); // Read the character

        if (ch == 'S' || ch == 's') {
            break; // Exit the loop
        }
        else if (ch == 'i') {
            printf("Enter an integer value: ");
            scanf("%d", &val);
            insert(btree, val); // Call the insert function
        }
        else if (ch == 'p') {
            struct Node* rootNode = getRoot(btree); // Call the getRoot function
            display(rootNode); // Call the display function
        }
        else {
            printf("Invalid operation.\n");
        }

        // Consume the newline character left in the input buffer
        while (getchar() != '\n');
    }






/*

    insert(btree, 1);
    insert(btree, 2);
    insert(btree, 3);
    insert(btree,4);
    insert(btree,5);
    insert(btree,9);
    insert(btree,11);
    insert(btree,10);
    struct Node* rootNode = getRoot(btree);
	display(rootNode);*/
    

    return 0;
}


void insert(struct Btree* btree, int x) {
    if (btree->root == NULL) {
        btree->root = createNode();
        btree->root->key[0] = x;
        btree->root->isLeaf = true;
        btree->root->size = 1;
    } else {
        struct Node* current = btree->root;
        struct Node* parent;

        while (current->isLeaf == false) {
            parent = current;

            for (int i = 0; i < current->size; i++) {
                if (x < current->key[i]) {
                    current = current->ptr[i];
                    break;
                }

                if (i == current->size - 1) {
                    current = current->ptr[i + 1];
                    break;
                }
            }
        }

        if (current->size < bucketSize) {
            int i = 0;

            while (x > current->key[i] && i < current->size)
                i++;

            for (int j = current->size; j > i; j--)
                current->key[j] = current->key[j - 1];

            current->key[i] = x;

            current->size++;

            current->ptr[current->size] = current->ptr[current->size - 1];
            current->ptr[current->size - 1] = NULL;
        } else {
            struct Node* newLeaf = createNode();
            int tempNode[bucketSize + 1];

            for (int i = 0; i < bucketSize; i++)
                tempNode[i] = current->key[i];
            int i = 0, j;

            while (x > tempNode[i] && i < bucketSize)
                i++;

            for (int j = bucketSize + 1; j > i; j--)
                tempNode[j] = tempNode[j - 1];
            tempNode[i] = x;

            newLeaf->isLeaf = true;
            current->size = (bucketSize + 1) / 2;
            newLeaf->size = (bucketSize + 1) - (bucketSize + 1) / 2;

            current->ptr[current->size] = newLeaf;
            newLeaf->ptr[newLeaf->size] = current->ptr[bucketSize];
            current->ptr[newLeaf->size] = current->ptr[bucketSize];
            current->ptr[bucketSize] = NULL;

            for (int i = 0; i < current->size; i++)
                current->key[i] = tempNode[i];

            for (int i = 0, j = current->size; i < newLeaf->size; i++, j++)
                newLeaf->key[i] = tempNode[j];

            if (current == btree->root) {
                struct Node* newRoot = createNode();
                newRoot->key[0] = newLeaf->key[0];
                newRoot->ptr[0] = current;
                newRoot->ptr[1] = newLeaf;
                newRoot->isLeaf = false;
                newRoot->size = 1;
                btree->root = newRoot;
            } else {
                shiftLevel(newLeaf->key[0], parent, newLeaf,btree);
            }
        }
    }
}


void shiftLevel(int x, struct Node* current, struct Node* child, struct Btree* btree) {
    if (current->size < bucketSize) {
        int i = 0;
        while (x > current->key[i] && i < current->size)
            i++;
        for (int j = current->size; j > i; j--)
            current->key[j] = current->key[j - 1];

        for (int j = current->size + 1; j > i + 1; j--)
            current->ptr[j] = current->ptr[j - 1];

        current->key[i] = x;
        current->size++;
        current->ptr[i + 1] = child;
    } else {
        struct Node* newInternal = createNode();
        int tempKey[bucketSize + 1];
        struct Node* tempPtr[bucketSize + 2];

        for (int i = 0; i < bucketSize; i++)
            tempKey[i] = current->key[i];

        for (int i = 0; i < bucketSize + 1; i++)
            tempPtr[i] = current->ptr[i];

        int i = 0, j;
        while (x > tempKey[i] && i < bucketSize)
            i++;

        for (int j = bucketSize + 1; j > i; j--)
            tempKey[j] = tempKey[j - 1];

        tempKey[i] = x;
        for (int j = bucketSize + 2; j > i + 1; j--)
            tempPtr[j] = tempPtr[j - 1];

        tempPtr[i + 1] = child;
        newInternal->isLeaf = false;
        current->size = (bucketSize + 1) / 2;

        newInternal->size = bucketSize - (bucketSize + 1) / 2;

        for (int i = 0, j = current->size + 1; i < newInternal->size; i++, j++)
            newInternal->key[i] = tempKey[j];

        for (int i = 0, j = current->size + 1; i < newInternal->size + 1; i++, j++)
            newInternal->ptr[i] = tempPtr[j];

        if (current == btree->root) {
            struct Node* newRoot = createNode();
            newRoot->key[0] = current->key[current->size];
            newRoot->ptr[0] = current;
            newRoot->ptr[1] = newInternal;
            newRoot->isLeaf = false;
            newRoot->size = 1;
            btree->root = newRoot;
        } else {
            shiftLevel(current->key[current->size], findParent(btree->root, current), newInternal, btree);
        }
    }
}

int search(struct Btree* btree, int x) {
    if (btree->root == NULL)
        return -1;

    else {
        struct Node* current = btree->root;
        while (current->isLeaf == false) {
            for (int i = 0; i < current->size; i++) {
                if (x < current->key[i]) {
                    current = current->ptr[i];
                    break;
                }

                if (i == current->size - 1) {
                    current = current->ptr[i + 1];
                    break;
                }
            }
        }

        for (int i = 0; i < current->size; i++) {
            if (current->key[i] == x) {
                // printf("Key found\n");
                return 1;
            }
        }

        // printf("Key not found\n");
        return 0;
    }
}


int queueSize(struct Queue* queue) {
    int size = 0;
    struct Queue* temp = queue;
    while (temp != NULL) {
        temp = temp->next;
        size++;
    }
    return size;
}

// Display function in C
void display(struct Node* current) {
    if (current == NULL)
        return;

    struct Queue* q = NULL;
    enqueue(&q, current);
    
    while (q != NULL) {
        int levelSize = queueSize(q);
        
        for (int i = 0; i < levelSize; i++) {
            struct Node* tNode = dequeue(&q);
            
            for (int j = 0; j < tNode->size; j++)
                printf("%d ", tNode->key[j]);
            
            for (int j = 0; j < tNode->size + 1; j++)
                if (tNode->ptr[j] != NULL)
                    enqueue(&q, tNode->ptr[j]);
            
            printf("\t");
        }
        
        printf("\n");
    }
}



struct Node* findParent(struct Node* current, struct Node* child) {
    struct Node* parent = NULL;
    if (current->isLeaf || current->ptr[0]->isLeaf)
        return NULL;

    for (int i = 0; i < current->size + 1; i++) {
        if (current->ptr[i] == child) {
            parent = current;
            return parent;
        } else {
            parent = findParent(current->ptr[i], child);
            if (parent != NULL)
                return parent;
        }
    }
    return parent;
}


struct Node* getRoot(struct Btree* btree) {
    return btree->root;
}





