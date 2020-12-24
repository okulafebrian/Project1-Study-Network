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