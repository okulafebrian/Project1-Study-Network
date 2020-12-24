#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

struct Profile{
	char username[25];
	char password[25];
	Profile *prev;
	Profile *next;
}*head,*tail;


void register_Page(){
	char inputUsername[25];
	char inputPassword[25];
	int checkLower=1;
	do{
		printf("Please type in your username [lowercase||1..24]: ");
		scanf("%[^\n]",inputUsername);getchar();
		if(strcmp(inputUsername,"0")==0) return;
		for(int i=0;i<strlen(inputUsername);i++){
			if(islower(inputUsername[i])==0){
				checkLower=-1;
			}
		}
	}while(strlen(inputUsername)<1&&strlen(inputUsername)>24&&checkLower!=1);
	checkLower=1;
	do{
		printf("Please type in your password [lowercase||1..24]: ");
		scanf("%[^\n]",inputPassword);getchar();
		if(strcmp(inputPassword,"0")==0) return;
		for(int i=0;i<strlen(inputPassword);i++){
			if(islower(inputPassword[i])==0){
				checkLower=-1;
			}
		}
	}while(strlen(inputPassword)<1&&strlen(inputPassword)>24&&checkLower!=1);
	//pushTail(inputUsername,inputPassword);
}

void enterToContinue(){
	printf("press enter to continue..\n");
	getch();
}

void login_Page(){
	int input;
	printf(">> ");
	scanf("%d",&input);getchar();
	if(input==0) return;
	Profile *choosen = head;
	for(int i=1;i<input;i++){
		choosen=choosen->next;
	}
	printf("---------------------------------------\n");
	int match=-1;
	char inputUsername[25];
	char inputPassword[25];
	do{
		printf("Username: ");
		scanf("%[^\n]",inputUsername);getchar();
		if(strcmp(inputUsername,"0")==0) return;
		printf("Password: ");
		scanf("%[^\n]",inputPassword);getchar();
		if(strcmp(inputPassword,"0")==0) return;
		if(strcmp(inputUsername,choosen->username)==0&&strcmp(inputPassword,choosen->password)==0) match=1;
	}while(match!=1);
	printf("\n---Login Successful---\n");
	enterToContinue();
	// loginSuccessful(choosen);
}

void mainMenu(){
	int input;
	do{
		printf("=========================\n");
		printf("      STUDY NETWORK      \n");
		printf("=========================\n");
		printf("\n[All User]\n");
		printf("No.   Username\n");
		//viewAllProfile();
		printf("-----------------\n");
		printf("[1]Register\n");
		printf("[2]Login\n");
		printf("[3]Exit\n");
		printf("---------------------------------------\n");
		printf("Press 0 and enter to abort an operation\n");
		printf("---------------------------------------\n");
		printf(">>");
		scanf("%d",&input);getchar();
			if(input==1){
				register_Page();
				break;
			}
			if(input==2){
				login_Page();
				break;
			}
	}while(input!=3);
}

int main(){
	mainMenu();
	return 0;
}

