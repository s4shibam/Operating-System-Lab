// Q. Create an unnamed pipe for inter-process communication.
//	Accept a string input and then pass the data from child process 
//	to parent process to reverse it and again pass it back to
//	child process to print it. 
	
#include <stdio.h>
#include <unistd.h>

int main()
{
	int f, fd[2], len = 0;
	char data[50], buf[50];
	
	printf("Enter the input string: ");
	for (int i = 0; i < 6; i++)
	{
		scanf("%c", &data[i]);
	}		
	
	pipe(fd);
	f = fork();	
	
	// The creation of the process was unsuccessful
	if (f < 0){
		
		printf ("Error occurred!\n");
	}
	
	// Child process
	else if (f == 0){
		
		printf ("Child: Passing the data to Parent.\n");		
		write(fd[1], data, 6);	// Send data to parent
		sleep(5);
		
		read(fd[0], data, 50);	// Received reversed string from parent
		printf("Child saying: %s.\n", data);
	}
	
	// Parent process
	else {

		read(fd[0], buf, 50);	// Received data from child
		
		// String reverse
		int i = 0, j = 6 - 1;
		while(i < j)
		{			
			char temp = buf[i]; 
			buf[i++] = buf[j];
			buf[j--] = temp;
		}
		
		write(fd[1], buf, sizeof(buf));	// Send the reversed string to child
		printf("Parent: Passing the reversed string to child.\n");
	}
}

/*
	Output: 
	
	s4shibam@SHIBAM:~/OS$ gcc 12_IPC_String_Reverse.c
	s4shibam@SHIBAM:~/OS$ ./a.out
	Enter the input string: qwerty
	Child: Passing the data to Parent.
	Parent: Passing the reversed string to child.
	s4shibam@SHIBAM:~/OS$ Child saying: ytrewq.	
*/
