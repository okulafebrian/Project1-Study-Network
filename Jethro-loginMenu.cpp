#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Login Menu

struct Node {
  char name[105];
  int number;
  Node *next; 
} *head, *tail;

Node *createNode(const char *name) {
  Node *newNode = (Node*)malloc(sizeof(Node)); 
  strcpy(newNode->name, name);
  newNode->next = NULL; 
  return newNode;
}

void pushHead(const char *name) {
    Node *temp = createNode(name);
    if(!head) { 
        head = tail = temp; 
    } else { 
        temp->next = head; 
        head = temp;
    }
}

void printLinkedList() {
  Node *curr = head;
      while (curr) {
    printf("%s\n", curr->name);
    curr = curr->next;
    }
}
  
void pushTail(const char *name) {
    Node *temp = createNode(name);
    if(!head) { 
        head = tail = temp; 
    } else { 
        tail->next = temp; 
        tail = temp;
    }
}


#include <stdio.h>

int main() {


    int num;

    printf("Oo=========================================================oO\n");
    printf("                        STUDY NETWORK\n");
    printf("Oo=========================================================oO\n");
    printf("\n");
    printf("[All User]\n");
    printf("No.    Username\n");
    pushHead("romario");
    pushTail("roland");
    printLinkedList();
    printf("\n");
    printf("------------------------\n");
    printf("[1] Register\n");
    printf("[2] Login\n");
    printf("[3] Exit\n");
    printf("------------------------\n");
    printf("Press 0 and enter to abort an operation\n");
    printf("------------------------\n");
    printf(">>");
    scanf("%d", &num);
    if (num == 0) {
        return 0;
    }
} 