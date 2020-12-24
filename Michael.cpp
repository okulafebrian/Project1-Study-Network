//FEATURE:
//- User can recover their deleted notes. Please validate the recycle bin is not empty and the note is in there. 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void recovery(char a[],char b[]){ //dari array a(recycle bin) mau dipindahin ke array b(tempat awal)
    if(a[0] == '\0'){ // check dulu array a nya ad isinya atau tidak
        printf("\nThere is no deleted Files !\n");
        return;
    }
    else{ // kalau ad isinya pake strcpy aja bwt pindahin string a ke b
        strcpy(b,a);
        int len = strlen(a);
        for(int i=0;i<5;i++){
            a[i] = 0;
        }
        printf("\nFiles Have Recovered !\n");
        return;
    }
}


int main(){
    char a[255]={0};
	char b[255]={0};
		
		for(int i=0;i<5;i++){
            a[i] = 'm';
        }
        printf("a yg awal : %s\n",a);
        for(int i=0;i<5;i++){
            b[i] = 'a';
        }
        printf("b yg awal : %s\n",b);
    recovery(a,b);
    printf("final b : %s\n",b);
    
    // ambil funcnya aja, sisanya comment aja
  	return 0;
}
