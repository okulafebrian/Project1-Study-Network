//FEATURE:
//- Selecting one of the choices should give easiness of use. 
//- When the user log out, output how long the user has used the application. 

#include<stdio.h>
int main(){
    int select, select2;
    puts("Oo=====================================oO");
    puts("              STUDY NETWORK              ");
    puts("Oo=====================================oO");
    puts("");
    puts("[All User]");
    puts("No. Username");
    puts("");


    puts("-----------------------------------------");
    puts("[1] Register");
    puts("[2] Login");
    puts("[3] Exit");
    puts("-----------------------------------------");
    puts("Press 0 and enter to abort an operation");
    puts("-----------------------------------------");
    printf(">>"); scanf("%d",&select); printf("\n");
    switch (select)
    {
    case 1:
        /*puts("-----------------------------------------");
        printf("Please type in your username [lowercase || 1..24]: "); scanf("%s",username);
        printf("Please type in your password [lowercase || 1..24]: "); scanf("%s",pass);
        jika sudah valid login setelahnya masukin code
        masuk ke halaman user
        //  clock_t sec; 
            sec = clock();
        puts("--- Registration Successfull ---");
        printf("Press enter to continue!"); scanf("%c",&tmbl);
        if(tmbl == 'ETX'){
            break;
        }
        */
    case 2:
        /* puts("-----------------------------------------");
        printf("Usrname: "); scanf("%s",username);
        printf("Password: "); scanf("%s",pass);
        puts("--- Login Successfull ---");
        printf("Press enter to continue!"); scanf("%c",&tmbl);
        if(tmbl == 'ETX'){
            break;
        }
        */
        break;
    case 3:
        //close program
        break;
    case 0:
        /* code */
        break;
    default:
        puts("Silahkan pilih option yang tersedia");
        break;
    }


    return 0;
}

//pilihan untuk User page
// switch (select_userpage)
// {
// case 1:
//     /* code */
//     break;
// case 2:
//     /* code */
//     break;
// case 3:
//     /* code */
//     break;
// case 4:
//     /* code */
//     break;
// case 5:
//     /* code */
//     break;
// case 6:
//      (setelah enter angka 6)
//      sec = clock() - sec; 
//      int t = ((int)sec)/CLOCKS_PER_SEC;
//     break;
// default:
//     break;
// }
