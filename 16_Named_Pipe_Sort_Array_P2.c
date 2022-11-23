// Q. Transfer an unsorted array from program1 to read by program2
// and then after sorting that array sent it back using Named Pipe.
// Execute the programs in separate terminals.

// program1 --> 15_Named_Pipe_Sort_Array_P1.c
// program2 --> 15_Named_Pipe_Sort_Array_P2.c

// **Note: This program or transfer will work only if both the sender and receiver is available

// Receiver
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Swap function
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int n = 5, res;
	int buf[5];

	// Open named pipe
	res = open("nPipe2", O_RDWR);

	// Read message
	read(res, buf, sizeof(buf));
	printf("P2: Unsorted array received to process pid: %d.\n", getpid());

	// Sort array
	int i, j;
	for (i = 0; i < n - 1; i++)
	{

		for (j = 0; j < n - i - 1; j++)
		{

			if (buf[j] > buf[j + 1])
				swap(&buf[j], &buf[j + 1]);
		}
	}
	printf("P2: Array sorted!\n");

	// Send sorted array to P1
	write(res, buf, sizeof(buf));
	printf("P2: Sorted array sent back from process pid: %d.\n", getpid());
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
