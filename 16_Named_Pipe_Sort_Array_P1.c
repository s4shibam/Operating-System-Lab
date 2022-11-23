// Q. Transfer an unsorted array from program1 to read by program2
// and then after sorting that array sent it back using Named Pipe.
// Execute the programs in separate terminals.

// program1 --> 15_Named_Pipe_Sort_Array_P1.c
// program2 --> 15_Named_Pipe_Sort_Array_P2.c

// **Note: This program or transfer will work only if both the sender and receiver is available

// Sender
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int res, arr[5], sort[5];

	// Create named pipe after unlinking
	unlink("nPipe2");
	res = mkfifo("nPipe2", 0777);
	printf("Named pipe created successfully!\n");

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
	printf("P1: Unsorted array sent from process pid: %d.\n", getpid());

	// Time to run the second program - P2
	// Run P2 in different terminal within this time
	sleep(10);

	// Read sorted array from P2
	read(res, sort, sizeof(sort));
	printf("P1: Sorted array received to process pid: %d.\n", getpid());

	// Print sorted array
	printf("P1 says: Sorted Array: ");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", sort[i]);
	}
	printf("\n");
}

/*
	Output:

	[Terminal 1]
	s4shibam@SHIBAM:~/OS$ gcc 16_Named_Pipe_Sort_Array_P1.c -o p1.out
	s4shibam@SHIBAM:~/OS$ ./p1.out
	Named pipe created successfully!
	Enter 5 array elements (space-separated): 56 87 90 21 45
	P1: Unsorted array sent from process pid: 602.
	P1: Sorted array received to process pid: 602.
	P1 says: Sorted Array: 21 45 56 87 90
	s4shibam@SHIBAM:~/OS$

	[Terminal 2]
	s4shibam@SHIBAM:~/OS$ gcc 16_Named_Pipe_Sort_Array_P2.c -o p2.out
	s4shibam@SHIBAM:~/OS$ ./p2.out
	P2: Unsorted array received to process pid: 603.
	P2: Array sorted!
	P2: Sorted array sent back from process pid: 603.
	s4shibam@SHIBAM:~/OS$
*/
