// Q. Create  5 thread and each individual thread function will print the parameter/id passed from the called thread.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *fun(void *p)
{
    long tid = (long)p;
    printf("Thread is called with parameter: %ld\n", tid);
    pthread_exit(NULL);
}
int main()
{
    // Thread declaration
    pthread_t th[5];
    printf("Main function starts!\n");

    // Thread creation
    int res;
    for (long i = 0; i < 5; i++)
    {
        res = pthread_create(&th[i], NULL, fun, (void *)i);

        if (res != 0)
        {
            printf("Thread not created!\n");
        }
        // pthread_join(th[i], NULL);
    }

    sleep(20);

    printf("Main function ends!\n");
}

/*
    Output:

    [With pthread_join]
    s4shibam@SHIBAM:~/OS$ gcc 21_Thread_With_Parameter.c -lpthread -o t.out
    s4shibam@SHIBAM:~/OS$ ./t.out
    Main function starts!
    Thread is called with parameter: 0
    Thread is called with parameter: 1
    Thread is called with parameter: 2
    Thread is called with parameter: 3
    Thread is called with parameter: 4
    Main function ends!
    s4shibam@SHIBAM:~/OS$

    [Without pthread_join]
    s4shibam@SHIBAM:~/OS$ gcc 21_Thread_With_Parameter.c -lpthread -o t.out
    s4shibam@SHIBAM:~/OS$ ./t.out
    Main function starts!
    Thread is called with parameter: 0
    Thread is called with parameter: 1
    Thread is called with parameter: 2
    Thread is called with parameter: 3
    Thread is called with parameter: 4
    Main function ends!
    s4shibam@SHIBAM:~/OS$
*/