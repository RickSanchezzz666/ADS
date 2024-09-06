#include <stdlib.h>
#include <stdio.h>

#include <limits.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node; 

typedef struct {
    int top;
    struct Node* s;
} MinStack;


MinStack* minStackCreate() {
    MinStack* stack = (MinStack *)malloc(sizeof(MinStack));

    stack->top = -1;
    stack->s = NULL; 

    return stack;
}

void minStackPush(MinStack* obj, int val) {
    Node* newNode = (Node* )malloc(sizeof(Node));

    newNode->value = val;
    newNode->next = NULL;
   
    Node* node = obj->s;
    
    if (obj->top == -1) {
        obj->s = newNode;
    } else {
        while(node->next != NULL) {
            node = node->next;
        }
        node->next = newNode;
    }

    obj->top++;
}

void minStackPop(MinStack* obj) {
    if (obj->top == -1) return;
    else if (obj->top == 0) {
        free(obj->s);
        obj->s = NULL;
    } else {
        Node* node = obj->s;
        for (int i = 0; i < obj->top - 1; ++i) {
            node = node->next;
        }

        free(node->next);
        node->next = NULL;
    }

    obj->top--;
}

int minStackTop(MinStack* obj) {
    if (obj->top == -1) return INT_MAX;
    
    Node* node = obj->s;
    
    while(node->next != NULL) {
        node = node->next;
    }

    return node->value;
}

int minStackGetMin(MinStack* obj) {
    if (obj->top == -1) return INT_MAX;

    int min = obj->s->value;

    Node* node = obj->s;
    while(node->next != NULL) {
        node = node->next;
        if (node->value < min) min = node->value;
    }

    return min;
}

void minStackFree(MinStack* obj) {
    Node* node = obj->s;
    while(node->next != NULL) {
        Node* temp = node;
        node = node->next;
        free(temp);
    }
    free(obj);
}