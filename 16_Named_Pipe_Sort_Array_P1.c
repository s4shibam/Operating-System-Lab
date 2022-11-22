// Q. Transfer an unsorted array from program1 to read by program2
// and then after sorting that array sent it back (Named Pipe)

// program1 --> 15_Named_Pipe_Sort_Array_P1.c 
// program2 --> 15_Named_Pipe_Sort_Array_P2.c

// **Note: This program or transfer will work only if both the sender and receiver is availale

// Sender
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int res, arr[5], sort[5];
	
	// Create named pipe
	unlink("nPipe2");
	res = mkfifo("nPipe2", 0777);
	printf ("Named pipe created successfully!\n");
	
	// User input
	printf("Enter 5 array elements (space-separated): ");
	for (int i = 0; i < 5; i++)
	{	
		scanf("%d", &arr[i]);
	}

	// Open named pipe
	res = open("nPipe2", O_RDWR);

	// Write message
	write(res, arr, sizeof(arr));
	printf ("P1: Unsorted array sent from process pid: %d.\n", getpid());
	
	sleep(10);
	
	read(res, sort, sizeof(sort));
	printf ("P1: Sorted array received to process pid: %d.\n", getpid());
	
	printf ("P1 says: Sorted Array: ");
	for (int i = 0; i < 5; i++)
	{	
		printf("%d ", sort[i]);
	}
	printf("\n");

}


/*
	Output: 
	
	
*/
