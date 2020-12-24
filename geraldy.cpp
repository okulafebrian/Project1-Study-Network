#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct chat
{
    char comment[255];
    int time;
} ct[10001];

void sortTime(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ct[j].time > ct[idx].time)
            {
                idx = j;
            }
        }
        struct chat temp = ct[i];
        ct[i] = ct[idx];
        ct[idx] = temp;
    }
}

void sortLike(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ct[j].time > ct[idx].time)
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
    int i = 0;
    i++;

    time_t now;
    //scanf("%[^\n] %d", &ct[i].comment, &ct[i].time);
    //time_t now;

    time(&now);
    scanf("%[^\n] %d", &ct[i].comment, &ct[i].time);
    //Convert to local time format and print to stdout
    printf("Today is : %s", ctime(&now));

    return 0;
}
