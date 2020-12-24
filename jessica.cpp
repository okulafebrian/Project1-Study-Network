//FEATURE:
//- Each user can post their own notes and choose a category (Backlog, In Progress, Peer Review, In Test, Done, and Blocked).
//  Validate the note must be alphanumeric only. Each user can only edit or delete their own notes. Announced notes will be shown at the top. 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void addNotes(void) {
    char notes[255];
    int nFlag = 1;
    do {
        nFlag = 1;
        printf("Note: ");
        scanf("%[^\n]", notes);
        getchar();
        if (strlen(notes) < 5 || strlen(notes) > 200) {
            nFlag = 0;
            printf("Please write notes with length between 5 - 200\n");
        } else {
            for (int i = 0; i < strlen(notes); i++) {
                if ((notes[i] < 'A' || notes[i] > 'Z') && (notes[i] < 'a' || notes[i] > 'z') && (notes[i] < '0' || notes[i] < '9')) {
                    nFlag = 0;
                    printf("Note must be alphanumeric!\n");
                    break;
                }
            }
        }
    } while (!nFlag);

    int cFlag = 1;
    char category[100];
    do {
        cFlag = 1;
        printf("Category: ");
        scanf("%[^\n]", category);
        getchar();
        if (strcmp(category, "Backlog") != 0 && strcmp(category, "In Progress") != 0 && strcmp(category, "Peer Review") != 0
            && strcmp(category, "In Test") != 0 && strcmp(category, "Done") != 0 && strcmp(category, "Blocked") != 0) {
                cFlag = 0;
                printf("Please enter one of the following category [Backlog | In Progress | Peer Review | In Test | Done | Blocked]!\n");
        }
    } while (!cFlag);
}


int main(){

  return 0;
}
