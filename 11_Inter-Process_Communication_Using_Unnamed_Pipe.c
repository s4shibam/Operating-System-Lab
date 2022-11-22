// Q. Create an unnamed pipe for inter-process communication.
//	Accept a string input in the child process and then pass the data
//	to parent process to print it. 

/*
Note:
pipe():
	pipe() function creates a unidirectional pipe for IPC.
	On success it return two file descriptors pipefd[0] and pipefd[1].
	fd[0] is the reading end of the pipe. So, the process which will receive the data should use this file descriptor.
	fd[1] is the writing end of the pipe. So, the process that wants to send the data should use this file descriptor.
*/
	
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int f, fd[2], len;
	char data[50], buf[50];
	
	pipe(fd);
	f = fork();	
	
	// The creation of the process was unsuccessful
	if (f < 0){
		
		printf ("Error occurred!\n");
	}
	
	// Child process
	else if (f == 0){
		
		// For runtime input
		char data[50];
		printf("Enter the input string: ");
		scanf("%[^\n]s", data);
		write(fd[1], data, sizeof(data));
		
		printf ("Child: Passing the data to Parent.\n");
	}
	
	// Parent process
	else {
	
		wait(NULL);
		printf ("Parent: Data received.\n");
		read(fd[0], buf, 50);
		printf("Parent saying: %s\n", buf);
	}
}

/*
	Output: 
	
	s4shibam@SHIBAM:~/OS$ gcc 11_Inter-Process_Communication_Using_Unnamed_Pipe.c
	s4shibam@SHIBAM:~/OS$ ./a.out
	Enter the input string: I am the Data!
	Child: Passing the data to Parent.
	Parent: Data received.
	Parent saying: I am the Data!
	s4shibam@SHIBAM:~/OS$
*/
