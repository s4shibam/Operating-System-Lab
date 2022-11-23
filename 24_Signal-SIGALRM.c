// Program in C, that gives an alarm massage after every 2 seconds until the counter has exceeded 10.

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void fun(int signum)
{
    printf("Alarm : ");
    // alarm(2);
    fflush(stdout);
}

int main()
{
    int count = 0;
    signal(SIGALRM, fun);
    alarm(2);
    while (1)
    {
        count++;
        pause();
        printf("Count = %d\n", count);
        if (count >= 10)
            break;
    }
}

/*
    Output:

    [With alarm(2)]
    s4shibam@SHIBAM:~/OS$ gcc 24_Signal-SIGALRM.c
    s4shibam@SHIBAM:~/OS$ ./a.out
    Alarm : Count = 1
    Alarm : Count = 2
    Alarm : Count = 3
    Alarm : Count = 4
    Alarm : Count = 5
    Alarm : Count = 6
    Alarm : Count = 7
    Alarm : Count = 8
    Alarm : Count = 9
    Alarm : Count = 10
    s4shibam@SHIBAM:~/OS$

    [Without alarm(2)]
    s4shibam@SHIBAM:~/OS$ gcc 24_Signal-SIGALRM.c
    s4shibam@SHIBAM:~/OS$ ./a.out
    Alarm : Count = 1
    ^C
    s4shibam@SHIBAM:~/OS$
*/