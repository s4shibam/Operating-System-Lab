// Q. Transfer message from program1 to read & display by program2 using Shared Memory

// program1 --> 17_Shared_Memory_Data_Transfer_P1.c (Sender)
// program2 --> 17_Shared_Memory_Data_Transfer_P2.c (Receiver)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    void *sharedMemory;
    int shmid;
    char data[50];

    // Create shared memory segment with key 1234, having size 1024 bytes.
    // IPC_CREAT is used to create the shared segment if it does not exist.
    // 0777 are the permissions on the shared segment
    shmid = shmget((key_t)1234, 1024, IPC_CREAT | 0777);
    printf("P1: Key of shared memory is %d.\n", shmid);

    // Process attached to shared memory segment
    sharedMemory = shmat(shmid, NULL, 0);

    // Print the address where the segment is attached with this process
    printf("P1: Process attached at %p.\n", sharedMemory);

    // User input
    printf("P1: Enter the data to pass :\n");
    scanf("%[^\n]s", data);

    // Data written to shared memory
    strcpy(sharedMemory, data);
    printf("P1: Entered data - %s\n", (char *)sharedMemory);
}

/*
    Output:

    s4shibam@SHIBAM:~/OS$ gcc 17_Shared_Memory_Data_Transfer_P1.c
    s4shibam@SHIBAM:~/OS$ ./a.out
    P1: Key of shared memory is 0.
    P1: Process attached at 0x7f4078c88000.
    P1: Enter the data to pass :
    I am Shibam.
    P1: Entered data - I am Shibam.
    s4shibam@SHIBAM:~/OS$ gcc 17_Shared_Memory_Data_Transfer_P2.c
    s4shibam@SHIBAM:~/OS$ ./a.out
    P2: Key of shared memory is 0.
    P2: Process attached at 0x7f33ba8f5000.
    P2: Data read from shared memory - I am Shibam.
    s4shibam@SHIBAM:~/OS$
*/
