// Q. Create thread which will print count 10 times after that the program terminates.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *fun()
{
    printf("Thread function starts!\n");
    for (int i = 1; i <= 10; i++)
    {
        printf("Count: %d\n", i);
        // sleep(1);
    }
    printf("Thread function ends!\n");
}
int main()
{
    // Thread declaration
    pthread_t th;
    printf("Main function starts!\n");

    // Thread creation
    int res = pthread_create(&th, NULL, fun, NULL);

    if (res != 0)
    {
        printf("Thread not created!\n");
    }

    // sleep(20);

    printf("Main function ends!\n");
}

/*
    Output:

    [With sleep()]
    s4shibam@SHIBAM:~/OS$ gcc 20_Thread.c -lpthread -o t.out
    s4shibam@SHIBAM:~/OS$ ./t.out
    Main function starts!
    Thread function starts!
    Count: 1
    Count: 2
    Count: 3
    Count: 4
    Count: 5
    Count: 6
    Count: 7
    Count: 8
    Count: 9
    Count: 10
    Thread function ends!
    Main function ends!
    s4shibam@SHIBAM:~/OS$

    [Without sleep()]
    s4shibam@SHIBAM:~/OS$ gcc 20_Thread.c -lpthread -o t.out
    s4shibam@SHIBAM:~/OS$ ./t.out
    Main function starts!
    Main function ends!
    Thread function starts!
    Thread function starts!
    Count: 1
    s4shibam@SHIBAM:~/OS$
*/