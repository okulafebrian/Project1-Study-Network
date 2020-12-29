#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct data{
  char name[100];
  char pswd[100];
} input;


struct People{
  char name[100];
  People *next, *prev;
};

struct User{
  char username[100];
  char password[100];
  User *next, *prev;
  People *headSent, *tailSent, *sentRequest, *headBox, *tailBox, *inbox, *headFriend, *tailFriend, *FriendList, *headList, *tailList, *listUser;
} *head, *tail;

//FUNCTIONS
int userPage(User **);
void addFriend(User **);
void removeFriend(User **);
void viewInbox(User **);
void viewSentReq(User **);


User *createUser(data input){
  User *temp = (User*)malloc(sizeof(User));
  strcpy(temp->username,input.name);
  strcpy(temp->password,input.pswd);
  temp->next = temp->prev = NULL;
  return temp;
}

User *createListUser(User **currUser, const char *name){
  User *temp = *currUser;
  temp->listUser = (People*)malloc(sizeof(People));

  strcpy(temp->listUser->name,name);
  temp->listUser->next = temp->listUser->prev = NULL;
  return temp;
}

User *createSentReq(User **currUser, const char *name){
  User *temp = *currUser;
  temp->sentRequest = (People*)malloc(sizeof(People));

  strcpy(temp->sentRequest->name,name);
  temp->sentRequest->next = temp->sentRequest->prev = NULL;
  return temp;
}

User *createInbox(User **target, const char *name){
  User *temp = *target;
  temp->inbox = (People*)malloc(sizeof(People));

  strcpy(temp->inbox->name,name);
  temp->inbox->next = temp->inbox->prev = NULL;
  return temp;
}

User *createFriendList(User **target, const char *name){
  User *temp = *target;
  temp->FriendList = (People*)malloc(sizeof(People));

  strcpy(temp->FriendList->name,name);
  temp->FriendList->next = temp->FriendList->prev = NULL;
  return temp;
}

User *pushUser(data input){
  User *temp = createUser(input);

  if(!head) {
    head = tail = temp;
  } else {
    tail->next = temp;
    tail = temp;
  }

  return temp;
}

void pushToListUser(User **tempUser, const char *name){
  User *temp = createListUser(&*tempUser,name);

  if(!temp->headList) {
    temp->headList = temp->tailList = temp->listUser;
  } else {
    temp->tailList->next = temp->listUser;
    temp->listUser->prev = temp->tailList; 
    temp->tailList = temp->listUser;
  }
}

void popFromListUser(User **tempUser, const char *name){
  User *temp = *tempUser;
  
  if(!temp->headList){
    return;
  } else if(strcmp(temp->headList->name,name) == 0) {
    //POPHEAD
    if(temp->headList == temp->tailList) {
      free(temp->headList);
      temp->headList = temp->tailList = NULL;
    } else {
      People *newHead = temp->headList->next;
      temp->headList->next = newHead->prev = NULL;
      free(temp->headList);
      temp->headList = newHead;
    }
  } else if(strcmp(temp->tailList->name,name) == 0) {
    //POPTAIL
    if(temp->headList == temp->tailList) {
      free(temp->headList);
      temp->headList = temp->tailList = NULL;
    } else {
      People *newTail = temp->tailList->prev;
      temp->tailList->prev = newTail->next = NULL;
      free(temp->tailList);
      temp->tailList = newTail;
    }
  } else {
    People *curr = temp->headList;

    while(curr && strcmp(curr->name,name) != 0) {
      curr = curr->next;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    curr->prev = curr->next = NULL;
    free(curr);
    curr = NULL;
  }
}

void pushToSentReq(User **tempUser, const char *name){
  User *temp = createSentReq(&*tempUser,name);

  if(!temp->headSent) {
    temp->headSent = temp->tailSent = temp->sentRequest;
  } else {
    temp->tailSent->next = temp->sentRequest;
    temp->sentRequest->prev = temp->tailSent; 
    temp->tailSent = temp->sentRequest;
  }
}

void popFromSentReq(User **tempUser, const char *name){
  User *temp = *tempUser;
  
  if(!temp->headSent){
    return;
  } else if(strcmp(temp->headSent->name,name) == 0) {
    //POPHEAD
    if(temp->headSent == temp->tailSent) {
      free(temp->headSent);
      temp->headSent = temp->tailSent = NULL;
    } else {
      People *newHead = temp->headSent->next;
      temp->headSent->next = newHead->prev = NULL;
      free(temp->headSent);
      temp->headSent = newHead;
    }
  } else if(strcmp(temp->tailSent->name,name) == 0) {
    //POPTAIL
    if(temp->headSent == temp->tailSent) {
      free(temp->headSent);
      temp->headSent = temp->tailSent = NULL;
    } else {
      People *newTail = temp->tailSent->prev;
      temp->tailSent->prev = newTail->next = NULL;
      free(temp->tailSent);
      temp->tailSent = newTail;
    }
  } else {
    People *curr = temp->headSent;

    while(curr && strcmp(curr->name,name) != 0) {
      curr = curr->next;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    curr->prev = curr->next = NULL;
    free(curr);
    curr = NULL;
  }
}

void pushToInbox(User **tempUser, const char *name){
  User *temp = createInbox(&*tempUser,name);

  if(!temp->headBox) {
    temp->headBox = temp->tailBox = temp->inbox;
  } else {
    temp->tailBox->next = temp->inbox;
    temp->inbox->prev = temp->tailBox;
    temp->tailBox = temp->inbox;
  }
}

void popFromInbox(User **tempUser, const char *name){
  User *temp = *tempUser;
  
  if(!temp->headBox){
    return;
  } else if(strcmp(temp->headBox->name,name) == 0) {
    //POPHEAD
    if(temp->headBox == temp->tailBox) {
      free(temp->headBox);
      temp->headBox = temp->tailBox = NULL;
    } else {
      People *newHead = temp->headBox->next;
      temp->headBox->next = newHead->prev = NULL;
      free(temp->headBox);
      temp->headBox = newHead;
    }
  } else if(strcmp(temp->tailBox->name,name) == 0) {
    //POPTAIL
    if(temp->headBox == temp->tailBox) {
      free(temp->headBox);
      temp->headBox = temp->tailBox = NULL;
    } else {
      People *newTail = temp->tailBox->prev;
      temp->tailBox->prev = newTail->next = NULL;
      free(temp->tailBox);
      temp->tailBox = newTail;
    }
  } else {
    People *curr = temp->headBox;

    while(curr && strcmp(curr->name,name) != 0) {
      curr = curr->next;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    curr->prev = curr->next = NULL;
    free(curr);
    curr = NULL;
  }
}

void pushToFriendList(User **tempUser, const char *name){
  User *temp = createFriendList(&*tempUser,name);

  if(!temp->headFriend) {
    temp->headFriend = temp->tailFriend = temp->FriendList;
  } else {
    temp->tailFriend->next = temp->FriendList;
    temp->FriendList->prev = temp->tailFriend;
    temp->tailFriend = temp->FriendList;
  }
}

void popFromFriendList(User **tempUser, const char *name){
  User *temp = *tempUser;
  
  if(!temp->headFriend){
    return;
  } else if(strcmp(temp->headFriend->name,name) == 0) {
    //POPHEAD
    if(temp->headFriend == temp->tailFriend) {
      free(temp->headFriend);
      temp->headFriend = temp->tailFriend = NULL;
    } else {
      People *newHead = temp->headFriend->next;
      temp->headFriend->next = newHead->prev = NULL;
      free(temp->headFriend);
      temp->headFriend = newHead;
    }
  } else if(strcmp(temp->tailFriend->name,name) == 0) {
    //POPTAIL
    if(temp->headFriend == temp->tailFriend) {
      free(temp->headFriend);
      temp->headFriend = temp->tailFriend = NULL;
    } else {
      People *newTail = temp->tailFriend->prev;
      temp->tailFriend->prev = newTail->next = NULL;
      free(temp->tailFriend);
      temp->tailFriend = newTail;
    }
  } else {
    People *curr = temp->headFriend;

    while(curr && strcmp(curr->name,name) != 0) {
      curr = curr->next;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    curr->prev = curr->next = NULL;
    free(curr);
    curr = NULL;
  }
}

void printUserList(){
  User *curr = head;

  while(curr){
    printf("Your username: %s\n", curr->username);
    printf("Your password: %s\n", curr->password);
    curr = curr->next;
  }
}

//===================================================================================================================

int mainMenu(){
	int n, i = 1;
  User *curr = head;

	printf("Oo=====================================oO\n");
	printf("              STUDY NETWORK              \n");
	printf("Oo=====================================oO\n");
	printf("\n[All User]\n");
	printf("No.   Username\n");
  while(curr) {
    printf("%d     %s\n", i, curr->username);
    curr = curr->next;
    i++;
  }
  puts("");

	printf("-----------------------------------------\n");
	printf("[1]Register\n");
	printf("[2]Login\n");
	printf("[3]Exit\n");
	printf("-----------------------------------------\n");
	printf("Press 0 and enter to abort an operation\n");
	printf("-----------------------------------------\n");
	printf(">>");
	scanf("%d", &n); getchar();
		
  return n;
}

void registerMenu(){
	printf("-----------------------------------------\n");

  int checkLower = 1;

	do{
		printf("Please type in your username [lowercase||1..24]: ");
		scanf("%[^\n]", input.name); getchar();
    
    if(strcmp(input.name,"0") == 0) return;
		
    for(int i = 0; i < strlen(input.name); i++){  
			if(islower(input.name[i]) == 0){
				checkLower = -1;
			}
		}
	} while(strlen(input.name) < 1 && strlen(input.name) > 24 && checkLower != 1);
	
  checkLower = 1;
	
  do{
		printf("Please type in your password [lowercase||1..24]: ");
		scanf("%[^\n]", input.pswd); getchar();

		if(strcmp(input.pswd,"0") == 0) return;

		for(int i = 0; i < strlen(input.pswd); i++){
			if(islower(input.pswd[i]) == 0){
				checkLower=-1;
			}
		}
	} while(strlen(input.pswd) < 1 && strlen(input.pswd) > 24 && checkLower != 1);
	
  User *temp = pushUser(input);

  //IMPORT DATA SEMUA USER DARI DATABASE KE "LIST OF USER" MILIK USER SEKARANG
  User *curr = head;
  People *curr1 = temp->headList;
  while(curr){
    int flag = 1;

    while(curr1){
      if(strcmp(curr->username,curr1->name) == 0){
        flag = 0;
        break;
      }
      curr1 = curr1->next;
    }
    
    if(flag && strcmp(curr->username,temp->username) != 0){
      pushToListUser(&temp,curr->username);
    }

    curr = curr->next;
  }

  //PUSH DATA USER SEKARANG KE "LIST OF USER" SEMUA USER
  curr = head;
  while(curr){
    if(strcmp(curr->username,temp->username) != 0){
      pushToListUser(&curr,temp->username);
    }
    curr = curr->next;
  }

  printf("\n--- Registration Successfull ---\n");
  printf("Press enter to continue!..."); getchar();
  puts("");
}

void loginMenu(){
	printf("-----------------------------------------\n");

  printf("Username: ");
	scanf("%[^\n]",input.name); getchar();
  if(strcmp(input.name,"0") == 0) return;
  
  printf("Password: ");
  scanf("%[^\n]",input.pswd); getchar();
  if(strcmp(input.pswd,"0") == 0) return;
  printf("\n");
  
  //CEK APAKAH USER YANG MAU LOGIN TERDAFTAR ATAU TIDAK
  User *curr = head;
  int flag = 0;
  while(curr){
    if(strcmp(curr->username,input.name) == 0 && strcmp(curr->password,input.pswd) == 0){
      printf("--- Login Successfull ---\n");
      printf("Press enter to continue!..."); getchar();
      puts("");
      flag = 1;
      break;
    }
    curr = curr->next;
  }

  //JIKA TERDAFTAR:
  if(flag){
    int selectUserMenu = userPage(&curr);
    while(selectUserMenu != 6){
      switch(selectUserMenu) {
        case 1:
          addFriend(&curr);
          break;
        case 2:
          removeFriend(&curr);
          break;
        case 3:
          viewInbox(&curr);
          break;
        case 4:
          viewSentReq(&curr);
          break;
        case 5:
          //noteFeature();
          break;
        case 6:
          return;
        default:
          printf("Wrong Input!");
      }
      selectUserMenu = userPage(&curr);
    }
  } else {
    //JIKA TIDAK TERDAFTAR:
    printf("--- User Not Found! ---\n");
    printf("Press enter to continue!..."); getchar();
  }
}

int userPage(User **currUser){  //currUser: USER YANG LOGIN
  int hours, minutes, seconds, day, month, year;
  time_t now;
  time(&now);

  int n, i = 1;
  User *temp = *currUser;

  printf("Oo=====================================oO\n");
  printf("Welcome, %s!\n", temp->username);
  printf("Oo=====================================oO\n");
  printf("Logged in: %s", ctime(&now));
  printf("-----------------------------------------\n");
  puts("");

  printf("[All Friends of %s]\n", temp->username);
  printf("No. 	Username\n");
  
  //PRINT SEMUA YANG ADA DI DALAM "FRIEND LIST" USER YANG LOGIN
  People *curr = temp->headFriend;
  while(curr) {
    printf("%d     %s\n", i, curr->name);
    curr = curr->next;
    i++;
  }
  puts("");

  printf("-----------------------------------------\n");
  printf("	        >>Menu<<\n");
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

  return n;
}

void addFriend(User **currUser){  //currUser: USER YANG LOGIN
  printf("-----------------------------------------\n");
  puts("");

  User *temp = *currUser;

  printf("[All User]\n");
  printf("No. 	Username\n");

  //PRINT SEMUA YANG ADA DI DALAM "LIST OF USER" USER YANG LOGIN
  int i = 1;
  People *curr1 = temp->headList;
  while(curr1) {
    printf("%d     %s\n", i, curr1->name);
    curr1 = curr1->next;
    i++;
  }
  puts("");

  printf("Which user do you want to add?\n");
  printf(">>");
  char inputname[100];
  scanf("%[^\n]", inputname); getchar();
  puts("");
  
  //CEK APAKAH INPUTNAME TERDAPAT DI DALAM "LIST OF USER" USER YANG LOGIN
  int flag = 0;   //FLAG = 0 : FALSE || FLAG = 1 : TRUE
  curr1 = temp->headList;
  while(curr1) {
    if(strcmp(curr1->name,inputname) == 0){
      flag = 1;
      break;
    }
    curr1 = curr1->next;
  }

  User *curr2 = head;
  if(flag){   //JIKA ADA DI DALAM "LIST OF USER":
    while(curr2) {
      if(strcmp(curr2->username,inputname) == 0) {
        //inputname      : user yang di add
        //temp->username : user yang login
        pushToSentReq(&temp,inputname);           // PUSH USER YANG DI ADD KE "SENT REQ" USER YANG LOGIN
        pushToInbox(&curr2,temp->username);       // PUSH USER YANG LOGIN KE "INBOX" USER YANG DI ADD
        popFromListUser(&temp,inputname);         // POP USER YANG DI ADD DARI "LIST OF USER" USER YANG LOGIN
        popFromListUser(&curr2,temp->username);   // POP USER YANG LOGIN DARI "LIST OF USER" USER YANG DI ADD
        printf("-- Your request has been sent to %s --\n", inputname);
        printf("Press enter to continue!..."); getchar();
        puts("");
        return;
      }
      curr2 = curr2->next;
    }
  }
  
  //JIKA TIDAK ADA DI DALAM "LIST OF USER":
  printf("--- User Not Found! ---\n");
  printf("Press enter to continue!..."); getchar();
  puts("");
}

void removeFriend(User **currUser){ //currUser: USER YANG LOGIN
  printf("-----------------------------------------\n");
  puts("");

  User *temp = *currUser;

  printf("[All Friends of %s]\n", temp->username);
  printf("No. 	Username\n");

  //PRINT SEMUA YANG ADA DI DALAM "FRIEND LIST" USER YANG LOGIN
  int i = 1;
  People *curr1 = temp->headFriend;
  while(curr1) {
    printf("%d     %s\n", i, curr1->name);
    curr1 = curr1->next;
    i++;
  }
  puts("");

  printf("Which user do you want to remove?\n");
  printf(">>");
  char inputname[100];
  scanf("%[^\n]", inputname); getchar();
  puts("");

  //CEK APAKAH INPUTNAME ADA DI DALAM "FRIEND LIST" USER YANG LOGIN
  int flag = 0;   //FLAG = 0 : FALSE || FLAG = 1 : TRUE
  curr1 = temp->headFriend;
  while(curr1) {
    if(strcmp(curr1->name,inputname) == 0){
      flag = 1;
      break;
    }
    curr1 = curr1->next;
  }

  if(flag){
    popFromFriendList(&temp,inputname);
    pushToListUser(&temp,inputname);

    User *curr2 = head;
    while(curr2){
      if(strcmp(curr2->username,inputname) == 0){
        popFromFriendList(&curr2,temp->username);
        pushToListUser(&curr2,temp->username);
        printf("-- You are no longer friends with %s --\n", inputname);
        printf("Press enter to continue!..."); getchar();
        puts("");
        return;
      }
      curr2 = curr2->next;
    }
  }

  //JIKA TIDAK ADA DI DALAM "FRIEND LIST":
  printf("--- User Not Found! ---\n");
  printf("Press enter to continue!..."); getchar();
  puts("");
}

void viewInbox(User **currUser){  //currUser: USER YANG LOGIN 
  printf("-----------------------------------------\n");
  puts("");

  User *temp = *currUser;

  printf("[All Friend Requests of %s]\n", temp->username);
  printf("No. 	Username\n");

  //PRINT SEMUA YANG ADA DI DALAM "INBOX" USER YANG LOGIN
  int i = 1;
  People *curr1 = temp->headBox;
  while(curr1) {
    printf("%d     %s\n", i, curr1->name);
    curr1 = curr1->next;
    i++;
  }
  puts("");

  printf("Which user do you want to be accepted?\n");
  printf(">>");
  char inputname[100];
  scanf("%[^\n]", inputname); getchar();
  puts("");


  curr1 = temp->headBox;
  User *curr2 = head;  
  while(curr1) {
    // CEK APAKAH INPUTNAME ADA DI DALAM INBOX
    if(strcmp(curr1->name,inputname) == 0) {   // JIKA ADA DI DALAM INBOX:
      //CARA SI INPUTNAME DARI DATABASE USER
      while(curr2) {
        if(strcmp(curr2->username,inputname) == 0) {
          // inputname       : user yang di accept
          // temp->username  : user yang login
          pushToFriendList(&curr2,temp->username);    // PUSH USER YANG LOGIN KE "FRIEND LIST" USER YANG DI ACCEPT
          pushToFriendList(&temp,inputname);          // PUSH USER YANG DI ACCEPT KE "FRIEND LIST" USER YANG LOGIN
          popFromInbox(&temp,inputname);              // POP USER YANG DI ACCEPT DARI "SENT REQ" USER YANG LOGIN
          printf("-- You accepted the request from %s --\n", inputname);
          printf("Press enter to continue!..."); getchar();
          puts("");
          return;
        }
        curr2 = curr2->next;
      }
    }
    curr1 = curr1->next;
  }

  //JIKA TIDAK ADA DI DALAM INBOX:
  printf("--- User Not Found! ---\n");
  printf("Press enter to continue!..."); getchar();;
  puts("");
}

void viewSentReq(User **currUser){  //currUser: USER YANG LOGIN
  printf("-----------------------------------------\n");
  puts("");

  User *temp = *currUser;

  printf("[All Sent Requests of %s]\n", temp->username);
  printf("No. 	Username\n");
  
  //PRINT SEMUA YANG ADA DI DALAM "SENT REQ" USER YANG LOGIN
  int i = 1;
  People *curr = temp->headSent;
  while(curr) {
    printf("%d     %s\n", i, curr->name);
    curr = curr->next;
    i++;
  }
  puts("");

  printf("Press enter to continue!..."); getchar();
  puts("");
}


int main(){
	//MAIN MENU PAGE
  int selectMainMenu = mainMenu();
  
  while(selectMainMenu != 3) {
    switch(selectMainMenu) {
      case 1:
        registerMenu();
        break;
      case 2:
        loginMenu();
        break;
      default:
        return 0;
    }
    selectMainMenu = mainMenu();
  }
  
  return 0;
}
