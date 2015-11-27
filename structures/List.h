#include <stdlib.h>
#include <stdio.h>
#include "Node.h"

typedef struct t_node {
    Edge edge;
    struct t_node *next;
} node;

typedef struct {
    node *head;
    int countNode;
} List;

void initList(List *list) {
    list->head = NULL;
    list->countNode = 0;
}

int listSize(List *list) {
    return list->countNode;
}

int isEmpty(List *list) {
    return listSize(list) == 0;
}

Edge getListFront(List *list) {
    return list->head->edge;
}

void updateListSize(List *list) {
    list->countNode++;
}

void insertFront(List *list, Edge edge) {
    node *newHead = malloc(sizeof(node));
    newHead->edge = edge;
    
    if(list->head == NULL) {
        list->head = newHead;
        list->head->next = NULL;
    }
    else {
        newHead->next = list->head;
        list->head = newHead;
    }
    updateListSize(list);
}

void destroyList(List *list) {
    node *current = list->head, *temp;
    while(current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    free(list);
}

void printList(List *list) {
    node *next;
    for(next = list->head; next != NULL; next = next->next) {
        Edge edge = next->edge;
        printf("to = %d, length = %d\n", edge.to, edge.length);
    }
}
