//  Q. program in C, to show the behaviour of different signals sigint, SIGINT
//  SIGTERM, SIGKILL and execute the handler externally form the command prompt.

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void fun(int s)
{
    if (s == SIGINT)
        printf("\nSIGINT called\n");
    if (s == SIGTERM)
        printf("\nSIGTERM called\n");
    if (s == SIGKILL)
        printf("\nSIGKILL called\n");
    fflush(stdout);
}

int main()
{
    signal(SIGINT, fun);
    signal(SIGTERM, fun);
    signal(SIGKILL, fun);
    for (;;)
        pause();
    return 0;
}

/*
    Output:
    s4shibam@SHIBAM:~/OS$ gcc 25_Signal-SIG_ING.c
    s4shibam@SHIBAM:~/OS$ ./a.out
    ^C
    SIGINT called
    ^Z
    [1]+  Stopped                 ./a.out
    s4shibam@SHIBAM:~/OS$ ps -e| grep "a.out"
    5993 tty1     00:00:00 a.out
    s4shibam@SHIBAM:~/OS$ kill -s SIGINT 5993
    s4shibam@SHIBAM:~/OS$ kill -s SIGTERM 5993
    s4shibam@SHIBAM:~/OS$ kill -s SIGKILL 5993
    s4shibam@SHIBAM:~OS$
*/