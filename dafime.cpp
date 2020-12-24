//FEATURE:
//- Login a user by his/her username and password. Validate the username and password are correct. 

#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
clrscr();
char username[15], password[15], ch, usr[15], pass[15];
int choice, i=0, found=0;

    printf("1.Add User");
    printf("\n2.Log-in User");
    printf("\n3.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
     case 1: FILE *acc;
        if((acc = fopen("c:\\account.txt","a+")) == NULL)
            printf("FILE NOT FOUND!");
        else
            {
            do
             {
              fscanf(acc,"%s %s%",username, password);
             }while(!feof(acc));
            }
        printf("\nEnter desired username: ");
        scanf("%s",username);
        printf("Enter desired password: ");

        while(ch != 13)
        {
         ch = getch();
         password[i] = ch;
         i++;
         printf("*");
        }
        password[i]='\0';
        fprintf(acc,"%s %s\n",username,password);
        fclose(acc);break;
     case 2: FILE *log;
        log = fopen("c:\\account.txt","r");

        printf("Username: ");   //user input username and password//
        scanf("%s",usr);
        printf("Password: ");

        while(ch != 13)
            {
            ch = getch();
            pass[i] = ch;
            i++;
            printf("*");
            }
            pass[i]='\0';
        while(!feof(log)&& found == 0)
        {
         fscanf(log,"%s %s",username,password);     //this is where i am having some problem//
         if(strcmp(usr,username) == 0 && strcmp(pass,password)); 
         found = 1;
         if(found == 1)
            printf("\nWelcome!");
         else
            printf("\nInvalid username or password");

        }

        fclose(log);
    }
getch();
return(0);
}
