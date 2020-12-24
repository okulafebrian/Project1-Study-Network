#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    int num;
    char name[255];
    node *next;
} *head , *tail;

node *createnode (int num, const char *name){
    node *newnode = (node*)malloc(sizeof(node));
    strcpy (newnode-> name , name );
    newnode -> num = num ;
    newnode -> next= NULL;
    return newnode;
}
void pushtail (int num , const char *name){
    node *temp = createnode (num ,name);
    if (!head){
        head = tail = temp;
    }
    else{
        tail -> next = temp;
        tail = temp;
    }
}
void poptail (){
    if (!head){
        return;
    }
    else if (head == tail){
        free (head);
        head = tail = NULL;
    }
    else {
        node *temp = head;
        while (temp -> next != tail){
            temp = temp -> next;
        }
        temp -> next = NULL;
        free (tail);
        tail = temp;
    }
}
void print(){
    node *curr=head;
    while (curr){
        printf ("%d %s\n",curr->num,curr->name);
        curr = curr-> next;
    }
}
int main (){
    // pushtail(1,"romario");
    // pushtail(2,"acep");
    // pushtail (3,"uus");
    // print();
    // poptail();
    // print();
    

    // untuk add friend
    // ambil inputan dari all user yang ada lalu bentuk dengan format scanf ("%d %s",num,name);
    // selanjutnya bikin printf ("Which user do you want to add?\n");
    // kemudian printf (">> %s",name); lalu printf("--Your request has been sent to ronald--");
    
    // untuk dibagian main menu
    // jika ingin menampilkan semua friend gunakan pushtail (num,name) dari inputan scanf yang diatas
    // lalu gunakan fungsi print();

    // untuk dibagian remove friend
    // gunakan poptail () untuk meremove friend dan print () untuk memperbaharui list friends
}