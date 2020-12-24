//Register Menu

#include <stdio.h>

void Register(int num) {
    char name[105], pass[105];
    if (num == 0) {
        return;
    }else if (num == 1){
        printf("Please type in your username [lowercase || 1..24]: ");
        scanf("%s", name);
        printf("Please type in your password [lowercase || 1..24]: ");
        scanf("%s", pass);
        printf("\n");
        printf("-- Registration Successfull --\n");
        printf("Press enter to continue!\n");
    }
}
int main() {

    int num;
    printf("Oo=========================================================oO\n");
    printf("                        STUDY NETWORK\n");
    printf("Oo=========================================================oO\n");
    printf("\n");
    printf("[All User]\n");
    printf("No.    Username\n");
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
    Register(num);
    printf("------------------------\n");
    return 0;
}

