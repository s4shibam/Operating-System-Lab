// Q. Transfer an unsorted array from program1 to read by program2
// and then after sorting that array sent it back using Shared Memory.

// program1 --> 17_Shared_Memory_Data_Transfer_P1.c (Sender)
// program2 --> 17_Shared_Memory_Data_Transfer_P2.c (Receiver)

/*
    **Note:
    Shared Memory is the fastest inter-process communication (IPC) method.
    The operating system maps a memory segment in the address space of several processes
    so that those processes can read and write in that memory segment.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int *sharedMemory;
    int shmid, n = 5;

    // Create shared memory segment with key 4321, having size 1024 bytes.
    // 0777 are the permissions on the shared segment
    shmid = shmget((key_t)4321, 1024, 0777);
    printf("P2: Key of shared memory is %d.\n", shmid);

    // Process attached to shared memory segment
    sharedMemory = shmat(shmid, NULL, 0);

    // Print the address where the segment is attached with this process
    printf("P2: Process attached at %p.\n", sharedMemory);

    // Sort array
    int i, j;
    for (i = 0; i < n - 1; i++)
    {

        for (j = 0; j < n - i - 1; j++)
        {

            if (sharedMemory[j] > sharedMemory[j + 1])
            {

                int temp = sharedMemory[j];
                sharedMemory[j] = sharedMemory[j + 1];
                sharedMemory[j + 1] = temp;
            }
        }
    }
    printf("P2: Array sorted!\n");
    printf("P2: Sorted array sent back to P1.\n");
}

/*
    Output:

    [Terminal 1]
    s4shibam@SHIBAM:~/OS$ gcc 18_Shared_Memory_Sort_Array_P1.c -o p1.out
    s4shibam@SHIBAM:~/OS$ ./p1.out
    Enter 5 array elements (space-separated): 234 789 12 567 123
    P1: Key of shared memory is 0.
    P1: Process attached at 0x7f873f032000.
    P1: Sorted array : 12 123 234 567 789
    s4shibam@SHIBAM:~/OS$


    [Terminal 2]
    s4shibam@SHIBAM:~/OS$ gcc 18_Shared_Memory_Sort_Array_P2.c -o p2.out
    s4shibam@SHIBAM:~/OS$ ./p2.out
    P2: Key of shared memory is 0.
    P2: Process attached at 0x7f19dab2b000.
    P2: Sorted array : 234 789 12 567 123
    P2: Array sorted!
    P2: Sorted array sent back to P1.
    s4shibam@SHIBAM:~/OS$
*/