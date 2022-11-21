// Q. Transfer an unsorted array from program1 to read by program2
// and then after sorting that array sent it back (Named Pipe)

// program1 --> 15_Named_Pipe_Sort_Array_P1.c 
// program2 --> 15_Named_Pipe_Sort_Array_P2.c

// **Note: This program or transfer will work only if both the sender and receiver is availale

// Receiver
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void swap(int* xp, int* yp)
{
	printf("Swap! ");
	
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main()
{
	int n = 5, res;
	int buf[5];
	
	// Open named pipe
	res = open("nPipe2", O_RDWR);
	
	// Read message
	read(res, buf, sizeof(buf));
	
	printf ("P2: Unsorted array received to process pid: %d.\n", getpid());
	
	// Sort array
	int i, j;
	for (i = 0; i < n - 1; i++){
		
		for (j = 0; j < n - i - 1; j++){
			
			if (buf[j] > buf[j + 1])	
				swap(&buf[j], &buf[j + 1]);
			
		}
	}
	
	printf ("P2 says: Sorted Array: ");
	for (int i = 0; i < 5; i++)
	{	
		printf("%d ", buf[i]);
	}
	printf("\n");
	
	write(res, buf, sizeof(buf));
	sleep(2);
	printf ("P2: Sorted array sent back from process pid: %d.\n", getpid());
}

/*
	Output: 
	
	
*/
