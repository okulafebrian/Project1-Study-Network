#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void viewInbox(char name[]){
  char temp[100];

  printf("[All Friends Requests of %s]\n", name);
  printf("No. 	Username\n");
  //friend requests

  printf("Which user do you want to be accepted?\n");
  printf(">>");
  scanf("%[^\n]", temp); getchar();
  printf("\n");

  printf("-- You accepted the request from %s --\n", temp);
  printf("Press enter to continue!\n");
  printf("\n");
}

void viewSentRequest(char name[]){
  printf("[All Sent Requests of %s]\n", name);
  printf("No. 	Username\n");
  //sent requests

  printf("Press enter to continue!\n");
  printf("\n");
}


int main(){
  int hours, minutes, seconds, day, month, year;
  time_t now;
  time(&now);
  
  int n;
  char name[] = "Vincent";

  printf("Oo=====================================oO\n");
  printf("Welcome, %s!\n", name);
  printf("Oo=====================================oO\n");
  printf("Logged in: %s\n", ctime(&now));
  printf("-----------------------------------------\n");
  printf("[All Friends of %s]\n", name);
  printf("No. 	Username\n");

  //print Friends

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
  scanf("%d", &n); getchar();
  printf("-----------------------------------------\n");
  printf("\n");

  if(n == 3){
    viewInbox(name);
  } else if(n == 4){
    viewSentRequest(name);
  }
  

  return 0;
}