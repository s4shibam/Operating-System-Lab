//  Q. Program which pauses until it receives a key like Ctrl+C when pressed with a suitable warning message.

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void fun(int signum)
{

    printf("\nCTRL + C is pressed!\n");
    fflush(stdout);
}
int main()
{
    signal(SIGINT, fun);
    while (1)
    {
        pause();
    }
}

/*
    Output:
    
    s4shibam@SHIBAM:~/OS$ gcc 23_Signal-SIGINT.c
	s4shibam@SHIBAM:~/OS$ ./a.out
	^C
	CTRL + C is pressed!
	^C
	CTRL + C is pressed!
	^C
	CTRL + C is pressed!
	^C
	CTRL + C is pressed!  
*/
