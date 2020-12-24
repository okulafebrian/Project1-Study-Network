//GABUNGAN SEMUA FITUR JADI SEBUAH PROGRAM
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

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
  printf("--- Registration Successfull ---\n");
  printf("Press enter to continue!\n");
  return;
}

void enterToContinue(){
	printf("press enter to continue..\n");
	getchar();
}

void login_Page(){
	Profile *choosen = head;
	for(int i=1;i<2;i++){
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

int userPage(){
  int input;
  //database account blum dibuat
  printf("Oo=====================================oO\n");
  printf("Welcome, %s!\n", name);
  printf("Oo=====================================oO\n");
  printf("Logged in: %s\n", ctime(&now));
  printf("-----------------------------------------\n");
  printf("[All Friends of %s]\n", name);
  printf("No. 	Username\n");
  //Friends list
  printf("-----------------------------------------\n");
  printf("	      >>Menu<<\n");
  printf("-----------------------------------------\n");
  printf("[1] Add Friend\n");
  printf("[2] Remove Friend\n");
  printf("[3] View Inbox\n");
  printf("[4] View Sent Request\n");
  printf("[5] Add, Edit, Announce, Delete Note\n");
  printf("[6] Log out\n");
  printf("-----------------------------------------\n");
  printf(">>");
  scanf("%d", &input); getchar();
  printf("-----------------------------------------\n");
  printf("\n");
  return input;
}

int mainMenu(){
	int input;
		printf("Oo=====================================oO\n");
		printf("              STUDY NETWORK              \n");
		printf("Oo=====================================oO\n");
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
		
    return input;
}

void addFriend(){
  char name[100];
  printf("[All User]\n");
  printf("No. 	Username\n");
  //Friend list
  printf("\n");
  printf("Which user do you want to add?\n");
  printf(">>");
  scanf("%[^\n", name); getchar();

  //cek ke data base
  printf("\n");
  printf("-- Your request has been sent to %s --\n", name);
  printf("Press enter to continue!\n");
}


int main(){
	//USER PAGE
  int menu = mainMenu(), flag = 0;

  while(menu != 3){
    if(menu == 1) {
      register_Page();
    } else if(menu == 2) {
      login_Page();
      flag = 1;
      break;
    } else {
      return 0;
    }
    menu = mainMenu();
  }
  
  if(flag == 1){
    int user = userPage();

    while(user != 6){
      if(user == 1) {
        addFriend();
      } else if(user == 2) {
        
      } else if(user == 3) {
        
      } else if(user == 4) {

      } else if(user == 5) {

      } else {
        return 0;
      }
      user = userPage();
    }
  }
  
  
	
  
  return 0;
}
