// Q. Create an unnamed pipe for inter-process communication.
//	Accept 2 integers x, y in the child process and
//	pass it to parent process to calculate x^y and pass it back to
//	child process to print it.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int f, fd[2], len;
	int arr[3] = {-1, -1, 1};
	
	pipe(fd);
	f = fork();	
	
	// The creation of the process was unsuccessfull
	if (f < 0){
		
		printf ("Error occured!\n");
	}
	
	// Child process
	else if (f == 0){
		
		// For runtime input
		char data[50];
		printf("Enter the base: ");
		scanf("%d", &arr[0]);
		printf("Enter the power: ");
		scanf("%d", &arr[1]);
		
		printf ("Child: Passing the data to Parent.\n");
		write(fd[1], arr, sizeof(arr));	// Send data to parent
		sleep(5);
		
		read(fd[0], arr, sizeof(arr));	// Received result from parent
		printf("Result: %d to the power %d is %d.\n", arr[0], arr[1], arr[2]);
	}
	
	// Parent process
	else {

		read(fd[0], arr, sizeof(arr));	// Received data from child
		printf ("Parent: Data received.\n");
		
		for (int i = 1; i <= arr[1]; i++)
		{
			arr[2] *= arr[0];
		}
		
		printf("Parent: Passing the result to child.\n");
		write(fd[1], arr, sizeof(arr));	// Send the result to child
	}
}

/*
	Output: 
	
	s4shibam@SHIBAM:~/OS$ gcc 13_IPC_Exponentiation.c
	s4shibam@SHIBAM:~/OS$ ./a.out
	Enter the base: 5
	Enter the power: 4
	Child: Passing the data to Parent.
	Parent: Data received.
	Parent: Passing the result to child.
	s4shibam@SHIBAM:~/OS$ Result:  5 to the power 4 is 625.   
*/
