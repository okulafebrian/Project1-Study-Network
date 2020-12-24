//FEATURE:
//- User can leave a comment (alphanumeric, 1 to 255 letters) on other user’s notes and user can like the comment. Comments are sorted based on the likes and time when posted.
//- User can set their notes to “private” so that only approved users (maximum of 3) can see their notes. When giving access, user must type in the username. When a user get an invitation to access the notes, the user can choose to accept or reject it. 


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct chat
{
    char comment[255];
    int time;
    int like;
} ct[10001];

void sortLike(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ct[idx].like < ct[j].like)
            {
                idx = j;
            }
        }
        struct chat temp = ct[i];
        ct[i] = ct[idx];
        ct[idx] = temp;
    }
}

void sortTime(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ct[idx].time > ct[j].time)
            {
                idx = j;
            }
        }
        struct chat temp = ct[i];
        ct[i] = ct[idx];
        ct[idx] = temp;
    }
}

int main(void)
{

    time_t now;
    time(&now);
    /*printf("Today is : %s", ctime(&now));
    //sortTime();
    //sortLike();
    for (int i = 0; i < n-1; i++) { //if like same
        int idx=i;
        for (int j = i+1; j < n; j++) {
            if (ct[j].like == ct[idx].like) {
                if (ct[idx].time > ct[j].time) {
                    struct chat temp=ct[j];
                    ct[j]=ct[idx];
                    ct[idx]=temp;
                }
            }
        }
    }*/

    return 0;
}
