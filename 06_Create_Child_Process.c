// Q. Create a child process using fork() and
// print the process ids.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int f;
	
	printf ("Before fork!\n");
	f = fork();	
	
	// The creation of the process was unsuccessful
	if (f < 0){
		
		printf ("Error occurred!\n");
	}
	
	// Child process
	else if (f == 0){
	
		printf ("This is Child Process!\n");
		printf ("Child: Child Process pid: %d\n", getpid());
		printf ("Child: Parent Process pid: %d\n", getppid());
	}
	
	// Parent process
	else {
	
		printf ("This is Parent Process!\n");
		printf ("Parent: Parent Process pid: %d\n", getpid());
		printf ("Parent: Child Process pid: %d\n", f);
	}
	
	// This part will be executed by both child & parent 
	printf ("This is common!\n");
}

/*
	Output:
	
	s4shibam@SHIBAM:~/OS$ gcc 6_Create_Child_Process.c
	s4shibam@SHIBAM:~/OS$ ./a.out
	Before fork!
	This is Parent Process!
	This is Child Process!
	Parent: Parent Process pid: 1868
	Child: Child Process pid: 1869
	Parent: Child Process pid: 1869
	Child: Parent Process pid: 1868
	This is common!
	This is common! 
	s4shibam@SHIBAM:~/OS$ 
*/
