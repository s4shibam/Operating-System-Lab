// Q. Create a process that loads another program as child process.
// Modify with following flexibilities:
//	1. Program name is user input.
//	2. The main process will terminate if user input is "exit".

// Note: This is basically Replacement Process image in Linux

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int f, s;
	char prog[20], path[50] = "./";
	
	printf("Enter program name: ");
	scanf("%s", prog);
	
	if (strcmp(prog, "exit") == 0)
	{		
		printf ("Exiting program...\n");
		exit(0);
	}
	
	strcat(path, prog);

	f = fork();	
	
	// The creation of the process was unsuccessfull
	if (f < 0){
		
		printf ("Error occured!\n");
	}
	
	// Child process
	else if (f == 0){
		
		printf ("Child: I am the child.\n");
		execlp(path, prog, NULL);

	}
	
	// Parent process
	else {
		
		sleep(5);
		wait(&s);
		printf ("Parent: I am the parent.\n");
		printf ("The child has exited with the status: %d.\n", WEXITSTATUS(s));
	}
}

/*
	Output 1: 
	
	s4shibam@SHIBAM:~/OS$ gcc Helper.c -o Helper.out
	s4shibam@SHIBAM:~/OS$ gcc 14_Load_Program_In_Child_Process.c
	s4shibam@SHIBAM:~/OS$ ./a.out
	Enter program name: Helper.out
	Child: I am the child.
	This is a Helper Program.
	Parent: I am the parent.
	The child has exited with the status: 0.
	s4shibam@SHIBAM:~/OS$
	
	Output 2:
	s4shibam@SHIBAM:~/OS$ gcc 14_Load_Program_In_Child_Process.c
	s4shibam@SHIBAM:~/OS$ ./a.out
	Enter program name: exit
	Exiting program...
	s4shibam@SHIBAM:~/OS$
*/

/*
	[Helper.c]

	#include <stdio.h>

	int main()
	{
		printf("This is a Helper Program.\n");	
	}
*/
