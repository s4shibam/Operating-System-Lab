//  Q. Create 2 threads are created and different values are called on created thread.
//  Set the scheduling policies as Round-Robin. For each thread called,
//  it prints and increments the value of the counter infinite number of times.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int c = 10, counter = 0, c1, c2;
int tmp1, tmp2;
sem_t mutex;
int semType = 0, sm = 1;

void *fun(void *p)
{

    while (1)
    {

        counter++;
        sem_wait(&mutex);
        tmp1 = rand();
        c1 = tmp1 + c;
        c2 = tmp1 - c;

        sem_post(&mutex);
        if (c1 - c2 != 2 * c)
            break;

        printf("Thread: %d, c1: %d, c2: %d.\n", *(int *)p, c1, c2);
    }
    printf("Loop breaks in iteration Thread: %d, c1: %d, c2: %d.\n", counter, c1, c2);
}
int main()
{
    pthread_t th1, th2;
    int a = 1, b = -1;
    pthread_attr_t att;
    pthread_attr_init(&att);
    pthread_attr_setschedpolicy(&att, SCHED_RR);
    sem_init(&mutex, semType, sm);
    pthread_create(&th1, &att, (void *)fun, (void *)&a);
    pthread_create(&th2, &att, (void *)fun, (void *)&b);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    sem_destroy(&mutex);
}

/*
	Output:
	
	s4shibam@SHIBAM:~/OS$ ./a.out
	Thread: 1, c1: 1804289393, c2: 1804289373.
	Thread: 1, c1: 1681692787, c2: 1681692767.
	Thread: 1, c1: 1714636925, c2: 1714636905.
	Thread: 1, c1: 1957747803, c2: 1957747783.
	Thread: 1, c1: 424238345, c2: 424238325.
	Thread: 1, c1: 719885396, c2: 719885376.
	Thread: 1, c1: 1649760502, c2: 1649760482.
	^C
*/
